#include <iostream>
#include <cmath>
#include "lvector.h"
#include "rvector.h"

using namespace std;

// custom lvector constructor
template<typename T>
lvector<T>::lvector(int a) : Matrix<T>(1, a){
#ifdef DEBUG
  cout << "\tCalling custom lvector constructor\n";
#endif
}

// lvector distructor
template<typename T>
lvector<T>::~lvector(){
#ifdef DEBUG
  cout << "\tCalling lvector distructor\n";
#endif
}

// lvector custom copy constructor
template<typename T>
lvector<T>::lvector(const rvector<T>& obj) : Matrix<T>(obj){
#ifdef DEBUG
  cout << "\n\tCalling custom lvector copy constructor\n";
#endif
  this -> set_row(1);
  this -> set_col(obj.get_row());
}

template<typename T>
lvector<T>& lvector<T>::operator=(const rvector<T>& obj){
#ifdef DEBUG
  cout << "\n\tCalling custom assignment operator\n";
#endif
  Matrix<T>::operator=(obj);
  int nc = obj.get_row();
  this -> set_row(1);
  this -> set_col(nc);

  return *this;
}

template<typename T>
T& lvector<T>::operator()(const int i){
  return Matrix<T>::operator()(0, i);
}

// norm function
template<typename T>
T lvector<T>::norm() const{
  T norm = 0, tmp;
  int n_c = this -> get_col();
  for(int i = 0; i < n_c; i++){
    tmp = this -> matrix[i];
    tmp *= tmp;
    norm += tmp;
  }
  return sqrt(norm);
}

template<typename T>
void lvector<T>::normalize(){
  T norm = this -> norm();
  int n_c = this -> get_col();
  for(int i = 0; i < n_c; i++)
    this -> matrix[i] /= norm;
}


template class lvector<double>;
template class lvector<float>;
template class lvector<int>;
