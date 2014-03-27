#include <stdlib.h>
#include <iostream>
#include <string>
#include "Sprite.h"

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
