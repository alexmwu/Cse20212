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
	Type();
	Type(string, int);
	string getName();
	int getIndex();
	void setName(string);
	void setIndex(int);

private:
	string my_name;
	int my_index;

};

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
#endif