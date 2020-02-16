#pragma once
#include <iomanip>
#include <iostream>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>

int IdGen(int &PrevID)
{
	int newID = 0;

	while (newID == 0 or newID == PrevID);
	{newID = PrevID + 1;
	}
	
	return newID;
	 

}
