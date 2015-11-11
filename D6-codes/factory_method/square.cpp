/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: October 2015
 */

#include <iostream>
#include "square.h"
using namespace std;


square::square()
{
}

square::square(float a)
:
rectangle(a,a)
{

}

square::~square()
{
}

float square::area()
{
	return width*width;

}

void square::whatAmI()
{
        cout << " I am a square " <<endl;
}


