#include <iostream>
#include "MyMatrix.h"

using namespace std;

int main(int argc, char** argv){
  Matrix a(3, 3);

  // cout << "\tnn_row = " << a.get_row() << endl;
  // cout << "\tnn_col = " << a.get_col() << endl;
  
  a.initialize("generic");
  a.self_print();
  //Matrix b = a;
  Matrix b(2, 4);
  b.initialize("generic");
  b.self_print();
  b*a;
  b = a;

  b.self_print();
  Matrix c(2,1);
  // cout << "\n\nHERE BEFORE PRODUCT\n";  
  // (a*b).self_print();
  // cout << "\n\nHERE AFTER PRODUCT\n";  

  c = a*b;
  c.self_print();

  return 0;
}
