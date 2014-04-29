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
	BoardPiece();				//black constructor, creates black object
	BoardPiece(Sprite, Location, int, int);	//creates boardpice with the given sprite, location. its are if it is walkable and interactable
	Sprite getSprite();			//returns the sprite value
	Location& getLocation();		//returns the location
	int canWalk();				//returns if a trainer can walk on it
	int canInteract();			//returns if the trainer can interact with the boardpiece
	int trainerPresent(Location);		//returns if there is a trainer present on the boardpiece
	virtual void interact();		//interacts

private:
	Location my_loc;			//location of the piece
	int my_walk;				//stores walkability
	int my_interact;			//stores interactability
	Sprite my_sprite;			//stores the sprite
};
#endif
