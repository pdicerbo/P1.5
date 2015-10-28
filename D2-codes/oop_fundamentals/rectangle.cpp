/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: October 2015
 */

#include <iostream>
using namespace std;


class rectangle
{
   public:
        float width, height;
        float area();
};

float rectangle::area()
{
return width*height;
}

int main() {
  
  rectangle a;
  a.width=5.0;
  a.height=2.0;
  cout << a.area()  << endl;
  return 0;
}
