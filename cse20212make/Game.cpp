#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <stdlib.h>
#include <iostream>
#include <string>
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
using namespace std;

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
	
	initializeSDL();
	initializeSpriteSheets();
	initializeSprites();
	drawMap();
	printMap();
	initializeTypes();
	initializeTypeChart();
	initializeMoves();
	initializePokemon();
	initializeTrainers();
}


SDL_Surface * Game::loadImage(string filename){
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
 	map=SDL_SetVideoMode(screen_width,screen_height,screen_bpp,SDL_SWSURFACE);
 	trainers=SDL_SetVideoMode(screen_width,screen_height,screen_bpp,SDL_SWSURFACE);
	battlescene=SDL_SetVideoMode(screen_width,screen_height,screen_bpp,SDL_SWSURFACE);

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
				Pokemon newPokemon(atoi(attribute[7].c_str()), atoi(attribute[9].c_str()), atoi(attribute[15].c_str()), atoi(attribute[11].c_str()),
					atoi(attribute[13].c_str()), atoi(attribute[17].c_str()), s1, s2, attribute[1], atoi(attribute[19].c_str()),
					atoi(attribute[21].c_str()), atoi(attribute[23].c_str()), atoi(attribute[25].c_str()),
					atoi(attribute[27].c_str()), t1, t2);
				my_pokemon.push_back(newPokemon);
				read = 0;
				for (int i = 0; i < 2; i++)
					getline(myfile, line);
			}
		}
	}
}

void Game::initializeSprites()
{

	string file = "text/Sprites.txt";
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
				Sprite newSprite(switchSheet(atoi(attribute[1].c_str())), attribute[3], atoi(attribute[5].c_str()), atoi(attribute[7].c_str()), atoi(attribute[9].c_str()), atoi(attribute[11].c_str()));
				my_sprites.push_back(newSprite);
				read = 0;
				for (int i = 0; i < 2; i++)
					getline(myfile, line);
			}
		}
	}
}



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
				b = BoardPiece(s, loc, 1, 0);
				temp.push_back(b);
			}
			my_map.push_back(temp);
			temp.clear();
			tokens.clear();
			x++;
		}		
	}
}

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
				temp = Trainer(tokens[1], piece);						
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


pair<int, int> Game::battle(Pokemon* user, Pokemon* opp)
{
	pair<int, int> returnVal = pair<int,int>(0, 0);
	int move = 0;
	int oppMove = 0;
	double strength = 0;
	int canMove = 1;
	cout << user->getName() << " VS " << opp->getName() << endl;
	displayBattle(*user,*opp);
while (user->getHP() > 0 && opp->getHP() > 0)
	{
		canMove = 1;
		oppMove = rand() % opp->getMoves().size();
		opp->oppPrint();
		cout << endl;
		user->battlePrint();
		cout << "Which move would you like to use?" << endl;
		cin >> move;
		cout << endl;		

		if (move == user->getMoves().size())
		{
			canMove = 0;
			if (my_pokeballs[0].canCatch(*opp))
			{
				returnVal.first = 3;
				return returnVal;
			}
		}
		else if (move == user->getMoves().size() + 1)
		{
			returnVal.first = 1;
			returnVal.second = user->getHP();
			return returnVal;
		}
		else if (move == user->getMoves().size() + 2)
		{
			canMove = 0;
			returnVal.first = 4;
			return returnVal;
		}

		if (user->getSpeed() >= opp->getSpeed() && canMove)
		{
			
			strength = getTypeStrength(user->getMove(move).getType(), opp->getType()[0]);
			if (opp->getType()[1].getName() != "")
				strength *= getTypeStrength(user->getMove(move).getType(), opp->getType()[1]);
			user->useMove(opp, move, strength);

			if (opp->getHP() <= 0)
			{
				cout << opp->getName() << " has fainted." << endl << endl;
				returnVal.first = 2;
				return returnVal;
			}

			strength = getTypeStrength(opp->getMove(oppMove).getType(), user->getType()[0]);
			if (user->getType()[1].getName() != "")
				strength *= getTypeStrength(opp->getMove(oppMove).getType(), user->getType()[1]);
			opp->useMove(user, oppMove, strength);

			if (user->getHP() <= 0)
			{
				cout << user->getName() << " has fainted." << endl << endl;
				returnVal.first = 0;
				return returnVal;
			}
		}
		else if (canMove)
		{
			strength = getTypeStrength(opp->getMove(oppMove).getType(), user->getType()[0]);
			if (user->getType()[1].getName() != "")
				strength *= getTypeStrength(opp->getMove(oppMove).getType(), user->getType()[1]);
			opp->useMove(user, oppMove, strength);


			if (user->getHP() <= 0)
			{
				cout << user->getName() << " has fainted." << endl << endl;
				returnVal.first = 0;
				return returnVal;
			}

			strength = getTypeStrength(user->getMove(move).getType(), opp->getType()[0]);
			if (user->getType()[1].getName() != "")
				strength *= getTypeStrength(user->getMove(move).getType(), opp->getType()[1]);
			user->useMove(opp, move, strength);

			if (opp->getHP() <= 0)
			{
				cout << opp->getName() << " has fainted." << endl << endl;
				returnVal.first = 2;
				return returnVal;
			}

		}
		else
		{
			strength = getTypeStrength(opp->getMove(oppMove).getType(), user->getType()[0]);
			if (user->getType()[1].getName() != "")
				strength *= getTypeStrength(opp->getMove(oppMove).getType(), user->getType()[1]);
			opp->useMove(user, oppMove, strength);


			if (user->getHP() <= 0)
			{
				cout << user->getName() << " has fainted." << endl << endl;
				returnVal.first = 0;
				return returnVal;
			}
		}
	}
	returnVal.first = 5;
	return returnVal;
}

