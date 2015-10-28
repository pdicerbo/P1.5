/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: October 2015
 */

#include <iostream>
using namespace std;


int main(){
 
  int *p;
  p = new int[5];

  delete []  p;
  return 0;
}
