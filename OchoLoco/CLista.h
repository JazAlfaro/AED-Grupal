#ifndef CLISTA_H
#define CLISTA_H
#pragma once
#include "CCarta.h"
#include "CNodo.h"

template <class T>
class CLista
{
public:
	CNodo<T> *m_head;
	CLista();
	void Print();
	bool Find(int num, std::string palo, CNodo<T> **&p);
	bool Find(int pos, CNodo<T> **&p);
	bool Insert(int num, std::string palo);
	bool Insert(int num, std::string palo, int pos);
	bool Insert(CNodo<T> *p);
	bool Remove(int num, std::string palo);
	void Swap(CNodo<T> **&t1, CNodo<T> **&t2);

	bool Pop();
	~CLista();
};

#endif 