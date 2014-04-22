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

class Pokeball : Item
{
public:
	Pokeball();
	Pokeball(string, int, int,  int);
	void setStrength(int);
	int getStrength();
	int canCatch(Pokemon *);
private:
	int my_strength;
	string my_name;
};
#endif