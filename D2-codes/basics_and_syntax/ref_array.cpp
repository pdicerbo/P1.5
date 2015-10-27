/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: October 2015
 */
#include <iostream>

void print( int (&a)[5])  //works only with fixed-size arrays
{
   for (int i=0; i<sizeof(a)/sizeof(int); i++)
	{
	a[i]=1;
	std::cout << a[i] << std::endl;
	}
}

int main(){

	int a[5];
	for (int i=0; i < 5; i++)
		{
		a[i]=0;
		}
	print(a);
	std::cout << " after printing a[3] = " << a[3] << std::endl;
	return 0;
}
