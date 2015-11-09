#include <iostream>
#include <cstdlib>
#include "MyMatrix.h"
#include "MySquareMatrix.h"

using namespace std;

template<typename MyType>
SquareMatrix<MyType>::SquareMatrix(int a) : Matrix<MyType>(a, a){
#ifdef DEBUG
  cout << "\tInvoked SquareMatrix Constructor\n";
#endif
}

template<typename MyType>
SquareMatrix<MyType>::~SquareMatrix(){
#ifdef DEBUG
  cout << "\tInvoked SquareMatrix Destructor\n";
#endif  
}

template<typename MyType>
SquareMatrix<MyType>::SquareMatrix(const SquareMatrix& obj) : Matrix<MyType>(obj) {
#ifdef DEBUG
  cout << "\tInvoked SquareMatrix Copy Constructor\n";
#endif
}

template<typename MyType>
SquareMatrix<MyType>::SquareMatrix(const Matrix<MyType>& obj) : Matrix<MyType>(obj) {
#ifdef DEBUG
  cout << "\tInvoked the second SquareMatrix Copy Constructor\n";
#endif
}

template<typename MyType>
void SquareMatrix<MyType>::initialize(string type){
  int N = this -> get_row();
  int i_tmp;

  if(type == "generic"){
#ifdef DEBUG
    cout << "\tInitializing matrix to growing number\n";
#endif
    for(int i = 0; i < N; i++){
      i_tmp = i*N;
      for(int j = 0; j < N; j++)
	this -> matrix[j + i_tmp] = j + i_tmp;
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
	  this -> matrix[j + i_tmp] = 1.;
        else
	  this -> matrix[j + i_tmp] = 0.;
    }
  }
  else{
#ifdef DEBUG
    cout << "\tInitializing matrix to zero\n";
#endif
    for(int i = 0; i < N * N; i++)
      this -> matrix[i] = 0.;
  }
}

template<typename MyType>
MyType SquareMatrix<MyType>::trace(){

  int N = this -> get_row();
  double tr = 0.;

  for(int j = 0; j < N * N; j += N + 1)
    tr += this -> matrix[j];
  return tr;
}

template class SquareMatrix<double>;
template class SquareMatrix<float>;
template class SquareMatrix<int>;
