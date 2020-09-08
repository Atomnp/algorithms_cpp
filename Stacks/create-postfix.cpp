#include <iostream>
#include <stack>

bool isOperator(char item) {
	if (item == '+' || item == '-' || item == '*' || item == '/' || item == '(' || item == ')') {
		return true;
	}
	return false;
}
int priority(char a) {
	if (a == '+' || a == '-')return 0;
	if (a == '*' || a == '/')return 1;
	if (a == '(' )          return 2;
	else return -1;
}
std::string createPostfix(std::string expression) {
	std::string result;
	std::stack<char>operatorStack;

	char topOfStack='1';
	for (char item : expression) {
		if (isOperator(item)) {
			//initially stack is empty so there is no top;
			if (!operatorStack.empty()) {
				topOfStack = operatorStack.top();
			}
			if (item == '(') {
				operatorStack.push('(');
				continue;
			}
			//if closing parenthesis is encountered 
			//from each top of stack append to result untill ( is encountered
			if (item == ')') {
				while (topOfStack != '(') {
					result.push_back(topOfStack);

					
					operatorStack.pop();
					topOfStack = operatorStack.top();
				}
				operatorStack.pop();
				continue;
			}
			//current operator has less priority than top of stack? then push top of stack to result
			if (priority(item) < priority(topOfStack) and topOfStack!='(') {
				result.push_back(topOfStack);
				operatorStack.pop();
			}
			//if new opertor is encountered push it to the stack
			operatorStack.push(item);
				
		}
		else {
			result.push_back(item);
		}
	}
	while (!operatorStack.empty()) {
		char top = operatorStack.top();
		operatorStack.pop();
		result.push_back(top);
	}
	return result;
}

//int main() {
//	std::string expression = "a+b+c";
//	std::string result=createPostfix(expression);
//	std::cout << result << std::endl;
//}