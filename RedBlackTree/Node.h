#pragma once
#include <iostream>

struct Node {
	int data;
	Node* left;
	Node* right;
	bool isRed;

	Node(int data):data(data){
		isRed = true;
		left = nullptr;
		right = nullptr;

	}
};
