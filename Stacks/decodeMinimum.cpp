//https://www.geeksforgeeks.org/form-minimum-number-from-given-sequence/
#include <iostream>
#include <stack>

std::string decode(std::string input) {
	std::stack<int> stack;
	std::string result;
	for (int i = 0; i < input.length(); i++) {
		stack.push(i + 1);
		
		if (input[i] == 'I') {
			while (!stack.empty()) {
				result.push_back(stack.top() + '0');
				stack.pop();
			}

		}
	}
	return result;
}

//testing
int main() {
	std::string input = "IDDI";
	decode(input);
}