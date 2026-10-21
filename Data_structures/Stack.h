#pragma once
#include <stdexcept>
#include <utility>


template<typename T>
class Stack
{
	T** base_ptr;
	T** stack_ptr;
	int max_size = 20;
	int current_size = 0;

	void reallocate();
	void refill(T**);
	void allocate(T*);
public:
	Stack();
	Stack(T*);
	~Stack();
	bool is_empty() { return current_size == 0; }
	void push(T* data);
	T& peek();
	void clear();
};

template<typename T>
void Stack<T>::allocate(T* data) {
	base_ptr = (T**)malloc(sizeof(T*) * max_size);

	if (base_ptr == nullptr) {
		throw std::bad_alloc();
	}
	*base_ptr = data;
	stack_ptr = base_ptr;
	current_size++;
}

template<typename T>
Stack<T>::Stack() : base_ptr(nullptr), stack_ptr(nullptr){}

template<typename T>
Stack<T>::Stack(T* data) {
	allocate(data);
}

template<typename T>
void Stack<T>::clear() {
	free(base_ptr);

	base_ptr = nullptr;
	stack_ptr = nullptr;
}

template<typename T>
Stack<T>::~Stack() {
	clear();
}

template<typename T>
void Stack<T>::refill(T** new_base) {
	T** ptr = base_ptr;
	T** top = base_ptr;

	for (auto head = new_base; ptr <= stack_ptr; head++, ptr++) {
		*head = *ptr;
		top = head;
	}
	base_ptr = new_base;
	stack_ptr = top;
}

template<typename T>
void Stack<T>::reallocate() {
	max_size = max_size << 1;

	T** tempBase = (T**)malloc(sizeof(T*) * max_size);
	refill(tempBase);
}

template<typename T>
void Stack<T>::push(T* data) {
	if (stack_ptr - base_ptr > max_size) {
		reallocate();
	}

	if (base_ptr == nullptr) {
		allocate(data);
		return;
	}

	stack_ptr++;
	*stack_ptr = data;
	current_size++;
}

template<typename T>
T& Stack<T>::peek() {
	if (is_empty()) {
		throw std::out_of_range("Liste vide");
	}
	return **stack_ptr;
}



