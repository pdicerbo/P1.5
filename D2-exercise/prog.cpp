#include <iostream>
#include "MyMatrix.h"

using namespace std;

int main(int argc, char** argv){
  Matrix a(2, 3);

  cout << "\tnn_row = " << a.get_row() << endl;
  cout << "\tnn_col = " << a.get_col() << endl;

  Matrix b = a;
  
  return 0;
}
