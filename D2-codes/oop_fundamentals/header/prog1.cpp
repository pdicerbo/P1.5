/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: October 2015
 */

#include <iostream>
#include "myvector.h"
using namespace std;

int main() {

  myvector a(2);
  for (int i=0; i<a.get_n(); i++)
        a.data[i]=1.0;
  cout << a.norm()  << endl;
  return 0;
}


