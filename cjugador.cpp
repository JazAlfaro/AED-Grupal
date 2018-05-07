#include "stdafx.h"
#include "CJugador.h"


//Se cambiado el constructor,ahora cuando se crea el jugador su puntación empieza con 0
//Se creo la funcion calcular puntuacion, esta se utilizara cuando ya no haya
CJugador::CJugador()
{
	puntuacion = 0;
}


CJugador::~CJugador()
{
}

void CJugador::calcular_puntacion()
{
	for (CNodo<CCarta>* i = m_lista.m_head;i; i = i->m_next)
		if (i->m_data.m_numero >= 10)
			puntuacion += 10;
		else if (i->m_data.m_numero == 8)
		{
			puntuacion += 50;
		}
		else
			puntuacion += i->m_data.m_numero;
}

void CJugador::Turno(CLista<CCarta> b, CLista<CCarta> d)   //b es la baraja volteada y d es la de descarte
{
	cout << "Ingresa el numero que desea colocar o sino '54' para sacar una carta";
	int x;
	m_lista.Print();
	if (x != 54)
	{
		cout << "Ingresa el palo de la carta ";
		std::string o;
		cin >> o;
		CNodo<CCarta> **p;
		if (m_lista.Find(x,o, p))
		{
			if (x == 8)
			{
				std::string y;
				cout << "Que palo deseas??" << endl;
				cin >> y;
				d.Insert(x, y);
				m_lista.Remove(x, o);
			}
			d.Insert(x,o);
			m_lista.Remove(x, o);
		}
	}
	m_lista.Insert(b.m_head);
	b.Remove(b.m_head->m_data.m_numero, b.m_head->m_data.m_palo);
}
