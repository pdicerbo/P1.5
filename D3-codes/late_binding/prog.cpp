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

  rectangle *d=new square(3.0);
  d->area();

  rectangle& e=c;
  e.area();

/*
rectangle **arr=new rectangle*[2];
arr[0]=new rectangle(2.0,5.0);
arr[1]=new square(2.0);
  
  arr[0]->area();
  arr[1]->area();
*/
  return 0;
}
