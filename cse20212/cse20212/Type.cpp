#include <stdlib.h>
#include <iostream>
#include <string>
#include "Type.h"

Type::Type()
{
	return;
}

Type::Type(string name, int index)
{
	my_index = index;
	my_name = name;
}

string Type::getName()
{
	return my_name;
}

int Type::getIndex()
{
	return my_index;
}

void Type::setName(string name)
{
	my_name = name;
}

void Type::setIndex(int index)
{
	my_index = index;
}