#include <stdexcept>
#include <utility>
#include "Linked_list.h"

template<typename T>
Linked_list<T>::Linked_list() :head(nullptr), tail(nullptr) { size = 0; }

template<typename T>
void Linked_list<T>::push(T data) {
	Node<T>* node = new Node<T> { std::move(data), nullptr };
	

	if (head == nullptr) {
		head = node;
		tail = node;
	}
	else {
		tail->next = node;
		tail = node;
	}
	size++;
}

template<typename T>
T& Linked_list<T>::at(int index) {
	if (index < 0 || index >= size){
		throw std::out_of_range("index invalide");
	}

	Node<T>* current = head;
	for (int idx = 0; idx < index; idx++) {
		current = current->next;
	}
	return current->data;
}

template<typename T>
T Linked_list<T>::remove(int index) {
	if (index < 0 || index >= size) {
		throw std::out_of_range("index invalide");
	}

	Node<T>* previous = nullptr;
	Node<T>* current = head;
	
	for (int idx = 0; idx < index; idx++) {
		previous = current;
		current = current->next;
	}
	if (previous == nullptr) {
		head = current->next;
	}
	else previous->next = current->next;

	if (current == tail) {
		tail = previous;
	}

	T data = std::move(current->data);
	delete current;
	size--;
	return data;
}

