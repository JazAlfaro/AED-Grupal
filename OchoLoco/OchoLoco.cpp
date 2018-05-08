// OchoLoco.cpp: define el punto de entrada de la aplicación de consola.
#include "stdafx.h"

#include "CCarta.h"
#include "CJugador.h"
#include "CBaraja.h"
#include "CBarajaDescarte.h"

bool comparar(CJugador* jugador,int NumJugadores)
{
	for (int i = 0; i < NumJugadores; i++) {
		if (!(jugador + i)->m_lista.m_head)
			return 0;
	}
}

int main()
{
	int NumJugadores;
	cout << "Ingresa el numero de jugadores: ";
	cin >> NumJugadores;

	CJugador *jugadores = new CJugador[NumJugadores];
	for (int i = 0; i < NumJugadores; i++)
	{
		cout << "Nombre del jugador: ";
		cin >> jugadores[i].m_nombre;
	}
	CBaraja baraja;
	//baraja.Repartir(jugadores, NumJugadores);
	
	CBarajaDescarte descarte;
	//descarte.Insert(baraja.m_lista.m_head);
	baraja.m_lista.Pop();

	//descarte.m_lista.m_head->m_data.Print();
	do
	{
		for (int i = 0; i < NumJugadores; i++) {
			//jugadores[i].Turno(b, LDescarte);
			if (!jugadores[i].m_lista.m_head)
				return 0;
		}
	} while (baraja.m_size != 0 && comparar(jugadores, NumJugadores));

	return 0;
}

