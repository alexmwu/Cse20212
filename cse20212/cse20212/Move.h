/* Pokemon Project
Alex Hansen
Move.h

Move Class.
Stores a type, strength, effect, and a name
*/

#ifndef MOVE_H
#define MOVE_H
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Type.h"

using namespace std;

class Move
{
public:
	Move();
	Move(string, Type, int, double, int, string);
	string getName();
	Type getType();
	int getStrength();
	string getEffect();
	void setName(string);
	void setType(Type);
	void setStrength(int);
	void setEffect(string);
	void print();
private:
	string my_name;
	Type my_type;
	int my_strength;
	double my_accuarcy;
	int my_pp;
	string my_effect;
};




#endif