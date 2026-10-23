#pragma once
#include <stdexcept>

template<typename T>
struct Node{
	T data;
	Node<T>* left;
	Node<T>* right;
};

template<typename T>
class Binary_tree
{
	Node<T>* root;

	Node<T>* delete_recursive(Node<T>*, T);
};

