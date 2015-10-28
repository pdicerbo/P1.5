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
	cout << " Invoked copy constructor " << endl;
	width=obj.width;
	height=obj.height;
}

rectangle print_infos(rectangle a)
{
     cout << " width= " << a.width << " height= " << a.height << endl;
     return a;
}

int main() {
  
  rectangle a;
  a.width=5.0;
  a.height=2.0;
  print_infos(a); 
 
  return 0;
}
