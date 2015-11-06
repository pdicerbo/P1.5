/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: October 2015
 */

#include <iostream>
#include "rectangle.h"
#include "square.h"
using namespace std;

int main() {
  
  square c(2.0);
  c.area();

  rectangle *d;
  d=&c;
  d->area();

  rectangle& e=c;
  e.area();

  return 0;
}
