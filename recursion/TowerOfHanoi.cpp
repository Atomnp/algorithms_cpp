#include <iostream>
#include <stack>
#include "./utils.h"
void solve(int numOfItems,std::stack<int>&from, std::stack<int>&mid, std::stack<int>&to) {
	//move n-1 items to mid from from using to
	if (numOfItems > 0) {
		solve(numOfItems - 1, from, to, mid);
		int last = from.top();
		from.pop();
		to.push(last);
		solve(numOfItems - 1, mid, from, to);
	}

}


//testing client
int main() {
	std::cout << "tower of hanoi started" << std::endl;

	std::stack<int>a;
	for (int i = 0; i < 10; i++) {
		a.push(10 - i);
	}

	std::stack<int>b;

	std::stack<int>c;
	std::cout << "printing stack a before solving" << std::endl;
	printStack(a);


	solve(a.size(),a, b, c);

	std::cout << "printing stack a after solving" << std::endl;
	printStack(a);
	std::cout << "printing stack b" << std::endl;
	printStack(b);
	std::cout << "printing stack c" << std::endl;
	printStack(c);


}