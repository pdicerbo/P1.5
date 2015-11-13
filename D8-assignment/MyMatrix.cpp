#include <iostream>
#include <cstdlib>
#include <fstream>
#include "lapacke.h"
#include "MyMatrix.h"
#include "lvector.h"

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
  matrix = new MyType[a * b];
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
  matrix = new MyType[row_ * col_];
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

template<typename MyType>
void Matrix<MyType>::set_row(int a){
  row_ = a;
}

template<typename MyType>
void Matrix<MyType>::set_col(int a){
  col_ = a;
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

// print matrix
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

// assignment operator
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
    matrix = new MyType[ob_row * ob_col];
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
    cout << "\tCan't perform the product; n_col(a) != n_row(b)\n\tExit!\n";
    exit(0);
    return *this;
  }

  // matrix needed to store multiplication
  Matrix<MyType> temp = *this;

  temp *= ob;
  
  return temp;
}

template<typename MyType>
Matrix<MyType>& Matrix<MyType>::operator*=(const Matrix& mat){

  if(col_ != mat.get_row()){
    cout << "\tCan't perform the product; n_col(a) != n_row(b)\n\tExit!\n";
    exit(0);
    return *this;
  }
  
  Matrix<MyType> temp(row_, mat.get_col());
  MyType tmp_sum = 0.;
  int i_tmp, i_sec;
  int n_col_b = mat.get_col();
  
  for(int i = 0; i < row_; i++){
    i_tmp = i * col_;
    i_sec = i * n_col_b;
    for(int j = 0; j < n_col_b; j++){
      for(int k = 0; k < col_; k++)
  	tmp_sum += matrix[i_tmp + k] * mat.matrix[k * n_col_b + j];
      
      temp.matrix[i_sec + j] = tmp_sum;
      tmp_sum = 0;
    }
  }
  *this = temp;
  return *this;
}

template<>
Matrix<double>& Matrix<double>::operator*=(const Matrix& mat){

  if(col_ != mat.get_row()){
    cout << "\tCan't perform the product; n_col(a) != n_row(b)\n\tExit!\n";
    exit(0);
    return *this;
  }

  Matrix<double> temp(row_, mat.get_col());
  int n_col_b = mat.get_col();

#ifdef USEBLAS
  cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, row_, n_col_b, col_, 1., matrix, col_, mat.matrix, n_col_b, 0., temp.matrix, n_col_b);
#else
  
  double tmp_sum = 0.;
  int i_tmp, i_sec;
  
  for(int i = 0; i < row_; i++){
    i_tmp = i * col_;
    i_sec = i * n_col_b;
    for(int j = 0; j < n_col_b; j++){
      for(int k = 0; k < col_; k++)
  	tmp_sum += matrix[i_tmp + k] * mat.matrix[k * n_col_b + j];
      
      temp.matrix[i_sec + j] = tmp_sum;
      tmp_sum = 0;
    }
  }
#endif

  *this = temp;
  return *this;
}

template<>
Matrix<float>& Matrix<float>::operator*=(const Matrix& mat){

  if(col_ != mat.get_row()){
    cout << "\tCan't perform the product; n_col(a) != n_row(b)\n\tExit!\n";
    exit(0);
    return *this;
  }

  Matrix<float> temp(row_, mat.get_col());
  int n_col_b = mat.get_col();

#ifdef USEBLAS
  cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, row_, n_col_b, col_, 1., matrix, col_, mat.matrix, n_col_b, 0., temp.matrix, n_col_b);
#else

  float tmp_sum = 0.;
  int i_tmp, i_sec;
  
  for(int i = 0; i < row_; i++){
    i_tmp = i * col_;
    i_sec = i * n_col_b;
    for(int j = 0; j < n_col_b; j++){
      for(int k = 0; k < col_; k++)
  	tmp_sum += matrix[i_tmp + k] * mat.matrix[k * n_col_b + j];
      
      temp.matrix[i_sec + j] = tmp_sum;
      tmp_sum = 0;
    }
  }

#endif
  *this = temp;
  return *this;
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
  if(row_ == col_){
    MyType tr = 0.;
    for(int i = 0; i < row_ * col_; i += col_ + 1)
      tr += matrix[i];
    return tr;
  }
  else
    cout << "\tWarning! Generic matrix can't call trace() method\n";
  return 0;
}

template<typename MyType>
Matrix<MyType>::operator MyType() const{
#ifdef DEBUG
  cout << "\n\tCalling cast operator\n";
#endif
  
  if(row_ != 1 && col_ != 1)
    cout << "\n\tWarning! You try to cast matrix with shape different from (1,1)\n\tReturn mat[0, 0]\n";

  return matrix[0];
}

template<typename MyType>
void Matrix<MyType>::print_to_file(ofstream &output) const{

  int nrow = get_row();
  int ncol = get_col();
  int i_tmp;
  
  for(int i = 0; i < nrow; i++){

    i_tmp = i * ncol;

    for(int j = 0; j < ncol; j++)
      output << " " << matrix[i_tmp + j]; // << "\t";

    output << "\n";
  }
}

template<typename MyType>
void Matrix<MyType>::non_zero_init(){

  int nrow = get_row();
  int ncol = get_col();

  for(int i = 0; i < nrow; i++)
    for(int j = 0; j < ncol; j++)
      matrix[i*ncol + j] = i * ncol + j + 1.;
}

template<typename MyType>
lvector<MyType> Matrix<MyType>::eigenvalues() const{

  lvector<MyType> ret(1);
  
  cout << "\n\tNot able to calculate eigenvalues of this data type\n";
  
  return ret;
}

template<>
lvector<double> Matrix<double>::eigenvalues() const{
  Matrix<double> temp = *this;
  int n = temp.get_row(), info;
  lvector<double> res(n);

  info = LAPACKE_dsyev(LAPACK_ROW_MAJOR, 'N', 'U', n, temp.matrix, n, res.matrix);
  if(info > 0)
    cout << "\n\tError in eigenvalues calculation\n";

  return res;
}

template<>
lvector<float> Matrix<float>::eigenvalues() const{
  Matrix<float> temp = *this;
  int n = temp.get_row(), info;
  lvector<float> res(n);

  info = LAPACKE_ssyev(LAPACK_ROW_MAJOR, 'N', 'U', n, temp.matrix, n, res.matrix);
  if(info > 0)
    cout << "\n\tError in eigenvalues calculation\n";

  return res;
}

template<typename MyType>
Matrix<MyType> Matrix<MyType>::eigenvectors() const{

  cout << "\n\tNot able to calculate eigenvectors of this data type\n";

  return *this;
}

template<>
Matrix<double> Matrix<double>::eigenvectors() const{
  Matrix<double> temp = *this;
  int n = temp.get_row(), info;
  double* res = new double[n];

  info = LAPACKE_dsyev(LAPACK_ROW_MAJOR, 'V', 'U', n, temp.matrix, n, res);
  if(info > 0)
    cout << "\n\tError in eigenvalues calculation\n";

  delete [] res;

  return temp;
}

template<>
Matrix<float> Matrix<float>::eigenvectors() const{
  Matrix<float> temp = *this;
  int n = temp.get_row(), info;
  float* res = new float[n];

  info = LAPACKE_ssyev(LAPACK_ROW_MAJOR, 'V', 'U', n, temp.matrix, n, res);
  if(info > 0)
    cout << "\n\tError in eigenvalues calculation\n";

  delete [] res;

  return temp;
}

template class Matrix<double>;
template class Matrix<float>;
template class Matrix<int>;
