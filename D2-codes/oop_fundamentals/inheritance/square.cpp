/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: October 2015
 */

#include <iostream>
#include "square.h"
using namespace std;


square::square()
{
	cout << " Invoked square default constructor " << endl;
}

square::square(int a)
{
	cout << " Invoked square custom constructor " << endl;
	width=a;
	height=a;
}

square::~square()
{
	cout << " Invoked square destructor " << endl;
}


float square::inscribed_area()
{
	return 3.1415*width*width/4.0;
}


