#include "MyMatrix.h"
#include "MySquareMatrix.h"
#include "../test.h"

using namespace std;

template <typename T>
void run_test()
{
  Matrix<T> a(4,3);

  a.non_zero_init();
  a.print_to_file(output_file);

  SquareMatrix<T> b(5);

  b.non_zero_init();
  b.print_to_file(output_file);
  
};

int main()
{
  //run_test();
  run_test<int>();

  return 0;
}
