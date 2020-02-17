/*#pragma once
#include <iomanip>
#include <iostream>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>

int IdGen(int &PrevID)
{
	int newID = 0;

	while (newID == 0 or newID == PrevID);
	{
		newID = PrevID + 1;
	}
	
	return newID;
	
}*/


//https://www.oreilly.com/library/view/c-cookbook/0596007612/ch08s09.html
#include <iostream>

class UniqueID {
protected:
    static int nextID;
public:
    int id;
    UniqueID();
    UniqueID(const UniqueID& orig);
    UniqueID& operator=(const UniqueID& orig);
};

int UniqueID::nextID = 0;

UniqueID::UniqueID() {
    id = ++nextID;
}

UniqueID::UniqueID(const UniqueID& orig) {
    id = orig.id;
}

UniqueID& UniqueID::operator=(const UniqueID& orig) {
    id = orig.id;
    return(*this);
}
