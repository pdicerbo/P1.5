/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: October 2015
 */
#include <iostream>
#include <iomanip> 

void print(int i)
{
	std::cout<<i<<std::endl;
}
void print(double i)
{
	std::cout<<std::setprecision(5)<<i<<std::endl;
}


int main()
{
	int a=4;
	double b=3.14159265359;
	print(a);
	print(b);
	return 0;
}
