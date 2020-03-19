#pragma once
#include <iostream>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <conio.h>
#include <string.h>


//Beginning of code by [Annija Balode 9102828]
//Function for placing separate functions side by side, referenced from https://stackoverflow.com/questions/38893113/how-to-display-two-functions-next-to-each-other-in-c

void side_by_side(std::istream& is1, std::istream& is2, std::istream& is3, std::istream& is4, std::size_t width)
{
	std::string line1;
	std::string line2;
	std::string line3;
	std::string line4;


	while (std::getline(is1, line1))
	{
		std::string padAmount;

		//Ensures there is enough padding to make the distance equal throughout no matter what.
		if (line1.size() < width)
			padAmount = std::string(width - line1.size(), ' ');

		//Gets the same line from second, third and fourth stream.
		std::getline(is2, line2);
		std::getline(is3, line3);
		std::getline(is4, line4);

		//Prints all functions side by side with the correct padding.
		std::cout << line1 << padAmount << line2 << padAmount << line3 << padAmount << line4 << '\n';
	}

	//The following while loops are just in case one of the streams include more lines than the first.
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


//A function that manages the health of the user. These are the initial values.
int healthManagement(std::ostream& os)
{
	const int healthLevel = 100;

	//If health goes below zero, everything on the screen is cleared and the user is notified that they are dead.
	if (healthLevel <= 0)
	{
		system("CLS");
		std::cout << "You are dead!" << std::endl;
		return (0);
	}

	os << "Health: " << healthLevel << "/100";
	return (0);
}


//A function that tells the user how much gold they currently have. They begin with 50 pieces.
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

void print(int& x);

//A function that shows the current hunger level of the user. The initial value is given as 50.
int foodManagement(std::ostream& os)
{
	int currentFoodLevel = 50;
	print(currentFoodLevel);
	os << "Hunger: " << currentFoodLevel << "/100";
	return(0);
};

//Same concept as the hunger level but for thirst instead.
int waterManagement(std::ostream& os)
{
	int currentWaterLevel = 50;
	print(currentWaterLevel);
	os << "Thirst: " << currentWaterLevel << "/100";
	return(0);
}


//A function which takes all of the functions above and prints them out in streams so that they can be printed side by side.
int output()
{
	//Stream objects to store the outputs.
	std::stringstream ss1;
	std::stringstream ss2;
	std::stringstream ss3;
	std::stringstream ss4;
	std::stringstream ss5;

	//Puts the objects in stream outputs.
	healthManagement(ss1);
	playerGold(ss2);
	foodManagement(ss3);
	waterManagement(ss4);

	//Prints the outputs side by side.
	side_by_side(ss1, ss2, ss3, ss4, 30);
	return (0);
};

//End of code by [Annija Balode 9102828]