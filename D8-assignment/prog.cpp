#include <iostream>
#include <vector>
#include "MyMatrix.h"
#include "MySquareMatrix.h"
#include "MyVectors.h"
#include "FactoryMatrix.h"

using namespace std;

int main(int argc, char** argv){

  rvector<double> AA(4);
 
  AA(0) = -3.;
  AA(1) = 42.;
  AA(2) = -5.;
  AA(3) = 3.14;
  lvector<double> AB(4);
  AB = AA;
  
  AA.self_print();
  AB.self_print();

  // // AB(0, 1) = -3.;
  // // AB(0, 2) = 42.;
  // // AB(0, 3) = -5.;
  // // AB(0, 4) = 3.14;
  
  SquareMatrix<double> M(2);

  // M.initialize("identity");
  M(0,0) = 0.;
  M(0,1) = 1.;
  M(1,0) = 1.;
  M(1,1) = 0.;

  M.self_print();

  lvector<double> res = M.eigenvalues();
  Matrix<double> eig = M.eigenvectors();
  cout << "\n\tres[0] = " << res.matrix[0] << ";  res[1] = " << res.matrix[1] << endl;
  cout << "\n\tCalling self_print() on lvector:\n";
  res.self_print();
  eig.self_print();

  cout << "\n\tPrinting determinant: " << M.determinant() << endl;

  Matrix<float> tr(2, 3);
  tr.initialize("generic");
  tr.self_print();
  tr.transpose().self_print();
  
  cout << "\tExit\n";

  return 0;
}
