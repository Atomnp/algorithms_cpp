#include <iostream>
struct Node {
	int data;
	Node* next;
	Node(int data,Node *next=nullptr):data(data),next(next) {
	}
};
class Stack {
	Node* top;
	int size;
public:
	bool isEmpty() {
		return size == 0;
	}
	Stack():size(0) {
		top = nullptr;
	}
	void push(int data) {
		Node* newNode = new Node(data,top);
		top = newNode;
		++size;

	}
	int pop() {
		auto temp = top;
		int tempData = top->data;
		top = top->next;
		delete temp;
		--size;
		return tempData;
	}
	int getTop() {
		return top->data;
	}
};

//unit test
int main() {
	Stack s;
	s.push(5);
	s.push(6);
	s.push(7);

	while (!s.isEmpty()) {
		std::cout << s.pop() << std::endl;
	}
}