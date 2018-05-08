#pragma once

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