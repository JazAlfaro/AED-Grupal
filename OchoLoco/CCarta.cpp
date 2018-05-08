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
	if (m_numero == 1)
		cout << "| A " << m_palo << " |" << endl;
	else if (m_numero == 11)
		cout << "| J " << m_palo << " |" << endl;
	else if (m_numero == 12)
		cout << "| Q " << m_palo << " |" << endl; 
	else if (m_numero == 13)
		cout << "| K " << m_palo << " |" << endl; 
	else
		cout << "| " << m_numero << " " << m_palo << " |" << endl;
}

CCarta::~CCarta()
{
}
