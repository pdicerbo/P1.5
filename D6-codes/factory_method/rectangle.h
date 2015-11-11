/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: October 2015
 */

#ifndef MY_RECTANGLE_HEADER
#define MY_RECTANGLE_HEADER
#include <string>
class rectangle
{
   public:
        float width, height;
        virtual float area();
	virtual void  whatAmI();
        ~rectangle();
        rectangle(float a, float b);
        rectangle(const rectangle &obj);
        rectangle();
};
#endif
