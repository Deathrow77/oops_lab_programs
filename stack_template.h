#include <bits/stdc++.h>

using namespace std;

template <class T>
class Stack {

	private:
		vector<T> elems;

	public:
		Stack() {}
		~Stack() {}
		void push(T const&);
		void pop();
		bool isEmpty();
		void printStack();
};

template <class T>
void Stack<T>::push(T const& item) {
	elems.push_back(item);
}

template <class T>
void Stack<T>::pop() {
	if (elems.empty()) {
		cout << "Empty stack. Can't pop!" << endl;
		return;
	} 
	elems.pop_back();
}

template <class T>
bool Stack<T>::isEmpty() {
	return elems.empty();
}

template <class T>
void Stack<T>::printStack() {
	typename vector<T> :: iterator it;
	cout << "Stack: ";
	for (it = elems.begin() ; it < elems.end() ; ++it)
		cout << *it << " ";
	cout << endl;
}