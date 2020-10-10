#pragma once
#include <exception>
#include <iostream>
template <typename T>
struct Node {
	T data;
	Node* next;
public:
	Node(T data) :data(data) {
		next = nullptr;
	}
};
template <typename T>
class LinkedList {

	int size;
public:
	Node<T>* head;
	Node<T>* tail;
	LinkedList() :size(0) {
		head = tail = nullptr;
	}
	bool isEmpty() {
		bool result = size == 0;
		if (result) {
			head = nullptr; tail = nullptr;
			return true;
		}
		return false;
	}
	int length() { return size; }
	T first() {
		if (isEmpty())throw std::exception("Linked list is empty");
		return head->data;
	}
	T last() {
		if (isEmpty())throw std::exception("Linked list is empty");
		return tail->data;
	}
	void addFirst(T data) {
		Node<T>* temp = new Node<T>(data);
		temp->next = head;
		if (isEmpty())tail = temp;
		head = temp;
		++size;
	}
	void addLast(T data) {
		if (isEmpty()) {
			addFirst(data);
			return;
		}
		Node<T>* temp = new Node<T>(data);
		tail->next = temp;
		tail = temp;
		++size;
	}
	void addAfter(T after, T data) {
		if (size == 0)throw std::exception("No after and before for size zero");
		Node<T>* preptr = head;
		while (preptr->data != after) {
			preptr = preptr->next;
			if (preptr == nullptr)throw std::exception("Cant find value provided as to add after");
		}
		Node<T>* newNode = new Node<T>(data);
		newNode->next = preptr->next;
		preptr->next = newNode;
		++size;
	}
	void addBefore(T before, T data) {
		if (size == 0)throw std::exception("No after and before for size zero");
		Node<T>* preptr = head;
		while (preptr->next->data != before) {
			preptr = preptr->next;
			if (preptr == nullptr)throw std::exception("Cant find value provided as to add before");
		}
		Node<T>* newNode = new Node<T>(data);
		newNode->next = preptr->next;
		preptr->next = newNode;
		++size;
	}
	T removeFirst() {
		if (isEmpty())throw std::exception("cant remove item from empty list");
		Node<T>* temp = head;
		head = head->next;
		T returnVal = temp->data;
		delete temp;
		--size;
		return returnVal;
	}
	T removeLast() {
		if (isEmpty())throw std::exception("cant remove item from empty list");

		Node<T>* preptr = head;
		if (preptr->next == nullptr) {
			T toReturn = preptr->data;
			delete preptr;
			head = tail = nullptr;
			--size;
			return toReturn;
		}
		while (preptr->next->next != nullptr) {
			preptr = preptr->next;
		}
		Node<T>* temp = preptr->next;
		T returnVal = temp->data;
		preptr->next = nullptr;
		tail = preptr;
		delete temp;
		--size;
		return returnVal;
	}
	T removeAfter(T val) {
		if (isEmpty() || size == 1)throw std::exception("Exception  List is  empty or size 1");
		Node<T>* preptr = head;
		while (preptr->data != val) {
			preptr = preptr->next;
			if (preptr == nullptr or preptr->next == nullptr) throw std::exception("Cant find value provided as to remove after");
		}
		Node<T>* temp = preptr->next;
		T returnVal = temp->data;
		preptr->next = preptr->next->next;
		delete temp;
		--size;
		return returnVal;
	}
	void showAll() {
		Node<T>* temp = head;
		while (temp->next != nullptr) {
			std::cout << temp->data << std::endl;
			temp = temp->next;
		}
		std::cout << temp->data << std::endl;
	}
};