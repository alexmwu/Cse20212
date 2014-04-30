#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "BoardPiece.h"
#include "Location.h"
#include "Pokemon.h"
#include <fstream>
#include <vector>
#include "Sprite.h"
#include <sstream>
#include <iterator>
#include "Type.h"
#include "Move.h"
#include "Pokeball.h"
#include "Timer.h"
#include <time.h>
#include "Game.h"
#include "Trainer.h"
#include "Item.h"
#include "Potion.h"
#include <cctype>
using namespace std;

//Constructor, creates a game object to be played 
Game::Game(int sw, int sh, int sbpp, int movespeed, int  fps)
{
	screen=NULL;
	map=NULL;
	trainers=NULL;
	battlescene=NULL;

	battlemenu=NULL;
	buildings=NULL;	
	environment=NULL;
	envpokemon=NULL;
	heroes=NULL;
	misc=NULL;
	npcs=NULL;
	pokemenu=NULL;
	battlepokemon=NULL;

	screen_width=sw;
	screen_height=sh;
	screen_bpp=sbpp;
	move_speed=movespeed;
	frames_per_second=fps;
	
	srand(time(NULL));
	
	//initializes all the objects for the game
	initializeSDL();
	initializeSpriteSheets();
	initializeSprites();
	drawMap();
	//printMap();
	initializeTypes();
	initializeTypeChart();
	initializeMoves();
	initializePokemon();
	initializeTrainers();
	initializeLocationPairs();
}


SDL_Surface * Game::loadImage(string filename)
{
	//The image that's loaded
	SDL_Surface* loadedImage = NULL;

	//The optimized image that will be used
	SDL_Surface* optimizedImage = NULL;

	//Load the image
	loadedImage = IMG_Load(filename.c_str());

	/*
	//If the image loaded
	if (loadedImage != NULL)
	{
		//Create an optimized image
		optimizedImage = SDL_DisplayFormat(loadedImage);

		//Free the old image
		SDL_FreeSurface(loadedImage);
	}


	//Return the optimized image
	return optimizedImage;
	*/
	return loadedImage;
}

SDL_Surface *Game::switchSheet(int sheetindex){
	switch(sheetindex){
		case 1:
			return battlemenu;
			break;
		case 2:
			return buildings;
			break;
		case 3:
			return environment;
			break;
		case 4:
			return envpokemon;
			break;
		case 5:
			return heroes;
			break;
		case 6:
			return misc;
			break;
		case 7:
			return npcs;
			break;
		case 8:
			return pokemenu;
			break;
		case 9:
			return battlepokemon;
			break;
		default:
			return NULL;
			break;	
	}
	
}


void Game::initializeSpriteSheets(){
	battlemenu=loadImage("images/battlemenu.png");
	buildings=loadImage("images/buildings.png");
	environment=loadImage("images/environment.png");
	envpokemon=loadImage("images/envpokemon.png");
	heroes=loadImage("images/heroes.png");
	misc=loadImage("images/misc.png");
	npcs=loadImage("images/npcs.png");
	pokemenu=loadImage("images/pokemenu.png");
	battlepokemon=loadImage("images/battlepokemon.png");
}


void Game::initializeSDL(){

	//Initialize all SDL subsystems
	SDL_Init(SDL_INIT_EVERYTHING);

	//Set up the screen
	screen = SDL_SetVideoMode(screen_width, screen_height, screen_bpp, SDL_SWSURFACE);
	//init map and battlescene
// 	map=SDL_SetVideoMode(screen_width,screen_height,screen_bpp,SDL_SWSURFACE);
// 	trainers=SDL_SetVideoMode(screen_width,screen_height,screen_bpp,SDL_SWSURFACE);
//	battlescene=SDL_SetVideoMode(screen_width,screen_height,screen_bpp,SDL_SWSURFACE);

	//enable key repeating
	SDL_EnableKeyRepeat(1, move_speed);

	//Set the window caption
	SDL_WM_SetCaption("Pokemon NotreDame", NULL);
}

void Game::quitSDL(){
		SDL_FreeSurface(map);		//free map
		SDL_FreeSurface(trainers);	//free trainers
		SDL_FreeSurface(battlescene);
		SDL_FreeSurface(screen);

		SDL_FreeSurface(battlepokemon);
		SDL_FreeSurface(battlemenu);
		SDL_FreeSurface(buildings);
		SDL_FreeSurface(environment);
		SDL_FreeSurface(envpokemon);
		SDL_FreeSurface(heroes);
		SDL_FreeSurface(misc);
		SDL_FreeSurface(npcs);
		SDL_FreeSurface(pokemenu);
		SDL_Quit();		//auto frees the screen
}

//Reads in data from text file and creates pokemon objects from it
void Game::initializePokemon() 
{
	string file = "text/PokemonFile.txt";
	ifstream myfile;
	myfile.open(file.c_str());
	string line;
	string attribute[32];
	int read = 0;
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			if (line == "+++++")
			{
				getline(myfile, line);
				if (line != "000)")
				{
					read = 1;
				}
			}
			if (!read)
				getline(myfile, line);
			else
			{
				myfile >> attribute[0];
				myfile >> attribute[1];
				myfile >> attribute[2];
				myfile >> attribute[3];
				myfile >> attribute[4];
				myfile >> attribute[5];
				myfile >> attribute[6];
				myfile >> attribute[7];
				myfile >> attribute[8];
				myfile >> attribute[9];
				myfile >> attribute[10];
				myfile >> attribute[11];
				myfile >> attribute[12];
				myfile >> attribute[13];
				myfile >> attribute[14];
				myfile >> attribute[15];
				myfile >> attribute[16];
				myfile >> attribute[17];
				myfile >> attribute[18];
				myfile >> attribute[19];
				myfile >> attribute[20];
				myfile >> attribute[21];
				myfile >> attribute[22];
				myfile >> attribute[23];
				myfile >> attribute[24];
				myfile >> attribute[25];
				myfile >> attribute[26];
				myfile >> attribute[27];
				myfile >> attribute[28];
				myfile >> attribute[29];
				myfile >> attribute[30];
				myfile >> attribute[31];
				Sprite s1=getSprite(attribute[29]);
				Sprite s2=getSprite(attribute[31]);
				Type t1 = getType(attribute[3]);
				Type t2 = getType(attribute[5]);

				Pokemon newPokemon(atoi(attribute[7].c_str()), atoi(attribute[9].c_str()), atoi(attribute[15].c_str()), atoi(attribute[11].c_str()),atoi(attribute[13].c_str()), atoi(attribute[17].c_str()), s1, s2, attribute[1], atoi(attribute[19].c_str()), atoi(attribute[21].c_str()), atoi(attribute[23].c_str()), atoi(attribute[25].c_str()),atoi(attribute[27].c_str()), t1, t2);
				my_pokemon.push_back(newPokemon);
				read = 0;
				for (int i = 0; i < 2; i++)
				{	
					getline(myfile, line);
				}
			}
		}
	}
}

