//max heap implentation

#include "../commonHeaders/utils.h"

class BinaryHeap {
	int root;
	int* data;
	int currentIndex;

	int maxIndex(int a, int b) {
		if (data[a] >= data[b])return a;
		return b;
	}
	void swim(int index) {
		if (index == root) return;
		while ((data[index] > data[index/2])and index>root) {
			swap(data, index,  index/2);
			index = index / 2;
		}
	}
	void sink(int index) {
		while ((2*index+1)<=currentIndex and (data[index] < data[2 * index] or data[index] < data[2 * index + 1])) {
			
			if (2 * index + 1 == currentIndex and data[2 * index] > data[index]) {
				swap(data, index, 2*index);
				break;
			}
			if (2 * index + 1 == currentIndex and data[2 * index] <= data[index]) {
				break;
			}
			
			int maxIn =maxIndex(2 * index, 2 * index + 1);
			swap(data,index, maxIn);
			index = maxIn;
		}
	}
public:
	BinaryHeap() {
		root = 1;
		data = new int[10];
		currentIndex = 1;
	}
	void insert(int a) {
		data[currentIndex] = a;
		++currentIndex;
		swim(currentIndex-1);
	}
	int removeMax() {
		int temp = data[root];
		swap(data, root, currentIndex-1);
		currentIndex--;
		sink(root);
		return temp;
	}
	int max() {
		return data[root];
	}
	int size() {
		return currentIndex - 1;
	}

	void display() {
		for (int i = 1; i < currentIndex; i++) {
			std::cout << data[i] << std::endl;
		}
	}
};

//unit test
int main() {
	

	auto heap = new BinaryHeap();

	heap->insert(5);
	heap->insert(4);
	heap->insert(3);
	heap->insert(2);
	heap->insert(1);
	heap->insert(9);
	heap->insert(19);
	heap->insert(29);
	heap->insert(13);
	heap->insert(16);
	heap->removeMax();
	std::cout << "max is" << heap->max() << std::endl;
	heap->display();
}