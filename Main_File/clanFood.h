#include <iostream>
#include <Windows.h>
#include <stdlib.h>
void ClanLvls(){
	//Annija fixed some of Rishikesh's errors.
	int W = 100, F = 100;
    while (F >= 0) {
		if (c == "levels") {
			system("CLS");//clear screen
			std::cout << "Your Water level is " << W << std::endl;
			std::cout << "Your Hunger level is " << F << std::endl;
			std::cout << "Available options: " << std::endl;
			std::cout << "\n1. Eat Food";
			std::cout << "\n2. Drink" << std::endl;
			std::cout << "\nUser choice: ";
			std::string choice;
			std::cin >> choice;
			std::cout << "*action depending on user choice*" << std::endl;
		}
			
		if (c == "levels" && MC == 1) {
			std::cout << "\nYour Water level is " << W << std::endl;
			std::cout << "Your Hunger level is " << F << std::endl;
		}