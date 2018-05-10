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
	for (CNodo<CCarta>* i = m_lista.m_head; i; i = i->m_next)
	{
		if (i->m_data.m_numero >= 10)
			puntuacion += 10;
		else if (i->m_data.m_numero == 8)
			puntuacion += 50;
		else
			puntuacion += i->m_data.m_numero;
	}
}

bool CJugador::Comparar(CNodo<CCarta> *p, int num, std::string palo)
{
	if (p != NULL)
		return ((p->m_data.m_numero == num) || (p->m_data.m_palo == palo) || (p->m_data.m_numero == 8));
	else
		return false;
}

void CJugador::Turno(CLista<CCarta>& b, int &bsize, CBDescarte &d)
{
	int pos;
	CNodo<CCarta> **p = &m_lista.m_head;

	cout << endl << " Palo actual: " << d.m_palo << endl;
	cout << " Descarte ";
	d.m_lista.m_head->m_data.Print();
	cout << endl;
	m_lista.Print();
	cout << "  54.- Para sacar carta" << endl << endl;

	do {
		cout << "Ingresa la pos ";
		cin >> pos;
		m_lista.Find(pos, p);
	} while ((pos != 54) && !Comparar(*p, d.m_num, d.m_palo));
	
	if (pos != 54)
	{
		d.Insert(*p);
		m_lista.Remove((*p)->m_data.m_numero, (*p)->m_data.m_palo);
	}
	else
	{
		if (bsize == 0)
		{
			return;
		}
		else
		{
			m_lista.Insert(b.m_head);
			b.Pop();
			bsize--;
			Turno(b, bsize, d);
		}
	}
}