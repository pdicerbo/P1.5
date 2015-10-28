/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: October 2015
 */

#include <iostream>


void swap( int &a, int &b)
{
   int c;
   c=a;
   a=b;
   b=c;
   std::cout<< " Swapping using references "<<std::endl;
}

void swap( int *a, int *b)
{
   int *c;
   c=a;
   a=b;
   b=c;
   std::cout<< " Swapping using pointers  "<<std::endl;
}

void swap2( int *a, int *b)
{
   int c;
   c=*a;
   *a=*b;
   *b=c;
   std::cout<< " Swapping using pointers and dereferencing  "<<std::endl;
}



int main(){

  int a=1;
  int b=2;

  std::cout << " a " << a << " b " << b << std::endl;
  swap(a,b);
  std::cout << " a " << a << " b " << b << std::endl;
  std::cout << std::endl;

  int c=3;
  int d=4;
  std::cout << " c " << c << " d " << d << std::endl;
  swap(&c,&d);
  std::cout << " c " << c << " d " << d << std::endl;
  std::cout << std::endl;

  int e=5;
  int f=6;
  std::cout << " e " << e << " f " << f << std::endl;
  swap2(&e,&f);
  std::cout << " e " << e << " f " << f << std::endl;
  std::cout << std::endl;

}

