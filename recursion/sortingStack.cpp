/*
this file contains code that sorts stacks solely based on recursion without any loop
just a practice


*/


#include<iostream>
#include <stack>


void insert(int item, std::stack<int>& stack) {
	if (stack.empty() || stack.top() < item) {
		stack.push(item);
		return;
	}
	int top = stack.top();
	stack.pop();
	insert(item, stack);
	stack.push(top);
}

void sort(std::stack<int>& stack) {
	if (stack.empty()) {
		return;
	}
	int top = stack.top();
	stack.pop();
	sort(stack);
	insert(top, stack);
}

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


int main() {
	std::cout << "sorting array started" << std::endl;
	//create stack

	std::stack<int >stack;
	stack.push(5);
	stack.push(6);
	stack.push(1);
	stack.push(3);
	stack.push(0);
	stack.push(2);
	
	sort(stack);
	printStackFromBottom(stack);
}