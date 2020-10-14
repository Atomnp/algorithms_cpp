#include <iostream>
#include <vector>

#include "../commonHeaders/utils.h" //swap() and generateRandomArray()


void merge(std::vector<int>& arr, int high, int low,int mid) {
	std::vector<int>aux = arr;
	int i = low;
	int m = mid + 1;
	int k = low;
	while (i<=mid or m<=high) {
		if (i > mid) {
			arr[k++] = aux[m++];
			continue;
		}
		if (m > high) {
			arr[k++] = aux[i++];
			continue;
		}
		if (aux[i] <= aux[m]) {
			arr[k++] = aux[i++];
		}
		else {
			arr[k++] = aux[m++];
		}
	}
}

void sort(std::vector<int>& arr,int high,int low) {
	if (high == low) {
		return;
	}
	int mid = (high + low) / 2;
	//sort function takes high then low
	sort(arr,mid,low);
	sort(arr,  high, mid + 1);
	merge(arr, high, low, mid);

}

void sort(std::vector<int>& arr) {
	int low = 0;
	int high = arr.size() - 1;
	sort(arr,high, low);
}
//unit test for selection sort
int main() {

	//testing merge function

	//std::vector<int> arr = {1,53,90,2,40,200 };
	//int low = 0;
	//int high = 5;
	//int mid = 2;
	//merge(arr, high,low,mid);



	std::vector<int> arr = generateRandomArray(10);
	std::cout << "unsorted array" << std::endl;
	printArray(arr);
	sort(arr);
	std::cout << "unsorted array" << std::endl;
	printArray(arr);
}