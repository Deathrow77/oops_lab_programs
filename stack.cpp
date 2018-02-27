#include <bits/stdc++.h>

using namespace std;


typedef struct Node {
	int data;
	Node* next;
} Node;


class Stack {

	Node* top;

public:
	Stack() {
		top = NULL;
	}
	Node* createNewNode(int n);
	void push(int num);
	int pop();
	void printStack();
};

// Functions of Stack class
Node* Stack::createNewNode(int n) {
	Node* newNode = new Node;
	if (newNode) {
		newNode->data = n;
		newNode->next = NULL;
	}
	return newNode;
}

void Stack::push(int num) {
	Node* node = createNewNode(num);
	if (!node) {
		cout << "Couldn't create a new node!" << endl;
		return;
	}
	if (top) {
		node->next = top;
	}
	top = node;
}

int Stack::pop() {
	if (!top) {
		cout << "Couldn't remove node from an empty stack!" << endl;
		return -1;
	} 
	Node* temp = top;
	top = top->next;
	int num = temp->data;
	delete temp;
	return num;
}

void Stack::printStack() {
	cout << "Stack: TOP";
	Node* temp = top;
	while (temp) {
		cout << " -> " << temp->data;
		temp = temp->next;
	}
	cout << " -> NULL" << endl;
}


main(void) {

	Stack stack;
	int ch, num;

	do {
		cout << endl;
		cout << "1. Push" << endl;
		cout << "2. Pop" << endl;
		cout << "3. Exit" << endl;
		cout << endl << "Enter your choice: ";

		cin >> ch;
		cout << endl;

		switch (ch) {
			case 1:
				cout << "Enter number to push: ";
				cin >> num;
				stack.push(num);
				stack.printStack();
				break;
			case 2:
				num = stack.pop();
				if (num != -1)
					cout << num << " was popped!" << endl;
				stack.printStack();
				break;
			case 3:
				break;
			default:
				cout << "You entered an incorrect choice!" << endl;
		}
	} while (ch != 3);
}