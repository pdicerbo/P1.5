#include "DumbGenerator.h"

DumbGenerator::DumbGenerator()
:
_seed(42)
{

}

void DumbGenerator::seed(unsigned int s )
{
        _seed=s;        
}

float DumbGenerator::rnd()
{
        return ((float)_seed - 21.0)/_seed;
}

