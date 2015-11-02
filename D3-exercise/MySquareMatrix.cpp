#include <iostream>
#include <cstdlib>
#include "MyMatrix.h"
#include "MySquareMatrix.h"

using namespace std;

SquareMatrix::SquareMatrix(int a) : Matrix(a, a){

  cout << "\tInvoked SquareMatrix Constructor\n";

}

SquareMatrix::~SquareMatrix(){

  cout << "\tInvoked SquareMatrix Destructor\n";
  
}

SquareMatrix::SquareMatrix(const SquareMatrix& obj) : Matrix(obj) {

  cout << "\tInvoked SquareMatrix Copy Constructor\n";

}

SquareMatrix::SquareMatrix(const Matrix& obj) : Matrix(obj) {

  cout << "\tInvoked the second SquareMatrix Copy Constructor\n";

}

void SquareMatrix::initialize(string type){
  int N = get_row();
  int i_tmp;

  if(type == "generic"){
    cout << "\tInitializing matrix to growing number\n";
    for(int i = 0; i < N; i++){
      i_tmp = i*N;
      for(int j = 0; j < N; j++)
	matrix[j + i_tmp] = j + i_tmp;
    }
  }
  else if(type == "identity"){
    cout << "\tInitializing matrix to Identity\n";
    for(int i = 0; i < N; i++){
      i_tmp = i*N;
      for(int j = 0; j < N; j++)
	if(i == j)
	  matrix[j + i_tmp] = 1.;
        else
	  matrix[j + i_tmp] = 0.;
    }
  }
  else{
    cout << "\tInitializing matrix to zero\n";
    for(int i = 0; i < N * N; i++)
      matrix[i] = 0.;
  }
}

double SquareMatrix::trace(){

  int N = get_row();
  double tr = 0.;

  for(int j = 0; j < N * N; j += N + 1)
    tr += matrix[j];
  return tr;
}
