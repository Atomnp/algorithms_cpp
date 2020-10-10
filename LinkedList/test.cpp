#include <iostream>
#include "LinkedList.h"
#include "List.h"
#include "./newQueue.h"
//unit test
int main() {
	//try {
	//	std::cout << "---linked list test---" << std::endl;
	//	LinkedList<int>* l = new LinkedList<int>();
	//	l->addFirst(5);
	//	l->addFirst(4);
	//	l->addFirst(3);
	//	l->addLast(6);
	//	l->addLast(7);
	//	l->addBefore(4, 44);
	//	l->addAfter(6, 66);
	//	l->showAll();

	//}
	//catch (std::exception e) {
	//	std::cout << e.what() << std::endl;
	//}
	/*try {
		std::cout << "---list test---" << std::endl;
		List<int>* l = new List<int>(5);
		l->insert(1);
		l->insert(2);
		l->insert(3);
		l->insert(1, 5);
		l->insert(1, 6);
		l->showAll();
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}*/

	try {
		std::cout << "----queue test -----" << std::endl;
		auto q = new Queue<int>(5);
		q->enqueue(5);
		q->enqueue(2);
		q->enqueue(4);

		std::cout << q->dequeue() << std::endl;
		std::cout << q->dequeue() << std::endl;

	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}

}