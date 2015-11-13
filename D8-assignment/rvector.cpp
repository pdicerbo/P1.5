#include <iostream>
#include <cmath>
#include "rvector.h"

using namespace std;

template<typename T>
rvector<T>::rvector(int a) : Matrix<T>(a, 1){
#ifdef DEBUG
  cout << "\tCalling custom rvector constructor\n";
#endif
}

template<typename T>
rvector<T>::~rvector(){
#ifdef DEBUG
  cout << "\tCalling rvector distructor\n";
#endif
}

template<typename T>
T rvector<T>::norm() const{
  T norm = 0;
  T tmp;
  int n_r = this -> get_row();
  for(int i = 0; i < n_r; i++){
    tmp = this -> matrix[i];
    tmp *= tmp;
    norm += tmp;
  }
  return sqrt(norm);
}

template<typename T>
void rvector<T>::normalize(){
  T norm = this -> norm();
  int n_r = this -> get_row();
  for(int i = 0; i < n_r; i++)
    this -> matrix[i] /= norm;
}

template class rvector<double>;
template class rvector<float>;
template class rvector<int>;
