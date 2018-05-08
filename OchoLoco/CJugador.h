#ifndef CJUGADOR_H
#define CJUGADOR_H

//#include "CBaraja.h"
#include "CLista.h"

class CJugador
{
public:
	CJugador();
	std::string m_nombre;
	CLista<CCarta> m_lista;
	int puntuacion;
	void calcular_puntacion();
	//void Turno(CLista<CCarta> d, CBaraja b);
	~CJugador();
};

#endif 