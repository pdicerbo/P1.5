/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: October 2015
 */
#include <iostream>

using namespace std;


int op(int a, int b)
{
	return a+b;
}

double  op(double a, double  b)
{
        return 2.0*(a+b);
}

int main(){

   int a=1;
   int b=1;
   double c=1.0;
   double d=1.0;
   int rInt;
   int rDouble;

   rInt=op(a,b);
   cout<<" rInt=op(a,b) "<<rInt<<endl;
  
   rDouble=op(c,d);
   cout<<" rDouble=op(c,d) "<<rDouble<<endl;

   rDouble=op(a,b);
   cout<<" rDouble=op(a,b) "<<rDouble<<endl;


   return 0;
}
