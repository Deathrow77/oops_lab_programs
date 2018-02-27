#include <bits/stdc++.h>

using namespace std;


typedef struct Node {
	int data;
	Node* next;
} Node;


class Queue {

	Node* front;
	Node* rear;

public:
	Queue() {
		front = NULL;
		rear = NULL;
	}
	Node* createNewNode(int n);
	void enqueue(int num);
	int dequeue();
	void printQueue();
};

// Functions of Queue class
Node* Queue::createNewNode(int n) {
	Node* newNode = new Node;
	if (newNode) {
		newNode->data = n;
		newNode->next = NULL;
	}
	return newNode;
}

void Queue::enqueue(int num) {
	Node* node = createNewNode(num);
	if (!node) {
		cout << "Couldn't create a new node!" << endl;
		return;
	}
	if (!front && !rear)
		front = node;
	else
		rear -> next = node;
	rear = node;
}

int Queue::dequeue() {
	if (!front) {
		cout << "Couldn't remove node from an empty Queue!" << endl;
		return -1;
	} 
	Node* temp = front;
	front = front->next;
	if (front == NULL)
		rear = NULL;
	int num = temp->data;
	delete temp;
	return num;
}

void Queue::printQueue() {
	cout << "Queue: FRONT";
	Node* temp = front;
	while (temp) {
		cout << " -> " << temp->data;
		temp = temp->next;
	}
	cout << " <- REAR" << endl;
}


main(void) {

	Queue queue;
	int ch, num;

	do {
		cout << endl;
		cout << "1. Enqueue" << endl;
		cout << "2. Dequeue" << endl;
		cout << "3. Exit" << endl;
		cout << endl << "Enter your choice: ";

		cin >> ch;
		cout << endl;

		switch (ch) {
			case 1:
				cout << "Enter number to enqueue: ";
				cin >> num;
				queue.enqueue(num);
				queue.printQueue();
				break;
			case 2:
				num = queue.dequeue();
				if (num != -1)
					cout << num << " was removed!" << endl;
				queue.printQueue();
				break;
			case 3:
				break;
			default:
				cout << "You entered an incorrect choice!" << endl;
		}
	} while (ch != 3);
}