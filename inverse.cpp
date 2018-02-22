#include <bits/stdc++.h>

using namespace std;

class Matrix {

	int size;
	int** matrix;
	int** adj;
	float** inv;

    // Creates the cofactor matrix 'dest' of size 'n' from the
    // matrix 'src' without the row 'p' and column 'q'
    void getCofactor(int **src, int **dest, int p, int q, int n) {
        int i = 0, j = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (row != p && col != q) {
                    dest[i][j++] = src[row][col];
                    // If the row is filled, reset the
                    // column and move to the next row
                    if (j == n - 1) {
                        j = 0;
                        i++;
                    }
                }
            }
        }
    }

    // Function to check if inverse can be obtained, and obtain it, if
    // possible. It calls the determinant and the adjoint functions.
	bool inverse() {

		// Calculate the determinant of the matrix
	    int det = determinant(matrix, size);

	    // Singular matrix, inverse cannot be obtained. Return false.
	    if (det == 0) {
	        cout << "Singular matrix, can't find its inverse" << endl;
	        return false;
	    }

		// Obtain the adjoint of the matrix
	    adjoint();

	    // Divide the adjoint with the determinant to get the inverse
	    for (int i=0; i<size; i++) {
	        for (int j=0; j<size; j++)
	            inv[i][j] = adj[i][j]/float(det);
	    }

	    return true;
	}

public:
	
	// Constructor
	Matrix(int s) {
		size = s;
		matrix = new int*[size];
		for (int i = 0 ; i < size ; i++) {
			matrix[i] = new int[size];
		}
		adj = new int*[size];
		for (int i = 0 ; i < size ; i++) {
			adj[i] = new int[size];
		}
		inv = new float*[size];
		for (int i = 0 ; i < size ; i++) {
			inv[i] = new float[size];
		}
	}

	// Fill the values of the matrix cells
	void setMatrix() {
		for (int i = 0 ; i < size ; ++i) {
			cout << "Enter values for row " << i+1 << ": ";
			for (int j = 0 ; j < size ; ++j) {
				cin >> matrix[i][j];
			}
		}
	}

	// Find the adjoint of the matrix
	void adjoint() {
	    if (size == 1) {
	        adj[0][0] = 1;
	        return;
	    }

	    int sign = 1;
	    int **temp = new int*[size];
		for (int i = 0 ; i < size ; i++) {
			temp[i] = new int[size];
		}

	    for (int i=0; i<size; i++) {
	        for (int j=0; j<size; j++) {
	            getCofactor(matrix, temp, i, j, size);
	            sign = ((i+j)%2==0)? 1: -1;
	            adj[j][i] = (sign)*(determinant(temp, size-1));
	        }
	    }

	    for (int i = 0; i < size; ++i) {
	        delete[] temp[i];   
	    }
	    delete[] temp;
	}

	// Recursive function to calculate the determinant
	int determinant(int **m, int n) {
	    int D = 0;

	    // Base case: When size of matrix is 1
	    if (n == 1)
	        return m[0][0];

	    int sign = 1;

	    // Declare the temporary matrix to hold the cofactors
	    int **temp = new int*[size];
		for (int i = 0 ; i < size ; ++i) {
			temp[i] = new int[size];
		}

	    for (int f = 0; f < n; ++f) {
	    	// Get the cofactors of m[0][f] and store in temp
	        getCofactor(m, temp, 0, f, n);
	        D += sign * m[0][f] * determinant(temp, n-1);
	        sign = -sign;
	    }

	    // Free the dynamically allocated memory for cofactor matrix
	    for (int i = 0; i < size; ++i) {
	        delete[] temp[i];   
	    }
	    delete[] temp;

	    return D;
	}

	void printMatrix() {
		for (int i = 0 ; i < size ; ++i) {
			for (int j = 0 ; j < size ; ++j) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}

	void printInverse() {
		if (inverse()) {
			for (int i = 0 ; i < size ; ++i) {
				for (int j = 0 ; j < size ; ++j) {
					if (j == 0)
						cout  << setw(4) << fixed << setprecision(1) << inv[i][j];
					else
						cout  << setw(5) << fixed << setprecision(1) << inv[i][j];
				}
				cout << endl;
			}
		}
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

	cout << "The inverse of the matrix is:" << endl;
	m.printInverse();

	return 0;
}