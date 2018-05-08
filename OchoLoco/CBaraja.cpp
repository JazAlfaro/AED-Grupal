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

void CBaraja::Barajear()
{
	m_lista.Pop();
}

CBaraja::~CBaraja()
{
	
}
