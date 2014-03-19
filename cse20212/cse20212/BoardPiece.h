/* Pokemon Project
Alex Hansen
BoardPiece.h

BoardPiece Class.
store an image, to be displayed as well as values that will determine if you can walk on that peice, or interact with that piece.
will also store if a trainer is present on that piece.
*/

#ifndef BOARDPIECE_H
#define BOARDPIECE_H
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Location.h"

using namespace std;

class BoardPiece
{
public:
	BoardPiece(string, Location, int, int);
	string getImage();
	Location getLocation();
	int canWalk();
	int trainerPresent(Location);
	virtual void interact();

private:
	string my_image;
	Location my_loc;
	int my_walk;
	int my_interact;
};

BoardPiece::BoardPiece(string image, Location loc, int walkable, int interact)
{
	my_image = image;
	my_loc = loc;
	my_walk = walkable;
	my_interact = interact;
}

string BoardPiece::getImage()
{
	return my_image;
}

Location BoardPiece::getLocation()
{
	return my_loc;
}

int BoardPiece::canWalk()
{
	return my_walk;
}

int BoardPiece::trainerPresent(Location loc)
{
	if (my_loc.getX() != loc.getX())
		return 0;
	if (my_loc.getY() != loc.getY())
		return 0;
	return 1;
}

void BoardPiece::interact()
{
	if (my_interact != 1)
		return;
}
#endif