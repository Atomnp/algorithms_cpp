//this program is a solution to knapsack problem using recursion

#include <iostream>
#include <vector>

std::vector<int> weights;
std::vector<int>values;
int** dp;

int max(int a, int b) {
	return a > b ? a : b;
}
int knapsack(int weight, int n) {
	if (dp[n][weight] != -1) {
		return dp[n][weight];
	}
	if (n == 0 or weight == 0) {
		return 0;
	}
	if (weights[n] <= weight) {
		int weightLeft = weight - weights[n];
		int whenChoosed = knapsack(weightLeft, n - 1);
		int whenNotChoosed = knapsack(weight, n - 1);
		
		int maxVal= max(values[n] + whenChoosed, whenNotChoosed);
		dp[n][weight] = maxVal;
		return maxVal;
	}
	else {
		int val= knapsack(weight, n - 1);
		dp[n][weight] = val;
		return val;
	}

}

int main() {
	weights = { 10,20,30 };
	values = { 60,100,120 };
	const int weight = 50;
	int size = weights.size();

	dp = new int* [size];
	for (int i = 0; i < size; ++i) {
		dp[i] = new int[weight];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j <=weight; j++) {
			dp[i][j] = -1;
		}
	}
	
	int result = knapsack(weight, size-1);
	std::cout << "the  result is " << result<<std::endl;
}
