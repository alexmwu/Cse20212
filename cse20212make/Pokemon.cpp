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

//blank pokemon object
Pokemon::Pokemon()
{
	return;
}

//atk, def, HP, spAtk, spDef, speed, user Sprite, opp Sprite, string name, lvl, nextlevlXP, isWild, evolvelvl, Type1, Type2. Creates an object with the given attributes	
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
	my_battleXP = nextlvlXP*my_multFact;
}

//returns the evolvelvl
int Pokemon::getEvolveLevel()
{
	return my_evolveLvl;
}

//returns if it is a wild pokemon
int Pokemon::isWild()
{
	return my_wild;
}

//returns the name
string Pokemon::getName()
{
	return my_name;
}

//get user pokemon sprite
Sprite Pokemon::getUserImage()
{
	return user_image;
}

//get opponent pokemon sprite
Sprite Pokemon::getOppImage()
{
	return opp_image;
}

//returns the atk
int Pokemon::getAtk()
{
	return my_Atk * my_multFact;
}

//returns the spatk
int Pokemon::getSpAtk()
{
	return my_SpAtk * my_multFact;
}

//returns the def
int Pokemon::getDef()
{
	return my_Def * my_multFact;
}

//returns the spdef
int Pokemon::getSpDef()
{
	return my_SpDef * my_multFact;
}

//returns the speed
int Pokemon::getSpeed()
{
	return my_speed * my_multFact;
}

//returns the hp
int Pokemon::getHP()
{
	return my_HP;
}

//returns the xp
int Pokemon::getXP()
{
	return my_XP;
}

//returns the nextlvlxp
int Pokemon::getNextLevelXP()
{
	return my_nexLvlXP;
}

//returns the lvl
int Pokemon::getLevel()
{
	return my_level;
}

//returns the maxHP of the pokemon
int Pokemon::getMaxHP()
{
	return my_maxHP;
}

//heals the pokemons hp to its max
void Pokemon::heal()
{
	my_HP = my_maxHP;
}

//sets the name to the passed in value
void Pokemon::setName(string name)
{
	my_name = name;
}

//sets the atk to the passed in value
void Pokemon::setAtk(int Atk)
{
	my_Atk = Atk;
}

//sets the def to the passed in value
void Pokemon::setDef(int Def)
{
	my_Def = Def;
}

//sets the hp to the passed in value
void Pokemon::setHP(int HP)
{
	if (HP < 0)
		HP = 0;
	if (HP > my_maxHP)
		HP = my_maxHP;
	my_HP = HP;
}

//sets the spatk to the passed in value
void Pokemon::setSpAtk(int SpAtk)
{
	my_SpAtk = SpAtk;
}

//sets the spdef to the passed in value
void Pokemon::setSpDef(int SpDef)
{
	my_SpDef = SpDef;
}

//sets the speed to the passed in value
void Pokemon::setSpeed(int speed)
{
	my_speed = speed;
}

//sets the userimage to the passed in value
void Pokemon::setUserImage(Sprite image)
{
	user_image = image;
}

//sets the oppimage to the passed in value
void Pokemon::setOppImage(Sprite image)
{
	opp_image = image;
}

//sets if the pokemon is wild
void Pokemon::setWild(int wild)
{
	my_wild = wild;
}

//sets the lvl to the passed in value
void Pokemon::setLevel(int level)
{
	my_level = level;
	my_multFact = 1 / 33.0 * my_level;
	my_HP *= my_multFact;
	my_maxHP *= my_multFact;
	my_battleXP = my_XP * my_multFact;
}

//sets the xp to the passed in value, changes level accordingly
void Pokemon::setXP(int XP)
{
	if (XP >= my_nexLvlXP)
	{
		setLevel(my_level + 1);
		XP = XP - my_nexLvlXP;
		setLevel(XP);
	}
	my_XP = XP;
}

//sets the nextlvlxp to the passed in value
void Pokemon::setNextLevelXP(int nextLvlXP)
{
	my_nexLvlXP = nextLvlXP;
}

//sets the evolvelvl to the passed in value
void Pokemon::setEvolveLevel(int evolveLvl)
{
	my_evolveLvl = evolveLvl;
}

//sets teh maxHP to the passed in value
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

//increments the level, adn checks eveolve accordingly
vector<Move> Pokemon::getMoves()
{
	return my_moves;
}

//adds a move the pokemon
void Pokemon::addMove(Move m)
{
	my_moves.push_back(m);
}

//returns a vector of the types that the pokemon is
vector<Type> Pokemon::getType()
{
	return my_types;
}

//sets the pokemons types the the two parameters
void Pokemon::setType(Type t1, Type t2)
{
	my_types[0] = t1;
	my_types[1] = t2;
}

//pritns the pokemon in such a way that the user can see only minimum info
void Pokemon::oppPrint()
{
	cout << my_name << endl;
	cout << "HP: " << my_HP << endl;
}

//prints the pokemon in such a way the user can unserstand it and help the user see their options in battle
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

//gets the moved stored at that index
Move Pokemon::getMove(int num)
{
	return my_moves[num];
}

//uses the move indexed by the int onto the pokemon passed, the double is the move strength agaisnt the pokemon	
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

//returns the battlexp
int Pokemon::battleEXP()
{
	return my_battleXP;
}

//evolves the pokemon
void Pokemon::evolve()
{
	return;
}
