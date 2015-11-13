#include <iostream>
#include <vector>
#include "MyMatrix.h"
#include "FactoryMatrix.h"

using namespace std;

int main(int argc, char** argv){

  vector< Matrix<double>* > vec;

  vec.push_back(CreateMat<double>(3, 3));
  vec.push_back(CreateMat<double>(3, 2));

  vector< Matrix<double>* >::iterator MyIt;

  for(MyIt = vec.begin(); MyIt != vec.end(); MyIt++){
    (*MyIt) -> initialize("generic");
    (*MyIt) -> self_print();
  }

  cout << "\n\tprinting traces:\n\n";
  for(MyIt = vec.begin(); MyIt != vec.end(); MyIt++)
    cout << "\t" << (*MyIt) -> trace() << endl;

  cout << endl;
  
  return 0;
}
