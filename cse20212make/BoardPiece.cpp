#include <stdlib.h>
#include <iostream>
#include <string>
#include "Location.h"
#include "BoardPiece.h"
using namespace std;

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