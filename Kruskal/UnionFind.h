#pragma once
#include<iostream>
#include <vector>
#include <utility>
using namespace std;

class UnionFind {
	int* entries;
	int* size;
	int numberOfNodes;

	//i think i must overload comparasion operators to use std::sort
public:
	
	UnionFind(int numberOfNode):numberOfNodes(numberOfNode){
		
		entries = new int[numberOfNode];

		size = new int[numberOfNode];

		for (int i = 0; i < numberOfNode; i++) {
			entries[i] = i;
			size[i] = 1;
		}
		
		
	}
	void join(int i,int j);
	bool isConnected(int i, int j);
	int root(int i);
	
	
	void printArray() {
		int n = numberOfNodes;
		std::cout << "the size of entries calculated is " <<n<< std::endl;
		for (int i = 0; i < n;i++) {
			std::cout << entries[i]<<"," ;
	
		}
		std::cout << std::endl;
		for (int i = 0; i < n; i++) {

			std::cout << size[i] << ",";
		}
	}
};