//reads in data from text file and creates Sprite objects from it
void Game::initializeSprites() 
{
	string file = "text/Sprites.txt";
	ifstream myfile;
	myfile.open(file.c_str());
	string line;
	string attribute[14];
	int read = 0;
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			if (line == "+++++")
			{
				getline(myfile, line);
				if (line != "000)")
					read = 1;
			}
			if (!read)
				getline(myfile, line);
			else
			{
				myfile >> attribute[0];
				myfile >> attribute[1];
				myfile >> attribute[2];
				myfile >> attribute[3];
				myfile >> attribute[4];
				myfile >> attribute[5];
				myfile >> attribute[6];
				myfile >> attribute[7];
				myfile >> attribute[8];
				myfile >> attribute[9];
				myfile >> attribute[10];
				myfile >> attribute[11];
				myfile >> attribute[12];
				myfile >> attribute[13];
				Sprite newSprite(switchSheet(atoi(attribute[1].c_str())), attribute[3], atoi(attribute[7].c_str()), atoi(attribute[9].c_str()), atoi(attribute[11].c_str()), atoi(attribute[13].c_str()), atoi(attribute[4].c_str()), atoi(attribute[5].c_str()));
				my_sprites.push_back(newSprite);
				read = 0;
				for (int i = 0; i < 2; i++)
					getline(myfile, line);
			}
		}
	}
}

//initializes boardpieces
void Game::drawMap()
{
	string file = "text/Map.txt";
	ifstream myfile;
	myfile.open(file.c_str());
	string line;
	int read = 0;
	vector<BoardPiece> temp;
	int x = 0;
	Location loc;
	Sprite s;
	BoardPiece b;
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, line);
			stringstream ss(line);
			istream_iterator<string> begin(ss);
			istream_iterator<string> end;
			vector<string> tokens(begin, end);
			for (int i = 0; i < tokens.size(); i++)
			{
				loc = Location(x, i);
				s = getSprite(tokens[i]);
				b = BoardPiece(s, loc, s.getWalk(), s.getInteract());
				temp.push_back(b);
			}
			my_map.push_back(temp);
			temp.clear();
			tokens.clear();
			x++;
		}		
	}
}

//returns the sprite with the name of the string parameter
Sprite Game::getSprite(string name)
{
	Sprite s = Sprite();
	for (int i = 0; i < my_sprites.size(); i++)
	{
		if (my_sprites[i].getName() == name)
			return my_sprites[i];
	}
	cout<<"Couldn't find sprite." << name <<endl;
	return s;
}

//prints out the map with just sprite names in the terminal window
void Game::printMap()
{
	//prints out the first element in the 3d array. If it is a 0 it hasnt been solved for yet.
	for (int i = 0; i < my_map.size(); i++)
	{
		for (int j = 0; j < my_map[i].size(); j++)
		{
			cout << my_map[i][j].getSprite().getName() << " ";
		}
		cout << endl;
	}
}

//reads in data from text file and creates Types objects from it
void Game::initializeTypes()
{
	string file = "text/Types.txt";
	ifstream myfile;
	myfile.open(file.c_str());
	string line;
	string attribute[4];
	int read = 0;
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			if (line == "+++++")
			{
				getline(myfile, line);
				if (line != "000)")
					read = 1;
			}
			if (!read)
				getline(myfile, line);
			else
			{
				myfile >> attribute[0];
				myfile >> attribute[1];
				myfile >> attribute[2];
				myfile >> attribute[3];
				Type newType(attribute[1], atoi(attribute[3].c_str()));
				my_types.push_back(newType);
				read = 0;
				for (int i = 0; i < 2; i++)
					getline(myfile, line);
			}
		}
	}
}

//Initializes the location pairs for movement between enveironment and buidlings
void Game::initializeLocationPairs()
{
	string file = "text/LocationPairs.txt";
	ifstream myfile;
	myfile.open(file.c_str());
	string line;
	string attribute[4];
	int read = 0;
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			if (line == "+++++")
			{
				getline(myfile, line);
				if (line != "000)")
					read = 1;
			}
			if (!read)
				getline(myfile, line);
			else
			{
				myfile >> attribute[0];
				myfile >> attribute[1];
				myfile >> attribute[2];
				myfile >> attribute[3];
				Location one = Location(atoi(attribute[0].c_str()), atoi(attribute[1].c_str()));
				Location two = Location(atoi(attribute[2].c_str()), atoi(attribute[3].c_str()));
				pair<Location, Location> p = pair<Location, Location>(one, two);
				my_locationPairs.push_back(p);
				read = 0;
				for (int i = 0; i < 2; i++)
					getline(myfile, line);
			}
		}
	}
}

//reads in data from text file and creates a type chart used for strength from it
void Game::initializeTypeChart()
{
	string file = "text/TypeChart.txt";
	ifstream myfile;
	myfile.open(file.c_str());
	string line;
	vector<char> temp;
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, line);
			for (int i = 0; i < line.size(); i += 2)
				temp.push_back(line[i]);
			my_typeChart.push_back(temp);
			temp.clear();
		}
	}
}

//given the two types returns the effectiveness of the first against the second(superEffective =2, normal =1, not veery effective =.5, not effectiv =0)
double Game::getTypeStrength(Type user, Type opp)
{
	char strength = my_typeChart[user.getIndex()][opp.getIndex()];
	switch (strength)
	{
	case 's':
		return 2;
		break;
	case 'w':
		return .5;
		break;
	case 'n':
		return 0;
		break;
	default:
		return 1;
		break;
	}
}

//returns the type who has the name of the string input
Type Game::getType(string name)
{
	Type s = Type();
	for (int i = 0; i < my_types.size(); i++)
	{
		if (my_types[i].getName() == name)
			return my_types[i];
	}
	return s;
}

