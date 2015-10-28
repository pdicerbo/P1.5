/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: October 2015
 */


#include <iostream>
using namespace std;

void change( int& a)
{
  a+=1;
}

void change( double& a)
{
  a+=2.0;
}


// pointer to constant
void change(int const* a)
{
  a=NULL;
  cout<<"pointer to constant"<<endl;
//  *a+=3; //error
}

// constant pointer
void change( int* const a)
{
//  a=NULL; // error
  *a+=3;
  cout<<" constant pointer "<<endl;
}





int main()
{
   int a=2;
   cout<<"--- Passing by reference"<<endl;
   cout<<a<<endl;
   change(a);
   cout<<a<<endl;

   cout<<"--- Passing by referencei, using polymorphism"<<endl;
   double b=1.5;
   cout<<b<<endl;
   change(b);
   cout<<b<<endl;

   cout<<"--- Passing pointer by value. Polymorphism - the function with constant pointer is selected "<<endl;
   cout<<a<<endl;
   change(&a);
   cout<<a<<endl;

   cout<<"--- Passing pointer by value. Polymorphism - the function with pointer to constant is selected "<<endl;
   const int d=4;
   cout<<d<<endl;
   change(&d);
   cout<<d<<endl;

   cout<<"--- Using a reference variable. Passing pointer by reference. "<<endl;
   int &c=a;
   cout<<c<<endl;
   change(c);
   cout<<c<<endl;

   return 0;

} 
