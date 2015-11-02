#include <iostream>
#include "MyMatrix.h"
#include "MySquareMatrix.h"

using namespace std;

int main(int argc, char** argv){
  Matrix a(3, 3);

  a.initialize("generic");
  a.self_print();

  SquareMatrix b(3);
  b.initialize("identity");
  b.self_print();

  // Matrix c(2,1);

  // c = a*b;
  // c.self_print();

  SquareMatrix d(3);
  d.initialize("generic");

  SquareMatrix res = d*b;
  res.self_print();
  
  return 0;
}
