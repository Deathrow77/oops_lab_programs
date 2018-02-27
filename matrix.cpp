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
        for (int i = 0 ; i < rows ; i++) {
            matrix[i] = new int[cols];
        }
    }
    int getRows();
    int getCols();
    int** getMatrix();
    void setMatrix(int**);
    void printMatrix();
};

int Matrix::getRows() {
    return rows;
}

int Matrix::getCols() {
    return cols;
}

int** Matrix::getMatrix() {
    return matrix;
}

void Matrix::setMatrix(int** m) {
    for (int i = 0 ; i < rows ; ++i) {
        for (int j = 0 ; j < cols ; ++j) {
            matrix[i][j] = m[i][j];
        }
    }
}

void Matrix::printMatrix() {
    for (int i = 0 ; i < rows ; ++i) {
        for (int j = 0 ; j < cols ; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


Matrix addMatrices(Matrix mat1, Matrix mat2) {

    int r1 = mat1.getRows(), c1 = mat1.getCols();
    int r2 = mat2.getRows(), c2 = mat2.getCols();

    int** m1 = mat1.getMatrix();
    int** m2 = mat2.getMatrix();

    Matrix res(r1, c1);

    if (r1 != r2 || c1 != c2) {
        cout << "Matrices of different sizes cannot be added!" << endl;
    } else {
        int** m = new int*[r1];
        for (int i = 0 ; i < r1 ; ++i) {
            m[i] = new int[c1];
            for (int j = 0 ; j < c1 ; ++j)
                m[i][j] = m1[i][j] + m2[i][j];
        }
        res.setMatrix(m);
        for (int i = 0; i < r1; ++i) {
            delete[] m[i];   
        }
        delete[] m;
    }
    return res;
}


Matrix subMatrices(Matrix mat1, Matrix mat2) {

    int r1 = mat1.getRows(), c1 = mat1.getCols();
    int r2 = mat2.getRows(), c2 = mat2.getCols();

    int** m1 = mat1.getMatrix();
    int** m2 = mat2.getMatrix();

    Matrix res(r1, c1);

    if (r1 != r2 || c1 != c2) {
        cout << "Matrices of different sizes cannot be subtracted!" << endl;
    } else {
        int** m = new int*[r1];
        for (int i = 0 ; i < r1 ; ++i) {
            m[i] = new int[c1];
            for (int j = 0 ; j < c1 ; ++j)
                m[i][j] = m1[i][j] - m2[i][j];
        }
        res.setMatrix(m);
        for (int i = 0; i < r1; ++i) {
            delete[] m[i];   
        }
        delete[] m;
    }
    return res;
}


Matrix mulMatrices(Matrix mat1, Matrix mat2) {

    int r1 = mat1.getRows(), c1 = mat1.getCols();
    int r2 = mat2.getRows(), c2 = mat2.getCols();

    int** m1 = mat1.getMatrix();
    int** m2 = mat2.getMatrix();

    Matrix res(r1, c2);

    if (r2 != c1) {
        cout << "Matrices of incompatible sizes! Cannot be multiplied!" << endl;
    } else {
        int** m = new int*[r1];
        for (int i = 0 ; i < r1 ; ++i) {
            m[i] = new int[c2];
            for (int j = 0 ; j < c2 ; ++j) {
                m[i][j] = 0;
                for (int k = 0 ; k < c1 ; ++k)
                    m[i][j] += m1[i][k] * m2[k][j];
            }
        }
        res.setMatrix(m);
        for (int i = 0; i < r1; ++i) {
            delete[] m[i];   
        }
        delete[] m;
    }
    return res;
}


main(void) {
    
    int r1, c1;
    cout << "Enter the number of rows and columns of first matrix: ";
    cin >> r1 >> c1;

    Matrix m1(r1, c1);
    int** m = new int*[r1];
    for (int i = 0 ; i < r1 ; ++i) {
        cout << "Enter values for row " << i+1 << ": ";
        m[i] = new int[c1];
        for (int j = 0 ; j < c1 ; ++j)
            cin >> m[i][j];
    }
    m1.setMatrix(m);
    for (int i = 0; i < r1; ++i) {
        delete[] m[i];   
    }
    delete[] m;

    cout << "First matrix:" << endl;
    m1.printMatrix();
    cout << endl;
    
    int r2, c2;
    cout << "Enter the number of rows and columns of second matrix: ";
    cin >> r2 >> c2;

    Matrix m2(r2, c2);
    m = new int*[r2];
    for (int i = 0 ; i < r2 ; ++i) {
        cout << "Enter values for row " << i+1 << ": ";
        m[i] = new int[c2];
        for (int j = 0 ; j < c2 ; ++j)
            cin >> m[i][j];
    }
    m2.setMatrix(m);
    for (int i = 0; i < r1; ++i) {
        delete[] m[i];   
    }
    delete[] m;

    cout << "Second matrix:" << endl;
    m2.printMatrix();

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
                Matrix res = addMatrices(m1, m2);
                res.printMatrix();
                break;
            }
            case 2: {
                cout << "Subtraction:" << endl;
                Matrix res = subMatrices(m1, m2);
                res.printMatrix();
                break;
            }
            case 3: {
                cout << "Multiplication:" << endl;
                Matrix res = mulMatrices(m1, m2);
                res.printMatrix();
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