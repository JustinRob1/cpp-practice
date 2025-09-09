// --------------------------------------------------
//   Name: Justin Robertson
//   SID: 1702786
//   CCID: jtrober1
//   CMPUT 275, Winter 2022
//
//   Weekly Exercise #5: Matrix Class 
// --------------------------------------------------

#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <cstring>
#include <iostream>
using namespace std;

class Matrix {
public:
  // Constructor that initializes all elements to init
  Matrix(size_t num_rows, size_t num_columns, float init);

  // Constructor that initializes all elements using the data stored
  // in arr_ptr
  Matrix(size_t num_rows, size_t num_columns, float * arr_ptr);
  
  // Destructor
  ~Matrix();

  // copy constructor
  Matrix(const Matrix& copy);

  // addition operator overload to add two matrices
  Matrix operator+(const Matrix& rhs);

  // subtraction operator overload to subtract two matrcies
  Matrix operator-(const Matrix& rhs);

  // unary negation operator to negate a matrix
  Matrix operator-();

  // multiplication operator overload to multiple two matrices
  Matrix operator*(const Matrix& rhs);

  // Matrix tranposition to tranpose a matrix
  Matrix transpose();

  // Insertion Operator
  friend ostream& operator<<(ostream& out, const Matrix& mat);
  // Extraction Operator
  friend istream& operator>>(istream& in, Matrix& mat);

  // Const and non const version of bracket operator 
  float* operator[](int index);
  const float* operator[](int index) const;

private:
	// Number of rows
  size_t rows;
  // Number of columns 
  size_t cols;
  // 2D Matrix stored on the heap
  float **matrix;
};



#endif