//reads in data from text file and creates pokemon objects from it
void Game::initializeMoves()
{
	string file = "text/Moves.txt";
	ifstream myfile;
	myfile.open(file.c_str());
	string line;
	string attribute[12];
	int read = 0;
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			if (line == "+++++")
			{
				getline(myfile, line);
				if (line != "000)")
					read = 1;
			}
			if (!read)
				getline(myfile, line);
			else
			{
				myfile >> attribute[0];
				myfile >> attribute[1];
				myfile >> attribute[2];
				myfile >> attribute[3];
				myfile >> attribute[4];
				myfile >> attribute[5];
				myfile >> attribute[6];
				myfile >> attribute[7];
				myfile >> attribute[8];
				myfile >> attribute[9];
				myfile >> attribute[10];
				myfile >> attribute[11];
				Type t = getType(attribute[3]);
				Move newMove(attribute[1], t, atoi(attribute[5].c_str()), atoi(attribute[7].c_str())*1.0/100, atoi(attribute[9].c_str()), attribute[11]);
				my_moves.push_back(newMove);
				read = 0;
				for (int i = 0; i < 2; i++)
					getline(myfile, line);
			}
		}
	}
}

//reads in data from text file and creates trainers objects from it
void Game::initializeTrainers()
{
	string file = "text/Trainers.txt";
	ifstream myfile;
	myfile.open(file.c_str());
	string line;
	Trainer temp = Trainer();
	int newTrainer = 0;
	Location loc = Location();
	BoardPiece piece = BoardPiece();
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, line);
			stringstream ss(line);
			istream_iterator<string> begin(ss);
			istream_iterator<string> end;
			vector<string> tokens(begin, end);
			if (tokens.size() <= 0)
			{
				continue;
			}
			else if (tokens[0] == "+++++")
			{
				newTrainer = 1;
				getline(myfile, line);
			}
			else if (tokens[0] == "###")
			{
				newTrainer = 3;
			}
			else if (newTrainer == 1)
			{
				newTrainer = 2;
				loc = Location(atoi(tokens[2].c_str()), atoi(tokens[3].c_str()));
				piece = BoardPiece(getSprite(tokens[4]), loc, 0, 1);
				temp = Trainer(tokens[1], piece,getSprite(tokens[5]));						
			}
			else if (newTrainer == 2)
			{
				Pokemon pTemp = Pokemon();
				for (int i = 0; i < tokens.size(); i++)
				{		
					if (i == 0)
						pTemp = getPokemon(tokens[i]);
					else if (i == 1)
						pTemp.setLevel(atoi(tokens[i].c_str()));
					else
						pTemp.addMove(getMove(tokens[i]));
				}
				pTemp.setName(pTemp.getName());
				Pokemon * ptt = &pTemp;
				temp.addToParty(pTemp);
			}
			if (newTrainer == 3)
			{
				my_trainers.push_back(temp);
				newTrainer = 0;
			}			
			tokens.clear();
		}
	}
}

//returns the move that has the name of the string input
Move Game::getMove(string name)
{
	Move m = Move();
	for (int i = 0; i < my_moves.size(); i++)
	{
		if (my_moves[i].getName() == name)
			return my_moves[i];
	}
	return m;
}

Sprite Game::charToSprite(char c){
	string query;
	if(isalpha(c)){	//alphabetical char
		if(islower(c)){	//lowercase
			query="BoldLower";
			c=toupper(c);
			query+=c;
		}
		else if(isupper(c)){	//uppercase
			query="BoldUpper";
			c=toupper(c);
			query+=c;
		}
	}
	else if(isdigit(c)){	//is number
		query="Bold";
		query+=c;
	}
	else{	//punctuation and other random symbols (like male/female)
		if(ispunct(c) && c!=34 && c!=39){
			switch(c){
				case '.':
					query="BoldPeriod";
					break;
				case ',':
					query="BoldComma";
					break;
				case '!':
					query="BoldExclamation";
					break;
				case '?':
					query="BoldQuestion";
					break;
				case '/':
					query="BoldSlash";
					break;
				case '-':
					query="BoldHyphen";
					break;
				default:
					break;
			}
		}
		else{
			switch(c){
				case '[':
					query="BoldMale";
					break;
				case ']':
					query="BoldFemale";
					break;
				case 92:
					query="BoldEllipsis";
					break;
				case '(':
					query="BoldOpenDoubleQuotes";
					break;
				case ')':
					query="BoldClosedDoubleQuotes";
					break;
				case '`':
					query="BoldOpenSingleQuote";
					break;
				case 34:
					query="BoldClosedSingleQuote";
					break;
			}
		}
	}
return getSprite(query);
}


void Game::textToSDL(string text, int textWidth, int x, int y, int gap){
	int spriteWidth=6;	//a text sprite's width
	int spriteLength=15;	//a bit more than their average lengths
	int oldX=x;
	for(int i=0;i<text.size();i++){
		if((x+spriteWidth*3)>(oldX+textWidth))
		{
			//if(text.at(i)!=' '){
			//	getSprite("BoldHyphen").display(x,y,screen);
			//}
			y+=spriteLength;
			x=oldX;
			i-=1;
			continue;
		}
		if(text.at(i)==' '){
			x+=spriteWidth+gap;
			continue;
			}
		charToSprite(text.at(i)).display(x,y,screen);
		x+=spriteWidth+gap;
	}
}

