#include <iostream>
#include "RedBlackTree.h"
int main() {
	RedBlackTree a;
	a.insert(9);
	a.insert(8);
	a.insert(7);

	std::cout << "----------------------------------------------------------------" << std::endl;
	a.print2D();


}