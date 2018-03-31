#include <bits/stdc++.h>


typedef struct QueueNode {
	int data;
	QueueNode* next;
} QueueNode;


class Queue {

	QueueNode* front;
	QueueNode* rear;

public:
	Queue() {
		front = NULL;
		rear = NULL;
	}
	QueueNode* createNewQueueNode(int n);
	void enqueue(int num);
	int dequeue();
	bool isEmpty();
};

// Functions of Queue class
QueueNode* Queue::createNewQueueNode(int n) {
	QueueNode* newQueueNode = new QueueNode;
	if (newQueueNode) {
		newQueueNode->data = n;
		newQueueNode->next = NULL;
	}
	return newQueueNode;
}

void Queue::enqueue(int num) {
	QueueNode* QueueNode = createNewQueueNode(num);
	if (!QueueNode) {
		return;
	}
	if (!front && !rear)
		front = QueueNode;
	else
		rear -> next = QueueNode;
	rear = QueueNode;
}

int Queue::dequeue() {
	if (!front) {
		return -1;
	} 
	QueueNode* temp = front;
	front = front->next;
	if (front == NULL)
		rear = NULL;
	int num = temp->data;
	delete temp;
	return num;
}

bool Queue::isEmpty() {
	return (front == NULL && rear == NULL);
}