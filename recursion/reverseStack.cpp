#include <iostream>
#include <stack>
#include "./utils.h"

void insertAtBottom(std::stack<int>& stack,int item) {
	if (stack.empty()) {
		stack.push(item);
		return;
	}
	int top = stack.top();
	stack.pop();
	insertAtBottom(stack,item);
	stack.push(top);
}

void reverse(std::stack<int>&stack) {
	if(stack.empty())return;
	int top = stack.top();
	stack.pop();
	reverse(stack);
	insertAtBottom(stack, top);
}
int main() {
	std::stack<int >stack;
	stack.push(5);
	stack.push(6);
	stack.push(1);
	stack.push(3);
	stack.push(0);
	stack.push(2);
	std::cout << "before reversiing" << std::endl;
	printStack(stack);
	std::cout << "--------------------------------------" << std::endl;
	reverse(stack);
	std::cout << "after reversing" << std::endl;
	printStack(stack);
}