//runs a battle sequece between two pokemon
pair<int, int> Game::battle(Pokemon* user, Pokemon* opp)
{
	//returns 0 if user faints
	//returns 1 if user wants to switch Pokemon
	//returns 2 if the opponentn faints
	//reuurns 3 if user throws a pokeball
	//returns 4 if user uses a potion
	//returns 5 if somehow none of these cases are met(5 would be a bug)
	pair<int, int> returnVal = pair<int,int>(0, 0);
	int move = -1;
	int oppMove = 0;
	double strength = 0;
	int canMove = 1;

	displayBar(*user,*opp,"Go "+user->getName()+"!",0);
	SDL_Flip(screen);
	SDL_Delay(1000);

	displayBar(*user,*opp,"What would you like to do?",0);
	SDL_Flip(screen);
	SDL_Delay(1000);
	while (user->getHP() > 0 && opp->getHP() > 0) // check to see if both pokemon are still useable
	{
		canMove = 1;
		int i;
		oppMove = rand() % opp->getMoves().size();
		//opp->oppPrint();
		stringstream display;
		//cout << endl;
		//user->battlePrint();
		for (i = 0; i < 4; i++)
		{
			display<<i<<" "<<user->getMove(i).getName()<<"        ";
		}
		string displayMoves=display.str();

		//moves that pokemon has
		displayBar(*user,*opp,displayMoves,0);
		SDL_Flip(screen);
		SDL_Delay(1000);
		//other options
		stringstream others;
		others<<i<<" "<<"Throw Pokeball."<<"  ";
		others<<++i<<" "<<"Switch Pokemon.";
		others<<++i<<" "<<"Use a Potion.";
		string othersDisplay=others.str();
		while (SDL_PollEvent(&event) || move==-1){
			//If a key was pressed
				if (event.type == SDL_KEYDOWN){	
					switch (event.key.keysym.sym){
						case SDLK_DOWN:{
							displayBar(*user,*opp,othersDisplay,0);
							SDL_Flip(screen);
							break;
						}
						case SDLK_UP:{
							stringstream display2;
							for (i = 0; i < 4; i++)
							{
								display2<<i<<" "<<user->getMove(i).getName()<<"        ";
							}
							string displayMoves2=display2.str();


							displayBar(*user,*opp,displayMoves2,0);
							SDL_Flip(screen);
							break;
						}
						case SDLK_0:
							if(i>=0) move=0;
							break;
						case SDLK_1:
							if(i>=1) move=1;
							break;
						case SDLK_2:
							if(i>=2) move=2;
							break;
						case SDLK_3:
							if(i>=3) move=3;
							break;
						case SDLK_4:
							if(i>=4) move=4;
							break;
						case SDLK_5:
							if(i>=5) move=5;
							break;
						case SDLK_6:
							if(i>=6) move=6;
							break;
						default:
							break;
					}
				}	
		}

		if (move == user->getMoves().size())
		{
			canMove = 0;
			int result=my_pokeballs[0].canCatch(*opp);
			if(result==1){
				displayBar(*user,*opp,opp->getName() + " was successfully caught!",0);
				SDL_Flip(screen);
				SDL_Delay(1000);
				returnVal.first = 3; //returns 3 if user tries to throw a pokeball
				return returnVal;
			}
			else if(result==-1){	//another trainer's pokemon
				displayBar(*user,*opp,"You cannot catch another trainer's Pokemon!",0);
				SDL_Flip(screen);
				SDL_Delay(1000);
			}
			else if(result==0){	//it broke free
				displayBar(*user,*opp, "Oh no, it broke free!",0);
				SDL_Flip(screen);
				SDL_Delay(1000);
			}
			move=-1;
		}
		else if (move == user->getMoves().size() + 1)
		{
			returnVal.first = 1;
			returnVal.second = user->getHP(); //returns 1 if user wants to switch pokemon
			return returnVal;
		}
		else if (move == user->getMoves().size() + 2)
		{
			canMove = 0;
			returnVal.first = 4;	//returns 4 if the user uses a potion
			return returnVal;
		}

		//if no value has been returned yet it will check to see which pokemon is faster
		//if the user is faster it will move first
		if (user->getSpeed() >= opp->getSpeed() && canMove) 
		{
			//calculates the move strength and then uses the move
			strength = getTypeStrength(user->getMove(move).getType(), opp->getType()[0]);
			if (opp->getType()[1].getName() != "")
				strength *= getTypeStrength(user->getMove(move).getType(), opp->getType()[1]);
			user->useMove(opp, move, strength);
			
			//checks to see if the opponent has fainted from the attack
			if (opp->getHP() <= 0)
			{
				displayBar(*user,*opp,opp->getName() + " has fainted.",0);
				SDL_Flip(screen);
				SDL_Delay(1000);
				returnVal.first = 2; //returns 2 if the opponent fainted
				return returnVal;
			}
			
			//calculates the move strength and then uses the move
			strength = getTypeStrength(opp->getMove(oppMove).getType(), user->getType()[0]);
			if (user->getType()[1].getName() != "")
				strength *= getTypeStrength(opp->getMove(oppMove).getType(), user->getType()[1]);
			opp->useMove(user, oppMove, strength);

			//checks if the user has fainted from the attack
			if (user->getHP() <= 0)
			{
				displayBar(*user,*opp,user->getName() + " has fainted.",0);
				SDL_Flip(screen);
				SDL_Delay(1000);
				returnVal.first = 0; //returns 0 if the user faints
				return returnVal;
			}
		}
		else if (canMove)
		{
			//calculates the move strength and then uses the move
			strength = getTypeStrength(opp->getMove(oppMove).getType(), user->getType()[0]);
			if (user->getType()[1].getName() != "")
				strength *= getTypeStrength(opp->getMove(oppMove).getType(), user->getType()[1]);
			opp->useMove(user, oppMove, strength);

			//checks if the user has fainted from the attack
			if (user->getHP() <= 0)
			{
				displayBar(*user,*opp,user->getName() + " has fainted.",0);
				SDL_Flip(screen);
				SDL_Delay(1000);
				returnVal.first = 0; //returns 0 if the user faints
				return returnVal;
			}

			//calculates the move strength and then uses the move
			strength = getTypeStrength(user->getMove(move).getType(), opp->getType()[0]);
			if (opp->getType()[1].getName() != "")
				strength *= getTypeStrength(user->getMove(move).getType(), opp->getType()[1]);
			user->useMove(opp, move, strength);

			//calculates the move strength and then uses the move
			if (opp->getHP() <= 0)
			{
				displayBar(*user,*opp,opp->getName() + " has fainted.",0);
				SDL_Flip(screen);
				SDL_Delay(1000);
				returnVal.first = 2;	//returns 2 if the opponent faints
				return returnVal;
			}

		}
		else
		{
			//calculates the move strength and then uses the move
			strength = getTypeStrength(opp->getMove(oppMove).getType(), user->getType()[0]);
			if (user->getType()[1].getName() != "")
				strength *= getTypeStrength(opp->getMove(oppMove).getType(), user->getType()[1]);
			opp->useMove(user, oppMove, strength);


			if (user->getHP() <= 0)
			{
				displayBar(*user,*opp,user->getName() + " has fainted.",0);
				SDL_Flip(screen);
				SDL_Delay(1000);
				returnVal.first = 0; //returns 0 if the user faints
				return returnVal;
			}
		}
		move=-1;	//reset move
	}
	returnVal.first = 5;
	return returnVal;
}



