#include <stdlib.h>
#include <iostream>
#include "Location.h"
using namespace std;

Location::Location()
{
	my_x = 0;
	my_y = 0;
}

Location::Location(int x, int y)
{
	my_x = x;
	my_y = y;
}

int Location::getX()
{
	return my_x;
}

int Location::getY()
{
	return my_y;
}

void Location::setX(int x)
{
	my_x = x;
}

void Location::setY(int y)
{
	my_x = y;
}