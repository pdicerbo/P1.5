#include <iostream>
#include <vector>
#include "MyMatrix.h"
#include "MySquareMatrix.h"
#include "MyVectors.h"
#include "FactoryMatrix.h"

using namespace std;

int main(int argc, char** argv){

  rvector<double> AA(4);
  lvector<double> AB(4);

  AA(0, 0) = -3.;
  AA(1, 0) = 42.;
  AA(2, 0) = -5.;
  AA(3, 0) = 3.14;
  AB(0, 1) = -3.;
  AB(0, 2) = 42.;
  AB(0, 3) = -5.;
  AB(0, 4) = 3.14;

  AA.self_print();
  SquareMatrix<double> M(4);
  M.initialize("identity");
  M.self_print();

  Matrix<double> a(4,1);
  
  a = M*AA;
  a.self_print();
  Matrix<double> ct = AB*M*AA;
  ct.self_print();

  cout << "\tExit\n";
  // vector< Matrix<double>* > vec;

  // vec.push_back(CreateMat<double>(3, 3));
  // vec.push_back(CreateMat<double>(3, 2));

  // vector< Matrix<double>* >::iterator MyIt;

  // for(MyIt = vec.begin(); MyIt != vec.end(); MyIt++){
  //   (*MyIt) -> initialize("generic");
  //   (*MyIt) -> self_print();
  // }

  // cout << "\n\tprinting traces:\n\n";
  // for(MyIt = vec.begin(); MyIt != vec.end(); MyIt++)
  //   cout << "\t" << (*MyIt) -> trace() << endl;

  // cout << endl;
  
  return 0;
}