//trainer v trainer, in turn it runs the pokemon v pokemon function for each match up
void Game::battle(Trainer *user, Trainer *opp)
{
	//cout << user->getName() << " VS " << opp->getName() << endl;
	int swap = -1;
	int item = -1;
	int uA = user->getFirstAvailablePokemon();
	int oA = 0;
	Item potion = Item();
	Pokemon userA = user->getPokemon(uA); //gets the user and opponents first pokemon in their parties
	Pokemon oppA = opp->getPokemon(oA);
	Pokemon swapper = Pokemon();

	whiteScreen();
	displayBar(*user,*opp,opp->getName()+" would like to battle!",0);
	SDL_Flip(screen);
	SDL_Delay(1000);
	while (user->getNumPokemonAvalible() > 0 && opp->getNumPokemonAvalible() > 0)
	{
		//cout << "Trainer: " << opp->getNumPokemonAvalible() << " User: " << user->getNumPokemonAvalible() << endl;
		pair<int, int> num = battle(&userA, &oppA); //gets the result of the battle from the two pokemon
		if (num.first == 1) //1 means user wants to swap pokemon
		{
			user->swapPokemon(uA, num.second); //stores the HP of the previously active pokemon
		//	user->printPokemon(); //pritns the users pokemon out so that they can see their options
			int i;
			stringstream party;
			for (i = 0; i < user->getParty().size(); i++)
				{
					party << i << " " <<user->getPokemon(i).getName()<<" ";
				}
			string displayParty=party.str();
			while (1) //loops assure the user is inputing proper input for the sawp and then preferms the switch
			{
				while (swap < 0 || swap > user->getParty().size())
				{
					displayBar(*user,*opp,"Which Pokemon do you want to swap?",0);
					SDL_Flip(screen);
					SDL_Delay(1000);
					displayBar(*user,*opp,displayParty,0);
					SDL_Flip(screen);
					SDL_Delay(1000);
while (SDL_PollEvent(&event) || swap==-1){
			//If a key was pressed
				if (event.type == SDL_KEYDOWN){	
					switch (event.key.keysym.sym){
						case SDLK_0:
							if(user->getParty().size()>=1) swap=0;
							break;
						case SDLK_1:
							if(user->getParty().size()>=2) swap=1;
							break;
						case SDLK_2:
							if(user->getParty().size()>=3) swap=2;
							break;
						case SDLK_3:
							if(user->getParty().size()>=4) swap=3;
							break;
						}
					}	
				}
				}
				swapper = user->getPokemon(swap);
				if (swapper.getHP() == 0)
				{
					displayBar(*user,*opp,"That Pokemon has fainted, try again",0);
					SDL_Flip(screen);
					SDL_Delay(1000);
				
					swap = -1;
					continue;
				}
				userA = user->getPokemon(swap);
				num.first = -1;
				swap = -1;
				break;
			}			
		}
		else if (num.first == 0) // 0 means user fainted
		{
			
			int i;
			stringstream party;
			for (i = 0; i < user->getParty().size(); i++)
			{
				//party << i << " " <<user->getPokemon(i).getName()<<" ";
			}
			string displayParty=party.str();
			user->swapPokemon(uA, 0); // sets the pokemons helth to 0
			if (user->getNumPokemonAvalible() == 0) //if this was the user's last pokemon, it breaks the loop
				break;
			user->printPokemon(); //prints pokemon in party
			while (1) //loops assure the user inputs proper input for the switch, then switches the pokemon
			{
				while (swap < 0 || swap > user->getParty().size())
				{
					displayBar(*user,*opp,"Which Pokemon do you want to swap?",0);
					SDL_Flip(screen);
					SDL_Delay(1000);
					displayBar(*user,*opp,displayParty,0);
					SDL_Flip(screen);
					SDL_Delay(1000);
while (SDL_PollEvent(&event) || swap==-1){
			//If a key was pressed
				if (event.type == SDL_KEYDOWN){	
					switch (event.key.keysym.sym){
						case SDLK_0:
							if(user->getParty().size()>=1) swap=0;
							break;
						case SDLK_1:
							if(user->getParty().size()>=2) swap=1;
							break;
						case SDLK_2:
							if(user->getParty().size()>=3) swap=2;
							break;
						case SDLK_3:
							if(user->getParty().size()>=4) swap=3;
							break;
						}
					}	
				}
				}
				swapper = user->getPokemon(swap);
				if (swapper.getHP() == 0)
				{
					displayBar(*user,*opp,"That Pokemon has fainted, try again",0);
					SDL_Flip(screen);
					SDL_Delay(1000);
				
					swap = -1;
					continue;
				}
				userA = user->getPokemon(swap);
				uA = swap;
				num.first = -1;
				swap = -1;
				break;
			}
		}
		else if (num.first == 2)	//2 means opponent fainted
		{
			int XP = userA.getXP() + oppA.battleEXP(); //gives the user pokemon the XP for defeating a pokemon
			displayBar(userA,oppA,userA.getName()+" has gained experience!",0);
			SDL_Flip(screen);
			SDL_Delay(1000);
			user->updateXP(uA, XP);
			opp->swapPokemon(oA, 0);
			//cout << opp->getPokemon(uA).getHP() << " fainted" << endl;
			if (opp->getNumPokemonAvalible() < 1) //checks to see if the opponent has any more pokemon avalible
				break;
			while (1) //randomly selects a valid pokemon from the user's party
			{
				swap = rand() % (opp->getParty().size());
				swapper = opp->getPokemon(swap);
				if (swapper.getHP() == 0)
				{
					swap = -1;
					continue;
				}
				oppA = opp->getPokemon(swap);
				num.first = -1;
				oA = swap;
				swap = -1;
				break;
			}
		}
		else if (num.first == 3) // means user successfully caught a pokemon
		{
			user->addToParty(oppA); //adds the pokemon to the user's party
			return;
		}
		else if (num.first == 4) //user wants to use a potion
		{
			int i;
			stringstream party;
			for (i = 0; i < user->getParty().size(); i++)
				{
					party << i << " " <<user->getPokemon(i).getName()<<" ";
				}
			string displayParty=party.str();
			user->swapPokemon(uA, 0); // sets the pokemons helth to 0
			//user->printPotions(); //prints avalible potions
			while (item < 0 || item > user->getPotions().size()) //confirms proper input
			{
				item=0;
			}
			//user->printPokemon(); //prints pokemon to use potion on
			while (swap < 0 || swap > user->getParty().size()) //confirms proper input
			{
				displayBar(*user,*opp,"Which Pokemon do you want to use it on?",0);
					SDL_Flip(screen);
					SDL_Delay(1000);
					displayBar(*user,*opp,displayParty,0);
					SDL_Flip(screen);
					SDL_Delay(1000);
while (SDL_PollEvent(&event) || swap==-1){
			//If a key was pressed
				if (event.type == SDL_KEYDOWN){	
					switch (event.key.keysym.sym){
						case SDLK_0:
							if(user->getParty().size()>=1) swap=0;
							break;
						case SDLK_1:
							if(user->getParty().size()>=2) swap=1;
							break;
						case SDLK_2:
							if(user->getParty().size()>=3) swap=2;
							break;
						case SDLK_3:
							if(user->getParty().size()>=4) swap=3;
							break;
						}
					}	
				}
			}
			user->usePotion(item, user->getPokemon(swap)); //uses potion
			num.first = -1;
			swap = 0;
		}
	}	
	if (user->getNumPokemonAvalible() == 0){ //check to see which trainer ran out of pokemon when the battle ended.
		displayBar(*user,*opp,"You're out of Pokemon!",0);
		SDL_Flip(screen);
		SDL_Delay(1000);
		}
	else{
		displayBar(*user,*opp,"You beat "+opp->getName()+"!",0);
		removeTrainer(opp->getName());
		SDL_Flip(screen);
		SDL_Delay(1000);
		}
	return;
}

