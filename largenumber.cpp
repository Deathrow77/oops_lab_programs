#include <bits/stdc++.h>

using namespace std;


string reverse(string number) {
	string numcopy = number;
	int len = numcopy.length();
	for (int i = 0 ; i < len/2 ; ++i)
		swap(numcopy[i], numcopy[len-1-i]);
	return numcopy;
}


class LargeInteger {
	string number;

public:
	LargeInteger(string num="0") {
		number = num;
	}
	LargeInteger(const LargeInteger& copy) {
		number = copy.number;
	}
	~LargeInteger() { }
	LargeInteger& operator=(const LargeInteger&);
	LargeInteger& operator=(const string&);
	friend LargeInteger& operator+(const LargeInteger&, const LargeInteger&);
	friend ostream& operator<<(ostream&, const LargeInteger&);
	friend istream& operator>>(istream&, LargeInteger&);
};


LargeInteger& operator+(const LargeInteger& num1, const LargeInteger& num2) {
	string operand1 = reverse(num1.number);
	string operand2 = reverse(num2.number);
	string res = "";
	int maxlen = operand1.length() > operand2.length() ? operand1.length() : operand2.length();
	int carry = 0, i = 0, temp;
	while (i < maxlen) {
		if (i < operand1.length() && i < operand2.length()) {
			temp = (int(operand1[i]) - 48) + (int(operand2[i]) - 48) + carry;
		} else if (i < operand1.length() && i >= operand2.length()) {
			temp = (int(operand1[i]) - 48) + carry;
		} else {
			temp = (int(operand2[i]) - 48) + carry;
		}
		carry = temp / 10;
		res += char((temp % 10) + 48);
		i++;
	}
	static LargeInteger result(reverse(res));

	return result;
}

LargeInteger& LargeInteger :: operator=(const LargeInteger& rhs) {
	if (this != &rhs)
		number = rhs.number;
	return *this;
}

LargeInteger& LargeInteger :: operator=(const string& rhs) {
	number = rhs;
	return *this;
}

ostream& operator<<(ostream& obj, const LargeInteger& num) {
	obj << num.number;
	return obj;
}

istream& operator>>(istream& obj, LargeInteger& num) {
	obj >> num.number;
	return obj;
}

int main(void) {
	LargeInteger num1, num2;

	num1 = "7869383";
	num2 = "79192837";

	// cout << "Enter number 1: ";
	// cin >> num1;

	// cout << "Enter number 2: ";
	// cin >> num2;

	LargeInteger res = num1 + num2;
	cout << num1 << " + " << num2 << " = " << res << endl;

	return 0;
}