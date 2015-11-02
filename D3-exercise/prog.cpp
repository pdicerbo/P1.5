#include <iostream>
#include "MyMatrix.h"
#include "MySquareMatrix.h"

using namespace std;

int main(int argc, char** argv){
  Matrix a(3, 3);

  a.initialize("generic");
  a.self_print();

  Matrix b(2, 4);
  b.initialize("generic");
  b.self_print();

  b = a;

  b.self_print();
  Matrix c(2,1);

  c = a*b;

  c.self_print();
  c(1, 1) = -1.;
  c.self_print();

  return 0;
}
