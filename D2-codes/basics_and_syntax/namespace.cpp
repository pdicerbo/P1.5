/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: October 2015
 */

#include <iostream>

namespace A{
   int var=3;
   void greet() {  std::cout <<" Hello!" << std::endl; };
}

namespace B{
   int var=4;
   void greet() {  std::cout << " Hi!" << std::endl; };
}

using namespace A;

int main() {

  std::cout << " a = " << A::var <<std::endl;
  A::greet();
  std::cout << " a = " << var << std::endl;
  greet(); 
  std::cout << " a = " << B::var << std::endl;
  B::greet();
  return 0;
}

