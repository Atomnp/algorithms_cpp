#include <iostream>
#include <vector>
int** dp;


int maxSum(int sum, std::vector<int>& data) {
	for (int i = 0; i <= data.size(); i++) {
		for (int j = 0; j <= sum; j++) {
			//fill the dp
			if (j == 0) {
				dp[i][j] = 1;
				continue;
			}
			if (i == 0) {
				dp[i][j] = 0;
				continue;
			}
			if (data[i-1] <=j) {
				int dataD = data[i-1];
				if (dp[i - 1][j - data[i-1]]==1 or dp[i-1][j]==1) {
					dp[i][j] = 1;
				}
				else {
					dp[i][j] = dp[i - 1][j];
				}
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}

		}
	}

	return dp[data.size()][sum];
}

int main() {
	std::cout << "max subset problems tarted" << std::endl;
	std::vector<int>data = {1,4,4,7};
	
	//test for 30 inputs
	for (int i = 0; i < 30; i++) {
		int sum = i;

		dp = new int* [data.size() + 1];

		for (int i = 0; i <= data.size() + 1; i++) {
			dp[i] = new int[sum + 1];
		}
		auto result = maxSum(sum, data);
		std::cout << "for " << sum << " =" << result<<std::endl;
	}
	
	//for (int i = 0; i <= data.size(); i++) {
	//	for (int j = 0; j <= sum; j++) {
	//		std::cout << dp[i][j] << " , ";
	//	}
	//	std::cout << std::endl;
	//}
}