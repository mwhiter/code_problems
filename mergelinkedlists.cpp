#include <iostream>

struct Node {
	Node(int x):value(x){}
	int value;
	Node* next;
};

// Create the lists.
void createLists(Node* l1, Node* l2) {
	l1->next = new Node(5);
	l1 = l1->next;
	l1->next = new Node(10);
	l1 = l1->next;
	l1->next = new Node(11);
	l1 = l1->next;
	l1->next = new Node(15);
	
	l2->next = new Node(7);
	l2 = l2->next;
	l2->next = new Node(8);
}

// Append node to head. Pointers passed as references because head and node will be advanced.
void append(Node* &head, Node* &node) {
	Node* newNode = new Node(node->value);
	head->next = newNode;
	
	// advance ptrs
	head = head->next;
	node = node->next;
}

// Merge l1 and l2 and return a new list
Node* merge(Node* l1, Node* l2) {
	// Create a fake node that will start the list.
	Node* fake = new Node(0);
	Node* head = fake;
	
	while(l1 != NULL && l2 != NULL) {
		if(l1->value <= l2->value) {
			append(head, l1);
		}
		else {
			append(head, l2);
		}
	}
	
	while(l1 != NULL) {
		append(head, l1);
	}
	while(l2 != NULL) {
		append(head, l2);
	}
	
	// Delete the fake node because we don't need it anymore.
	head = fake->next;
	delete fake;
	
	return head;
}

// Print a list.
void printList(const char* name, Node* list) {
	std::cout << name << ": ";
	while(list != NULL) {
		std::cout << list->value << " ";
		list = list->next;
	}
	std::cout << std::endl;
}

int main() {
	Node* l1 = new Node(3);
	Node* l2 = new Node(1);
	
	createLists(l1, l2);
	Node* l3 = merge(l1, l2);
	
	printList("list1", l1);
	printList("list2", l2);
	printList("list3", l3);
	
	return 0;
}