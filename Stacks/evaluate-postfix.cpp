#include <iostream>
#include <stack>
#include <string>


bool isOperator(char item) {
	if (item == '+' || item == '-' || item == '*' || item == '/' || item == '(' || item == ')') {
		return true;
	}
	return false;
}

int popAndReturn(std::stack<int>& stack) {
	int top = stack.top();
	stack.pop();
	return top;
}

int evaluatePostFix(std::string expression) {
	std::stack<int> stack;
	for (char item : expression) {
		if (isOperator(item)) {
			int second = popAndReturn(stack);
			int first = popAndReturn(stack);
			std::string toEval = "";
			
			switch (item) {
			case'+':
				stack.push(first + second);
				break;
			case'-':
				stack.push(first - second);
				break;
			case'*':
				stack.push(first * second);
				break;
			case'/':
				stack.push(first / second);
				break;

			}
		}
		else {
			std::string str;
			str.push_back(item);
			stack.push(std::stoi(str));
		}

	}
	return popAndReturn(stack);
}
//int main() {
//	std::string expression = "56*9+";
//	int result = evaluatePostFix(expression);
//	std::cout << "result is " << result << std::endl;
//
//}