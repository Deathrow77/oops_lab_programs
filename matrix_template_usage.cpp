#include <bits/stdc++.h>
#include "matrix_template.h"

using namespace std;


main(void) {
    
    int r, c;

    cout << "Enter the number of rows and columns of first matrix: ";
    cin >> r >> c;
    Matrix<float> m1(r, c);
    cin >> m1;
    cout << "\nFirst matrix:" << endl;
    cout << m1;
    cout << endl;
    
    cout << "Enter the number of rows and columns of second matrix: ";
    cin >> r >> c;
    Matrix<float> m2(r, c);
    cin >> m2;
    cout << "\nSecond matrix:" << endl;
    cout << m2;

    int ch;
    do {
        cout << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Exit" << endl;
        cout << endl << "Enter your choice: ";
        cin >> ch;
        cout << endl;
        switch(ch) {
            case 1: {
                cout << "Addition:" << endl;
                Matrix<float>res = m1 + m2;
                cout << res;
                break;
            }
            case 2: {
                cout << "Subtraction:" << endl;
                Matrix<float>res = m1 - m2;
                cout << res;
                break;
            }
            case 3: {
                cout << "Multiplication:" << endl;
                Matrix<float>res = m1 * m2;
                cout << res;
                break;
            }
            case 4:
                break;
            default:
                cout << "Wrong choice!" << endl;
        }
    } while (ch != 4);

    return 0;
}