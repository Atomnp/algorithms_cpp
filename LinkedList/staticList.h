#pragma once
#include <iostream>
#include <exception>
#include <string>
template <typename T>
class StaticList {
	struct Node {
		T data;
		int next;
	};
	int avail;
	Node* memory;
	int head;
	int tail;
	int size;

	int getNode() {
		if (avail == -1)throw std::exception(" memory overflow");
		int toReturn = avail;
		avail = memory[avail].next;
		return toReturn;
	}
	void freeNode(int p) {
		memory[p].next = avail;
		avail = p;
	}
	int insertAfter(int p, T data) {
		if (avail == -1)throw std::exception("memory overflow");
		int q = getNode();
		memory[q].data = data;
		if (memory[p].next != q) {
			memory[q].next = memory[p].next;
		}

		memory[p].next = q;
		size++;
		return q;
	}
	T deleteAfter(int pos) {
		if (pos == -1 or memory[pos].next == -1)throw std::exception("Out Of Bound");
		int toDeleteIndex = memory[pos].next;
		T toReturn = memory[toDeleteIndex].data;
		freeNode(toDeleteIndex);
		size--;
		return toReturn;

	}
public:
	StaticList(int SIZE) :SIZE(SIZE) {
		avail = 0;
		tail = -1;
		head = -1;
		size = 0;
		memory = new Node[SIZE];

		for (int i = 0; i < SIZE; i++) {
			memory[i].next = i + 1;
		}
		memory[SIZE - 1].next = -1;
	}

	void addLast(T data) {
		if (isEmpty()) {
			int q = getNode();
			memory[q].data = data;
			tail = q;
			head = q;
			size++;
			return;
		}
		int index = head;
		while (index != tail) {
			index = memory[index].next;
		}

		tail = insertAfter(index, data);

	}
	void addFirst(T data) {
		if (isEmpty()) {
			addLast(data);
			return;
		}
		if (avail == -1 or size == SIZE)throw std::exception("Exception!! memory overflow ");
		int q = getNode();
		memory[q].data = data;
		memory[q].next = head;
		head = q;
		size++;
	}
	void addAfter(T val, T data) {
		int index = head;
		while (memory[index].data != val) {
			index = memory[index].next;
			if (index == tail)throw std::exception("No such value to add after");
		}
		if (index == tail) {
			addLast(data);
			return;
		}
		insertAfter(index, data);
	}
	T removeFirst() {
		if (isEmpty())throw std::exception("List already empty");
		int tempHead = head;
		head = memory[head].next;
		memory[tempHead].next = avail;
		avail = tempHead;
		size--;
		return memory[tempHead].data;
	}
	T removeLast() {
		if (isEmpty())throw std::exception("List already empty");
		T temp = memory[tail].data;
		int index = head;
		while (index != tail and memory[index].next != tail) {
			index = memory[index].next;
		}
		tail = index;
		deleteAfter(index);
		return temp;
	}
	T removeAfter(T val) {

		if (isEmpty())throw std::exception("EXception!! list is already empty");
		int index = head;
		while (memory[index].data != val) {
			index = memory[index].next;
			if (index == tail) {
				throw std::exception("no such value in the list");
			}
		}
		if (memory[index].next == tail) {
			T result = removeLast();
			return result;
		}
		deleteAfter(index);
	}
	void display() {
		if (size == 0) {
			std::cout << "[]" << std::endl;
			return;
		}
		std::string message = "[";
		int index = head;

		while (index != tail) {
			message += std::to_string(memory[index].data);
			message.push_back(',');
			index = memory[index].next;
		}
		message += std::to_string(memory[index].data);
		message.push_back(']');
		std::cout << message << std::endl;
	}

	bool isEmpty() {
		return size == 0;
	}
	bool isFull() {
		return size == SIZE;
	}
	int length() {
		return size;
	}
};