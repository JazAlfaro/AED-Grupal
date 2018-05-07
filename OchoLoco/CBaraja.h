#pragma once
#include "CLista.h"
#include "CJugador.h"

class CBaraja
{
public:
	CBaraja();
	int m_size;
	CLista<CCarta> m_lista;
	void Repartir(CJugador ju[], int tam);
	void Barajear(int a, int b);
	void Barajear2();
	~CBaraja();
};

