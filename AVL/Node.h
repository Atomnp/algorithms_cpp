#pragma once

struct Node {
	
	int data;
	Node* left;
	Node* right;
	int height;
	Node(int data):data(data),height(0) {
		left = nullptr;
		right = nullptr;
		
	}
};
