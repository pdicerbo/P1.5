/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: October 2015
 */
#include <iostream>

class gg
{
   public:
     int n;
     int *data;
     gg(int n);
     ~gg();
};

gg::gg(int m)
{
    n=m;
    data=new int[m];
}
gg::~gg()
{
    delete [] data;
}

void print(const int& a )
{
	//a=1;  
	std::cout << a << std::endl;
}

void print(const gg& a )
{
	for (int i=0; i < a.n; i++)
		{
		//a[i]=1;
       		std::cout << a.data[i] << std::endl;
		}
}


int main(){

   int a=2;
   gg b(2);
   print(a);
   print(b);
   return 0;

}
