#pragma once
#include "CLista.h"
#include "CJugador.h"
#include <time.h>

class CBaraja
{
public:
	CBaraja();
	int m_size;
	CLista<CCarta> m_lista;
	void Repartir(CJugador ju[], int tam);
	void Barajear();
	~CBaraja();
};

