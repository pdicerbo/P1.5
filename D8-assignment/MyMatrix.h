#ifndef MYMATRIX_HEADER
#define MYMATRIX_HEADER
#include <fstream>

template <typename MyType> class lvector;

template <typename MyType>
class Matrix
{
 private:
  int row_, col_;

 public:
  MyType* matrix;
  int get_row() const;
  int get_col() const;
  void set_row(int);
  void set_col(int);
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
  operator MyType() const;
  void print_to_file(std::ofstream &) const;
  void non_zero_init();
  lvector<MyType> eigenvalues() const;
  Matrix eigenvectors() const;
  MyType determinant() const;
  Matrix transpose();
 protected:
  Matrix();
};
#endif /* MYMATRIX_HEADER */
