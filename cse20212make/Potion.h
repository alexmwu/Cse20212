/* Pokemon Project
Alex Hansen
Potion.h

Potion Class.
Class extedning item, used for an item to heal HP ~ Potion
*/

#ifndef POTION_H
#define POTION_H
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

class Potion : Item
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