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
#include <time.h>
#include "Game.h"
using namespace std;

Game::Game(int sw, int sh, int sbpp, int movespeed)
{
	screen=NULL;
	map=NULL;
	trainers=NULL;
	screen_width=sw;
	screen_height=sh;
	screen_bpp=sbpp;
	move_speed=movespeed;

	srand(time(NULL));
	initializeSprites();
	drawMap();
	printMap();
	initializeTypes();
	initializeTypeChart();
	initializeMoves();
	initializePokemon();
	initializeSDL();	

	Pokemon p1 = my_pokemon[2];
	Pokemon p2 = my_pokemon[5];

	p1.addMove(my_moves[0]);
	p2.addMove(my_moves[1]);
	p2.addMove(my_moves[2]);

	Pokeball pb1 = Pokeball(1);
	my_pokeballs.push_back(pb1);


}


void Game::initializeSDL(){

	//Initialize all SDL subsystems
	SDL_Init(SDL_INIT_EVERYTHING);

	//Set up the screen
	screen = SDL_SetVideoMode(screen_width, screen_height, screen_bpp, SDL_SWSURFACE);

	//enable key repeating
	SDL_EnableKeyRepeat(1, move_speed);

	//Set the window caption
	SDL_WM_SetCaption("Pokemon NotreDame", NULL);
}

void Game::quitSDL(){
		SDL_FreeSurface(map);		//free map
		SDL_FreeSurface(trainers);	//free trainers

		SDL_Quit();		//auto frees the screen
}


void Game::initializePokemon()
{

	string file = "text/PokemonFile.txt";
	ifstream myfile;
	myfile.open(file.c_str());
	string line;
	string attribute[30];
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
				Type t1 = getType(attribute[5]);
				Type t2 = getType(attribute[7]);
				Pokemon newPokemon(atoi(attribute[9].c_str()), atoi(attribute[11].c_str()), atoi(attribute[17].c_str()), atoi(attribute[13].c_str()),
					atoi(attribute[15].c_str()), atoi(attribute[19].c_str()), attribute[3], attribute[1], atoi(attribute[21].c_str()),
					atoi(attribute[23].c_str()), atoi(attribute[25].c_str()), atoi(attribute[27].c_str()),
					atoi(attribute[29].c_str()), t1, t2);
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
				Sprite newSprite(attribute[1], attribute[3], atoi(attribute[5].c_str()), atoi(attribute[7].c_str()), atoi(attribute[9].c_str()), atoi(attribute[11].c_str()));
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
				s = findSprite(tokens[i]);
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

Sprite Game::findSprite(string name)
{
	Sprite s = Sprite();
	for (int i = 0; i < my_sprites.size(); i++)
	{
		if (my_sprites[i].getName() == name)
			return my_sprites[i];
	}
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

void Game::battle(Pokemon user, Pokemon opp)
{
	int move = 0;
	int oppMove = 0;
	double strength = 0;
	cout << "Pokemon Battle" << endl << endl;
	cout << user.getName() << " VS " << opp.getName() << endl;
	while (user.getHP() > 0 && opp.getHP() > 0)
	{
		cout << endl << endl << endl;
		oppMove = rand() % opp.getMoves().size();
		opp.oppPrint();
		cout << endl;
		user.battlePrint();
		cout << "Which move would you like to use?" << endl;
		cin >> move;
		cout << endl;		

		if (user.getSpeed() >= opp.getSpeed())
		{
			if (move == user.getMoves().size())
			{
				if (my_pokeballs[0].canCatch(opp))
				{
					break;
				}
			}
			else
			{
				strength = getTypeStrength(user.getMove(move).getType(), opp.getType()[0]);
				if (user.getType()[1].getName() != "")
					strength *= getTypeStrength(user.getMove(move).getType(), opp.getType()[1]);
				user.useMove(&opp, move, strength);

				if (opp.getHP() <= 0)
				{
					cout << opp.getName() << " has fainted." << endl;
					break;
				}
			}

			strength = getTypeStrength(opp.getMove(oppMove).getType(), user.getType()[0]);
			if (user.getType()[1].getName() != "")
				strength *= getTypeStrength(opp.getMove(oppMove).getType(), user.getType()[1]);
			opp.useMove(&user, oppMove, strength);

			if (user.getHP() <= 0)
			{
				cout << user.getName() << " has fainted." << endl;
				break;
			}
		}
		else
		{
			strength = getTypeStrength(opp.getMove(oppMove).getType(), user.getType()[0]);
			if (user.getType()[1].getName() != "")
				strength *= getTypeStrength(opp.getMove(oppMove).getType(), user.getType()[1]);
			user.useMove(&user, oppMove, strength);


			if (user.getHP() <= 0)
			{
				cout << user.getName() << " has fainted." << endl;
				break;
			}

			if (move == user.getMoves().size())
			{
				if (my_pokeballs[0].canCatch(opp))
				{
					break;
				}
			}
			else
			{
				strength = getTypeStrength(user.getMove(move).getType(), opp.getType()[0]);
				if (user.getType()[1].getName() != "")
					strength *= getTypeStrength(user.getMove(move).getType(), opp.getType()[1]);
				user.useMove(&opp, move, strength);

				if (opp.getHP() <= 0)
				{
					cout << opp.getName() << " has fainted." << endl;
					break;
				}
			}
		}
	}
}


void Game::play(){
	int quit=0;

	//While the user hasn't quit
	while (!quit)
	{
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
	}

quitSDL();

}




void Game::test()
{
	return;
}
