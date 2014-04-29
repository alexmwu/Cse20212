#include <stdlib.h>
#include <iostream>
#include "Location.h"
using namespace std;

//creates a black Location object
Location::Location()
{
	my_x = 0;
	my_y = 0;
}

//creates a Location with x and y passed in as the parameters
Location::Location(int x, int y)
{
	my_x = x;
	my_y = y;
}

//returns x
int Location::getX()
{
	return my_x;
}

//returns y
int Location::getY()
{
	return my_y;
}

//sets x to the paremeter
void Location::setX(int x)
{
	my_x = x;
}

//sets y to the parameter
void Location::setY(int y)
{
	my_y = y;
}
