/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: October 2015
 */

#include <iostream>
#include "rectangle.h"
#include "square.h"
using namespace std;

int main() {
  
  rectangle a(3.0,4.0);
  rectangle *d=new square(3.0);
  d->area();

  delete d;
  return 0;
}
