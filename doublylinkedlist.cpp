#include <iostream>

class Node {
	int data;
	Node* next;

public:
	Node(int i_data) {
		data = i_data;
		next = NULL;
	}
}

class LinkedList {
	Node* head;

public:
	LinkedList() {
		head = NULL;
	}
	void insert(const int&);
}

void LinkedList :: insert(const int& elem) {
	Node newNode(elem);
	Node* temp = head;
	if (head == NULL) {
		head = newNode;
	} else {
		while (temp -> next != NULL) {
			temp = temp -> next;
		}
		temp -> next = newNode;
	}
}