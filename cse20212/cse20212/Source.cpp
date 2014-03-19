/* Pokemon Project
Alex Hansen
Source.cpp

Testing class used to test implementations in parts
*/

#include <stdlib.h>
#include <iostream>
#include <string>
#include "BoardPiece.h"
#include "Location.h"
#include "Pokemon.h"
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	//Location loc1(5, 5);
	//BoardPiece p1("test.jpg", loc1, 1, 1);
	vector<Pokemon> list;
	string file = "PokemonFile.txt";
	ifstream myfile;
	myfile.open(file.c_str());
	string line;
	string attribute[26];
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
				Pokemon newPokemon(atoi(attribute[5].c_str()), atoi(attribute[7].c_str()), atoi(attribute[13].c_str()), atoi(attribute[9].c_str()),
					atoi(attribute[11].c_str()), atoi(attribute[15].c_str()), attribute[3], attribute[1], atoi(attribute[17].c_str()),
					atoi(attribute[19].c_str()), atoi(attribute[21].c_str()), atoi(attribute[23].c_str()),
					atoi(attribute[25].c_str()));
				list.push_back(newPokemon);
				read = 0;
				for (int i = 0; i < 2; i++)
					getline(myfile, line);
			}
		}
	}

	while (1)
	{
	}

	return 0;
}