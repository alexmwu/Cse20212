/* Pokemon Project
Alex Hansen
Item.h

item Class.
abstract class that will be used for portions, and elixers and such, as well as pokeballs.
*/

#ifndef ITEM_H
#define ITEM_H
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

class Item
{
public:
	Item();
	Item(string, int, int);
	void setName(string);
	void setBattle(int);
	void setOutside(int);
	string getName();
	int getBattle();
	int getOutside();
public:
	string my_name;
	int my_battleItem;
	int my_outsideItem;
};
#endif