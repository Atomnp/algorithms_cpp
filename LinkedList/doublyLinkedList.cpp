#include <iostream>
#include <vector>

template <typename T>
struct Node {
	Node<T>* next;
	Node<T>* prev;
	T data;

	Node(T data, Node<T>* prev, Node<T>* next) :data(data), next(next), prev(prev) {
		
	}
};

template <typename DLinkedList>
class CustomIterator {

public:
	using Type = typename DLinkedList::ValueType;
	using ValueType = Node<typename DLinkedList::ValueType>;
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;
	CustomIterator(PointerType ptr):ptr(ptr) {
	}
	CustomIterator& operator++() {
		ptr = ptr->next;
		return *this;
	}
	bool operator!=(const CustomIterator& other) {
		return ptr != other.ptr;
	}
	bool operator==(const CustomIterator& other) {
		return ptr == other.ptr;
	}
	Type& operator*() {
		return ptr->data;
	}

private:
	PointerType ptr;

};


template <typename T>
class DoublyLinkedList {
private:
	Node<T>* head;
	Node<T>* tail;
	int size;
public:
	using ValueType = T;
	using iterator = CustomIterator<DoublyLinkedList<T>>;

	iterator begin() {
		return iterator(head);
	}
	iterator end() {
		return iterator(nullptr);
	}
public:
	DoublyLinkedList():size(0) {
		head = tail = nullptr;
	}
	bool isEmpty() {
		return size == 0;
	}
	T first() {
		if (size==0) {
			std::cout << "Cant call first when list is empty" << std::endl;
			exit(0);
		}
		return head->data;
	}
	T last() {
		if (size==0) {
			std::cout << "Cant call last when list is empty" << std::endl;
			exit(0);
		}
		return tail->data;
	}
	void addFirst(T data) {
		Node<T>* newNode = new Node<T>(data, nullptr, head);
		if (size == 0) {
			tail = newNode;
		}
		else {
			head->prev = newNode;
		}
		head = newNode;
		size++;
	}
	void addLast(T data) {
		if (size == 0) {
			addFirst(data); 
			return; 
		};
		Node<T>* newNode = new Node<T>(data, tail, nullptr);
		tail->next = newNode;
		tail = newNode;
		size++;
	}
	void addAfter(T val, T data) {
		Node<T> * temp = head;
		while ( temp != nullptr and temp->data != val) {
			temp=temp->next;
		}
		if (temp != nullptr) {
			if (temp == tail) {
				addLast(data);
				return;
			}
			Node<T>* newNode = new Node<T>(data, temp, temp->next);
			Node<T>* forPrev=temp->next;
			temp->next = newNode;
			forPrev->prev = newNode;
			size++;
		}
		else {
			std::cout << "Cant insert  After the value that is not in list" << std::endl;
			exit(0);
		}
	}
	void addBefore(T val, T data) {
		Node<T>* temp = tail;
		while (temp != nullptr and temp->data != val) {
			temp = temp->prev;
		}
		if (temp != nullptr) {
			if (temp == head) {
				addFirst(data);
				return;
			};
			Node<T>* newNode = new Node<T>(data, temp->prev, temp);
			Node<T>* forNext=temp->prev;
			temp->prev = newNode;
			forNext->next = newNode;
			size++;
		}
		else {
			std::cout << "Cant insert before the value that is not in list" << std::endl;
			exit(0);
		}
	}
	void removeFirst() {
		if (size == 1) {
			delete head;
			head = tail = nullptr;
			size--;
			return;
		}
		Node<T>* prevHead = head;
		head = head->next;
		head->prev = nullptr;
		delete prevHead;
		size--;
	}
	void removeLast() {
		if (size == 1) {
			removeFirst();
			return;
		}
		Node<T>* prevTail = tail;;
		tail = tail->prev;
		tail->next = nullptr;
		delete prevTail;
		size--;
	}

	void removeAfter(T val) {
		Node<T>* temp = head;
		while (temp != nullptr and temp->data != val) {
			temp = temp->next;
		}
		if (temp != nullptr and temp!=tail) {
			if (temp == tail->prev) {
				removeLast();
				return;
			};
			
			Node<T>* toDel = temp->next;
			temp->next = toDel->next;
			toDel->next->prev = temp;
			delete toDel;	
			size--;
		}
		else {
			std::cout << "Cant remove  After the value that is not in list" << std::endl;
			exit(0);
		}
	}
	void removeBefore(T val) {
		Node<T>* temp = tail;
		while (temp != nullptr and temp->data != val) {
			temp = temp->prev;
		}
		if (temp != nullptr and temp!=head) {
			if (temp == head->next) {
				removeFirst();
				return;
			};
		
			Node<T>* toDel = temp->prev;
			temp->prev = toDel->prev;
			toDel->prev->next = temp;
			delete toDel;
			size--;
		}
		else {
			std::cout << "Cant remove before the value that is not in list" << std::endl;
			exit(0);
		}
	}

	void showAll() {
		if (size == 0) {
			std::cout << "the list is empty" << std::endl;
			return;
		}
		Node<T>* temp = head;
		while (temp->next != nullptr) {
			std::cout << temp->data << std::endl;
			temp = temp->next;
		}
		std::cout << temp->data << std::endl;
	}

};

//unit test
int main() {
	DoublyLinkedList<int> d;
	d.addLast(5);
	d.addLast(6);
	d.addBefore(6, 16);
	d.addAfter(5, 18);
	d.removeBefore(16);
	d.showAll();
	for (auto item : d) {
		std::cout << item<<std::endl;
	}
}