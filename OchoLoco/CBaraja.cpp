#include "stdafx.h"

CBaraja::CBaraja()
{
	srand(time(NULL));
	m_size = 0;
	std::string lista_palos[4] = {"Espadas", "Corazones", "Rombos", "Treboles"};
	for (int i = 1; i <= 13; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m_lista.Insert(i, lista_palos[j], rand() % (m_size + 1));
			m_size++;
		}
	}
}

void CBaraja::Repartir(CJugador ju[], int tam)
{
	int NumCartas = 8;
	if (tam == 2)
		NumCartas = 7;
	for (int i = 0; i < NumCartas; i++)
	{
		for (int j = 0; j < tam; j++)
		{
			ju[j].m_lista.Insert(m_lista.m_head->m_data.m_numero, m_lista.m_head->m_data.m_palo, 0);
			m_lista.Pop();
			m_size--;
		}
	}
}

void CBaraja::Barajear(int a, int b)
{
	CNodo<CCarta> **t1, **t2;
	//for (int i = 0; i < 1; i++)
	//{
		cout << a << " " << b << endl;
		t1 = NULL;
		t2 = NULL;
		m_lista.Find(a, t1);
		m_lista.Find(b, t2);
		
		CNodo<CCarta> *t3 = *t1;
		CNodo<CCarta> *t4 = *t2;
		CNodo<CCarta> *t5 = t3->m_next;
		CNodo<CCarta> *t6 = t4->m_next;

		*t1 = t4;
		(*t1)->m_next = t3->m_next;
		*t2 = t3;
		t3->m_next = t6;
		a = 0;
		b = 0;
	//}
	//cout << m_size << endl;
}

void CBaraja::Barajear2()
{
	srand(time(NULL));
	int a, b;
	for (int i = 0; i < 25; i++)
	{
		a = (rand() % m_size);
		b = (rand() % m_size);
		if ((a+1 != b) || (b+1 != a))
			Barajear(a, b);

	}
}

CBaraja::~CBaraja()
{
	
}
