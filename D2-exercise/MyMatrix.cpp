#include <iostream>
#include <cstdlib>
#include "MyMatrix.h"
#include "cblas.h"

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
  cout << "\tCalling copy constructor; deep copy\n";

  row_ = obj.get_row();
  col_ = obj.get_col();
  matrix = new double[row_ * col_];
  int n_row = row_;
  int n_col = col_;

  for(int i = 0; i < n_row; i++)
    for(int j = 0; j < n_col; j++)
      matrix[j + i*n_col] = obj.matrix[j + i* n_col];  
}

// getting number of rows
int Matrix::get_row() const{
  return row_;
}

// getting number of columns
int Matrix::get_col() const{
  return col_;
}

// initialize
void Matrix::initialize(string type){
  int n_row = get_row();
  int n_col = get_col();
  if(type == "generic"){
    cout << "\tInitializing matrix to growing number";
    for(int i = 0; i < n_row; i++)
      for(int j = 0; j < n_col; j++)
	  matrix[j + i*n_col] = j + i*n_col;
  }
  else{
    cout << "\tInitializing matrix to zero\n";
    for(int i = 0; i < n_row; i++)
      for(int j = 0; j < n_col; j++)
	matrix[j + i*n_col] = 0.;
  }
}

void Matrix::self_print(){
  int n_row = get_row();
  int n_col = get_col();
  cout << "\n\n";
  for(int i = 0; i < n_row; i++){
    for(int j = 0; j < n_col; j++){
      cout << "\t" << matrix[j + i * n_col];
    }
    cout << "\n";
  }
  cout << "\n";
}

Matrix &Matrix::operator=(const Matrix& ob){
  cout << "\tInvoked assignment operator\n";

  int ob_row = ob.get_row();
  int ob_col = ob.get_col();

  if (this == &ob){
    cout << "\tWarning! You write something like a = a\n";
    return *this;
  }
  else if(row_ * col_ != ob_row * ob_col){
    delete [] matrix;
    matrix = new double[ob_row * ob_col];
    row_ = ob_row;
    col_ = ob_col;
  }
  else{
    row_ = ob_row;
    col_ = ob_col;
  }

  for(int i = 0; i < ob_row; i++)
    for(int j = 0; j < ob_col; j++)
      matrix[j + i * ob_col] = ob.matrix[j + i*ob_col];

  return *this;
}

Matrix Matrix::operator*(const Matrix& ob) const{
  // matrix need to store multiplication

  if(col_ != ob.get_row()){
    Matrix temp(1, 1);
    cout << "\tCan't perform the product; n_col(a) != n_row(b)\n";
    return temp;
  }
  int n_col_b = ob.get_col();
  Matrix temp(row_, n_col_b);

  double tmp_sum = 0.;
  
  for(int i = 0; i < row_; i++){
    for(int j = 0; j < n_col_b; j++){
      for(int k = 0; k < col_; k++){
	tmp_sum += matrix[i*col_ + k] * ob.matrix[k * n_col_b + j];
      }
      temp.matrix[i*n_col_b + j] = tmp_sum;
      tmp_sum = 0;
    }
  }  
  return temp;
}

double& Matrix::operator()(const int i, const int j){
  if(i < 0 || j < 0 || i > row_ || j > col_){
    cout << "\tIndex out of bounds\n\tExit\n";
    exit(EXIT_FAILURE);
    return matrix[j + i*col_];
  }
  return matrix[j + i*col_];
}
