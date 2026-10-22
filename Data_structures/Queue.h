#pragma once
#include <stdexcept>


template<typename T>
class Queue
{
	T* front;
	T* back;
	int max_size = 20;
	int current_size = 0;

	void allocate(T);
public:
	Queue();
	Queue(T);
	~Queue();
	void clear();
	void enqueue(T);
};

template<typename T>
void Queue<T>::allocate(T Data) {
	back = (T*)malloc(sizeof(T) * max_size);

	if (back == nullptr)throw std::bad_alloc();

	*back = data;
	front = back;
	current_size++;
}

template<typename T>
void Queue<T>::clear() {
	free(back);
	back = nullptr;
	front = nullptr;
}

template<typename T>
Queue<T>::Queue() : front(nullptr), back(nullptr) {}

template<typename T>
Queue<T>::Queue(T data) {
	allocate(data);
}

template<typename T>
Queue<T>::~Queue() {
	clear();
}

template<typename T>
void Queue<T>::enqueue(T data) {

}

