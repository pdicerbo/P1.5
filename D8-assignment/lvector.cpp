#include <iostream>
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

template class lvector<double>;
template class lvector<float>;
template class lvector<int>;
