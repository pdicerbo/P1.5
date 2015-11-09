/* Created by G.P. Brandino for the Course P1.5 - Object Oriented Programming @ MHPC
 * Last Revision: November 2015
 */
#ifndef DUMBGENERATOR_H
#define DUMBGENERATOR_H
#include "Generator.h"

class DumbGenerator : public Generator
{
public:
    void seed(unsigned int s );
    virtual float rnd();
    DumbGenerator(); 

private: 
    unsigned int _seed;
};
#endif


