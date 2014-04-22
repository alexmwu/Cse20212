/* Pokemon Project
Alex Hansen
Potion.h

Potion Class.
Class extending item, used for an item to heal HP ~ Potion
*/

#ifndef POTION_H
#define POTION_H
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Item.h"
#include "Pokemon.h"

using namespace std;

class Potion : public Item
{
public:
	Potion();
	Potion(string, int, int, int);
	void setStrength(int);
	int getStrength();
	int use(Pokemon);
	string getName();
private:
	int my_strength;
};
#endif