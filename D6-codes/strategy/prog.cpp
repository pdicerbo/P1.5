/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: November 2015
 */

#include <iostream>
#include "MonteCarlo.h"
#include "LCGenerator.h"
#include "DumbGenerator.h"

int main()
{
	MonteCarlo M;

	LCGenerator LC;
	M.setGenerator(&LC);
	std::cout << " Area of a unit circle with LCGenerator " << M.calculateUnitCircleArea(100000) << std::endl;
	
	
	DumbGenerator D;
	M.setGenerator(&D);
	std::cout << " Area of a unit circle with DumbGenerator " << M.calculateUnitCircleArea(100000) << std::endl;

	return 0;
}
