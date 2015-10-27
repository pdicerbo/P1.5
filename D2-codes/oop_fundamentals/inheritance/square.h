/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: October 2015
 */

#ifndef MY_SQUARE_HEADER
#define MY_SQUARE_HEADER
#include "rectangle.h"
class square : public rectangle
{
   public:
        ~square();
        square(int a);
	float inscribed_area();
   private:
        square();
};
#endif
