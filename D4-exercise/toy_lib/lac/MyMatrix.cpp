#include <iostream>
#include <cstdlib>
#include "MyMatrix.h"

#ifdef USEBLAS
#include "cblas.h"
#endif

using namespace std;

// default constructor
template<typename MyType>
Matrix<MyType>::Matrix(){
#ifdef DEBUG
  cout << "\tCalling default Matrix constructor\n";
#endif
}

// custom constructor
template<typename MyType>
Matrix<MyType>::Matrix(int a, int b){
#ifdef DEBUG
  cout << "\tCalling custom Matrix constructor\n";
#endif
  row_ = a;
  col_ = b;
  matrix = new double[a * b];
}

// destructor
template<typename MyType>
Matrix<MyType>::~Matrix(){
#ifdef DEBUG
  cout << "\tCalling Matrix destructor\n";
#endif
  delete [] matrix;
}

// copy constructor
template<typename MyType>
Matrix<MyType>::Matrix(const Matrix &obj){
#ifdef DEBUG
  cout << "\tCalling copy constructor; deep copy\n";
#endif
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
template<typename MyType>
int Matrix<MyType>::get_row() const{
  return row_;
}

// getting number of columns
template<typename MyType>
int Matrix<MyType>::get_col() const{
  return col_;
}

// initialize
template<typename MyType>
void Matrix<MyType>::initialize(string type){
  int n_row = get_row();
  int n_col = get_col();
  if(type == "generic"){
#ifdef DEBUG
    cout << "\tInitializing matrix to growing number";
#endif
    for(int i = 0; i < n_row; i++)
      for(int j = 0; j < n_col; j++)
	  matrix[j + i*n_col] = j + i*n_col;
  }
  else{
#ifdef DEBUG
    cout << "\tInitializing matrix to zero\n";
#endif
    for(int i = 0; i < n_row; i++)
      for(int j = 0; j < n_col; j++)
	matrix[j + i*n_col] = 0.;
  }
}

template<typename MyType>
void Matrix<MyType>::self_print(){
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

template<typename MyType>
Matrix<MyType>& Matrix<MyType>::operator=(const Matrix& ob){
#ifdef DEBUG
  cout << "\tInvoked assignment operator\n";
#endif
  int ob_row = ob.get_row();
  int ob_col = ob.get_col();

  if (this == &ob){
    cout << "\tWarning! You wrote something like a = a\n";
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

template<typename MyType>
Matrix<MyType> Matrix<MyType>::operator*(const Matrix& ob) const{

  if(col_ != ob.get_row()){
    Matrix<MyType> temp(1, 1);
    cout << "\tCan't perform the product; n_col(a) != n_row(b)\n";
    return temp;
  }
  int n_col_b = ob.get_col();

  // matrix needed to store multiplication
  Matrix<MyType> temp(row_, n_col_b);

#ifdef USEBLAS
  cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, row_, n_col_b, col_, 1., matrix, col_, ob.matrix, n_col_b, 0., temp.matrix, n_col_b);
#else
  double tmp_sum = 0.;
  int i_tmp, i_sec;
  
  for(int i = 0; i < row_; i++){
    i_tmp = i * col_;
    i_sec = i * n_col_b;
    for(int j = 0; j < n_col_b; j++){
      for(int k = 0; k < col_; k++){
  	tmp_sum += matrix[i_tmp + k] * ob.matrix[k * n_col_b + j];
      }
      temp.matrix[i_sec + j] = tmp_sum;
      tmp_sum = 0;
    }
  }
#endif
  return temp;
}

template<typename MyType>
MyType& Matrix<MyType>::operator()(const int i, const int j){
  if(i < 0 || j < 0 || i > row_ || j > col_){
    cout << "\tIndex out of bounds\n\tExit\n";
    exit(EXIT_FAILURE);
    return matrix[j + i*col_];
  }
  return matrix[j + i*col_];
}

template<typename MyType>
MyType* Matrix<MyType>::operator[](int i){
  if(i < 0 || i > row_){
    cout << "\tIndex out of bounds\n\tExit\n";
    exit(EXIT_FAILURE);
    return matrix;
  }
  return matrix + i*col_;  
}

template<typename MyType>
MyType Matrix<MyType>::trace(){
  cout << "\tWarning! Generic matrix can't call trace() method\n";
  return 0;
}