/* Pokemon Project
Alex Hansen
Location.h

Location Class.
Object will be used to store the location on the grid.
Object intended to be implemented by a BoardPiece
*/

#ifndef LOCATION_H
#define LOCATION_H
#include <stdlib.h>
#include <iostream>

using namespace std;

class Location
{
public:
	Location();
	Location(int, int);
	int getX();
	int getY();
	void setX(int);
	void setY(int);

private:
	int my_x;
	int my_y;
};

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

#endif