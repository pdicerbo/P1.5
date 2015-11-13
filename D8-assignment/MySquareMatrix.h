#ifndef MY_SQUARE_MATRIX_HEADER
#define MY_SQUARE_MATRIX_HEADER
#include "MyMatrix.h"

template <typename MyType>
class SquareMatrix : public Matrix<MyType>
{
  
 public:
  SquareMatrix(int);
  ~SquareMatrix();
  SquareMatrix(const SquareMatrix&);
  SquareMatrix(const Matrix<MyType>&);
  void initialize(std::string);
  MyType trace();

 protected:
  SquareMatrix();
};
#endif
