#ifndef MYMATRIX_HEADER
#define MYMATRIX_HEADER

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
  
 protected:
  Matrix();
};
#endif