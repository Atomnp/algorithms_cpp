#include <iostream>
#include <vector>

#include "../commonHeaders/utils.h"

void sort(std::vector<int>& arr) {
	for (int i = 1; i < arr.size(); i++) {
		int j = i;
		while (j>0 and arr[j] < arr[j - 1]) {
			swap(arr, j, j - 1);
			j--;
		}
	}
}
//unit test for selection sort
int main() {
	auto arr = generateRandomArray(20);
	std::cout << "unsorted array" << std::endl;
	printArray(arr);
	std::cout << "sorted array" << std::endl;
	sort(arr);
	printArray(arr);
}