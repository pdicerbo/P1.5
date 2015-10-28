#include <iostream>
#include "MyMatrix.h"

using namespace std;

// default constructor
Matrix::Matrix(){
  cout << "\tCalling default Matrix constructor\n";
}

// custom constructor
Matrix::Matrix(int a, int b){
  cout << "\tCalling custom Matrix constructor\n";
  row_ = a;
  col_ = b;
  matrix = new double[a * b];
}

// destructor
Matrix::~Matrix(){
  cout << "\tCalling Matrix destructor\n";
  delete [] matrix;
}

// copy constructor
Matrix::Matrix(const Matrix &obj){
  cout << "\tCalling copy constructor; shallow copy\n";

  row_ = obj.get_row();
  col_ = obj.get_col();
  matrix = obj.matrix;
}

// getting number of rows
int Matrix::get_row() const{
  return row_;
}

// getting number of columns
int Matrix::get_col() const{
  return col_;
}

