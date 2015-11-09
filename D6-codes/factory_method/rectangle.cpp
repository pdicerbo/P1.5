/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: October 2015
 */

#include <iostream>
#include "rectangle.h"
using namespace std;


rectangle::rectangle()
{
}

rectangle::rectangle(float a, float b)
{
	width=a;
	height=b;
}

rectangle::~rectangle()
{
}


float rectangle::area()
{
	return width*height;
}

rectangle::rectangle(const rectangle &obj)
{
	width=obj.width;
	height=obj.height;
}

void rectangle::whatAmI()
{
	cout << " I am a rectangle " <<endl;
}
