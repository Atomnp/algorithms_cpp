#include <iostream>
#include <vector>
#include "../commonHeaders/utils.h"

void sort(std::vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr.size()-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				swap(arr, j, j+1);
			}
		}
	}
}

//unit test
int main() {
	std::cout << "unsorted array" << std::endl;
	auto arr = generateRandomArray(10);
	printArray(arr);
	sort(arr);
	std::cout << "sorted array" << std::endl;
	printArray(arr);
}