/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: November 2015
 */

#include "LCGenerator.h"

LCGenerator::LCGenerator()
:
_seed( 0 ), _a( 1103515245 ), _c( 12345 ), _m( 1<<31 ) 
{

}

void LCGenerator::seed(unsigned int s )
{
        _seed=s;
}


float LCGenerator::rnd()
{
          _seed = ( _a * _seed + _c ) % _m ;
          return  ((float) _seed)/_m;
}

