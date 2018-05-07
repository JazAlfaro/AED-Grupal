#pragma once
#include "stdafx.h"

class CCarta
{
public:
	CCarta();
	CCarta(int num, std::string palo);
	int m_numero;
	std::string m_palo;
	void operator() (int num, std::string palo);
	void Print();
	~CCarta();
};

