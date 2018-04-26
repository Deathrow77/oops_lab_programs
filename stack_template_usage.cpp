#include <bits/stdc++.h>
#include "stack_template.h"

using namespace std;


int main() {
	Stack<int> intStack;
	intStack.push(5);
	intStack.push(6);
	intStack.push(2);
	intStack.pop();
	intStack.printStack();
	intStack.pop();
	intStack.printStack();

	Stack<string> stringStack;
	stringStack.push("Hello");
	stringStack.push("World");
	stringStack.printStack();
	stringStack.pop();
	stringStack.pop();
	stringStack.pop();

	return 0;
}