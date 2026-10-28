#pragma once
#include <utility>
#include <stdexcept>


template<typename T>
class List
{
	T* list;
	int capacity;
	int currentLength;

	void reallocate();
	void move_left(int);
	void move_right(int);
	void allocate(int);
public:
	List();
	~List();
	void add(T);
	T& get_at(int);
	int size() { return currentLength; }
	T& remove_at(int);
	bool remove(T);
	int index_of(T);
	void insert(int, T);
	void clear();
};

template<typename T>
void List<T>::allocate(int size) {
	capacity = size;
	list = (T*)malloc(sizeof(T) * capacity);
	currentLength = 0;
}

template<typename T>
List<T>::List() {
	allocate(20);
}

template<typename T>
List<T>::~List() {
	free(list);
}

template<typename T>
void List<T>::clear() {
	free(list);
	allocate(20);
}

template<typename T>
void List<T>::reallocate() {
	capacity = capacity << 1;

	T* new_list = (T*)malloc(sizeof(T) * capacity);
	
	for (int idx = 0; idx < currentLength; idx++) {
		new_list[idx] = list[idx];
	}
	free(list);
	list = new_list;
}

template<typename T>
void List<T>::add(T data) {
	if (currentLength >= capacity) {
		reallocate();
	}

	list[currentLength] = std::move(data);
	currentLength++;
}

template<typename T>
T& List<T>::get_at(int index) {
	if (index >= currentLength || index < 0) {
		throw std::out_of_range("index invalide");
	}

	return *(list + index);
}

template<typename T>
void List<T>::move_left(int index) {
	if (index < 0 || index >= currentLength)throw std::out_of_range("index invalide");

	while (index < currentLength - 1) {
		list[index] = list[++index];
	}
}

template<typename T>
void List<T>::move_right(int index) {
	if (index < 0 || index > currentLength)throw std::out_of_range("index invalide");

	for (int idx = currentLength - 1; idx >= index;) {
		list[idx] = list[--idx];
	}
}

template<typename T>
T& List<T>::remove_at(int index) {
	if (index < 0 || index >= currentLength) {
		throw std::out_of_range("index invalide");
	}

	T* data = list + index;
	move_left(index);
	currentLength--;
	return *data;
}

template<typename T>
bool List<T>::remove(T data) {
	for (int idx = 0; idx < currentLength; idx++) {
		if (list[idx] == data) {
			move_left(idx);
			currentLength--;
			return true;
		}
	}
	return false;
}

template<typename T>
int List<T>::index_of(T data) {
	for (int idx = 0; idx < currentLength; idx++) {
		if (list[idx] == data) {
			return idx;
		}
	}
	return -1;
}

template<typename T>
void List<T>::insert(int index, T data) {
	if (index < 0 || index > currentLength) {
		throw std::out_of_range("index invalide");
	}

	if (currentLength + 1 >= capacity) {
		reallocate();
	}

	move_right(index);
	list[index] = data;
	currentLength++;
}

