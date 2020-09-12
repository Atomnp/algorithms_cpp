#include <iostream>
#include <vector>
#include <stack>

std::vector<int>NGR(std::vector<int>& input) {
	std::stack<int> stack;
	std::vector<int>result;
	for (int i = input.size() - 1; i >= 0; i--) {

		while (!stack.empty() and stack.top() <= input[i]) {
			stack.pop();
		}
		if (stack.empty()) {
			result.push_back(-1);
			stack.push(input[i]);
			continue;
		}
		result.push_back(stack.top());
		stack.push(input[i]);
	}
	std::reverse(result.begin(), result.end());
	return result;
}
//testing
int main() {
	std::vector<int>input = { 1,3,0,0,1,2,4 };
	auto result = NGR(input);


}