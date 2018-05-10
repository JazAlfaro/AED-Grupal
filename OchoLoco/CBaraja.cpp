#include "stdafx.h"

CBaraja::CBaraja() //constructor por defecto para la generacion del mazo
{
	srand(time(NULL));
	m_size = 0;
	std::string lista_palos[4] = {"Espadas", "Corazones", "Rombos", "Treboles"}; //variable lista de palos para valores figurativos de las cartas
	for (int i = 1; i <= 13; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m_lista.Insert(i, lista_palos[j], rand() % (m_size + 1));	//for encargado de generar la baraja del 1 al 13
			m_size++;							//escogiendo un valor de la lista de palos, formando
		}									//la carta con valor numerico y simbolo.
	}
}

void CBaraja::Repartir(CJugador ju[], int tam)//funcion para repatir las cartas, parametros de la clase jugador y la cantidad de jugadores
{
	int NumCartas = 8;//cantidad estandar de cartas para mas de 3 jugadores
	if (tam == 2)
		NumCartas = 7;//cantidad estricta para dos jugadores a repartir
	for (int i = 0; i < NumCartas; i++)
	{
		for (int j = 0; j < tam; j++)//entrega las cartas por cada jugador insertando desde la baraja el palo la cantidad que se ha solicitado
		{
			ju[j].m_lista.Insert(m_lista.m_head->m_data.m_numero, m_lista.m_head->m_data.m_palo, 0);
			m_lista.Pop();
			m_size--;
		}
	}
}

void CBaraja::Barajear()//funcion encargada de barajear el mazo a partir de la lista de palos
	CNodo<CCarta> **t1, **t2;
	int a, b;
	for (int i = 0; i < 23; i++) {
		a = rand() % (m_size + 1);
		b = rand() % (m_size + 1);
		m_lista.Find(a, t1);
		m_lista.Find(b, t2);
		//cout << "A: " << a << "B:  " << b << endl;
		m_lista.Swap(*t1, *t2);
	}
}

CBaraja::~CBaraja()//destructor 
{
	
}
