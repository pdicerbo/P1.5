/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: November 2015
 */

#ifndef LCGENERATOR_H
#define LCGENERATOR_H
#include "Generator.h"

class LCGenerator : public Generator 
{
public:
    void seed( unsigned int s );
    LCGenerator();
    virtual float rnd();

private: 
    int _a, _c;
    unsigned int _m, _seed;
};
#endif
