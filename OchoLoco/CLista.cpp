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
	cout << "cabeza";
	m_head->m_data.Print();
	for (CNodo<T> *t = m_head; t != NULL; t = t->m_next)
	{
		cout << i;
		t->m_data.Print();
		i++;
	}
	cout << endl;
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
	p = &m_head;
	for (int i = 0; i < pos; i++)
		p = &(*p)->m_next;

	return 1;
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
void CLista<T>::Swap(CNodo<T> **&t1, CNodo<T> **&t2)
{
	CNodo<T> *t3 = *t1;
	CNodo<T> *t4 = *t2;
	CNodo<T> *t5 = t3->m_next;
	CNodo<T> *t6 = t4->m_next;

	*t1= t4;
	(*t1)->m_next = t3->m_next;
	*t2 = t3;
	t3->m_next = t6;
	//(*t2)->m_next = t4->m_next;
}

template <class T>
CLista<T>::~CLista()
{
}

template class CLista<CCarta>;