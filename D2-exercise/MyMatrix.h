#ifndef MYMATRIX_HEADER
#define MYMATRIX_HEADER
class Matrix
{
  int row_, col_;
 public:
  double* matrix;
  int get_row() const;
  int get_col() const;
  Matrix(int, int);
  ~Matrix();
  Matrix(const Matrix&);
  void initialize(std::string);
  void self_print();
  Matrix& operator=(const Matrix&);
  Matrix operator*(const Matrix&) const;
  double& operator()(const int, const int);
 protected:
  Matrix();
};
#endif
