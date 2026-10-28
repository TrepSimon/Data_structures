#pragma once
#include <utility>
#include <stdexcept>
#include <iterator>
#include <cstddef>


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
	struct Iterator {
		using iterator_category = std::forward_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = T;
		using pointer = T*;
		using reference = T&;

		Iterator(pointer ptr) : m_ptr(ptr) {}

		reference operator*() const { return *m_ptr; }
		pointer operator->() { return m_ptr; }

		Iterator& operator++() { m_ptr++; return *this; }
		Iterator& operator--() { m_ptr--; return *this; }

		Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
		Iterator operator--(int) { Iterator tmp = *this; --(*this); return tmp; }

		friend bool operator==(const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
		friend bool operator!=(const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };

	private:
		pointer m_ptr;
	};


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

	Iterator begin() { return Iterator(list); }
	Iterator end() { return Iterator(list + currentLength); }

	using ReverseIterator = std::reverse_iterator<Iterator>;

	ReverseIterator rBegin() { return ReverseIterator(end()); }
	ReverseIterator rEnd() { return ReverseIterator(begin()); }
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

