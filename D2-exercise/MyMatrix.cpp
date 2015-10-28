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


