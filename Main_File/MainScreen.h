#pragma once
#include <iostream>
#include "Indicators.h"
#include "timeTillFight.h"


void MainScreen()
{
	std::cout << "Days Left: " << timeTillFight() << std::endl;
}

