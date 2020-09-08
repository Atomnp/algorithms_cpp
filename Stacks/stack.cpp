#include <iostream>
#include <exception>

template <typename T>
class Stack {
private:
	T* data;
	int size;
	int top;
public:
	Stack(int n) {
		size = n;
		top = -1;
		data = new T[size];
	}
	void push(T n) {
		if (top == size - 1)throw(std::exception("stack is already full"));
		data[++top] = n;

	}
	bool isEmpty() {
		return top == -1;
	}
	T pop() {
		if (top == -1)throw(std::exception("already empty"));
		T topValue = data[top--];
		return topValue;
		
	}
};
//int main() {
//	try {
//		Stack<int> st = Stack<int>(5);
//		st.push(1);
//		st.push(2);
//		st.push(2);
//		st.push(2);
//		st.push(2);
//		st.push(2);
//		std::cout << st.pop() << std::endl;
//		std::cout << st.pop() << std::endl;
//		std::cout << st.pop() << std::endl;
//	}
//	catch (std::exception e) {
//		std::cout << e.what() << std::endl;
//	}
//}
