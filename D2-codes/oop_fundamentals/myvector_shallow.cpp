/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: October 2015
 */

#include <iostream>
#include <cmath>
using namespace std;

class myvector 
{
   private:
        int m_n;
        myvector();
   public:
	float *data;
	int get_n();
        float norm();
        myvector(const myvector &obj);
        myvector(int n);
	~myvector();
};


myvector::myvector(int n)
{
     m_n=n;
     data= new float[m_n];
}

myvector::~myvector()
{
     delete [] data;
}

myvector::myvector(const myvector &obj)
{
    m_n=obj.m_n;
    data=obj.data;
}

int myvector::get_n()
{ 
     return m_n;
}

float myvector::norm()
{
     float sum=0.0;
     for (int i=0; i<m_n; i++)
	 sum+=data[i]*data[i];
     return sqrt(sum);
}

int main() {

  myvector a(2);
  for (int i=0; i<a.get_n(); i++)
	a.data[i]=1.0;
   
  myvector b=a;
  cout << b.norm()  << endl;
  a.data[0]=0.0; 
  cout << b.norm()  << endl;
  return 0;
}

