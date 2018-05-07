#pragma once
#include "CLista.h"
#include "CBaraja.h"

class CJugador
{
public:
	CJugador();
	std::string m_nombre;
	CLista<CCarta> m_lista;
	int puntuacion;
	void calcular_puntacion();
	void Turno(CLista<CCarta> b, CLista<CCarta> l);
	~CJugador();
};

