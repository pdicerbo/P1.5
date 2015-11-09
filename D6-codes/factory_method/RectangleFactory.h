/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: November 2015
 */

#ifndef __RECTANGLE_FACTORY_H
#define __RECTANGLE_FACTORY_H
#include <string>
#include "rectangle.h"
#include "square.h"

rectangle* createRect(const float a, const float b);
rectangle* createRectByName(const std::string name);


// a different approach, using templates and std:map
template <typename T>
rectangle* creator()
{
        return new T;
}

typedef rectangle* (*RectCreator)();

#endif 
