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
	Pokemon();			//blank pokemon object
	Pokemon(int, int, int, int, int, int, Sprite ,Sprite , string, int, int, int, int, int, Type, Type); //atk, def, HP, spAtk, spDef, speed, user Sprite, opp Sprite, string name, lvl, nextlevlXP, isWild, evolvelvl, Type1, Type2. Creates an object with the given attributes	
	string getName();		//returns the name
	int getAtk();			//returns the atk
	int getDef();			//returns the def
	int getHP();			//returns the hp
	int getSpAtk();			//returns the spatk
	int getSpDef();			//returns the spdef
	int getSpeed();			//returns the speed
	Sprite getUserSprite();		//get user pokemon sprite
	Sprite getOppSprite();		//get opponent pokemon sprite
	int isWild();			//returns if it is a wild pokemon
	int getLevel();			//returns the lvl
	int getXP();			//returns the xp
	int getNextLevelXP();		//returns the nextlvlxp
	int getEvolveLevel();		//returns the evolvelvl
	void setName(string);		//sets the name to the passed in value
	void setAtk(int);		//sets the atk to the passed in value
	void setDef(int);		//sets the def to the passed in value
	void setHP(int);		//sets the hp to the passed in value
	void setSpAtk(int);		//sets the spatk to the passed in value
	void setSpDef(int);		//sets the spdef to the passed in value
	void setSpeed(int);		//sets the speed to the passed in value
	void setUserSprite(Sprite);	//sets the userimage to the passed in value
	void setOppSprite(Sprite);	//sets the oppimage to the passed in value
	void setWild(int);		//sets if the pokemon is wild
	void setLevel(int);		//sets the lvl to the passed in value
	void setXP(int);		//sets the xp to the passed in value, changes level accordingly
	void setNextLevelXP(int);	//sets the nextlvlxp to the passed in value
	void setEvolveLevel(int);	//sets the evolvelvl to the passed in value
	void levelUp();			//increments the level, adn checks eveolve accordingly
	void evolve();			//evolves the pokemon
	void heal();			//heals the pokemons hp to its max
	vector<Move> getMoves();	//returns the vecotr of moves
	Move getMove(int);		//gets the moved stored at that index
	void addMove(Move);		//adds a move the pokemon
	vector<Type> getType();		//returns a vector of the types that the pokemon is
	void setType(Type, Type);	//sets the pokemons types the the two parameters
	void battlePrint();		//prints the pokemon in such a way the user can unserstand it and help the user see their options in battle
	void oppPrint();		//pritns the pokemon in such a way that the user can see only minimum info
	int getMaxHP();			//returns the maxHP of the pokemon
	void setMaxHP(int);		//sets teh maxHP to the passed in value
	void useMove(Pokemon*, int, double);	//uses the move indexed by the int onto the pokemon passed, the double is the move strength agaisnt the pokemon	
	int battleEXP();		//returns the battlexp
	//void useMove(Move m);
	//Type getType();
	//Item getEquipped();

private:
	//Item equipped;
	int my_index;		//stores the index of the pokemon
	int my_Atk;		//stores the value of the atk
	int my_Def;		//stores the value of the def
	int my_HP;		//stores the value of the hp
	int my_SpAtk;		//stores the value of the spatk
	int my_SpDef;		//stores the value of the spdef
	int my_speed;		//stores the value of the speed
	string my_name;		//stores the value of the name
	Sprite user_image;	//stores the value of the user image
	Sprite opp_image;	//stores the value of the opp image
	int my_level;		//stores the value of the lvl
	int my_XP;		//stores the value of the xp
	int my_nexLvlXP;	//stores the value how much xp it takes to reach the next lvl
	int my_wild;		//stores if the pokemon is wild
	int my_evolveLvl;	//stores the value of the evolve lvl
	int my_maxHP;		//stores the value of the maxHP
	vector<Move> my_moves;	//stores a vector of all the moves the pokemon knows
	vector<Type> my_types;	//stores a vector of types that the pokemon is
	double my_multFact;	//stores the value of the multFact, used to determine stats at each lvl
	int my_battleXP;	//stores the value of how much xp one would gain for defeating this pokemon
};
#endif
