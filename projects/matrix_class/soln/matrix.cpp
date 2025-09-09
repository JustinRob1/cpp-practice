#include "matrix.h"
#include <iostream>
using namespace std;

/* 
    Descirption: Parameterized constructor, creates an object of class 
    Matrix and initializes all elements of the matrix to init 

    Arguments: num_rows (size_t): The number of rows of the array
    num_columns (size_t): The number of columns of the array
    init (float): The inital value of every element in the array

    Returns: None 
*/
Matrix::Matrix(size_t num_rows, size_t num_columns, float init) {
	rows = num_rows;
	cols = num_columns;
	// Dynamically allocate an array of pointers to the private attribute matrix
	// that represents the 2D array
	matrix = new float*[rows];

	// Iterate the number of rows and set each element to it's own dynamically
	// allocated array of floats
	for (unsigned int i = 0; i < rows; i++) {
		matrix[i] = new float[cols];
	}

	// Iterate rows * cols times and set the [i][j] element in the matrix to init
	for (unsigned int i = 0; i < rows; i++) {
		for (unsigned int j = 0; j < cols; j++) {
			matrix[i][j] = init;
		}
	}
}

/* 
    Descirption: Parameterized constructor that creates an object of class matrix and 
    initializes the elements of the matrix using the data stored in arr_ptr. This array 
    will contain exactly num_rows * num_columns elements 

    Arguments: num_rows (size_t): The number of rows of the array
    num_columns (size_t): The number of columns of the array
    arr_ptr (float *): An array of floats the user wants stored in a matrix 

    Returns: None 
*/
Matrix::Matrix(size_t num_rows, size_t num_columns, float * arr_ptr) {
	rows = num_rows;
	cols = num_columns;
	// Dynamically allocate an array of pointers to the private attribute matrix
	// that represents the 2D array
	matrix = new float*[rows];

	// Iterate the number of rows and set each element to it's own dynamically
	// allocated array of floats
	for (unsigned int i = 0; i < rows; i++) {
		matrix[i] = new float[cols];
	}

	// Iterate rows * cols times and set the [i][j] element in the matrix to
	// the k'th element the the arr_ptr, increment k each time
	int k = 0;
	for (unsigned int i = 0; i < rows; i++) {
		for (unsigned int j = 0; j < cols; j++) {
			matrix[i][j] = arr_ptr[k];
			k++;
		}
	}
}

/* 
    Descirption: Copy constructor, makes a deep copy of an instance of the matrix class

    Arguments: copy (const Matrix&): The matrix object you want to make the copy of

    Returns: None 
*/
Matrix::Matrix(const Matrix& copy) {
	// Set the rows and cols of the copy to the rows and cols of the matrix
	// you want to copy
	rows = copy.rows;
	cols = copy.cols;

	// Dynamically allocate an array of pointers to the private attribute matrix
	// that represents the 2D array
	matrix = new float*[rows];

	// Iterate the number of rows and set each element to it's own dynamically
	// allocated array of floats
	for (unsigned int i = 0; i < rows; i++) {
		matrix[i] = new float[cols];
	}


	// Iterate rows * cols times and set the [i][j] element in the matrix to
	// the k'th element the the arr_ptr, increment k each time
	for (unsigned int i = 0; i < rows; i++) {
		for (unsigned int j = 0; j < cols; j++) {
			matrix[i][j] = copy.matrix[i][j];
		}
	}
}

