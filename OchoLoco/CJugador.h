#pragma once
#include "CLista.h"
#include "CBDescarte.h"

class CJugador
{
public:
	CJugador();
	std::string m_nombre;
	CLista<CCarta> m_lista;
	int puntuacion;
	void calcular_puntacion();
	bool Comparar(CNodo<CCarta> *p, int num, std::string palo);
	void Turno(CLista<CCarta> &b, CBDescarte &d);
	~CJugador();
};

