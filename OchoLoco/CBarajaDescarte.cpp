#include "stdafx.h"
#include "CBarajaDescarte.h"


void CBarajaDescarte::Set_palo(std::string palo)
{
	m_palo = palo;
}

void CBarajaDescarte::Set_numero(int numero)
{
	m_numero = numero;
}

void CBarajaDescarte::Set(CNodo<CCarta> *p)
{
	m_numero = p->m_data.m_numero;
	m_palo = p->m_data.m_palo;
}

bool CBarajaDescarte::Insert(CNodo<CCarta> *p)
{
	if (m_lista.Insert(p))
	{
		Set(p);
		return true;
	}
	return false;
}

CBarajaDescarte::CBarajaDescarte()
{
}


CBarajaDescarte::~CBarajaDescarte()
{
}
