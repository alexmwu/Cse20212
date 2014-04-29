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
	Move();						//creates a blank move object
	Move(string, Type, int, double, int, string);	//creates a move object with the string name, type passed, int strenght, double accuracy, int pp, and string effect
	string getName();				//returns the name of the move
	Type getType();					//returns the type of the move
	int getStrength();				//returns the strength of the move
	string getEffect();				//returns the effect of the move
	void setName(string);				//sets teh name of the move
	void setType(Type);				//sets teh type of the move
	void setStrength(int);				//sets the strength of the move
	void setEffect(string);				//sets the effect of the move
	void print();					//prints the move for battle
private:
	string my_name;					//sotres the name
	Type my_type;					//stores teh type
	int my_strength;				//stores the moves strength
	double my_accuarcy;				//stores the accuracy
	int my_pp;					// stores the power points
	string my_effect;				//stores the effect of the move
};




#endif
