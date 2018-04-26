#include <bits/stdc++.h>

using namespace std;


class Queue {

	const int max_size;
	int head, tail;
	int *queue;

public:
	
	// Constructor
	Queue(const int& m_size=50):max_size(m_size) {
		head = 0;
		tail = 0;
		queue = new int[max_size];
	}

	// Destructor
	~Queue() {
		delete[] queue;
	}

	// Getter methods
	const int& getMaxSize() {
		return max_size;
	}

	int& getHead() {
		return head;
	}

	int& getTail() {
		return tail;
	}

	int* getQueue() {
		return queue;
	}


	// Setter methods
	void setHead(const int& i) {
		head = i;
	}

	void setTail(const int& i) {
		tail = i;
	}


	void enqueue(const int& num);
	void dequeue();
	void printQueue();
};


// Functions of Queue class
void Queue :: enqueue(const int& num) {
	if (tail == max_size) {
		cout << "Queue size exceeded!" << endl;
		return;
	}
	queue[tail++] = num;
}

void Queue::dequeue() {
	if (tail == 0 || tail > head) {
		cout << "No elements in the queue!" << endl;
		return;
	}
	head++;
}

void Queue :: printQueue() {
	cout << "Queue: FRONT";
	for (int i = head ; i < tail ; ++i) {
		cout << " -> " << queue[i];
	}
	cout << " <- REAR" << endl;
}


class PriorityQueue : public Queue {

private:
	int parent(const int& i) {
		return (i-1)/2;
	}

	int leftChild(const int& i) {
		return (2*i) + 1;
	}

	int rightChild(const int& i) {
		return (2*i) + 2;
	}

	void swapElements(int& num1, int& num2) {
		int temp = num1;
		num1 = num2;
		num2 = temp;
	}

public:
	PriorityQueue(int m_size=50):Queue(m_size) { }
	void enqueue(const int&);
	void dequeue();
};


void PriorityQueue :: enqueue(const int& num) {
	int tail = getTail();
	int head = getHead();
	int max_size = getMaxSize();
	if (tail == max_size) {
		cout << "Can't add more elements, heap is full" << endl;
		return;
	}

	setTail(++tail);
	int i = tail - 1;
	int* queue = getQueue();
	queue[i] = num;

	while (i != head && queue[parent(i)] < queue[i]) {
		swap(queue[i], queue[parent(i)]);
		i = parent(i);
	}
}

void PriorityQueue :: dequeue() {
	int tail = getTail();
	int head = getHead();
	int* queue = getQueue();

	if (tail == 0 || head > tail) {
		cout << "Can't delete from an empty queue" << endl;
		return;
	}

	setTail(--tail);
	swap(queue[head], queue[tail]);
	int i = head;

	while (leftChild(i) <= tail &&
		   (queue[i] < queue[leftChild(i)] || queue[i] < queue[rightChild(i)])) {
		int swappable = queue[leftChild(i)] > queue[rightChild(i)] ? leftChild(i) : rightChild(i);
		swap(queue[swappable], queue[i]);
		i = swappable;
	}
}

int main(void) {

	PriorityQueue q(100);

	q.enqueue(13);
	q.enqueue(33);
	q.enqueue(44);
	q.enqueue(11);

	q.printQueue();

	q.dequeue();
	q.dequeue();

	q.printQueue();

	return 0;
}