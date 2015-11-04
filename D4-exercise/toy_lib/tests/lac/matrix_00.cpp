//#include "matrix.h"
#include "MyMatrix.h"
#include "../test.h"


using namespace std;

template<typename T>
void run_test()
{
  Matrix<T> a(4,3);
    
  a.print_to_file(output_file);
  a.non_zero_init();
  a.print_to_file(output_file);
};

int main()
{
  //run_test();
    run_test<double>();
    run_test<float>();
    return 0;
}
