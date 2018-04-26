#include <bits/stdc++.h>

using namespace std;


template <typename T>
class Matrix;


template <typename T>
void operator>>(istream&, Matrix<T>&);

template <typename T>
void operator<<(ostream&, Matrix<T>&);

template <typename T>
Matrix<T> operator+(Matrix<T>&, Matrix<T>&);

template <typename T>
Matrix<T> operator-(Matrix<T>&, Matrix<T>&);

template <typename T>
Matrix<T> operator*(Matrix<T>&, Matrix<T>&);


template <typename T>
class Matrix {

    int rows;
    int cols;
    T** matrix;

public:
    Matrix(int r=1, int c=1) {
        rows = r;
        cols = c;
        matrix = new T*[rows];
        for (int i = 0 ; i < rows ; i++)
            matrix[i] = new T[cols];
    }
    ~Matrix() {
        for (int i=0 ; i<rows ; ++i)
            delete[] matrix[i];
        delete[] matrix;
    }
    friend void operator<< <>(ostream& obj, Matrix& m);
    friend void operator>> <>(istream& obj, Matrix<T>& m);
    friend Matrix<T> operator+ <>(Matrix<T>&, Matrix<T>&);
    friend Matrix<T> operator- <>(Matrix<T>&, Matrix<T>&);
    friend Matrix<T> operator* <>(Matrix<T>&, Matrix<T>&);
};

template <typename T>
void operator<<(ostream& obj, Matrix<T>& m) {
    for (int i = 0 ; i < m.rows ; ++i) {
        for (int j = 0 ; j < m.cols ; ++j) {
            cout << m.matrix[i][j] << " ";
        }
        cout << endl;
    }
}

template <typename T>
void operator>>(istream& obj, Matrix<T>& m) {
    for (int i = 0 ; i < m.rows ; ++i) {
        cout << "Enter values for row " << i << ": ";
        for (int j = 0 ; j < m.cols ; ++j) {
            cin >> m.matrix[i][j];
        }
    }
}

template <typename T>
Matrix<T> operator+(Matrix<T>& mat1, Matrix<T>& mat2) {

    int r1 = mat1.rows, c1 = mat1.cols;
    int r2 = mat2.rows, c2 = mat2.cols;

    T** m1 = mat1.matrix;
    T** m2 = mat2.matrix;

    Matrix<T> res(r1, c1);

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

template <typename T>
Matrix<T> operator-(Matrix<T>& mat1, Matrix<T>& mat2) {

    int r1 = mat1.rows, c1 = mat1.cols;
    int r2 = mat2.rows, c2 = mat2.cols;

    T** m1 = mat1.matrix;
    T** m2 = mat2.matrix;

    Matrix<T> res(r1, c1);

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

template <typename T>
Matrix<T> operator*(Matrix<T>& mat1, Matrix<T>& mat2) {

    int r1 = mat1.rows, c1 = mat1.cols;
    int r2 = mat2.rows, c2 = mat2.cols;

    T** m1 = mat1.matrix;
    T** m2 = mat2.matrix;

    Matrix<T> res(r1, c2);

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