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


#endif
