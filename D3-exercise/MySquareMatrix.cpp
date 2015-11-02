#include <iostream>
#include <cstdlib>
#include "MyMatrix.h"
#include "MySquareMatrix.h"

using namespace std;

SquareMatrix::SquareMatrix(int a) : Matrix(a, a){
#ifdef DEBUG
  cout << "\tInvoked SquareMatrix Constructor\n";
#endif
}

SquareMatrix::~SquareMatrix(){
#ifdef DEBUG
  cout << "\tInvoked SquareMatrix Destructor\n";
#endif  
}

SquareMatrix::SquareMatrix(const SquareMatrix& obj) : Matrix(obj) {
#ifdef DEBUG
  cout << "\tInvoked SquareMatrix Copy Constructor\n";
#endif
}

SquareMatrix::SquareMatrix(const Matrix& obj) : Matrix(obj) {
#ifdef DEBUG
  cout << "\tInvoked the second SquareMatrix Copy Constructor\n";
#endif
}

void SquareMatrix::initialize(string type){
  int N = get_row();
  int i_tmp;

  if(type == "generic"){
#ifdef DEBUG
    cout << "\tInitializing matrix to growing number\n";
#endif
    for(int i = 0; i < N; i++){
      i_tmp = i*N;
      for(int j = 0; j < N; j++)
	matrix[j + i_tmp] = j + i_tmp;
    }
  }
  else if(type == "identity"){
#ifdef DEBUG
    cout << "\tInitializing matrix to Identity\n";
#endif
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
#ifdef DEBUG
    cout << "\tInitializing matrix to zero\n";
#endif
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
