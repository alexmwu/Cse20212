/* Pokemon Project
Alex Hansen
Game.h

Game Class.
Basically the running file for the entire game
*/

#ifndef GAME_H
#define GAME_H
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

using namespace std;

class Game
{
public:
	Game();
	void initilizePokemon();
	void initilizeSprites();
	void drawMap();
	Sprite findSprite(string);
	void printMap();
	void initilizeTypes();
	void initilizeTypeChart();
	double getTypeStrength(Type, Type);
	Type getType(string);
	void initilizeMoves();
	void battle(Pokemon, Pokemon);
	Move getMove(string);
	void test();
private:
	vector<Pokemon> my_pokemon;
	vector<Sprite> my_sprites;
	vector<vector<Sprite> > my_map;
	vector<Type> my_types;
	vector<vector<char> > my_typeChart;
	vector<Move> my_moves;
};

Game::Game()
{
	initilizeSprites();
	drawMap();
	initilizeTypes();
	initilizeTypeChart();
	initilizeMoves();
	initilizePokemon();

	Pokemon p1 = my_pokemon[2];
	Pokemon p2 = my_pokemon[5];

	p1.addMove(my_moves[0]);
	p2.addMove(my_moves[1]);
	p2.addMove(my_moves[2]);

	battle(p2, p1);

}

void Game::initilizePokemon()
{

	string file = "PokemonFile.txt";
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

void Game::initilizeSprites()
{

	string file = "Sprites.txt";
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
	string file = "Map.txt";
	ifstream myfile;
	myfile.open(file.c_str());
	string line;
	int read = 0;
	vector<Sprite> temp;
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
				temp.push_back(findSprite(tokens[i]));
			}
			my_map.push_back(temp);
			temp.clear();
			tokens.clear();
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
			cout << my_map[i][j].getName() << " ";
		}
		cout << endl;
	}
}

void Game::initilizeTypes()
{
	string file = "Types.txt";
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

void Game::initilizeTypeChart()
{
	string file = "TypeChart.txt";
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

void Game::initilizeMoves()
{
	string file = "Moves.txt";
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
				Move newMove(attribute[1], t, atoi(attribute[5].c_str()), atoi(attribute[7].c_str())*1.0 / 100, atoi(attribute[9].c_str()), attribute[11]);
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
	double calc = 0;
	int HPLoss = 0;
	double f[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
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
			f[0] = user.getLevel();
			f[1] = user.getAtk();
			f[2] = user.getMove(move).getStrength();
			f[3] = opp.getLevel();
			f[4] = user.getDef();
			f[5] = getTypeStrength(user.getMove(move).getType(), opp.getType()[0]);
			if (opp.getType()[1].getName() != "")
				f[5] *= getTypeStrength(user.getMove(move).getType(), opp.getType()[1]);
			f[6] = rand() % 38 + 217;

			calc = (((((2.0 * f[0]) / 5 + 2)*f[1] * f[2]) / ((f[3] * f[4]) + 2) * f[5] * f[6])) / 255 + 1;
			HPLoss = calc / 1;
			opp.setHP(opp.getHP() - HPLoss);
			cout << user.getName() << " used " << user.getMove(move).getName() << endl;

			if (opp.getHP() <= 0)
			{
				cout << opp.getName() << " has fainted." << endl;
				break;
			}

			f[0] = opp.getLevel();
			f[1] = opp.getAtk();
			f[2] = opp.getMove(oppMove).getStrength();
			f[3] = user.getLevel();
			f[4] = opp.getDef();
			f[5] = getTypeStrength(opp.getMove(oppMove).getType(), user.getType()[0]);
			if (user.getType()[1].getName() != "")
				f[5] *= getTypeStrength(user.getMove(oppMove).getType(), user.getType()[1]);
			f[6] = rand() % 38 + 217;

			calc = (((((2.0 * f[0]) / 5 + 2)*f[1] * f[2]) / ((f[3] * f[4]) + 2) * f[5] * f[6])) / 255 + 1;
			HPLoss = calc / 1;
			user.setHP(user.getHP() - HPLoss);
			cout << opp.getName() << " used " << opp.getMove(oppMove).getName() << endl;

			if (user.getHP() <= 0)
			{
				cout << user.getName() << " has fainted." << endl;
				break;
			}

		}
		else
		{
			f[0] = opp.getLevel();
			f[1] = opp.getAtk();
			f[2] = opp.getMove(oppMove).getStrength();
			f[3] = user.getLevel();
			f[4] = opp.getDef();
			f[5] = getTypeStrength(opp.getMove(oppMove).getType(), user.getType()[0]);
			if (user.getType()[1].getName() != "")
				f[5] *= getTypeStrength(user.getMove(oppMove).getType(), user.getType()[1]);
			f[6] = rand() % 38 + 217;

			calc = (((((2.0 * f[0]) / 5 + 2)*f[1] * f[2]) / ((f[3] * f[4]) + 2) * f[5] * f[6])) / 255 + 1;
			HPLoss = calc / 1;
			user.setHP(user.getHP() - HPLoss);
			cout << opp.getName() << " used " << opp.getMove(oppMove).getName() << endl;

			if (user.getHP() <= 0)
			{
				cout << user.getName() << " has fainted." << endl;
				break;
			}

			f[0] = user.getLevel();
			f[1] = user.getAtk();
			f[2] = user.getMove(move).getStrength();
			f[3] = opp.getLevel();
			f[4] = user.getDef();
			f[5] = getTypeStrength(user.getMove(move).getType(), opp.getType()[0]);
			if (opp.getType()[1].getName() != "")
				f[5] *= getTypeStrength(user.getMove(move).getType(), opp.getType()[1]);
			f[6] = rand() % 38 + 217;

			calc = (((((2.0 * f[0]) / 5 + 2)*f[1] * f[2]) / ((f[3] * f[4]) + 2) * f[5] * f[6])) / 255 + 1;
			HPLoss = calc / 1;
			opp.setHP(opp.getHP() - HPLoss);
			cout << user.getName() << " used " << user.getMove(move).getName() << endl;
		}

		if (opp.getHP() <= 0)
		{
			cout << opp.getName() << " has fainted." << endl;
			break;
		}
	}
}






void Game::test()
{
	return;
}

#endif