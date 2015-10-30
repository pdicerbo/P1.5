#include "myclass.h"

int myclass::s_num=0;

myclass::myclass()
{
	s_num++;
}

myclass::~myclass()
{
	s_num--;
}

int myclass::get_num()
{
	return s_num;
}
