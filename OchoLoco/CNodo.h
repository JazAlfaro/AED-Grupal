#ifndef CNODO_H
#define CNODO_H
#pragma once
#include "CCarta.h"

template <class T>
class CNodo
{
public:
	T m_data;
	CNodo<T> *m_next;
	CNodo(char num, std::string palo);
	//CNodo(char num, std::string palo, CNodo<T> *s);
	~CNodo();
};

#endif 