#pragma once

template<typename T>
struct Node {
	T data;
	Node<T>* next;
};

template<typename T>
class Linked_list
{
	Node<T>* tail;
	Node<T>* head;
	int size;
public:
	Linked_list();
	void push(T);
	T remove(int);
	T& at(int);
	int get_size() { return size; }
};


