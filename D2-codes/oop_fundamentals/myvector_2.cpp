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
	int get_n() const;
        float norm();
        myvector(int n);
	~myvector();
	float operator*(const myvector& a);
        
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

int myvector::get_n() const
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

float myvector::operator*( const myvector& a)
{
      int range = ( m_n < a.get_n() ? m_n : a.get_n());
      float sum=0.0;
      for (int i=0 ; i < range; i++)
	 {
	 sum+=data[i]*a.data[i];	
	 }
      return sum;
}

int main() {

  myvector a(3), b(2);
  a.data[0]=1.0;
  a.data[1]=1.0;
  a.data[2]=5.0;
  
  b.data[0]=2.0;
  b.data[1]=3.0;
  cout << a*b  << endl;
  return 0;
}

