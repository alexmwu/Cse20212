#include <stdlib.h>
#include <iostream>
#include <string>
#include "Sprite.h"

//creates a blank sprite
Sprite::Sprite()
{
	return;
}

//sheet, name, x, y, height, width, walkable, interactable
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

//returns the sprite sheet's name
string Sprite::getSheet()
{
	return my_sheet;
}

//returns x
int Sprite::getX()
{
	return my_x;
}

//returns y
int Sprite::getY()
{
	return my_y;
}

//returns height
int Sprite::getHeight()
{
	return my_height;
}

//returns thewidth
int Sprite::getWidth()
{
	return my_width;
}

//returns sprites name
string Sprite::getName()
{
	return my_name;
}

//sets teh sheet
void Sprite::setSheet(string sheet)
{
	my_sheet = sheet;
}

//sets the x
void Sprite::setX(int x)
{
	my_x = x;
}

//sets the y
void Sprite::setY(int y)
{
	my_y = y;
}

//sets the height
void Sprite::setHeight(int h)
{
	my_height = h;
}

//sets the width
void Sprite::setWidth(int w)
{
	my_width = w;
}

//sets the name
void Sprite::setName(string name)
{
	my_name = name;
}

//ints are for x and y location to be displayed. the pointer to SDL_Surface is the screen
void Sprite::display(int x,int y,SDL_Surface* destination){
	//Temporary rectangle to hold the offsets
	SDL_Rect offset;

	//Get the offsets
	offset.x=x;
	offset.y=y;

	//Blit the surface
	SDL_BlitSurface(sprite,&sprite_loc,destination,&offset);
}

//sets if is walkable
void Sprite::setWalk(int walk)
{
	my_walk = walk;
}

//sets if it is interactable
void Sprite::setInteract(int interact)
{
	my_interact = interact;
}

//returns if it is walkable
int Sprite::getWalk()
{
	return my_walk;
}

//returns if it is interacable
int Sprite::getInteract()
{
	return my_interact;
}


