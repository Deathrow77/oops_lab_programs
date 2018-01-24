#include <iostream>
#include <iomanip>

using namespace std;

main(void) {
	int range;
	cout << "Enter range for pyramid: ";
	cin >> range;
	for (int i=1;i<=range;i++) {
		if (i != range) {
			cout << setw(2*(range+1-i)) << "1";
			if (i != 1) {
				cout << setw(4*(i-1)) << "1";
			}
		} else {
			for (int j=0;j<(2*range)-1;j++) {
				cout << " 1";
			}
		}
		cout << endl;
	}
	return 0;
}