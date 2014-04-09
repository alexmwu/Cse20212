/* Pokemon Project
Alex Hansen
Pokemon.h

Pokemon Class.
Pokemon Object

Stores all the attributes of a pokemon, getter/setter functions for the proper values, and some interaction functions
*/

#ifndef POKEMON_H
#define POKEMON_H
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Location.h"
#include "Sprite.h"
#include <string>
#include <vector>
#include "Move.h"
#include "Type.h"
using namespace std;

class Pokemon
{
public:
	Pokemon();
	Pokemon(int, int, int, int, int, int, Sprite ,Sprite , string, int, int, int, int, int, Type, Type);
	string getName();
	int getAtk();
	int getDef();
	int getHP();
	int getSpAtk();
	int getSpDef();
	int getSpeed();
	Sprite getUserImage();	//get user pokemon sprite
	Sprite getOppImage();	//get opponent pokemon sprite
	int isWild();
	int getLevel();
	int getXP();
	int getNextLevelXP();
	int getEvolveLevel();
	void setName(string);
	void setAtk(int);
	void setDef(int);
	void setHP(int);
	void setSpAtk(int);
	void setSpDef(int);
	void setSpeed(int);
	void setUserImage(Sprite);
	void setOppImage(Sprite);
	void setWild(int);
	void setLevel(int);
	void setXP(int);
	void setNextLevelXP(int);
	void setEvolveLevel(int);
	void levelUp();
	void evolve();
	void heal();
	vector<Move> getMoves();
	Move getMove(int);
	void addMove(Move);
	vector<Type> getType();
	void setType(Type, Type);
	void battlePrint();
	void oppPrint();
	int getMaxHP();
	void setMaxHP(int);
	void useMove(Pokemon*, int, double);
	//void useMove(Move m);
	//Type getType();
	//Item getEquipped();

private:
	//Item equipped;
	int my_index;
	int my_Atk;
	int my_Def;
	int my_HP;
	int my_SpAtk;
	int my_SpDef;
	int my_speed;
	string my_name;
	Sprite user_image;
	Sprite opp_image;
	int my_level;
	int my_XP;
	int my_nexLvlXP;
	int my_wild;
	int my_evolveLvl;
	int my_maxHP;
	vector<Move> my_moves;
	vector<Type> my_types;

};
#endif
