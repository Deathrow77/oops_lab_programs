#include <bits/stdc++.h>

typedef struct StackNode {
	int data;
	StackNode* next;
} StackNode;


class Stack {

	StackNode* top;

public:
	Stack() {
		top = NULL;
	}
	StackNode* createNewStackNode(int n);
	void push(int num);
	int pop();
	bool isEmpty();
};

// Functions of Stack class
StackNode* Stack::createNewStackNode(int n) {
	StackNode* newStackNode = new StackNode;
	if (newStackNode) {
		newStackNode->data = n;
		newStackNode->next = NULL;
	}
	return newStackNode;
}

void Stack::push(int num) {
	StackNode* StackNode = createNewStackNode(num);
	if (!StackNode) {
		return;
	}
	if (top) {
		StackNode->next = top;
	}
	top = StackNode;
}

int Stack::pop() {
	if (!top) {
		return -1;
	} 
	StackNode* temp = top;
	top = top->next;
	int num = temp->data;
	delete temp;
	return num;
}

bool Stack::isEmpty() {
	return top == NULL;
}