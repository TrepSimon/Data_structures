#pragma once
#include <stdexcept>


template<typename T>
class Queue
{
	T* array;
	T* front;
	T* back;
	int max_size = 20;
	int current_size = 0;

	void allocate(T);
	void reallocate();
	void refill(T*);
public:
	Queue();
	Queue(T);
	~Queue();
	void clear();
	void enqueue(T);
	T& dequeue();
	bool isEmpty() { return current_size == 0; }
	T& get_front();
};

template<typename T>
void Queue<T>::refill(T* base) {
	int idx;
	for (T* iter = front, idx = 0; iter <= back; iter++, idx++) {
		base[idx] = *iter;
	}
	front = array;
	back = &array[current_size - 1];
}

template<typename T>
void Queue<T>::reallocate() {
	max_size = max_size << 1;

	T* temp_base = (T*)malloc(sizeof(T) * max_size);
	refill(temp_base);
	free(array);
	array = temp_base;
	front = array;
	back = &array[current_size - 1];
}

template<typename T>
void Queue<T>::allocate(T data) {
	array = (T*)malloc(sizeof(T) * max_size);

	if (array == nullptr)throw std::bad_alloc();

	back = array;
	*back = data;
	front = back;
	current_size++;
}

template<typename T>
void Queue<T>::clear() {
	free(array);
	array = nullptr;
	back = nullptr;
	front = nullptr;
}

template<typename T>
Queue<T>::Queue() : front(nullptr), back(nullptr), array(nullptr) {}

template<typename T>
Queue<T>::Queue(T data) {
	if (data == NULL)throw std::invalid_argument("data est null");
	allocate(data);
}

template<typename T>
Queue<T>::~Queue() {
	clear();
}

template<typename T>
void Queue<T>::enqueue(T data) {

	if (back == nullptr) {
		allocate(data);
		return;
	}

	if (back == &array[max_size - 1]) {
		if (front != array) refill(array);
		else reallocate();
	}

	back++;
	*back = data;
	current_size++;
}

template<typename T>
T& Queue<T>::dequeue() {
	if (front == nullptr || isEmpty())throw std::out_of_range("Liste vide");
	if (front > back)throw std::range_error("erreur de queue");

	T data = *front;
	front++;
	current_size--;
	return data;
}

template<typename T>
T& Queue<T>::get_front() {
	if (front == nullptr)throw std::out_of_range("Liste vide");

	return *front;
}

