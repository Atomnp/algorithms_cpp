#include <iostream>
#include <vector>
#include <stack>
int maxAreaHist(std::vector<int>histogram);
void changeToHistGram(std::vector<std::vector<int>>& mat) {
	for (int i = 1; i < mat.size(); i++) {
		for (int j = 0; j < mat[i].size(); j++) {
			if (mat[i][j] == 1) {
				mat[i][j] += mat[i - 1][j];
			}
		}
	}
}
int max(int a, int b) {
	return a > b ? a : b;
}
int maxArea(std::vector<std::vector<int>>&mat) {
	changeToHistGram(mat);
	int maxarea=0;
	for (int i = 0; i < mat.size(); i++) {
		maxarea = max(maxarea,maxAreaHist(mat[i]));
	}
	return maxarea;
}

//test
int main() {
	std::vector<std::vector<int>>input = {
		{1,0,1,0,0} ,
		{1,0,1,1,1},
		{1,1,1,1,1},
		{1,0,0,1,0}
	};
	int result =maxArea(input);

}