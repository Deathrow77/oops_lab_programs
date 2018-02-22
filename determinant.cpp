#include <bits/stdc++.h>

using namespace std;

class Matrix {

    int size;
    int** matrix;
    int det;

    // Creates the cofactor matrix 'dest' of size 'n' from the
    // matrix 'src' without the row 'p' and column 'q'
    void getCofactor(int **src, int **dest, int p, int q, int n) {
        int i = 0, j = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (row != p && col != q) {
                    dest[i][j++] = src[row][col];
                    if (j == n - 1) {
                        j = 0;
                        i++;
                    }
                }
            }
        }
    }

    // Recursive function to calculate the determinant
    int determinant(int **m, int n) {
        int D = 0;

        // Base case: When size of matrix is 1
        if (n == 1)
            return m[0][0];

        int sign = 1;

        // Declare the temporary matrix to hold the cofactors
        int **temp = new int*[n];
        for (int i = 0 ; i < n ; ++i) {
            temp[i] = new int[n];
        }

        for (int f = 0; f < n; ++f) {
            // Get the cofactors of m[0][f] and store in temp
            getCofactor(m, temp, 0, f, n);
            D += sign * m[0][f] * determinant(temp, n-1);
            sign = -sign;
        }

        // Free the dynamically allocated memory for cofactor matrix
        for (int i = 0; i < n; ++i) {
            delete[] temp[i];   
        }
        delete[] temp;

        return D;
    }

public:

    Matrix(int s) {
        size = s;
        matrix = new int*[size];
        for (int i = 0 ; i < size ; i++) {
            matrix[i] = new int[size];
        }
    }

    void setMatrix() {
        for (int i = 0 ; i < size ; ++i) {
         cout << "Enter values for row " << i+1 << ": ";
         for (int j = 0 ; j < size ; ++j) {
             cin >> matrix[i][j];
         }
        }
    }

    void printMatrix() {
        for (int i = 0 ; i < size ; ++i) {
            for (int j = 0 ; j < size ; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    int getDeterminant() {
        return determinant(matrix, size);
    }
};

main(void) {
    
    int size;
    cout << "Enter the size of matrix: ";
    cin >> size;

    Matrix m(size);
    m.setMatrix();

    cout << "You entered the matrix:" << endl;
    m.printMatrix();

    cout << "The determinant of the matrix is " << m.getDeterminant() << endl;

    return 0;
}