#include "MyMatrix.h"
#include "MySquareMatrix.h"
#include <vector>

#include <typeinfo>

#include <boost/timer.hpp>

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

using namespace std;
using namespace boost::numeric::ublas;

template<class T>
class BoostMatrix
{
public:
  BoostMatrix(unsigned int m,unsigned int n) : mat(m,n)
  {};
  
  BoostMatrix(const matrix<T> &in) : mat(in)
  {};
  
  void non_zero_init() {
    
        for (unsigned int i=0; i<mat.size1(); i++)
	  for (unsigned int j=0; j<mat.size2(); j++)
	    mat(i,j)=i*mat.size1()+j+1.;
  };
  
  void print()
  {
    cout << mat << endl;
  };
  
  matrix<T> & get_boost_matrix()
  {
    return mat;
  };
  
  const BoostMatrix<T> operator*(BoostMatrix<T>& B) const
  {
    const auto b = B.get_boost_matrix();
    auto c = prod(mat, b);
    
    return BoostMatrix<T>( c );
  };
  
  
private:
  matrix<T> mat;
};

template<class M>
double run_test(const int m, const int k, const int l)
{
  M matrix1(m, k), matrix2(k, l), res(m, l);
  matrix1.non_zero_init();
  matrix2.non_zero_init();

  boost::timer t;
  res = matrix1 * matrix2;
  return t.elapsed();
};

int main()
{

  Matrix<double> a(3,4);
  SquareMatrix<double> b(4);

  a.initialize("generic");
  b.initialize("generic");

  a.self_print();

  b.self_print();

  std::vector< Matrix<double>* > vec;
  vec.push_back(&a);
  vec.push_back(&b);

  std::vector<Matrix<double>*>::iterator MyIt;

  for(MyIt = vec.begin(); MyIt != vec.end(); MyIt++)
    cout << (*MyIt) -> trace() << endl;

  // cout << "boost matrix time = " << run_test<BoostMatrix<float>>(800,600,500) << endl;
  // cout << "in house matrix time = " << run_test<Matrix<float>>(800,600,500) << endl;
  return 0;
}
