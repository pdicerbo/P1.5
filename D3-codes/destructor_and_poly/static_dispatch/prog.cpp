/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: October 2015
 */

#include <iostream>
#include "rectangle.h"
#include "square.h"
using namespace std;

int main() {
  
  rectangle *d=new square(4.0);

  delete d;
  return 0;
}
