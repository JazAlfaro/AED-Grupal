#include "stdafx.h"
#include "CBDescarte.h"

CBDescarte::CBDescarte()
{

}

bool CBDescarte::Insert(CNodo<CCarta>* p)
{
	if (p->m_data.m_numero != 8)
	{
		m_palo = p->m_data.m_palo;
		m_num = p->m_data.m_numero;
		m_lista.Insert(p);
	}
	else
	{
		cout << " ***Ingrese el nuevo palo*** " << endl;
		cin >> m_palo;
		m_num = 8;
		m_lista.Insert(p);
	}
	return true;
}

CBDescarte::~CBDescarte()
{
}