void Game::removeTrainer(string name)
{
	for(int i = 1; i < my_trainers.size(); i++)
	{
		if(my_trainers[i].getName() == name)
		{
			my_trainers.erase(my_trainers.begin() + i);
			i--;
		}
	}
}

//returns the pokemon whose name is the same as the string
Pokemon Game::getPokemon(string name)
{
	for (int i = 0; i < my_pokemon.size(); i++)
	{
		if (my_pokemon[i].getName() == name)
			return my_pokemon[i];
	}
	Pokemon p = Pokemon();
	return p;
}

void Game::whiteScreen(){
SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));
}

//prints all the pokemon that have been instantiated
void Game::printPokemon()
{
	for (int i = 0; i < my_pokemon.size(); i++)
	{
		//cout << i << ") " << my_pokemon[i].getName() << " " << my_pokemon[i].getType()[0].getName() << " " << my_pokemon[i].getType()[1].getName() << endl;
	}
}


void Game::displayBar(Trainer user,Trainer opp, string text, int gap){

	int battleTextWidth=screen_width-getSprite("BattleOptions").getWidth();	//available space to work with battle text

	whiteScreen();

//goes last
	user.getSprite().display(40,screen_height-40-user.getSprite().getHeight(),screen);
	opp.getSprite().display(screen_width-40-opp.getSprite().getWidth(),30,screen);
	getSprite("BattleText").display(0,screen_height-getSprite("BattleText").getHeight(),screen);
//	getSprite("BattleOptions").display(battleTextWidth,screen_height-getSprite("BattleOptions").getHeight(),screen);
	textToSDL(text,battleTextWidth,10,screen_height-getSprite("BattleText").getHeight()+10,gap);
}

void Game::displayBar(Pokemon userPoke,Pokemon oppPoke, string text,int gap){
//		whiteScreen();
//		user.getUserImage().display(20,400,battlescene);
//		opp.getOppImage().display(560,20,battlescene);
// 		whiteScreen();
//		applySurface(0,0,battlescene,screen);
//		SDL_Flip(screen);

	int battleTextWidth=screen_width-getSprite("BattleOptions").getWidth();	//available space to work with battle text
	Sprite oppHPSprite;
	Sprite userHPSprite;
	whiteScreen();

//so we don't have to use getsprite each time (which is inefficient)
	Sprite upb=getSprite("UserPokemonBar");	
	Sprite opb=getSprite("OppPokemonBar");
	Sprite bt=getSprite("BattleText");
	Sprite bo=getSprite("BattleOptions");
//goes last
	userPoke.getUserSprite().display(40,screen_height-30-userPoke.getUserSprite().getHeight(),screen);
	oppPoke.getOppSprite().display(screen_width-40-oppPoke.getOppSprite().getWidth(),30,screen);
	upb.display(screen_width-10-upb.getWidth(),screen_height-50-upb.getHeight(),screen);
	opb.display(10,15,screen);
	bt.display(0,screen_height-bt.getHeight(),screen);
//	bo.display(battleTextWidth,screen_height-bo.getHeight(),screen);
	textToSDL(text,battleTextWidth,10,screen_height-bt.getHeight()+10,0);

	//hp bars and xp bars find sprite to use based on health
	double oppPercentHP=((double)oppPoke.getHP()/(double)oppPoke.getMaxHP());
	double userPercentHP=((double)userPoke.getHP()/(double)userPoke.getMaxHP());
	double userPercentXP=((double)userPoke.getXP()/(double)userPoke.getNextLevelXP());
		if(oppPercentHP<(1/3.0)) oppHPSprite=getSprite("BattleYellowHP");
		else if(oppPercentHP<(1/10.0)) userHPSprite=getSprite("BattleRedHP");
		else oppHPSprite=getSprite("BattleGreenHP");

		if(userPercentHP<(1/3.0)) userHPSprite=getSprite("BattleYellowHP");
		else if(userPercentHP<(1/10.0)) userHPSprite=getSprite("BattleRedHP");
		else userHPSprite=getSprite("BattleGreenHP");
cout<<oppPercentHP<<"op"<<endl<<userPercentHP<<"user"<<endl;		
//fill bars for hp and xp
	for(int ohp=0;ohp<oppPercentHP*48;ohp++){
		oppHPSprite.display(10+40+ohp,15+18,screen);
	}
//cout<<userPoke.getHP()<<userPoke.getMaxHP();
	for(int uhp=0;uhp<userPercentHP*48;uhp++){
		userHPSprite.display(screen_width-10-upb.getWidth()+49+uhp,screen_height-50-upb.getHeight()+18,screen);
	}
	for(int xp=0;xp<userPercentXP*64;xp++){
		getSprite("BattleXP").display(screen_width-10-upb.getWidth()+33+xp,screen_height-50-upb.getHeight()+33,screen);
	}

//add pokemon info
	textToSDL(userPoke.getName()/*+to_string(userPoke.getLevel())*/,85,screen_width-10-upb.getWidth()+16,screen_height-50-upb.getHeight()+5,0);
	textToSDL(oppPoke.getName()/*+to_string(oppPoke.getLevel())*/,85,10+6,15+5,0);
}

/*
void Game::displayBattle(Trainer user,Trainer opp,Pokemon userPoke,Pokemon oppPoke,int scenario){
	switch(scenario){
		case 0:	//trainers face beginning of battle
			displayBar(user,opp,opp.getName()+" would like to battle!",0);
			SDL_Flip(screen);
			break;
		case 1:
			break;
		
			

	}
}
*/

