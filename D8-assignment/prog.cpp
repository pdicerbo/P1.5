#include <iostream>
#include <vector>
#include "MyMatrix.h"
#include "MySquareMatrix.h"
#include "MyVectors.h"

using namespace std;

int main(int argc, char** argv){

  rvector<double> AA(4);
 
  AA(0) = -3.;
  AA(1) = 42.;
  AA(2) = -5.;
  AA(3) = 3.14;

  lvector<double> AB(4);
  AB = AA;
  
  // AA.self_print();
  // AB.self_print();

  SquareMatrix<double> M(2);

  // M.initialize("identity");
  M(0,0) = 0.;
  M(0,1) = 1.;
  M(1,0) = 1.;
  M(1,1) = 0.;
  
  cout << "\n\tMatrix:\n";
  M.self_print();

  lvector<double> res = M.eigenvalues();
  Matrix<double> eig = M.eigenvectors();
  cout << "\n\tEigenvalues:\n";
  res.self_print();
  cout << "\n\tEigenvectors:\n";
  eig.self_print();

  cout << "\n\tDeterminant: " << M.determinant() << endl;

  Matrix<float> tr(2, 3);
  tr.initialize("generic");
  tr.self_print();
  tr.transpose().self_print();
  cout << "\n\tDeterminant: " << tr.determinant() << endl;
  cout << "\tExit\n";

  return 0;
}
