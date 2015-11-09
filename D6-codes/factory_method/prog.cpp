/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: October 2015
 */

#include <iostream>
#include "rectangle.h"
#include "square.h"
#include "RectangleFactory.h"
#include <map>
using namespace std;

int main() {
  
	rectangle* a=createRect(3.0,4.0);
	rectangle* b=createRect(4.0,4.0);
  	a->whatAmI();
	b->whatAmI();
	delete a;
	delete b;
        rectangle* c=createRectByName("rectangle");
        rectangle* d=createRectByName("square");
	c->whatAmI();
	d->whatAmI();
	delete c;
	delete d;


	// using templates and maps
	map<string, RectCreator> shapes;
	shapes["rectangle"]=&creator<rectangle>;
	shapes["square"]=&creator<square>;
	rectangle* e=(*shapes["rectangle"])();
	rectangle* f=(*shapes["square"])();
        e->whatAmI();
        f->whatAmI();
        delete e;
        delete f;


	return 0;
}
