/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: November 2015
 */
#ifndef MONTECARLO_H
#define MONTECARLO_H
#include "Generator.h"
class MonteCarlo
{
	public:
		void setGenerator(Generator* );
		float calculateUnitCircleArea(int );
	private:
		Generator* m_gen;
	
};
#endif
