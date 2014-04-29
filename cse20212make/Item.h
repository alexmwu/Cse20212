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
	Item();			//black constructor, creates empty object
	Item(string, int, int);	//creates object with the given name, ints are if its a battle item and if its an outside item
	void setName(string); 	//sets the items name
	void setBattle(int);	//sets if the item is a battle item
	void setOutside(int);	//sets if the item is an outside item
	string getName();	//returns the value of the name
	int getBattle();	//returns if the item can be used in battle
	int getOutside();	//returns if the item can be used outside
public:
	string my_name;		//name of the item
	int my_battleItem;	//holds if the item is a battle item
	int my_outsideItem;	//holes if the itme is an outside item
};
#endif
