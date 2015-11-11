/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: November 2015
 */

#include "MonteCarlo.h"
#include "Generator.h"

void MonteCarlo::setGenerator(Generator* gen)
{
	m_gen=gen;
}

float MonteCarlo::calculateUnitCircleArea(int points)
{
	float area=0.0;
	float x;
	float y;
	for (int i=0; i<points; i++)
		{
		x=m_gen->rnd();
		y=m_gen->rnd();
		if ((x*x+y*y)<1.0)
			area++;
		}
	return area*4.0/points;
}



