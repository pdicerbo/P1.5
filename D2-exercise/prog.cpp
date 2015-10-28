#include <iostream>
#include "MyMatrix.h"

using namespace std;

int main(int argc, char** argv){
  Matrix a(3, 3);

  // cout << "\tnn_row = " << a.get_row() << endl;
  // cout << "\tnn_col = " << a.get_col() << endl;
  
  a.initialize("generic");
  a.self_print();
  Matrix b = a;

  // string test = "num";
  // if(test == "num")
  //   cout << "\tOK! " << test << endl;
  // else
  //   cout << "damn " << test << endl;

  // for identity initialization...
  // for(int i = 0; i < n_row; i++)
  //   for(int j = 0; j < n_col; j++){
  //     if(i != j)
  // 	matrix[j + i*n_col] = 0.;
  //     else
  // 	matrix[j + i*n_col] = 1.;
  //   }
  
  return 0;
}
