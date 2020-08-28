#include <iostream>
#include <vector>


void remove(std::vector<int>&arr, int& currentPosition, int frequency) {
	int deletingIndex = (currentPosition + frequency) % (arr.size());
	currentPosition=(deletingIndex) % arr.size();
	//because erase function takes iterator
	arr.erase(arr.begin() + deletingIndex);
	
}
void solve(std::vector<int>&arr ,int frequency, int currentPosition) {
	
	if (arr.size() == 1) {
		return;
	}
	remove(arr, currentPosition, frequency);
	solve(arr, frequency, currentPosition);
}
int solve(int totalNumber, int frequency) {
	std::vector<int>arr;
	int currentIndex = 0;
	for (int i = 0; i < totalNumber; i++) {
		arr.push_back(i + 1);
	}
	solve(arr, frequency,currentIndex);
	return arr[0];
}
int main() {
	//currently this only works when frequency is one
	int frequency = 1;
	int totalNumber;
	for (int i = 1; i < 20; i++) {
		 totalNumber = i;
		int position = solve(totalNumber, frequency);
		std::cout << "there are "<<i<<" people and joshephus is in " << position << " position" << std::endl;
	}
	
}