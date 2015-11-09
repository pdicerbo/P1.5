#include "MyMatrix.h"
#include "MySquareMatrix.h"

using namespace std;

template<typename MyType>
Matrix<MyType>* CreateMat(const int a, const int b){
  if(a != b)
    return new Matrix<MyType>(a, b);
  else
    return new SquareMatrix<MyType>(a);
}

template Matrix<double>* CreateMat<double>(const int, const int);
