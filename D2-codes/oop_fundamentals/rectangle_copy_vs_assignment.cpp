/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: October 2015
 */

#include <iostream>
using namespace std;


class rectangle
{
   private:
	rectangle();
   public:
        float width, height;
        float area();
	rectangle(float a, float b);
        rectangle(const rectangle &obj);
        rectangle& operator=(const rectangle &obj);
};

rectangle::rectangle()
{

}

rectangle::rectangle(float a, float b)
{
     width=a;
     height=b; 
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

rectangle &rectangle::operator=(const rectangle &obj)
{
	cout << "Invoked assignment operator " << endl;
	width=obj.width;
	height=obj.height;
	return *this;
}


void print_infos(rectangle a)
{
     cout << " width= " << a.width << " height= " << a.height << endl; 
}

int main() {
  
  rectangle a(5.0,2.0); 
  rectangle b(1.0,2.0);
  rectangle c=a;
  b=a;
 
  return 0;
}
