#pragma once
#include <iostream>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>

void healthManagement()
{
	const int healthLevel = 100;

	if (healthLevel <= 0)
	{
		std::cout << "You are dead!" << std::endl;
		return;
	}

	std::cout << "Health: " << healthLevel << "/100\n" << std::endl;
}