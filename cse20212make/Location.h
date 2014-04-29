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
	Location(); 		//creates a black Location object
	Location(int, int);	//creates a Location with x and y passed in as the parameters
	int getX();		//returns x
	int getY();		//returns y
	void setX(int);		//sets x to the paremeter
	void setY(int);		//sets y to the parameter

private:
	int my_x;		//holds the x value
	int my_y;		//holds the y value
};
#endif
