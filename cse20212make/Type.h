/* Pokemon Project
Alex Hansen
Type.h

Type Class.
Stores a value for type, along with some interaction functions
*/

#ifndef TYPE_H
#define TYPE_H
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

class Type
{
public:
	Type();			//creates a blank type object
	Type(string, int);	//creates a type with the string name and int index
	string getName();	//returns the string's name
	int getIndex();		//returns the index of the type
	void setName(string);	//sets the name to the string 
	void setIndex(int);	//sets the index to the int passed in

private:
	string my_name;		//stores the name of the type
	int my_index;		//stores the index of the type

};
#endif
