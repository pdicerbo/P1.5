/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: October 2015
 */

#include <iostream>

using namespace std;


int main(){

	int i=5;
	int a=3;

	cout<<" i before loop "<<i<<" a before loop "<<a<<endl;
	for (int i=0; i<10; i++)
		{
		int a=7;
		int b=3;
		cout<<" i inside loop "<<i<<" a inside loop "<<a<<endl;
		}
	cout<<" i after loop "<<i<<" a after loop "<<a<<endl;
	//cout<< b<<endl;

	return 0;
}