void Game::battle(Trainer *user, Trainer *opp)
{
	cout << user->getName() << " VS " << opp->getName() << endl;
	int swap = -1;
	int item = -1;
	int uA = 0;
	int oA = 0;
	Item potion = Item();
	Pokemon userA = user->getPokemon(uA);
	Pokemon oppA = opp->getPokemon(oA);
	Pokemon swapper = Pokemon();
	while (user->getNumPokemonAvalible() > 0 && opp->getNumPokemonAvalible() > 0)
	{
		pair<int, int> num = battle(&userA, &oppA);
		if (num.first == 1)
		{
			user->swapPokemon(uA, num.second);
			user->printPokemon();
			while (1)
			{
				while (swap < 0 || swap > user->getParty().size())
				{
					cout << "Which Pokemon do you want to swap?" << endl;
					cin >> swap;
				}
				swapper = user->getPokemon(swap);
				if (swapper.getHP() == 0)
				{
					cout << "That Pokemon has fainted, try again" << endl;
					swap = -1;
					continue;
				}
				userA = user->getPokemon(swap);
				num.first = -1;
				swap = -1;
				break;
			}			
		}
		else if (num.first == 0)
		{
			user->swapPokemon(uA, 0);
			if (user->getNumPokemonAvalible() == 0)
				break;
			user->printPokemon();
			while (1)
			{
				while (swap < 0 || swap > user->getParty().size())
				{
					cout << "Which Pokemon do you want to swap?" << endl;
					cin >> swap;
				}
				swapper = user->getPokemon(swap);
				if (swapper.getHP() == 0)
				{
					cout << "That Pokemon has fainted, try again" << endl;
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
		else if (num.first == 2)
		{
			opp->swapPokemon(oA, 0);
			if (opp->getNumPokemonAvalible() == 0)
				break;
			while (1)
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
				swap = -1;
				break;
			}
		}
		else if (num.first == 3)
		{
			user->addToParty(oppA);
			return;
		}
		else if (num.first == 4)
		{
			user->printPotions();
			while (item < 0 || item > user->getPotions().size())
			{
				cout << "What item do you want to use?" << endl;
				cin >> item;
			}
			user->printPokemon();
			while (swap < 0 || swap > user->getParty().size())
			{
				cout << "Which Pokemon do you want to use this on?" << endl;
				cin >> swap;
			}
			user->usePotion(item, user->getPokemon(swap));
			num.first = -1;
			swap = -1;
		}
		cout << endl;
	}	
	if (user->getNumPokemonAvalible() == 0)
		cout << "You lost all your Pokemon, you blacked out." << endl;
	else
		cout << "Congratulations, you beat " << opp->getName() << endl;
	return;
}

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

void Game::printPokemon()
{
	for (int i = 0; i < my_pokemon.size(); i++)
	{
		cout << i << ") " << my_pokemon[i].getName() << " " << my_pokemon[i].getType()[0].getName() << " " << my_pokemon[i].getType()[1].getName() << endl;
	}
}

void Game::displayBattle(Pokemon user, Pokemon opp){
		whiteScreen();
		user.getUserImage().display(20,400,battlescene);
		opp.getOppImage().display(560,20,battlescene);
// 		whiteScreen();
		applySurface(0,0,battlescene,screen);
		SDL_Flip(screen);
}


void Game::displayMap(){
//my_map[0][0].getSprite().display(15,15,map);
	/*for(int i=0;i<my_map.size();i++)
	{
		for(int j=0;j<my_map[i].size();j++)
		{
			if(my_map[j][i].getSprite().getName()=="") 
				continue;
			//my_map[j][i].getSprite().display(i*15,j*15,map);
		}

	}*/

	for (int i = 0; i < my_map.size(); i++)
	{
		for (int j = 0; j < my_map[i].size(); j++)
		{
			//f(my_map[j][i].getSprite().getName()=="") 
				//continue;
			my_map[i][j].getSprite().display(j*15,i*15,map);
		}
	}
	applySurface(0,0,map,screen);
	SDL_Flip(screen);
}


void Game::displayTrainers(){
	for (int i = 0; i < my_trainers.size(); i++)
	{
		int x=my_trainers[i].getBoardPiece().getLocation().getX();
		int y=my_trainers[i].getBoardPiece().getLocation().getY();
		my_trainers[i].getBoardPiece().getSprite().display(y*15,x*15,trainers);
	}
	applySurface(0,0,trainers,screen);
	SDL_Flip(screen);
}


void Game::play(){
	int quit=0;

	whiteScreen();
	displayMap();
	displayTrainers();	
	
	Trainer user = my_trainers[0];
	Trainer opp = my_trainers[2];
	//battle(&user, &opp);
	
	//While the user hasn't quit
	while (!quit)
	{
		fps.start();
		//While there's an event to handle
		while (SDL_PollEvent(&event))
		{
			//If the user has Xed out the window
			if (event.type == SDL_QUIT)
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
