#include <iostream>
#include <vector>
#include "MyMatrix.h"
#include "MySquareMatrix.h"
#include "FactoryMatrix.h"

using namespace std;

int main(int argc, char** argv){

  std::vector< Matrix<double>* > vec;

  Matrix<double>* a = CreateMat<double>(4, 4);
  Matrix<double>* b = CreateMat<double>(3, 2);

  vec.push_back(a);
  vec.push_back(b);


  // vec.push_back(CreateMat<double>(3, 3));
  // vec.push_back(CreateMat<double>(3, 2));

  std::vector< Matrix<double>* >::iterator MyIt;

  for(MyIt = vec.begin(); MyIt != vec.end(); MyIt++){
    (*MyIt) -> initialize("generic");
    (*MyIt) -> self_print();
  }

  cout << "\n\tprinting traces:\n\n";
  for(MyIt = vec.begin(); MyIt != vec.end(); MyIt++)
    cout << "\t" << (*MyIt) -> trace() << endl;
  
  return 0;
}
