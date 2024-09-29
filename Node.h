#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
struct Node {
	T data;

	shared_ptr<Node<T>> Left = nullptr;

	shared_ptr<Node<T>> Right = nullptr;

	Node(T data)
	{
		this->data = data;
	}


};