void Game::displayMap(){
	my_map[0][0].getSprite().display(15,15,map);
	int userX=my_trainers[0].getBoardPiece().getLocation().getX();
	int userY=my_trainers[0].getBoardPiece().getLocation().getY();
	//cout << userX << " " << userY << endl;

	int sx = userY - 10;
	int sy = userX - 13;
	if(sx < 0)
		sx = 0;
	if(sy < 0)
		sy = 0;

	for (int x = 0; x <= 20; x++)
	{
		for (int y = 0; y <= 26; y++)
		{
			my_map[sx+x][sy+y].getSprite().display((y)*15, (x)*15, screen);
		}
	}	

	//int userX=my_trainers[0].getBoardPiece().getLocation().getX();
	//int userY=my_trainers[0].getBoardPiece().getLocation().getY();
	//applySurface(userX,userY,map,screen);
	//SDL_Flip(map);
}

void Game::displayTrainers()
{
	int userX=my_trainers[0].getBoardPiece().getLocation().getX();
	int userY=my_trainers[0].getBoardPiece().getLocation().getY();
	

	my_trainers[0].getBoardPiece().getSprite().display(196, 150, screen);

	int sx = userY - 10;
	int sy = userX - 13;
	if(sx < 0)
		sx = 0;
	if(sy < 0)
		sy = 0;
	int disX = 0;
	int disY = 0;
	int tX =0;
	int tY = 0;
	
	for(int i = 1; i < my_trainers.size(); i++)
	{
		tX = my_trainers[i].getBoardPiece().getLocation().getX();
		tY = my_trainers[i].getBoardPiece().getLocation().getY();
		if(tX >= sy && tX <= sy+20 && tY >= sx && tY <= sx+26)
		{
			disX = (tX-userX)*15;
			disY = (tY-userY)*15;
			my_trainers[i].getBoardPiece().getSprite().display(200+disX, 150+disY, screen);
		}
	}


	//applySurface(userX,userY,trainers,screen);
	//SDL_Flip(trainers);
}

//checks to see if trainers can see the user after each step
void Game::checkTrainerSight(Location user)
{
	string SpriteName="";
	int userX = user.getX();
	int userY = user.getY();
	int tX = 0;
	int tY = 0;
	for(int i=1; i< my_trainers.size(); i++)
	{
		SpriteName = my_trainers[i].getBoardPiece().getSprite().getName();
		tX = my_trainers[i].getBoardPiece().getLocation().getX();
		tY = my_trainers[i].getBoardPiece().getLocation().getY();
		if(SpriteName == "TrainerUP" && (tY-userY) > 0 && (tY-userY) <= 3 && tX == userX)
		{
			moveTrainer(my_trainers[i], user);
		}
		else if(SpriteName == "TrainerDOWN" && (tY-userY) < 0 && (tY-userY) >= -3 && tX == userX)
		{
			moveTrainer(my_trainers[i], user);
		}
		else if(SpriteName == "TrainerLEFT" && (tX-userX) > 0 && (tX-userX) <= 3 && tY == userY)
		{
			moveTrainer(my_trainers[i], user);
		}
		else if(SpriteName == "TrainerRIGHT" && (tX-userX) < 0 && (tX-userX) >= -3 && tY == userY)
		{
			moveTrainer(my_trainers[i], user);
		}
	}

}

//function that will move the trainers to attack the user
void Game::moveTrainer(Trainer opp, Location loc)
{
	battle(&my_trainers[0],&opp);

	//cout << "Trainer attack!" <<endl;
	//IPLEMENT
	//MOVEMENT
	//AND
	//ATTACK
	//OF
	//TRAINER
	//HERE
}

