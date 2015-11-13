#include <iostream>
#include <cmath>
#include "lvector.h"


using namespace std;

template<typename T>
lvector<T>::lvector(int a) : Matrix<T>(1, a){
#ifdef DEBUG
  cout << "\tCalling custom lvector constructor\n";
#endif
}

template<typename T>
lvector<T>::~lvector(){
#ifdef DEBUG
  cout << "\tCalling lvector distructor\n";
#endif
}

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
