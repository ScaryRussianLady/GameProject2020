#pragma once

#include <iostream>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>
#include <sstream>

void side_by_side(std::istream& is1, std::istream& is2, std::size_t width)
{
	std::string line1;
	std::string line2;

	while (std::getline(is1, line1))
	{
		std::string pad;

		// ensure we add enough padding to make the distance
		// the same regardless of line length
		if (line1.size() < width)
			pad = std::string(width - line1.size(), ' ');

		// get same line from second stream
		std::getline(is2, line2);

		// print them size by the side the correct distance (pad)
		std::cout << line1 << pad << line2 << '\n';
	}

	// in case second stream has more line than the first
	while (std::getline(is2, line2))
	{
		auto pad = std::string(width, ' ');
		std::cout << pad << line2;
	}
}

int healthManagement(std::ostream& os)
{
	const int healthLevel = 100;

	if (healthLevel <= 0)
	{
		os << "You are dead!";
		return (0);
	}

	os << "Health: " << healthLevel << "/100";
	return (0);
};

int playerGold(std::ostream& os) {
	int currentGold = 500;

	os << "Gold: " << currentGold;
	return (0);

	/*char market[5];
	std::cout << "Welcome to the market Cheif!" << std::endl;
	std::cout << "Are you looking to sell or buy items? ";
	std::cin >> market;
	if (strcmp(market, "buy") == 0) {
		std::cout << "1) Water - 25 Gold\n2)Food - 25 Gold\n3) Weapons supplies - 100";
		char choice[5];
		std::cout << "Choice: ";
		std::cin >> choice;
		if (strcmp(choice, "1") == 0) {
			crntGold -= 25;
			std::cout << "Water has been added to your invent" << std::endl;
			std::cout << "current gold: " << crntGold;
			Sleep(5000);

		}
		return 1;
	}*/
};

//int foodManagement()
//{
//};

int output()
{
	// some stream objects to store the outputs
	std::stringstream ss1;
	std::stringstream ss2;

	// capture output in stream objects
	healthManagement(ss1);
	playerGold(ss2);

	// print captured output side by side
	side_by_side(ss1, ss2, 30);
	return (0);
};