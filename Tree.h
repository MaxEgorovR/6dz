#pragma once
#include "Node.h"
using namespace std;

template <class T>
struct Tree {
	shared_ptr<Node<T>> root = nullptr;

	Tree()
	{

	}

	Tree(T val)
	{
		this->root = make_shared<Node<T>>(val);
	}

	void add(T val) {
		if (this->root != nullptr) {
			auto cur = this->root;
			while (cur != nullptr) {
				if (val > cur->data) {
					if (cur->Right != nullptr) {
						cur = cur->Right;
					}
					else {
						cur->Right = make_shared<Node<T>>(val);
						break;
					}
				}
				else {
					if (cur->Left != nullptr) {
						cur = cur->Left;
					}
					else {
						cur->Left = make_shared<Node<T>>(val);
						break;
					}
				}
			}
		}
		else {
			this->root = make_shared<Node<T>>(val);
		}
	}


	void Print() {
		if (root) {
			Print(root);
		}
	}

	void Print(shared_ptr<Node<T>> node) {
		if (node) {
			Print(node->Left);
			cout << node->data << " ";
			Print(node->Right);
		}
	}

	bool search(T val) {
		auto cur = this->root;
		while (cur != nullptr && cur->data != val) {
			if (cur->data < val) {
				if (cur->Right == nullptr) {
					break;
				}
				cur = cur->Right;
			}
			else {

				if (cur->Left == nullptr) {
					break;
				}
				cur = cur->Left;
			}
		}
		if (cur->data == val) {
			return true;
		}
		else {
			return false;
		}
	}

	int getDiameter(shared_ptr<Node<T>> root, int& diameter)
	{
		if (root == nullptr) {
			return 0;
		}

		int left_height = getDiameter(root->Left, diameter);
		int right_height = getDiameter(root->Right, diameter);

		int max_diameter = left_height + right_height + 1;

		diameter = max(diameter, max_diameter);

		return max(left_height, right_height) + 1;
	}

	int getDiameter()
	{
		int diameter = 0;
		getDiameter(this->root, diameter);

		return diameter;
	}
};