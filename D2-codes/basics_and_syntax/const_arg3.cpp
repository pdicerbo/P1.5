/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: October 2015
 */
#include <iostream>

void print(int* const a, int n)
{
  int* b;
  b=new int[3];
  
  delete [] a;
  a=b;

  for (int i=0; i<n;i++)
	{
	a[i]=1;  
	std::cout<<a[i]<<std::endl;
	}
}

int main(){

   int *a;
   int n=3;
   a= new int[3];
   for (int i=0; i<n;i++)
        {
        a[i]=0;   
        }
   print(a,n);
   return 0;

}
