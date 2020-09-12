#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>


std::vector<int>smallestLeft(std::vector<int>& input) {
	std::vector<int> result;
	std::stack<int> stack;

	for (int i = 0; i < input.size(); i++) {
		while (!stack.empty() and input[stack.top()] >= input[i]) {
			stack.pop();
		}
		//if the program flow reaches here either the stack is empty or top of stack is less than current 
		//input element
		if (stack.empty()) {
			result.push_back(-1);
			stack.push(i);
			continue;
		}
		result.push_back(stack.top());
		stack.push(i);
	}
	return result;
}
std::vector<int>smallestRight(std::vector<int>& input) {
	std::vector<int> result;
	std::stack<int> stack;

	for (int i = input.size()-1; i >= 0; i--) {
		while (!stack.empty() and input[stack.top()] >= input[i]) {
			stack.pop();
		}
		//if the program flow reaches here either the stack is empty or top of stack is less than current 
		//input element
		if (stack.empty()) {
			result.push_back(input.size());
			stack.push(i);
			continue;
		}
		result.push_back(stack.top());
		stack.push(i);
	}
	std::reverse(result.begin(), result.end());
	return result;
}

int maxAreaHist(std::vector<int>histogram) {
	//create the vector of smallest left index
	auto smallestLeftArr = smallestLeft(histogram);
	auto smallestRightArr = smallestRight(histogram);

	std::vector<int>maxAreaContaingBuilding;
	for (int i = 0; i < histogram.size(); i++) {
		maxAreaContaingBuilding.push_back((smallestRightArr[i] - smallestLeftArr[i]-1) * histogram[i]);
	}
	return *std::max_element(maxAreaContaingBuilding.begin(), maxAreaContaingBuilding.end());

}
//test
//int main() {
//	//test for smallest left;
//	std::vector<int>input = { 6,2,5,4,5,1,6 };
//	auto result = maxAreaHist(input);
//
//}