#include <stdlib.h>
#include <iostream>
#include <string>
#include "Sprite.h"

Sprite::Sprite()
{
	return;
}

Sprite::Sprite(SDL_Surface * sheet, string name, int x, int y, int h, int w, int walk, int interact)
{
	sprite = sheet;
	my_x = x;
	my_y = y;
	my_height = h;
	my_width = w;
	my_name = name;
	my_walk = walk;
	my_interact = interact;

	//SDL_Rect internal variables
	sprite_loc.x=my_x;
	sprite_loc.y=my_y;
	sprite_loc.w=my_width;
	sprite_loc.h=my_height;
}

SDL_Surface *Sprite::getSurface(){
	return sprite;
}

void Sprite::freeSurface(){
	SDL_FreeSurface(sprite);
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

void Sprite::display(int x,int y,SDL_Surface* destination){
	//Temporary rectangle to hold the offsets
	SDL_Rect offset;

	//Get the offsets
	offset.x=x;
	offset.y=y;

	//Blit the surface
	SDL_BlitSurface(sprite,&sprite_loc,destination,&offset);
}

void Sprite::setWalk(int walk)
{
	my_walk = walk;
}

void Sprite::setInteract(int interact)
{
	my_interact = interact;
}


int Sprite::getWalk()
{
	return my_walk;
}


int Sprite::getInteract()
{
	return my_interact;
}


