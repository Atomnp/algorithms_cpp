#include <iostream>
#include "RedBlackTree.h"
int main() {
	RedBlackTree a;
	a.insert(50);
	a.insert(75);
	a.insert(65);
	a.insert(100);
	a.remove(50);
	std::cout << "----------------------------------------------------------------" << std::endl;
	a.print2D();


}