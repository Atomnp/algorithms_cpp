#include "AVL.h"
using namespace std;
#define COUNT 10 

Node * AVL::insert(Node* x, int n) {

	if (x == nullptr) {
		x = new Node(n);		
	}
	else if (n <= x->data) {
		x->left = insert(x->left, n);
		
		if (height(x->left) - height(x->right) >= 2) {
			//item was inserted to left of left
			if (n <= x->left->data) {
				x=singleRightRotate(x);
			}
			else {
				x=doubleRightRotate(x);
			}
		}
	}
	else if (n > x->data) {
		x->right = insert(x->right, n);
		
		if (height(x->right) - height(x->left) >= 2) {
			//item was inserted to left of left
			if (n > x->right->data) {
				x=singleLeftRotate(x);
			}
			else {
				x=doubleLeftRotate(x);
			}
		}
	}
	x->height = max(height(x->left), height(x->right)) + 1;
	//std::cout << "heignt of " <<" root "<<"="<<height(root)<< std::endl;
	return x;
}
Node* AVL::singleRightRotate(Node* x) {
	
	Node* temp = x->left;
	x->left=temp->right;
	temp->right = x;
	x->height = max(height(x->left), height(x->right)) + 1;
	temp->height = max(height(temp->left), x->height) + 1;

	return temp;

}
Node* AVL::singleLeftRotate(Node* x) {

	Node* temp = x->right;
	x->right = temp->left;
	temp->left = x;
	x->height = max(height(x->left), height(x->right)) + 1;
	temp->height = max(height(temp->right), x->height) + 1;
	return temp;

}
int AVL::max(int i, int j) {
	if (i <= j)return j;
	return i;
}
Node* AVL::doubleLeftRotate(Node *x){
	x->right = singleRightRotate(x->right);
	return  singleLeftRotate(x);
}
Node* AVL::doubleRightRotate(Node*x){
	x->left = singleLeftRotate(x->left);
	return singleRightRotate(x);
}
Node* AVL::findMin(Node* t){
	if (t == nullptr)
		return nullptr;
	else if (t->left == nullptr)
		return t;
	else
		return findMin(t->left);
}

Node* AVL::findMax(Node* t){
	if (t == nullptr)
		return nullptr;
	else if (t->right == nullptr)
		return t;
	else
		return findMax(t->right);
}
void AVL::printInorder(Node* x) {
	if (x == nullptr)return;
	printInorder(x->left);
	std::cout << x->data<<" ";
	printInorder(x->right);
}
Node* AVL::remove(Node* x,int n) {
	std::cout << "height ar remove top height of  " << x->data << "=" << height(x) << std::endl;
	std::cout << "this is remove definition from avl.cpp" << std::endl;
	//when element is not found in the tree
	if (x == nullptr)return nullptr;

	//when delete node key is less then key we are current standing at search left
	if (n < x->data) {
		x->left=remove(x->left, n);
	}
	//when delete node key is greater then key we are current standing at search right
	else if (n > x->data) {
		x->right=remove(x->right, n);
	}
	//when we find the deleting node
	else {
		//if both child are present
		if (x->left && x->right) {
			Node* temp = x;
			x->right->left =x->left->right;
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
			Node* temp=x;
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
	x->height = max(height(x->left), height(x->right)) + 1;

	std::cout << "before balancing after removal" << std::endl;
	std::cout << "x->data=" << x->data << std::endl;
	std::cout << "left height" << height(x->left) << std::endl;
	std::cout << "right height" << height(x->right) << std::endl;
	//std::cout << "x->left.da=" << x->data << std::endl;
	//std::cout << "x->data=" << x->data << std::endl;
	//now we have to balance the tree;
	if (height(x->left) - height(x->right) >= 2) {
		//when left has more height than right
		//we have to rotate 3 node one is x
		//other is higher children of x
		//next is higher children of higher children of x

		//now i may have to do ll rotate or lr rotate
		if (height(x->left->left) >= height(x->left->right)) {
			//perform ll rotate
			x = singleRightRotate(x);
		}
		if (height(x->left->left) < height(x->left->right)) {
			//perform ll rotate
			x = doubleRightRotate(x);
		}
	}
	else if (height(x->right) - height(x->left) >= 2) {
		//when left has more height than right
		//we have to rotate 3 node one is x
		//other is higher children of x
		//next is higher children of higher children of x

		//now i may have to do rr rotate or rl rotate
		if (height(x->right->right) > height(x->right->left)) {
			//perform ll rotate
			x = singleLeftRotate(x);
		}
		else if (height(x->left->left) < height(x->left->right)) {
			//perform ll rotate
			x = doubleLeftRotate(x);
		}
	}
	
	return x;

}
void AVL::print2DUtil(Node* root, int space)
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
	cout << root->data << "\n";

	// Process left child  
	print2DUtil(root->left, space);
}
