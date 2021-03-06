#pragma once
#include "CCarta.h"

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
	void Swap(CNodo<CCarta> *&t1, CNodo<CCarta> *&t2);

	bool Pop();
	~CLista();
};