/* 
    Descirption: Destructor, frees the dynamically allocated memory when an instance of
    this class goes out of scope

    Arguments: None

    Returns: None 
*/
Matrix::~Matrix() {
	// Iterate through all the rows in the matrix and delete each array
	// storing the row
	for (unsigned int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	// Delete the entire matrix
	delete[] matrix;
}

/* 
    Descirption: Addition Operator, creates a new instance of class Matrix and sets
    the [i][j] element of the new matrix object to be the sum of the [i][j] element of 
    this matrix and the [i][j] element of the rhs matrix

    Arguments: rhs (const Matrix&): An object of the class matrix to be added

    Returns: A new instance of the class matrix
*/
Matrix Matrix::operator+(const Matrix& rhs) {
	// Create a new object of class array and set the rows and cols
	// to be this matrix rows and cols. Initalize every value to 0
	Matrix mat(rows, cols, (float) 0);

	// Iterate rows * cols times and set the [i][j] element of the new
	// matrix object to be the sum of the [i][j] element of this matrix
	// and the [i][j] element of the rhs matrix
	for (unsigned int i = 0; i < rows; i++) {
		for (unsigned int j = 0; j < cols; j++) {
			mat.matrix[i][j] = matrix[i][j] + rhs.matrix[i][j];
		}
	}

	return mat;
}

/* 
    Descirption: Subtraction Operator, creates a new instance of class
    Matrix and sets the [i][j] element of the new matrix object to be the
    difference of the [i][j] element of this matrix and the [i][j] element of
    the rhs matrix

    Arguments: rhs (const Matrix&): An object of the class matrix to be subtracted

    Returns: A new instance of the class matrix
*/
Matrix Matrix::operator-(const Matrix& rhs) {
	// Create a new object of class array and set the rows and cols to be 
	// this matrix rows and cols. Initalize every value to 0
	Matrix mat(rows, cols, (float) 0);

	// Iterate rows * cols times and set the [i][j] element of the new
	// matrix object to be the difference of the [i][j]  element of this
	// matrix and the [i][j] element of the rhs matrix
	for (unsigned int i = 0; i < rows; i++) {
		for (unsigned int j = 0; j < cols; j++) {
			mat.matrix[i][j] = matrix[i][j] - rhs.matrix[i][j];
		}
	}

	return mat;
}

/* 
    Descirption: Multiplication Operator, creates a new instance of class Matrix and sets
    the [i][j] element of the new matrix object to be the total sum of the ith row of this matrix
    multipled by the jth column of the rhs matrix. Each element in the ith row of this matrix is multiplied
    with its corresponding element in the jth column of the rhs matrix and the sum of all these products 
    is the [i][j] element in the new matrix object

    Arguments: rhs (const Matrix&): An object of the class matrix to be multipled

    Returns: A new instance of the class matrix
*/
Matrix Matrix::operator*(const Matrix& rhs) {
	// Create a new object of class array and set the rows and cols to be this matrix
	// rows and rhs matrix cols. Initalize every value to 0
	Matrix mat(rows, rhs.cols, (float) 0);

	// Iterate rows * rhs.cols * cols times and add the product of the [i][k] element of 
	// this matrix with the [k][j] element of the rhs matrix to the [i][j] element of the
	// new matrix object
	for (unsigned int i = 0; i < rows; i++) {
		for (unsigned int j = 0; j < rhs.cols; j++) {
			for (unsigned int k = 0; k < cols; k++) {
				mat.matrix[i][j] += (matrix[i][k] * rhs.matrix[k][j]);
			}
		}
	}

	return mat;
}

/* 
    Descirption: Creates a new instance of class Matrix and sets
    the [j][i] element of the new matrix object to be the [i][j] element of this matrix

    Arguments: None

    Returns: A new instance of the class matrix
*/
Matrix Matrix::transpose() {
	// Create a new object of class array and set the rows and cols to be this matrix
	// cols and rows. Initalize every value to 0
	Matrix mat(cols, rows, (float) 0);

	// Iterate rows * cols times and set the [j][i] element of the new 
	// matrix object to be the [i][j] element of this matrixx
	for (unsigned int i = 0; i < rows; i++) {
		for (unsigned int j = 0; j < cols; j++) {
			mat.matrix[j][i] = matrix[i][j];
		}
	}

	return mat;
}

/* 
    Descirption: Negation Operator, creates a new instance of class Matrix and sets
    the [i][j] element of the new matrix object to be the [i][j] element of this matrix 
    with the signed flipped

    Arguments: None

    Returns: A new instance of the class matrix with the sign of each element is flipped
*/
Matrix Matrix::operator-() {
	// Create a new object of class array and set the rows and cols to be this matrix
	// rows and cols. Initalize every value to 0
	Matrix mat(rows, cols, (float) 0);

	// Iterate rows * cols times and set the [i][j] element of the new matrix object to be the 
	// [i][j] element of this matrix with the sign fliiped
	for (unsigned int i = 0; i < rows; i++) {
		for (unsigned int j = 0; j < cols; j++) {
			mat.matrix[i][j] = -1 * matrix[i][j];
		}
	}
	return mat;
}

/* 
    Descirption: Bracket operator, return a row of the matrix as a float pointer

    Arguments: index (const index): The row of the matrix the user wants

    Returns: A row of the matrix as a float pointer
*/
float* Matrix::operator[](int index) {
	return matrix[index];
}

/* 
    Descirption: Const Bracket operator, return a row of the matrix as a float pointer

    Arguments: index (const index): The row of the matrix the user wants

    Returns: A row of the matrix as a const float pointer
*/
const float* Matrix::operator[](int index) const {
	return matrix[index];
}


/* 
    Descirption: Insertion Operator, allows us to print elements of a matrix row by row

    Arguments: out (ostream&): An object of the class ostream that allows the user to print
    the matrix to the standard output stream

    Returns: An object (out) of the class ostream
*/
ostream& operator<<(ostream& out, const Matrix& mat) {
	// Iterate mat.rows * mat.cols times and print out each element of the
	// matrix row by row with a space in between each element 
	for (unsigned int i = 0; i < mat.rows; i++) {
		out << mat.matrix[i][0];
		for (unsigned int j = 1; j < mat.cols; j++) {
			out << " " << mat.matrix[i][j];
		}
		// If the last row has been reach, do not print a new line character
		if (i != mat.rows - 1) {
			out << endl;
		}
	}
	return out;
}

/* 
    Descirption: Extraction Operator, eads mat.rows × matcols space separated elements
	from the input stream and populates elements of the matrix row by row

    Arguments: in (istream&): An object of the class istream that allows the user to read in
    elements from the input stream

    Returns: An object (in) of the class istream
*/
istream& operator>>(istream& in, Matrix& mat) {
	// Iterate mat.rows * mat.cols times and set the [i][j] element
	// of the mat object matrix to the next element read in from standard input
	for (unsigned int i = 0; i < mat.rows; i++) {
		for (unsigned int j = 0; j < mat.cols; j++) {
			in >> mat.matrix[i][j];
		}
	}
	return in;
}