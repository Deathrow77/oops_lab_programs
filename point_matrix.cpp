#include <bits/stdc++.h>


class Matrix;

class TwoDPoint {
	int x, y;

public:
	TwoDPoint(int i=0, int j=0) {
		x = i;
		y = j;
	}
	~TwoDPoint() {

	}
	inline int getX() {
		return x;
	}
	inline int getY() {
		return y;
	}
	friend class Matrix;
};

class Matrix {
	int row, col;
	TwoDPoint **matrix;
public:
	// Default constructor
	Matrix(int i=1, int j=1) {
		row = i;
		col = j;
		matrix = new TwoDPoint*[row];
		for (int c=0 ; c<row ; ++c)
			matrix[c] = new TwoDPoint[col];
	}

	//Copy constructor
	Matrix(Matrix& other) {
		row = other.row;
		col = other.col;
		matrix = new TwoDPoint*[row];
		for (int c=0 ; c<row ; ++c) {
			matrix[c] = new TwoDPoint[col];
			for (int d=0 ; d<col ; ++d)
				matrix[c][d] = other.matrix[c][d];
		}
	}

	//Destructor
	~Matrix() {
		for (int c=0 ; c<row ; c++)
			delete[] matrix[c];
		delete[] matrix;
	}

	void setMatrix();
	void printMatrix();
	friend bool checkCollinearity(Matrix& m, int i);
};

void Matrix::setMatrix() {
	for (int i=0; i<row ; ++i) {
		for (int j=0 ; j<col ; ++j) {
			int x, y;
			std::cout << "Enter x and y values for element in row " << i+1;
			std::cout << " and column " << j+1 << ": ";
			std::cin >> x >> y;
			matrix[i][j].x = x;
			matrix[i][j].y = y;
		}
	}
}

void Matrix::printMatrix() {
	for (int i=0; i<row ; ++i) {
		for (int j=0 ; j<col ; ++j)
			std::cout << "(" << matrix[i][j].getX() << ", " << matrix[i][j].getY() << ")" << "\t";
		std::cout << std::endl;
	}
}

bool checkCollinearity(Matrix& m, int i) {
	if (m.col > 2) {
		if (i >= m.row) {
			std::cout << "Value of i is greater than the number of rows" << std::endl;
			exit(1);
		} else {
			int x1 = m.matrix[i][0].getX(), y1 = m.matrix[i][0].getY();
			int x2 = m.matrix[i][1].getX(), y2 = m.matrix[i][1].getY();
			float slope = (float)(y2-y1)/(x2-x1);
			int c = 1;
			for (c ; c<(m.col-1) ; ++c) {
				int x1 = m.matrix[i][c].getX(), y1 = m.matrix[i][c].getY();
				int x2 = m.matrix[i][c+1].getX(), y2 = m.matrix[i][c+1].getY();
				if (slope != (float)(y2-y1)/(x2-x1))
					break;
			}
			return (c == m.col-1);
		}
	} else {
		return true;
	}
}

int main(void) {
	Matrix m1(1, 3);
	m1.setMatrix();
	Matrix m2 = m1;
	std::cout << "Matrix 1:" << std::endl;
	m1.printMatrix();
	std::cout << "Matrix 2:" << std::endl;
	m2.printMatrix();
	int i = 0;
	if (checkCollinearity(m1, i))
		std::cout << "The elements of the " << i << "th row in matrix 1 are collinear" << std::endl;
	else
		std::cout << "The elements of the " << i << "th row matrix 1 are not collinear" << std::endl;
}