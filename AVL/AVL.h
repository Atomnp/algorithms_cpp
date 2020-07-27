#pragma once
#include "Node.h"
#include <iostream>

class AVL
{
	Node* root;
	Node * insert(Node* x, int n);
	int max(int i, int j);
	void printInorder(Node* node);
	Node* remove(Node* node, int n);
	void print2DUtil(Node* root, int space);
public:
	AVL(){
		root = nullptr;
	}
	void insert(int n) {
		root = insert(root, n);
	}
	int height(Node* x) {
		return x == nullptr ? -1: x->height;
	}
	Node* singleRightRotate(Node* node);
	Node* singleLeftRotate(Node* node);
	Node* doubleLeftRotate(Node* node);
	Node* doubleRightRotate(Node* node);
	Node * findMin(Node* node);
	Node * findMax(Node* node);
	void printInorder() {
		printInorder(root);
	}
	void remove(int n) {
		root=remove(root, n);
	}
	void print2D()
	{
		// Pass initial space count as 0  
		print2DUtil(root, 0);
	}
};

