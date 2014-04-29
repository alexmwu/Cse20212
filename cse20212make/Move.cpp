#include <stdlib.h>
#include <iostream>
#include <string>
#include "Type.h"
#include "Move.h"
using namespace std;

//creates a blank move object
Move::Move()
{
	return;
}

//creates a move object with the string name, type passed, int strenght, double accuracy, int pp, and string effect
Move::Move(string name, Type type, int strength, double accuracy, int pp, string effect)
{
	my_name = name;
	my_type = type;
	my_strength = strength;
	my_effect = effect;
	my_accuarcy = accuracy;
	my_pp = pp;
}

//returns the name of the move
string Move::getName()
{
	return my_name;
}

//returns the type of the move
Type Move::getType()
{
	return my_type;
}

//returns the strength of the move
int Move::getStrength()
{
	return my_strength;
}

//returns the effect of the move
string Move::getEffect()
{
	return my_effect;
}

//sets teh name of the move
void Move::setName(string name)
{
	my_name = name;
}

//sets teh type of the move
void Move::setType(Type type)
{
	my_type = type;
}

//sets the strength of the move
void Move::setStrength(int strength)
{
	my_strength = strength;
}

//sets the effect of the move
void Move::setEffect(string effect)
{
	my_effect = effect;
}

//prints the move for battle
void Move::print()
{
	cout << my_name << " " << my_pp << " (PP) " << my_strength << " (Power)" << endl;
}
