#include <iostream>
#include <iomanip>

using namespace std;

main(void) {
	int range;
	cout << "Enter range for pyramid: ";
	cin >> range;
	for (int i=1;i<=range;i++) {
		cout << setw(2*(range+1-i));
		for (int j=1;j<i;j++) {
			cout << j << " ";
		}
		for (int j=i;j>=1;j--) {
			cout << j << " ";
		}
		cout << endl;
	}
}