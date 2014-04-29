#include <stdlib.h>
#include <iostream>
#include <string>
#include "Location.h"
#include "BoardPiece.h"
using namespace std;

//black constructor, creates black object
BoardPiece::BoardPiece()
{
	return;
}

//creates boardpice with the given sprite, location. its are if it is walkable and interactable
BoardPiece::BoardPiece(Sprite sprite, Location loc, int walkable, int interact)
{
	my_sprite = sprite;
	my_loc = loc;
	my_walk= walkable;
	my_interact = interact;
}

//returns the sprite value
Sprite BoardPiece::getSprite()
{
	return my_sprite;
}

//returns the location
Location& BoardPiece::getLocation()
{
	return my_loc;
}

//returns if a trainer can walk on it
int BoardPiece::canWalk()
{
	return my_walk;
}

//returns if the trainer can interact with the boardpiece
int BoardPiece::canInteract()
{
	return my_interact;
}

//returns if there is a trainer present on the boardpiece
int BoardPiece::trainerPresent(Location loc)
{
	if (my_loc.getX() != loc.getX())
		return 0;
	if (my_loc.getY() != loc.getY())
		return 0;
	return 1;
}

//interacts
void BoardPiece::interact()
{
	if (my_interact != 1)
		return;
}

//sets the sprite to the passed value
void BoardPiece::setSprite(Sprite s)
{
	my_sprite = s;
}
