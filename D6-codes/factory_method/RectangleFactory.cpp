/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: November 2015
 */

#include "rectangle.h"
#include "square.h"
#include <cmath>
#include <iostream>

rectangle* createRect(const float a, const float b)
{
	if (fabs(a-b)<1.0e-14)
		return new square(a);
	return new rectangle(a,b);
}

rectangle* createRectByName(const std::string name)
{
	if (name == "square")
		return new square;
	if (name == "rectangle")	
		return new rectangle;
	std::cout<<" wrong type! : only 'rectangle' and 'square' allowed. Returning an instance of 'rectangle' " << std::endl;
	return new rectangle;
}



