#include <bits/stdc++.h>

using namespace std;

class Matrix {

    int rows;
    int cols;
    int** matrix;

public:
    Matrix(int r, int c) {
        rows = r;
        cols = c;
        matrix = new int*[rows];
        for (int i = 0 ; i < rows ; i++)
            matrix[i] = new int[cols];
    }
    ~Matrix() {
        for (int i=0 ; i<rows ; ++i)
            delete[] matrix[i];
        delete[] matrix;
    }
    friend void operator<<(ostream& obj, Matrix& m);
    friend void operator>>(istream& obj, Matrix& m);
    friend Matrix operator+(Matrix& mat1, Matrix& mat2);
    friend Matrix operator-(Matrix& mat1, Matrix& mat2);
    friend Matrix operator*(Matrix& mat1, Matrix& mat2);
};

void operator<<(ostream& obj, Matrix& m) {
    for (int i = 0 ; i < m.rows ; ++i) {
        for (int j = 0 ; j < m.cols ; ++j) {
            cout << m.matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void operator>>(istream& obj, Matrix& m) {
    for (int i = 0 ; i < m.rows ; ++i) {
        cout << "Enter values for row " << i << ": ";
        for (int j = 0 ; j < m.cols ; ++j) {
            cin >> m.matrix[i][j];
        }
    }
}


Matrix operator+(Matrix& mat1, Matrix& mat2) {

    int r1 = mat1.rows, c1 = mat1.cols;
    int r2 = mat2.rows, c2 = mat2.cols;

    int** m1 = mat1.matrix;
    int** m2 = mat2.matrix;

    Matrix res(r1, c1);

    if (r1 != r2 || c1 != c2) {
        cout << "Matrices of different sizes cannot be added!" << endl;
    } else {
        for (int i = 0 ; i < r1 ; ++i) {
            for (int j = 0 ; j < c1 ; ++j)
                res.matrix[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return res;
}


Matrix operator-(Matrix& mat1, Matrix& mat2) {

    int r1 = mat1.rows, c1 = mat1.cols;
    int r2 = mat2.rows, c2 = mat2.cols;

    int** m1 = mat1.matrix;
    int** m2 = mat2.matrix;

    Matrix res(r1, c1);

    if (r1 != r2 || c1 != c2) {
        cout << "Matrices of different sizes cannot be subtracted!" << endl;
    } else {
        for (int i = 0 ; i < r1 ; ++i) {
            for (int j = 0 ; j < c1 ; ++j)
                res.matrix[i][j] = m1[i][j] - m2[i][j];
        }
    }
    return res;
}


Matrix operator*(Matrix& mat1, Matrix& mat2) {

    int r1 = mat1.rows, c1 = mat1.cols;
    int r2 = mat2.rows, c2 = mat2.cols;

    int** m1 = mat1.matrix;
    int** m2 = mat2.matrix;

    Matrix res(r1, c2);

    if (r2 != c1) {
        cout << "Matrices of incompatible sizes! Cannot be multiplied!" << endl;
    } else {
        for (int i = 0 ; i < r1 ; ++i) {
            for (int j = 0 ; j < c2 ; ++j) {
                res.matrix[i][j] = 0;
                for (int k = 0 ; k < c1 ; ++k)
                    res.matrix[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return res;
}


main(void) {
    
    int r, c;

    cout << "Enter the number of rows and columns of first matrix: ";
    cin >> r >> c;
    Matrix m1(r, c);
    cin >> m1;
    cout << "\nFirst matrix:" << endl;
    cout << m1;
    cout << endl;
    
    cout << "Enter the number of rows and columns of second matrix: ";
    cin >> r >> c;
    Matrix m2(r, c);
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
                Matrix res = m1 + m2;
                cout << res;
                break;
            }
            case 2: {
                cout << "Subtraction:" << endl;
                Matrix res = m1 - m2;
                cout << res;
                break;
            }
            case 3: {
                cout << "Multiplication:" << endl;
                Matrix res = m1 * m2;
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