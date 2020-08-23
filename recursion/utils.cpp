#include "./utils.h"
#include <iostream>


void printStack(std::stack<int>stack) {
	//this function prints stack from top to bottom

	if (stack.empty())return;
	std::cout << stack.top() << std::endl;
	stack.pop();
	printStack(stack);

}
void printStackFromBottom(std::stack<int>stack) {
	if (stack.empty())return;
	int top = stack.top();
	stack.pop();
	printStackFromBottom(stack);
	std::cout << top << std::endl;
}