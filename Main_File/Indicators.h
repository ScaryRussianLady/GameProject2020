#pragma once

#include <iostream>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <conio.h>
#include <string.h>


//Beginning of code by [Annija Balode 9102828]
void side_by_side(std::istream& is1, std::istream& is2, std::istream& is3, std::istream& is4, std::size_t width)
{
	std::string line1;
	std::string line2;
	std::string line3;
	std::string line4;


	while (std::getline(is1, line1))
	{
		std::string pad;

		// ensure we add enough padding to make the distance
		// the same regardless of line length
		if (line1.size() < width)
			pad = std::string(width - line1.size(), ' ');

		// get same line from second and third stream
		std::getline(is2, line2);
		std::getline(is3, line3);
		std::getline(is4, line4);

		// print them side by the side the correct distance (pad)
		std::cout << line1 << pad << line2 << pad << line3 << pad << line4 << '\n';
	}

	// in case second stream has more line than the first
	while (std::getline(is2, line2))
	{
		auto pad = std::string(width, ' ');
		std::cout << pad << line2;
	}

	while (std::getline(is3, line3))
	{
		auto pad = std::string(width, ' ');
		std::cout << pad << line3;
	}

	while (std::getline(is4, line4))
	{
		auto pad = std::string(width, ' ');
		std::cout << pad << line4;
	}

}


int healthManagement(std::ostream& os)
{
	const int healthLevel = 100;

	if (healthLevel <= 0)
	{
		system("CLS");
		std::cout << "You are dead!" << std::endl;
		return (0);
	}

	os << "Health: " << healthLevel << "/100";
	return (0);
}


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


int foodManagement(std::ostream& os)
{
	int currentFoodLevel = 50;

	os << "Hunger: " << currentFoodLevel << "/100";
	return(0);
};


int waterManagement(std::ostream& os)
{
	int currentWaterLevel = 50;
	os << "Thirst: " << currentWaterLevel << "/100";
	return(0);
}

int output()
{
	// some stream objects to store the outputs
	std::stringstream ss1;
	std::stringstream ss2;
	std::stringstream ss3;
	std::stringstream ss4;
	std::stringstream ss5;

	// capture output in stream objects
	healthManagement(ss1);
	playerGold(ss2);
	foodManagement(ss3);
	waterManagement(ss4);

	// print captured output side by side
	side_by_side(ss1, ss2, ss3, ss4, 30);
	return (0);
};

//https://stackoverflow.com/questions/38893113/how-to-display-two-functions-next-to-each-other-in-c
//End of code by [Annija Balode 9102828]