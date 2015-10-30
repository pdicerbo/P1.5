/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: October 2015
 */

#include <iostream>
#include "rectangle.h"
using namespace std;


rectangle::rectangle()
{
	cout << " Invoked rectangle default constructor " << endl;
}

rectangle::rectangle(float a, float b)
{
	cout << " Invoked rectangle custom constructor " << endl;
	width=a;
	height=b;
}

rectangle::~rectangle()
{
	cout << " Invoked rectangle destructor " << endl;
}


float rectangle::area()
{
	return width*height;
}

rectangle::rectangle(const rectangle &obj)
{
	cout << " Invoked rectangle copy constructor " << endl;
	width=obj.width;
	height=obj.height;
}

