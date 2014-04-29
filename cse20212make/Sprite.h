/* Pokemon Project
Alex Hansen
Sprite.h

Sprite Class.
Stores the sprite sheet, location on the sheet, and height and width of the sprite. Includes getter and setter functions.
*/

#ifndef SPRITE_H
#define SPRITE_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

class Sprite
{
public:
	Sprite();		//creates a blank sprite
	Sprite(SDL_Surface *, string, int, int, int, int, int, int); //sheet, name, x, y, height, width, walkable, interactable
	void freeSurface();	//frees surface at the end of the program (probably not needed, as the surfaces are initialized in the Game class
	SDL_Surface *getSurface();	//returns the actual image (sdl surface)
	string getSheet();	//returns the sprite sheet's name
	int getX();		//returns x
	int getY();		//returns y
	int getHeight();	//returns height
	int getWidth();		//returns thewidth
	string getName();	//returns sprites name
	void setSheet(string);	//sets teh sheet
	void setX(int);		//sets the x
	void setY(int);		//sets the y
	void setHeight(int);	//sets the height
	void setWidth(int);	//sets the width
	void setName(string);	//sets the name
	void setWalk(int);	//sets if is walkable
	void setInteract(int);	//sets if it is interactable
	int getWalk();		//returns if it is walkable
	int getInteract();	//returns if it is interacable
	void display(int,int,SDL_Surface*);	//ints are for x and y location to be displayed. the pointer to SDL_Surface is the screen

private:
	int my_x;		//store the x location
	int my_y;		//stores the y location
	string my_sheet;	//holds the string name
	int my_height;		//holds the height
	int my_width;		//holds the width
	string my_name;		//stores the sprites name
	int my_walk;		//stores if you can walk over it
	int my_interact;	//stores if it can be interacted with
	
	SDL_Rect sprite_loc;	//location of sprite on sprite map
	SDL_Surface *sprite;
};


#endif
