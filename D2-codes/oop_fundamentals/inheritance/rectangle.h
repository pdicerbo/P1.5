/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: October 2015
 */

#ifndef MY_RECTANGLE_HEADER
#define MY_RECTANGLE_HEADER
class rectangle
{
   public:
        float width, height;
        float area();
        ~rectangle();
        rectangle(float a, float b);
        rectangle(const rectangle &obj);
   protected:
        rectangle();
};
#endif
