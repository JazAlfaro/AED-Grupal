#pragma once
#include "CLista.h"

class CBDescarte
{
public:
	std::string m_palo;
	int m_num;
	CLista<CCarta> m_lista;
	CBDescarte();
	bool Insert(CNodo<CCarta> *p);
	~CBDescarte();
};

