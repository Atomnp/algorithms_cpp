#include "RedBlackTree.h"
#include <chrono>
#include <thread>
using namespace std::chrono;

using namespace std;
#define COUNT 10 

Node* RedBlackTree::insert(Node* x, int n) {
	
	
	if (x == nullptr) {
		x = new Node(n);
		return x;
	}
	else if (n <= x->data) {
		
		x->left = insert(x->left, n);
	}
	else if (n > x->data) {
		x->right = insert(x->right, n);
	}
	//std::cout << "curent Input is " << n << std::endl;
	//std::cout << "currenttree is" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	this->print2D();
	
	if (isRed(x->right) && !isRed(x->left))x=singleLeftRotate(x);
	if (isRed(x->left) && isRed(x->left->left))x=singleRightRotate(x);
	if (isRed(x->left) && isRed(x->right))flipColors(x);
	
	return x;
}
Node* RedBlackTree::singleRightRotate(Node* x) {
	
	Node* temp = x->left;
	x->left = temp->right;
	temp->right = x;

	return temp;

}
Node* RedBlackTree::singleLeftRotate(Node* x) {


	Node* temp = x->right;
	bool  tempc  = x->right->isRed;
	x->right = temp->left;
	temp->isRed = x->isRed;
	x->isRed =tempc ;
	
	temp->left = x;
	return temp;

}
int RedBlackTree::max(int i, int j) {
	if (i <= j)return j;
	return i;
}
Node* RedBlackTree::findMin(Node* t) {
	if (t == nullptr)
		return nullptr;
	else if (t->left == nullptr)
		return t;
	else
		return findMin(t->left);
}

Node* RedBlackTree::findMax(Node* t) {
	if (t == nullptr)
		return nullptr;
	else if (t->right == nullptr)
		return t;
	else
		return findMax(t->right);
}
void RedBlackTree::printInorder(Node* x) {
	if (x == nullptr)return;
	printInorder(x->left);
	//std::cout << x->data << " ";
	printInorder(x->right);
}

void RedBlackTree::print2DUtil(Node* root, int space)
{
	// Base case  
	if (root == NULL)
		return;

	// Increase distance between levels  
	space += COUNT;

	// Process right child first  
	print2DUtil(root->right, space);

	// Print current node after space  
	// count  
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << root->data <<(root->isRed?"R":"B")<< "\n";

	// Process left child  
	print2DUtil(root->left, space);
}
Node* RedBlackTree::remove(Node* x, int n) {

	//when element is not found in the tree
	if (x == nullptr)return nullptr;

	//when delete node key is less then key we are current standing at search left
	if (n < x->data) {
		x->left = remove(x->left, n);
	}
	//when delete node key is greater then key we are current standing at search right
	else if (n > x->data) {
		x->right = remove(x->right, n);
	}
	//when we find the deleting node
	else {
		//if both child are present
		if (x->left && x->right) {
			Node* temp = x;
			x->right->left = x->left->right;
			x->left->right = x->right;
			x = x->left;
			delete temp;
		}
		//when deleting node is leaf node
		else if (x->left == nullptr and x->right == nullptr) {
			delete x;
			return nullptr;
		}
		//when only right child is present
		else if (x->left == nullptr) {
			Node* temp = x;
			x = x->right;
			delete temp;
		}
		//when only left child is present
		else if (x->right == nullptr) {
			Node* temp = x;
			x = x->left;
			delete temp;
		}

	}
	std::cout << "x.data remove" << x->data << std::endl;
	if (isRed(x->right) && !isRed(x->left))x = singleLeftRotate(x);
	if (isRed(x->left) && isRed(x->left->left))x = singleRightRotate(x);
	if (isRed(x->left) && isRed(x->right))flipColors(x);

	return x;

}