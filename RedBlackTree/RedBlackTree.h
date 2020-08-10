#pragma once
#include "./Node.h"
#include <iostream>
class RedBlackTree
{
	Node* root;
	Node* insert(Node* x, int n);
	int max(int i, int j);
	void printInorder(Node* node);
	void print2DUtil(Node* root, int space);
	Node* remove(Node* node, int n);
public:
	RedBlackTree() {
		root = nullptr;
	}
	void insert(int n) {
		root = insert(root, n);
	}

	Node* singleRightRotate(Node* node);
	Node* singleLeftRotate(Node* node);
	Node* findMin(Node* node);
	Node* findMax(Node* node);
	void flipColors(Node* node) {
		node->left->isRed =!node->left->isRed;
		node->right->isRed = !node->right->isRed;
		node->isRed = node == root ? false:true;
	}
	bool isRed(Node* node) {
		if (node == nullptr)return false;
		return node->isRed;
	}
	void printInorder() {
		printInorder(root);
	}
	void remove(int n) {
		root = remove(root, n);
	}

	void print2D()
	{
		// Pass initial space count as 0  
		print2DUtil(root, 0);
	}
};

