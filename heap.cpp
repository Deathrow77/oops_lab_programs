#include <bits/stdc++.h>

using namespace std;

void swap(int*, int*);

class MaxHeap {

	int *heap_array;
	int maximum_size;
	int heap_size;

	int parent(int i) {
		return (i-1)/2;
	}

	int leftChild(int i) {
		return (2*i) + 1;
	}

	int rightChild(int i) {
		return (2*i) + 2;
	}

public:
	MaxHeap(int max_size) {
		heap_size = 0;
		maximum_size = max_size;
		heap_array = new int[max_size];
	}

	void maxHeapInsert(int num) {
		if (heap_size == maximum_size) {
			cout << "Can't add more elements, heap is full" << endl;
			return;
		}

		heap_size++;
		int i = heap_size - 1;
		heap_array[i] = num;

		while (i != 0 && heap_array[parent(i)] < heap_array[i]) {
			swap(&heap_array[i], &heap_array[parent(i)]);
			i = parent(i);
		}
	}

	void maxHeapDelete(int index)  {
		if (heap_size == 0 || index > heap_size) {
			cout << "Can't delete a non-existent element" << endl;
			return;
		}

		swap(&heap_array[index], &heap_array[--heap_size]);
		int i = index;

		while (leftChild(i) <= heap_size && (heap_array[i] < heap_array[leftChild(i)] || heap_array[i] < heap_array[rightChild(i)])) {
			int swappable = heap_array[leftChild(i)] > heap_array[rightChild(i)] ? leftChild(i) : rightChild(i);
			swap(&heap_array[swappable], &heap_array[i]);
			i = swappable;
		}	
	}

	void showHeap() {
		int i = 0;
		cout << endl << "Heap: ";
		while (i < heap_size) {
			cout << heap_array[i++] << " ";
		}
		cout << endl;
	}
};

void swap(int *num1, int *num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

main(void) {
	int size, elements, num;
	cout << "Enter the maximum number of elements: ";
	cin >> size;
	MaxHeap heap(size);
	cout << "Enter the number of elements you wish to insert: ";
	cin >> elements;
	cout << "Enter the elements: ";
	int i = 0;
	while (i < elements) {
		cin >> num;
		heap.maxHeapInsert(num);
		i++;
	}
	heap.showHeap();
	cout << endl << "What do you wish to do?" << endl;
	cout << "1. Insert element" << endl;
	cout << "2. Delete element" << endl;
	cout << "3. Exit" << endl;
	int ch;
	do {
		cout << endl << "Enter your choice: ";
		cin >> ch;
		switch(ch) {
			case 1:
				cout << "Enter element: ";
				cin >> num;
				heap.maxHeapInsert(num);
				heap.showHeap();
				break;
			case 2:
				cout << "Enter index: ";
				cin >> num;
				heap.maxHeapDelete(num);
				heap.showHeap();
				break;
			case 3:
				break;
			default:
				cout << "Wrong choice!" << endl;
		}
	} while (ch != 3);
	return 0;
}