#include "stdafx.h"
#include "CNodo.h"
#include "CCarta.h"

template <class T>
CNodo<T>::CNodo(char num, std::string palo)
{
	m_data(num, palo);
	m_next = NULL;
}
/*
template <class T>
CNodo<T>::CNodo(T x, CNodo<T> *s)
{
	m_data = x;
	m_next = s;
}
*/
template <class T>
CNodo<T>::~CNodo()
{
	m_next = NULL;
	//delete m_next;
}

template class CNodo<CCarta>;