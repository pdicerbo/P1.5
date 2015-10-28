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
	rectangle();
        rectangle(const rectangle &obj);
};

rectangle::rectangle()
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

int main() {
  
  rectangle a;
  a.width=5.0;
  a.height=2.0;
  rectangle b=rectangle(a);
  rectangle c=a;	
  cout << a.area()  << endl;
  cout << b.area()  << endl;
  cout << c.area()  << endl;
  
  return 0;
}
