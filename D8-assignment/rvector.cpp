#include <iostream>
#include <cmath>
#include "rvector.h"
#include "lvector.h"

using namespace std;

// custom rvector constructor
template<typename T>
rvector<T>::rvector(int a) : Matrix<T>(a, 1){
#ifdef DEBUG
  cout << "\tCalling custom rvector constructor\n";
#endif
}

// rvector distructor
template<typename T>
rvector<T>::~rvector(){
#ifdef DEBUG
  cout << "\tCalling rvector distructor\n";
#endif
}

// rvector custom copy constructor
template<typename T>
rvector<T>::rvector(const lvector<T>& obj) : Matrix<T>(obj){
#ifdef DEBUG
  cout << "\n\tCalling custom rvector copy constructor\n";
#endif
  this -> set_row(obj.get_col());
  this -> set_col(1);
}

template<typename T>
rvector<T>& rvector<T>::operator=(const lvector<T>& obj){
#ifdef DEBUG
  cout << "\n\tCalling custom assignment operator\n";
#endif

  int nr = obj.get_col();
  this -> set_row(nr);
  this -> set_col(1);

  for(int i = 0; i < nr; i++)
    this -> matrix[i] = obj.matrix[i];
  return *this;
}

// norm function
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

// normalize function
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
