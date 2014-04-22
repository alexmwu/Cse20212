/* Pokemon Project
Alex Hansen
Pokemon.h

Pokemon Class.
Pokemon Object

Stores all the attributes of a pokemon, getter/setter functions for the proper values, and some interaction functions
*/
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Location.h"
#include <string>
#include <vector>
#include "Move.h"
#include "Type.h"
#include "Pokemon.h"
using namespace std;

Pokemon::Pokemon()
{
	return;
}

Pokemon::Pokemon(int atk, int def, int HP, int spAtk, int spDef, int speed, Sprite user,Sprite opp, string name, int lvl, int XP, int nextlvlXP, int wild, int evolveLvl, Type t1, Type t2)
{
	my_index = 0;
	my_Atk = atk;
	my_Def = def;
	my_HP = HP;
	my_maxHP = HP;
	my_SpAtk = spAtk;
	my_SpDef = spDef;
	my_speed = speed;
	my_name = name;
	my_level = lvl;
	my_XP = XP;
	my_nexLvlXP = nextlvlXP;
	my_wild = wild;
	my_evolveLvl = evolveLvl;
	my_types.push_back(t1);
	my_types.push_back(t2);
	user_image=user;
	opp_image=opp;
	my_multFact = my_level / 33.0;
}

int Pokemon::getEvolveLevel()
{
	return my_evolveLvl;
}

int Pokemon::isWild()
{
	return my_wild;
}

string Pokemon::getName()
{
	return my_name;
}

Sprite Pokemon::getUserImage()
{
	return user_image;
}

Sprite Pokemon::getOppImage()
{
	return opp_image;
}

int Pokemon::getAtk()
{
	return my_Atk * my_multFact;
}

int Pokemon::getSpAtk()
{
	return my_SpAtk * my_multFact;
}

int Pokemon::getDef()
{
	return my_Def * my_multFact;
}

int Pokemon::getSpDef()
{
	return my_SpDef * my_multFact;
}

int Pokemon::getSpeed()
{
	return my_speed * my_multFact;
}

int Pokemon::getHP()
{
	return my_HP;
}

int Pokemon::getXP()
{
	return my_XP;
}

int Pokemon::getNextLevelXP()
{
	return my_nexLvlXP;
}

int Pokemon::getLevel()
{
	return my_level;
}

int Pokemon::getMaxHP()
{
	return my_maxHP;
}

void Pokemon::heal()
{
	my_HP = my_maxHP;
}

void Pokemon::setName(string name)
{
	my_name = name;
}

void Pokemon::setAtk(int Atk)
{
	my_Atk = Atk;
}

void Pokemon::setDef(int Def)
{
	my_Def = Def;
}

void Pokemon::setHP(int HP)
{
	if (HP < 0)
		HP = 0;
	if (HP > my_maxHP)
		HP = my_maxHP;
	my_HP = HP;
}

void Pokemon::setSpAtk(int SpAtk)
{
	my_SpAtk = SpAtk;
}

void Pokemon::setSpDef(int SpDef)
{
	my_SpDef = SpDef;
}

void Pokemon::setSpeed(int speed)
{
	my_speed = speed;
}

void Pokemon::setUserImage(Sprite image)
{
	user_image = image;
}

void Pokemon::setOppImage(Sprite image)
{
	opp_image = image;
}

void Pokemon::setWild(int wild)
{
	my_wild = wild;
}

void Pokemon::setLevel(int level)
{
	my_level = level;
	my_multFact = 1 / 33.0 * my_level;
	my_HP *= my_multFact;
	my_maxHP *= my_multFact;
	my_battleXP = my_XP * my_multFact;
}

void Pokemon::setXP(int XP)
{
	my_XP = XP;
}

void Pokemon::setNextLevelXP(int nextLvlXP)
{
	my_nexLvlXP = nextLvlXP;
}

void Pokemon::setEvolveLevel(int evolveLvl)
{
	my_evolveLvl = evolveLvl;
}

void Pokemon::setMaxHP(int hp)
{
	my_maxHP = hp;
}

void Pokemon::levelUp()
{
	my_level++;
	if (my_level > my_evolveLvl && my_evolveLvl != 1)
		evolve();
}

vector<Move> Pokemon::getMoves()
{
	return my_moves;
}

void Pokemon::addMove(Move m)
{
	my_moves.push_back(m);
}

vector<Type> Pokemon::getType()
{
	return my_types;
}

void Pokemon::setType(Type t1, Type t2)
{
	my_types[0] = t1;
	my_types[1] = t2;
}

void Pokemon::oppPrint()
{
	cout << my_name << endl;
	cout << "HP: " << my_HP << endl;
}

void Pokemon::battlePrint()
{
	int i = 0;
	cout << my_name << endl;
	cout << "HP: " << getHP() << " " << endl;
	cout << "Moves: " << endl;
	for (i = 0; i < my_moves.size(); i++)
	{
		cout << i << ")" << " ";
		my_moves[i].print();
	}		
	cout << i << ")  Throw Pokeball." << endl;
	cout << ++i << ") Switch Pokemon" << endl;
	cout << ++i << ") Use an Item." << endl;
}

Move Pokemon::getMove(int num)
{
	return my_moves[num];
}

void Pokemon::useMove(Pokemon *opp, int move, double strength)
{
	double calc;
	int HPLoss;
	int f[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	f[0] = getLevel();
	f[1] = getAtk();
	f[2] = getMove(move).getStrength();
	f[3] = getLevel();
	f[4] = opp->getDef();
	f[5] = strength;
	f[6] = rand() % 39 + 152;

	//calc = (((((2.0 * f[0]) / 5 + 2)*f[1] * f[2]) / ((f[3] * f[4]) + 2) * f[5] * f[6])) / 255 + 1;
	calc = (1.0 * f[1] * f[2] * f[5]) / (f[4]) * (f[6] / 464.0);
	HPLoss = calc / 1;
	opp->setHP(opp->getHP() - HPLoss);
	cout << getName() << " used " << getMove(move).getName() << endl;

}

int Pokemon::battleEXP()
{
	return my_battleXP;
}

void Pokemon::evolve()
{
	return;
}