void Game::play(){	
	//displayBar(getSprite("UserCharizard"),getSprite("OppVenusaur"),"What will BULBASAUR do?",0);

	int quit=0;

	whiteScreen();
	displayMap();
	displayTrainers();
	SDL_Flip(screen);


	int trainerX;	//trainer's x position
	int trainerY;	//trainer's y position	
	BoardPiece nextStep = BoardPiece();

	//While the user hasn't quit
	while (!quit)
	{
		fps.start();
		//While there's an event to handle
		while (SDL_PollEvent(&event))
		{
			//If a key was pressed
			if (event.type == SDL_KEYDOWN)
			{
				trainerX=my_trainers[0].getBoardPiece().getLocation().getX();
				trainerY=my_trainers[0].getBoardPiece().getLocation().getY();
				//cout<<trainerX<<","<<trainerY<<endl;
				//Set the proper message surface
				switch (event.key.keysym.sym)
				{
				case SDLK_UP: 
					my_trainers[0].getBoardPiece().setSprite(getSprite("PlayerUP"));
					nextStep = getMapPiece(trainerX, trainerY-1);
					if (!nextStep.canWalk())
					{
	//					cout << "You cannot walk there. UP " << my_trainers[0].getBoardPiece().getLocation().getY();
		//				cout << "NextStep is : " << nextStep.getSprite().getName() << " at " << nextStep.getLocation().getX() << " " << nextStep.getLocation().getY() <<endl;
						break;
					}
					
					/*if (trainerY>0)*/ my_trainers[0].getBoardPiece().getLocation().setY(trainerY-1);
					if(nextStep.canInteract())
					{
						interact(my_trainers[0].getBoardPiece().getLocation(), nextStep.getSprite());
						break;
					}
			//		cout<<"y up change"<<my_trainers[0].getBoardPiece().getLocation().getY();
					break;
				case SDLK_DOWN:
					my_trainers[0].getBoardPiece().setSprite(getSprite("PlayerDOWN"));
					nextStep = getMapPiece(trainerX, trainerY+1);
					if (!nextStep.canWalk())
					{
		//				cout << "You cannot walk there. DOWN" << my_trainers[0].getBoardPiece().getLocation().getY();
		//				cout << "NextStep is : " << nextStep.getSprite().getName() << " at " << nextStep.getLocation().getX() << " " << nextStep.getLocation().getY() <<endl;
						break;
					}
					
					/*if (trainerY < my_map[trainerX])*/ my_trainers[0].getBoardPiece().getLocation().setY(trainerY+1);
					if(nextStep.canInteract())
					{
						interact(my_trainers[0].getBoardPiece().getLocation(), nextStep.getSprite());
						break;
					}
		//			cout<<"y down change"<<my_trainers[0].getBoardPiece().getLocation().getY();
					break;
				case SDLK_LEFT:
					my_trainers[0].getBoardPiece().setSprite(getSprite("PlayerLEFT"));
					nextStep = getMapPiece(trainerX-1, trainerY);
					if (!nextStep.canWalk())
					{
		//				cout << "You cannot walk there. LEFT" << my_trainers[0].getBoardPiece().getLocation().getX();
		//				cout << "NextStep is : " << nextStep.getSprite().getName() << " at " << nextStep.getLocation().getX() << " " << nextStep.getLocation().getY() <<endl;
						break;
					}
					
					/*if (trainerX>0)*/ my_trainers[0].getBoardPiece().getLocation().setX(trainerX-1);
					if(nextStep.canInteract())
					{
						interact(my_trainers[0].getBoardPiece().getLocation(), nextStep.getSprite());
						break;
					}
		//			cout<<"x left change"<<my_trainers[0].getBoardPiece().getLocation().getX();
					break;
				case SDLK_RIGHT:
					my_trainers[0].getBoardPiece().setSprite(getSprite("PlayerRIGHT"));
					nextStep = getMapPiece(trainerX+1, trainerY);
					if (!nextStep.canWalk())
					{
		//				cout << "You cannot walk there. RIGHT" << my_trainers[0].getBoardPiece().getLocation().getX();
		//				cout << "NextStep is : " << nextStep.getSprite().getName() << " at " << nextStep.getLocation().getX() << " " << nextStep.getLocation().getY() <<endl;
						break;
					}
					
					/*if (trainerX < SCREEN_WIDTH-trainersquare.w)*/ my_trainers[0].getBoardPiece().getLocation().setX(trainerX+1);
					if(nextStep.canInteract())
					{
						interact(my_trainers[0].getBoardPiece().getLocation(), nextStep.getSprite());
						break;
					}
		//			cout<<"x right change"<<my_trainers[0].getBoardPiece().getLocation().getX();
					break;
				}
				if(trainerX != my_trainers[0].getBoardPiece().getLocation().getX() || trainerY != my_trainers[0].getBoardPiece().getLocation().getY())
				{
					checkTrainerSight(my_trainers[0].getBoardPiece().getLocation());
				}
				whiteScreen();
				displayMap();
				displayTrainers();
				SDL_Flip(screen);
			}
			//If the user has Xed out the window
			else if (event.type == SDL_QUIT)
			{
				//Quit the program
				quit = 1;
			}
		}
		//Update the screen
		SDL_Flip( screen);
		
		//Cap the frame rate if cap is true
		
		if(( frame_cap == 1 ) && ( fps.get_ticks() < 1000 / frames_per_second ) )
		{
		    SDL_Delay( ( 1000 / frames_per_second ) - fps.get_ticks() );
		}
		
		
	 }

quitSDL();

}

//returns the BoardPice at the corresponding location. 
BoardPiece Game::getMapPiece(int i, int j)
{
	BoardPiece piece = BoardPiece();
	if (j >= my_map.size() || i >= my_map[j].size())
	{
		cout << "Invalid location. (" << i << ", " << j << ")" << endl;
		return piece;
	}
	return my_map[j][i];
}

//will allow the user to interact with sprites.
void Game::interact(Location l, Sprite s)
{
	if(s.getName() == "A17" || s.getName() == "L22" || s.getName() == "P23" || s.getName() == "G39" || s.getName() == "EXT" || s.getName() == "R27")
	{
		Location newL = getLocationComplement(l);
		my_trainers[0].getBoardPiece().getLocation().setX(newL.getX());
		my_trainers[0].getBoardPiece().getLocation().setY(newL.getY());
	}
	else if(s.getName() == "TGR")
	{
		wildPokemon();
	}
}

//function for when a wild Pokemon attacks
void Game::wildPokemon()
{
	int b = rand()%8;
	if (b >= 1)
	{
		//cout << "no wild Pokemon" <<endl;
		return;
	}
	//cout << "Wild Pokemon" << endl;
	Trainer t = Trainer();
	Pokemon p = Pokemon();
	int r = rand() % 100;
	if (r >= 95)
	{
		int a = rand() %3;
		if(a >2)
			p = getPokemon("Bulbasaur");
		else if(a >2)
			p = getPokemon("Charmander");
		else
			p = getPokemon("Blastoise");
	}
	else if(r >=70)
	{
		int a = rand() %6;
		if(a >5)
			p = getPokemon("Pikachu");
		else if(a >4)
			p = getPokemon("Vulpix");
		else if(a >3)
			p = getPokemon("Diglett");
		else if(a >2)
			p = getPokemon("Geodude");
		else if(a >1)
			p = getPokemon("Scyther");
		else if(a >2)
			p = getPokemon("Poliwhirl");
	}
	else
	{	p=getPokemon("Nidorino");
		int a = rand() %12;
		if(a >11)
			p = getPokemon("Caterpie");
		else if(a >10)
			p = getPokemon("Weedle");
		else if(a >9)
			p = getPokemon("Pidgey");
		else if(a >8)
			p = getPokemon("Rattata");
		else if(a >7)
			p = getPokemon("Spearow");
		else if(a >2)
			p = getPokemon("Zubat");
		else if(a >6)
			p = getPokemon("Oddish");
		else if(a >5)
			p = getPokemon("Abra");
		else if(a >4)
			p = getPokemon("Bellsprout");
		else if(a >3)
			p = getPokemon("Geodude");
		else if(a >2)
			p = getPokemon("Krabby");
		else 
			p = getPokemon("Magikarp");
	}
	p.setLevel(my_trainers[0].getBoardPiece().getLocation().getY()/5);
	//add p moves
	t.addToParty(p);
	battle(&my_trainers[0], &t);
}

//returns the complement location to the passed location
Location Game::getLocationComplement(Location l)
{
	for(int i = 0; i < my_locationPairs.size(); i++)
	{
		pair<Location, Location> p = my_locationPairs[i];
		if(p.first.getX() == l.getX() && p.first.getY() == l.getY())
			return p.second;
		if(p.second.getX() == l.getX() && p.second.getY() == l.getY())
			return p.first;
	}
	return Location();
}

void Game::applySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip)
{
	//Temporary rectangle to hold the offsets
	SDL_Rect offset;

	//Get the offsets
	offset.x = x;
	offset.y = y;

	//Blit the surface
	SDL_BlitSurface(source, clip, destination, &offset);
}


void Game::test()
{
	return;
}
