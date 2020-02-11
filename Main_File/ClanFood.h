#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <string>

	// & Here makes this function take parameters by reference ie, function will change these values

void ClanFood( int &CurrentFoodLevel, int &CurrentWaterLevel ) {
	const int food_addition  = 5;
	const int water_addition = 5;

	const int food_max  = 100;
	const int water_max = 100;

	if (CurrentFoodLevel <= 0) {
		std::cout << "Current Food level is < 0 , ie dead?" << std::endl;
		return;
	}
	std::string choice;
    choice = "0";

    while (choice.compare("3") != 0) {
		//system("CLS");// clear screen
		std::cout << "Your Water level is " << CurrentWaterLevel << std::endl;
		std::cout << "Your Hunger level is " << CurrentFoodLevel << std::endl;
		std::cout << "Available options: " << std::endl;
		std::cout << "\n1. Eat Food";
		std::cout << "\n2. Drink" << std::endl;
		std::cout << "\n3. Continue..." << std::endl;
		std::cout << "\nUser choice: ";
		std::cin >> choice;
		//std::cout << "*action depending on user choice*" << std::endl;

		if (choice.compare("1") == 0 ) {
			if ((CurrentFoodLevel + food_addition) >= food_max)
			{
				CurrentFoodLevel = food_max;
				std::cout << "Max food allowed is " << food_max << std::endl;
			}
			else
			{
				CurrentFoodLevel += food_addition;
			}
		}

		if (choice.compare("2") == 0 ) {
			if ((CurrentWaterLevel + water_addition) >= water_max)
			{
				CurrentWaterLevel = water_max;
				std::cout << "Max Water allowed is " << water_max << std::endl;
			}
			else
			{
				CurrentWaterLevel += water_addition;
			}
		}
    }
}