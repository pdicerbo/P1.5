#include <iostream>
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

template class rvector<double>;
template class rvector<float>;
template class rvector<int>;
