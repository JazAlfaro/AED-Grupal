#ifndef CBARAJADESCARTE_H
#define CBARAJADESCARTE_H

#pragma once
#include "CLista.h"

class CBarajaDescarte
{
public:
	CLista<CCarta> m_lista;
	std::string m_palo;
	int m_numero;
	void Set_palo(std::string palo);
	void Set_numero(int numero);
	void Set(CNodo<CCarta> *p);
	bool Insert(CNodo<CCarta> *p);
	CBarajaDescarte();
	~CBarajaDescarte();
};

#endif 