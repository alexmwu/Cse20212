#include <stdlib.h>
#include <iostream>
#include <string>
#include "Type.h"

//creates a blank type object
Type::Type()
{
	return;
}

//creates a type with the string name and int index
Type::Type(string name, int index)
{
	my_index = index;
	my_name = name;
}

//returns the string's name
string Type::getName()
{
	return my_name;
}

//returns the index of the type
int Type::getIndex()
{
	return my_index;
}

//sets the name to the string 
void Type::setName(string name)
{
	my_name = name;
}

//sets the index to the int passed in
void Type::setIndex(int index)
{
	my_index = index;
}
