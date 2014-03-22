/* Pokemon Project
Alex Hansen
Sprite.h

Sprite Class.
Stores the sprite sheet, location on the sheet, and height and width of the sprite. Includes getter and setter functions.
*/

#ifndef SPRITE_H
#define SPRITE_H
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

class Sprite
{
public:
	Sprite();
	Sprite(string, string, int, int, int, int);
	string getSheet();
	int getX();
	int getY();
	int getHeight();
	int getWidth();
	string getName();
	void setSheet(string);
	void setX(int);
	void setY(int);
	void setHeight(int);
	void setWidth(int);
	void setName(string);

private:
	int my_x;
	int my_y;
	string my_sheet;
	int my_height;
	int my_width;
	string my_name;
};

Sprite::Sprite()
{
	return;
}

Sprite::Sprite(string sheet, string name, int x, int y, int h, int w)
{
	my_sheet = sheet;
	my_x = x;
	my_y = y;
	my_height = h;
	my_width = w;
	my_name = name;
}

string Sprite::getSheet()
{
	return my_sheet;
}

int Sprite::getX()
{
	return my_x;
}

int Sprite::getY()
{
	return my_y;
}

int Sprite::getHeight()
{
	return my_height;
}

int Sprite::getWidth()
{
	return my_width;
}
string Sprite::getName()
{
	return my_name;
}

void Sprite::setSheet(string sheet)
{
	my_sheet = sheet;
}

void Sprite::setX(int x)
{
	my_x = x;
}

void Sprite::setY(int y)
{
	my_y = y;
}

void Sprite::setHeight(int h)
{
	my_height = h;
}

void Sprite::setWidth(int w)
{
	my_width = w;
}

void Sprite::setName(string name)
{
	my_name = name;
}

#endif