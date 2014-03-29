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
#include "Sprite.h"

using namespace std;

class BoardPiece
{
public:
	BoardPiece();
	BoardPiece(Sprite, Location, int, int);
	Sprite getSprite();
	Location getLocation();
	int canWalk();
	int trainerPresent(Location);
	virtual void interact();
	
private:
	Location my_loc;
	int my_walk;
	int my_interact;
	Sprite my_sprite;
};
#endif
