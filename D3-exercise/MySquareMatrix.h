#ifndef MY_SQUARE_MATRIX_HEADER
#define MY_SQUARE_MATRIX_HEADER
#include "MyMatrix.h"

class SquareMatrix : public Matrix
{
  
 public:
  SquareMatrix(int);
  ~SquareMatrix();
  SquareMatrix(const SquareMatrix&);
  SquareMatrix(const Matrix&);
  void initialize(std::string);
  double trace();

 protected:
  SquareMatrix();
};
#endif
