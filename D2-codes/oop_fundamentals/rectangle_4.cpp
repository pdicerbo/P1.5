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
        rectangle(int a, int b);
   private:
        rectangle();
};

rectangle::rectangle()
{

}

rectangle::rectangle(int a, int b)
{
     width=a;
     height=b;
}



float rectangle::area()
{
return width*height;
}

int main() {
 
  rectangle a(5.0,2.0);
  //rectangle b;
  cout << a.area()  << endl;
  return 0;
}
