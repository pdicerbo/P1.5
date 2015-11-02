#ifndef MY_SQUARE_MATRIX_HEADER
#define MY_SQUARE_MATRIX_HEADER
#include "MyMatrix.h"

class SquareMatrix : public Matrix
{
  
 public:
  SquareMatrix(int);
  virtual ~SquareMatrix();
  SquareMatrix(const SquareMatrix&);
  SquareMatrix(const Matrix&);
  virtual void initialize(std::string);

 protected:
  SquareMatrix();
};
#endif
