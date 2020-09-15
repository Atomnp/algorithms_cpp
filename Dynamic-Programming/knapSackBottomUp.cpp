//this program solves 0,1 knapsack problem using 
//dp bottom up approach
#include <iostream>
#include <vector>

std::vector<int> weights;
std::vector<int>values;
int** dp;

int max(int a, int b) {
	return a > b ? a : b;
}
int knapsack(int capacity, int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= capacity; j++) {
			if (i == 0 or j == 0) {
				dp[i][j] = 0; continue;
			}
			//if weight to put is less than capacity
			if (weights[i] <= j) {
				//std::cout<<dp[i-1][j-weights[j]]<<std::endl;
				dp[i][j] = max(values[i] +dp[i - 1][j - weights[i]], dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp[n-1][capacity];
}

int main() {
	values = {10,20,30 };
	weights = { 1, 1, 1 };
	const int weight = 2;
	int size = weights.size();

	//creates 2d array dynamically 
	dp = new int* [size];
	for (int i = 0; i < size; ++i) {
		dp[i] = new int[weight+1];
	}

	int result = knapsack(weight, size );
	std::cout << "the  result is " << result << std::endl;
}
