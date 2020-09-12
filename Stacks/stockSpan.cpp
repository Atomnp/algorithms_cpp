//The stock span problem is a financial problem where we have a series of n daily price quotes for a stockand we need to 
//calculate span of stock’s price for all n days.The span Si of the stock’s price on a given day i is defined as the
//maximum number of consecutive days just before the given day, for which the price of the stock on the current
//day is less than or equal to its price on the given day.
//For example, if an array of 7 days prices is given as{ 100, 80, 60, 70, 60, 75, 85 }, then the span values for 
//corresponding 7 days are{ 1, 1, 1, 2, 1, 4, 6 }

#include <vector>
#include <stack>
#include <iostream>


std::vector<int>stockSpan(std::vector<int>& input) {
	std::vector<int>result;
	std::stack<int>stack;
	//we use conce[t of nearest greater to the left
	for (int i = 0; i < input.size(); i++) {
		while (!stack.empty() && input[stack.top()] < input[i]) {
			stack.pop();
		}
		//if it reaches here either the stack must be empty or top must be greater than input at i
		if (stack.empty()) {
			result.push_back(1);
			//push index instead
			stack.push(i);
			continue;
		}
		result.push_back(i-stack.top());
		stack.push(i);	
	}
	return result;
}
//testing
int main() {
	std::vector<int>input = { 100, 80, 60, 70, 60, 75, 85 };
	auto res = stockSpan(input);
	for (auto item : res) {
		std::cout << item << std::endl;
	}
}