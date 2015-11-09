/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: November 2015
 */

#include "matrix.h"
#include "MyBoostMatrix.h"

int main()
{
	MyBoostMatrix<float> a(3,5), b(5,4);
	MyBoostMatrix<float> c=a*b;
	c.print();

	std::cout << "  ---- " << std::endl;

	matrix<float> d(3,5), e(5,4);
	matrix<float> f=d*e;
	f.print();	

	return 0;
}
