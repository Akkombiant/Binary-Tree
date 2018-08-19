#ifndef ELEMENT_H
#define ELEMENT_H


template<typename T>
struct Element
{
	T info;
	Element<T> *left;
	Element<T> *right;
	Element<T> *parent;
	Element();
};

template<typename T>
Element<T>::Element() : left(nullptr), right(nullptr), parent(nullptr), info(0) {}

#endif // !ELEMENT_H