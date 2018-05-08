// OchoLoco.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "CCarta.h"
bool comparar(CJugador* jugador,int NumJugadores)
{
	for (int i = 0; i < NumJugadores; i++) {
		if (!(jugador + i)->m_lista.m_head)
			return 0;
	}
	return 1;
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
	CBaraja b;
	b.Repartir(jugadores, NumJugadores);

	while (b.m_lista.m_head->m_data.m_numero == 8)
		b.Barajear();

	CBDescarte Descarte;
	Descarte.Insert(b.m_lista.m_head);
	b.m_lista.Pop();
	b.m_size--;

	do
	{
		for (int i = 0; i < NumJugadores; i++) 
		{
			system("cls");
			cout << endl << " Turno de " << jugadores[i].m_nombre << endl;
			system("pause");
			jugadores[i].Turno(b.m_lista, b.m_size, Descarte);
			if (!jugadores[i].m_lista.m_head && !b.m_size != 0)
				break;
		}
	} while (b.m_size != 0 && comparar(jugadores, NumJugadores));
	
	return 0;
}

