#pragma once
#include <stdlib.h>
#include <iostream>

int playerGold () {
	int crntGold = 500;

	char market[3];
	std::cout << "Welcome to the market Cheif!" << std::endl;
	std::cout << "Are you looking to sell or buy items? ";
	std::cin >> market;
	if (strcmp(market, "buy") == 0) {
		std::cout << "1) Water - 25 Gold\n 2)Food - 25 Gold\n 3) Weapons supplies - 100";
		char choice[1];
		std::cin >> choice;
		if (strcmp(choice, "1")) {
			crntGold -= 25;
			std::cout << "Water has been added to your invent" << std::endl;
			std::cout << "current gold: " << crntGold;
		}
	}
}