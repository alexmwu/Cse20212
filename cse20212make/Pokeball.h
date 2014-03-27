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

using namespace std;

class Pokeball
{
public:
	Pokeball();
	Pokeball(int);
	void setStrength(int);
	int getStrength();
	int canCatch(Pokemon);
private:
	int my_strength;
};




#endif