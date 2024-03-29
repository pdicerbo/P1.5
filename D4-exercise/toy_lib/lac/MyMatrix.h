#ifndef MYMATRIX_HEADER
#define MYMATRIX_HEADER

#include <fstream>

template <typename MyType>
class Matrix
{
 private:
  int row_, col_;

 public:
  MyType* matrix;
  int get_row() const;
  int get_col() const;
  Matrix(int, int);
  virtual ~Matrix();
  Matrix(const Matrix&);
  void initialize(std::string);
  void self_print();
  virtual MyType trace();
  Matrix& operator=(const Matrix&);
  Matrix operator*(const Matrix&) const;
  MyType& operator()(const int, const int);
  MyType* operator[](const int);
  Matrix& operator*=(const Matrix&);
  void print_to_file(std::ofstream &) const;
  void non_zero_init();
 protected:
  Matrix();
};
#endif
