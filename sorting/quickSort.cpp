//most slow implementation of the quicksort algorithm

#include <iostream>
#include <vector>
#include "../commonHeaders/utils.h"
int  partition(std::vector<int>& arr, int low, int high) {
	int pivotElm = arr[low];
	int i = low + 1;
	int j = high;
	while (true) {
		while (arr[i] < pivotElm) {
			if (i == high) break;
			i++;
			
		}
		while (arr[j] > pivotElm) {
			if (j == low)break;
			j--;
			
		}
		if (i >= j) {
			swap(arr, low, j);
			return j;

		}
		swap(arr, i, j); i++; j--;
	}
}
void qsort(std::vector<int>& arr, int low, int high) {
	if (high <= low)return;
	int index = partition(arr, low, high);
	qsort(arr, low, index-1);
	qsort(arr, index + 1, high);
}
void sort(std::vector<int>& arr) {
	int low = 0;
	int high = arr.size() - 1;
	qsort(arr, low, high);
}


int main() {
	std::cout << "generating array....." << std::endl;
	std::vector<int>arr = generateRandomArray(10000000,10000000);
	//printArray(arr);
	std::cout << "sorting...." << std::endl;
	sort(arr);
	std::cout << "sorted array" << std::endl;
	//printArray(arr);

	//partition test
	/*std::vector<int>arr = { 2,1 };
	int index = partition(arr, 0, 1);*/

}