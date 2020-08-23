#include <iostream>
#include <stack>

void printStack(std::stack<int>stack) {
	//this function prints stack from top to bottom

	if (stack.empty())return;
	std::cout << stack.top() << std::endl;
	stack.pop();
	printStack(stack);

}

void remove(std::stack<int>&stack, int index) {
	if (index == 0) {
		stack.pop();
		return;

	}
	int top = stack.top();
	stack.pop();
	remove(stack, index - 1);
	stack.push(top);

}

void removeMid(std::stack<int>&stack) {
	int size = stack.size();
	int mid = size/2;
	int midFromTop = size - 1 - mid;
	remove(stack, midFromTop);

}

int main() {

	std::stack<int >stack;
	stack.push(5);

	
	printStack(stack);
	std::cout << "=n ---------------" << std::endl;
	removeMid(stack);
	printStack(stack);
}