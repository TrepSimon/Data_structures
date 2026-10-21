#pragma once
#include <stdexcept>
#include <utility>

template<typename T>
struct Node {
	T* data;
	Node<T>* next;
	Node<T>* previous;
};

template<typename T>
class Linked_list
{
	Node<T>* tail;
	Node<T>* head;
	int size;
public:
	Linked_list();
	~Linked_list();
	void push(T*);
	T& pop();
	T& remove(int);
	T& front();
	T& back();
	T& at(int);
	int get_size() { return size; }
	bool empty() { return size == 0; }
	void clear();
};

template<typename T>
Linked_list<T>::Linked_list() :head(nullptr), tail(nullptr) { size = 0; }

template<typename T>
Linked_list<T>::~Linked_list() {
	Node<T>* current = head;

	while (current->next != nullptr) {
		Node<T>* nextNode = current->next;
		delete current;
		current = nextNode;
	}
}

template<typename T>
void Linked_list<T>::push(T* data) {
	Node<T>* node = new Node<T>{ std::move(data), nullptr, nullptr };


	if (head == nullptr) {
		head = node;
		tail = node;
	}
	else {
		node->previous = tail;
		tail->next = node;
		tail = node;
	}
	size++;
}

template<typename T>
T& Linked_list<T>::pop() {
	if (size <= 0) {
		throw std::length_error("Liste vide");
	}

	T* data = std::move(tail->data);
	Node<T>* temp = tail;
	tail = tail->previous;
	tail->next = nullptr;
	delete temp;
	size--;
	return *data;
}

template<typename T>
T& Linked_list<T>::at(int index) {
	if (index < 0 || index >= size) {
		throw std::out_of_range("index invalide");
	}

	Node<T>* current = head;
	for (int idx = 0; idx < index; idx++) {
		current = current->next;
	}
	return *current->data;
}

template<typename T>
T& Linked_list<T>::front() {
	if (head == nullptr) {
		throw std::length_error("Liste vide");
	}
	return *head->data;
}

template<typename T>
T& Linked_list<T>::back() {
	if (tail == nullptr) {
		throw std::length_error("Liste vide");
	}

	return *tail->data;
}

template<typename T>
T& Linked_list<T>::remove(int index) {
	if (index < 0 || index >= size) {
		throw std::out_of_range("index invalide");
	}

	Node<T>* previous = nullptr;
	Node<T>* current = head;

	for (int idx = 0; idx < index; idx++) {
		previous = current;
		current = current->next;
	}

	if (current->next != nullptr) {
		current->next->previous = previous;
	}

	if (previous == nullptr) {
		head = current->next;
	}
	else previous->next = current->next;

	if (current == tail) {
		tail = previous;
	}

	T* data = std::move(current->data);
	delete current;
	size--;
	return *data;
}

template<typename T>
void Linked_list<T>::clear() {
	while (head != nullptr) {
		remove(0);
	}
	
}


