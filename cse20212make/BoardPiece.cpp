#include <stdlib.h>
#include <iostream>
#include <string>
#include "Location.h"
#include "BoardPiece.h"
using namespace std;

BoardPiece::BoardPiece()
{
	return;
}

BoardPiece::BoardPiece(Sprite sprite, Location loc, int walkable, int interact)
{
	my_sprite = sprite;
	my_loc = loc;
	my_walk= walkable;
	my_interact = interact;
}

Sprite BoardPiece::getSprite()
{
	return my_sprite;
}

Location& BoardPiece::getLocation()
{
	return my_loc;
}

int BoardPiece::canWalk()
{
	return my_walk;
}

int BoardPiece::canInteract()
{
	return my_interact;
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
