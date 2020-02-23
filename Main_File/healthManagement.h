#pragma once
#include <iostream>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>

int healthManagement()
{
	const int healthLevel = 100;

	if (healthLevel <= 0)
	{
		std::cout << "You are dead!" << std::endl;
		return (0);
	}

	std::cout << "Health: " << healthLevel << "/100\n" << std::endl;
}