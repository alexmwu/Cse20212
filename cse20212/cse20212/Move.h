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

Move::Move()
{
	return;
}

Move::Move(string name, Type type, int strength, double accuracy, int pp, string effect)
{
	my_name = name;
	my_type = type;
	my_strength = strength;
	my_effect = effect;
	my_accuarcy = accuracy;
	my_pp = pp;
}

string Move::getName()
{
	return my_name;
}

Type Move::getType()
{
	return my_type;
}

int Move::getStrength()
{
	return my_strength;
}

string Move::getEffect()
{
	return my_effect;
}

void Move::setName(string name)
{
	my_name = name;
}

void Move::setType(Type type)
{
	my_type = type;
}

void Move::setStrength(int strength)
{
	my_strength = strength;
}

void Move::setEffect(string effect)
{
	my_effect = effect;
}

void Move::print()
{
	cout << my_name << " " << my_pp << " (PP) " << my_strength << " (Power)" << endl;
}


#endif