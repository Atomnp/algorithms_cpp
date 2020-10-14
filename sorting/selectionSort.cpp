#include <iostream>
#include <vector>

#include "../commonHeaders/utils.h"

void sort(std::vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		int minIndex=i;
		for (int j = i+1; j < arr.size(); j++) {
			if (arr[j] < arr[minIndex])minIndex = j;
		}
		swap(arr, i, minIndex);
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