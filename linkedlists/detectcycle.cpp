#include <iostream>

/** Detect a cycle in a linked-list, using Floyd's Cycle-Finding Algorithm. */
/** 
 	* We can detect a cycle in a linked-list if the fast node moves ahead two pointers while the slow node moves ahead one pointer.
	* If there is a cycle, fast and slow will be equal after one loop
	* Otherwise, if any are null, then there is no cycle
*/

struct Node {
	Node(int value):value(value), next(NULL){}
	
	int value;
	Node* next;
};

// Does this linked list have a cycle?
bool hasLoop(Node* head) {
	Node* slow = head;
	Node* fast = head;
	
	while(slow != NULL) {
		fast = fast->next;
		if(fast == NULL) return false;
		fast = fast->next;
		if(fast == NULL) return false;
		slow = slow->next;
		
		if(fast == slow) return true;
	}
	
	return false;
}

void buildLists(Node* l1, Node* l2) {
	for(int i=0;i<10;i++) {
		l1->next = new Node(i);
		l1 = l1->next;
	}
	
	Node* l2_start = l2;
	for(int i=0;i<10;i++) {
		l2->next = new Node(i);
		l2 = l2->next;
	}
	l2->next = l2_start;
}

int main() {
	Node* l1 = new Node(0);
	Node* l2 = new Node(1);
	buildLists(l1, l2);
	
	std::cout << "l1: " << hasLoop(l1) << std::endl;
	std::cout << "l2: " << hasLoop(l2) << std::endl;
	
	return 0;
}