#include <iostream>
#include <stdlib.h>
#include <time.h>

/** Binary Tree: Create insert(), printPreOrder(), printInOrder(), printPostOrder() */

template <class T>
struct BinaryNode {
	BinaryNode(T value) : value(value), left(NULL), right(NULL) {}
	T value;
	BinaryNode<T>* left;
	BinaryNode<T>* right;
};

template <class T>
class BinaryTree {
	public:
		BinaryTree() : head(NULL) {}
		void insert(BinaryNode<T>* &head, T value);
		
		void printOrder(BinaryNode<T>* head);
		void printOrderPre(BinaryNode<T>* head);
		void printOrderPost(BinaryNode<T>* head);
		
		inline BinaryNode<T>*& getHead() { return head; }
	private:
		BinaryNode<T>* head;
};

template <class T>
void BinaryTree<T>::insert(BinaryNode<T>* &head, T value) {
	if(head == NULL) head = new BinaryNode<T>(value);
	else if(value <= head->value) insert(head->left, value);
	else insert(head->right, value);
}

template <class T>
void BinaryTree<T>::printOrder(BinaryNode<T>* head) {
	if(head == NULL) return;
	printOrder(head->left);
	std::cout << head->value << " ";
	printOrder(head->right);
}

template <class T>
void BinaryTree<T>::printOrderPre(BinaryNode<T>* head) {
	if(head == NULL) return;
	std::cout << head->value << " ";
	printOrderPre(head->left);
	printOrderPre(head->right);
}

template <class T>
void BinaryTree<T>::printOrderPost(BinaryNode<T>* head) {
	if(head == NULL) return;
	printOrderPost(head->left);
	printOrderPost(head->right);
	std::cout << head->value << " ";
}

int main() {
	srand(time(NULL));
	
	BinaryTree<int> tree;

	for(int i=0; i < 25; i++) {
		int value = rand() % 100;
		tree.insert(tree.getHead(), value);
	}
	
	tree.printOrder(tree.getHead());
	std::cout << std::endl;
	tree.printOrderPre(tree.getHead());
	std::cout << std::endl;
	tree.printOrderPost(tree.getHead());
	
	return 0;
}