/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: October 2015
 */
#include <iostream>

void print(const int i)
{
  // i=3;  // won't compile, i is const in this scope
  std::cout<<i<<std::endl;
}

int main(){

   int a=3;
   print(a);
   return 0;

}
