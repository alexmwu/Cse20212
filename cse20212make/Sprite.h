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
	Sprite();
	Sprite(SDL_Surface *, string, int, int, int, int);
	void freeSurface();	//frees surface at the end of the program (probably not needed, as the surfaces are initialized in the Game class
	SDL_Surface *getSurface();	//returns the actual image (sdl surface)
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
	void display(int,int,SDL_Surface*);	//ints are for x and y location to be displayed. the pointer to SDL_Surface is the screen

private:
	int my_x;
	int my_y;
	string my_sheet;
	int my_height;
	int my_width;
	string my_name;
	
	SDL_Rect sprite_loc;	//location of sprite on sprite map
	SDL_Surface *sprite;
};


#endif
