/*
this program implement fibonacci sequence given the position to find the fibonacci sequence
this program returns the fibonacci number at that sequence

*/

#include <iostream>

 long long fib(int n, long long*memo) {
	if (memo[n] != -1) {
		return memo[n];
	}
	if (n <= 1) {
		memo[n] = n;
		return n;
	}
	else {
		 long long result = fib(n - 1,memo) + fib(n - 2,memo);
		memo[n] = result;
		return result;
	}
}
 long long fib(int n) {
	 long long* memo = new  long long[n+1];
	for (int i = 0; i <= n; i++) {
		memo[i] = -1;
	}
	return fib(n, memo);
}

 int main() {
	std::cout << "fibonacci series started" << std::endl;
	int position = 1000;
	std::cout << "calculating......" << std::endl;
	 long long result=fib(position);
	std::cout << "fibonacce number at position " << position << " is " << result;
}