/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: November 2015
 */

#ifndef GENERATOR_H
#define GENERATOR_H
class Generator
{
	public:
	        virtual void seed(unsigned int s ) =0;
        	virtual float rnd() =0;
};
#endif
