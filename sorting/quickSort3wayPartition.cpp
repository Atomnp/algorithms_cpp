//three way partitioning implementation of quick sort

#include <iostream>
#include <vector>
#include "../commonHeaders/utils.h"

void qsort(std::vector<int>& arr, int low, int high) {
	if (high <= low)return;
	//we have 3 pointers lt,i ,gt
	//the invarient is as follws
	//every thing to the left of lt is less than pivot element
	//everything to the right of gt is greater than pivot element
	//every element between lt and i is equal to pivot element
	//we maintain this invarient while performing partition

	int lt = low;
	int i = low + 1;
	int gt = high;
	while (i <= gt) {
		if (arr[i] < arr[lt]) {
			swap(arr, i, lt);
			i++; lt++;
		}
		else if (arr[i] > arr[lt]) {
			swap(arr, i, gt);
			gt--;
		}
		else {
			i++;
		}
	}
	qsort(arr, low, lt - 1);
	qsort(arr, gt+ 1, high);
}
void sort(std::vector<int>& arr) {
	int low = 0;
	int high = arr.size() - 1;
	qsort(arr, low, high);
}


int main() {
	std::cout << "generating array....." << std::endl;
	std::vector<int>arr = generateRandomArray(100, 100);
	printArray(arr);
	std::cout << "sorting...." << std::endl;
	sort(arr);
	std::cout << "sorted array" << std::endl;
	printArray(arr);

}