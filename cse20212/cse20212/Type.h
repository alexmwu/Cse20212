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
#endif