#include <iostream>
#include "AVL.h"
int main() {
	AVL a;
	a.insert(50);
	a.insert(25);
	a.insert(75);
	a.insert(10);
	a.insert(30);
	a.insert(5);
	a.insert(15);
	a.insert(27);
	a.insert(1);
	a.insert(60);
	a.insert(55);
	a.insert(80);
	
	std::cout << "original tree" << std::endl;
	a.print2D();
	std::cout << "after deletiin" << std::endl;
	a.remove(80);
	a.remove(15);
	a.print2D();

}