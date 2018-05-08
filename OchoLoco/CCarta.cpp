#include "stdafx.h"
#include "CCarta.h"

CCarta::CCarta()
{
	m_numero = ' ';
	m_palo = "";
}

CCarta::CCarta(int num, std::string palo)
{
	m_numero = num;
	m_palo = palo;
}

void CCarta::operator() (int num, std::string palo)
{
	m_numero = num;
	m_palo = palo;
}

void CCarta::Print()
{
	cout << "| " << m_numero << " " << m_palo << " |" << endl;
}

CCarta::~CCarta()
{
}
