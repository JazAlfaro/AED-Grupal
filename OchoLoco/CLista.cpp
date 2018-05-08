#include "stdafx.h"
#include "CLista.h"

template <class T>
CLista<T>::CLista()
{
	m_head = NULL;
}

template <class T>
void CLista<T>::Print()
{
	int i = 0;
	for (CNodo<T> *t = m_head; t != NULL; t = t->m_next)
	{
		cout << "  " << i << ".- ";
		t->m_data.Print();
		i++;
	}
}

template <class T>
bool CLista<T>::Find(int num, std::string palo, CNodo<T> **&p)
{
	for (p = &m_head; *p && ((*p)->m_data.m_numero != num || (*p)->m_data.m_palo != palo); p = &((*p)->m_next));
	return (*p) && (*p)->m_data.m_numero == num && (*p)->m_data.m_palo == palo;
}

template <class T>
bool CLista<T>::Find(int pos, CNodo<T> **&p)
{
	int i;
	p = &m_head;
	for (i = 0; *p && i < pos; i++)
		p = &(*p)->m_next;

	if (i == pos)
		return true;
	else
		return false;
}

template <class T>
bool CLista<T>::Insert(int num, std::string palo)
{
	CNodo<T> **p;
	if (Find(num, palo, p))
		return 0;
	CNodo<T> *t = new CNodo<T>(num, palo);
	t->m_next = *p;
	*p = t;
	return 1;
}

template <class T>
bool CLista<T>::Insert(int num, std::string palo, int pos)
{
	CNodo<T> **p = &m_head;
	
	for (int i = 0; (*p) && i < pos; i++)
		p = &((*p)->m_next);

	CNodo<T> *t = new CNodo<T>(num, palo);
	t->m_next = *p;
	*p = t;
	return 1;
}

template <class T>
bool CLista<T>::Insert(CNodo<T> *p)
{
	Insert(p->m_data.m_numero, p->m_data.m_palo, 0);
	return 1;
}

template <class T>
bool CLista<T>::Remove(int num, std::string palo)
{
	CNodo<T> **p;
	if (!Find(num, palo, p))
		return 0;
	CNodo<T> *t = *p;
	*p = t->m_next;
	delete t;
	return 1;
}

template <class T>
bool CLista<T>::Pop()
{
	CNodo<T> **p = &m_head;
	if (!(*p))
		return 0;
	CNodo<T> *t = *p;
	*p = t->m_next;
	delete t;
	return 1;
}

template <class T>
void CLista<T>::Swap(CNodo<CCarta> *&t1, CNodo<CCarta> *&t2) 
{
	std::string Tpalo = (*t1).m_data.m_palo;
	int Tnum = (*t1).m_data.m_numero;

	(*t1).m_data.m_numero = (*t2).m_data.m_numero;
	(*t1).m_data.m_palo = (*t2).m_data.m_palo;
	(*t2).m_data.m_numero = Tnum;
	(*t2).m_data.m_palo = Tpalo;
}

template <class T>
CLista<T>::~CLista()
{
}

template class CLista<CCarta>;