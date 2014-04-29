/* Pokemon Project
Alex Hansen
Sprite.h

Sprite Class.
Stores the sprite sheet, location on the sheet, and height and width of the sprite. Includes getter and setter functions.
*/

#ifndef POKEBALL_H
#define POKEBALL_H
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Pokemon.h"
#include "Item.h"

using namespace std;

class Pokeball : public Item
{
public:
	Pokeball();				//creates a blank pokeball
	//Pokeball(string, int, int,  int);
	Pokeball(string, int);			//creates a pokeball with the string name, and int strength
	void setStrength(int);			//sets teh strength to the passed value
	int getStrength();			//returns the strength of the pokeball
	int canCatch(Pokemon);			//determines if the pokemon will be caught will the given pokeball, and pokemon passed in
private:
	int my_strength;			//stores the strength of the pokeball
	string my_name;				//stores the name of the pokeball
};
#endif
