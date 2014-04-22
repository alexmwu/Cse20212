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
#endif