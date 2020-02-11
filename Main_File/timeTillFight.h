#include <iostream>
#include <Windows.h> //include windows.h to use the sleep function. takes innput as milliseconds
#include <stdlib.h>
//#include "clear.h"

/*
void timeTillFight() {
	int count = 7;
	while (count >= 0) {
		if (count > 0) {
			system("CLS");//clear screen
			std::cout << "Days Remaining: " << count << std::endl;
			std::cout << "----------------------------------------------\n";
			std::cout << "during this countdown we need to figure out a way of being able to train, visit market etc." << std::endl;
			std::cout << "pretty certain now that time is going to become a currency mechanic" << std::endl;
			std::cout << "or maybe we could stop the sleep() at the emd of every day and prompt the user to input what they want to do.";
			std::cout << "\nCHANGE THIS BEFORE PRESENTATION";
			Sleep(3000);//set to seconds right now just for testing purposes
		}
		if (count == 0) {
			system("CLS");//clear screen
			std::cout << "IT'S FIGHT DAY!\n" << std::endl;

		}
		count -= 1;
	}
	std::cout << "\nGREAT! It's time to send your fighters in!" << std::endl;


}
*/
void timeTillFight() {
	Sleep(2000);
	int count = 7;
	while (count >= 0) {
		if (count > 0) {
			system("CLS");//clear screen
			std::cout << "Days Remaining: " << count << std::endl;
			std::cout << "----------------------------------------------\n";
			std::cout << "Available options: " << std::endl;
			std::cout << "\n1. view Fighters";
			std::cout << "\n2. visit market";
			std::cout << "\n3. view inventory";
			std::cout << "\n4. rest fighters" << std::endl;
			std::cout << "\nUser choice: ";
			std::string choice;
			std::cin >> choice;
			std::cout << "*action depending on user choice*";
			Sleep(2000);
		}
		if (count == 0) {
			system("CLS");//clear screen
			std::cout << "IT'S FIGHT DAY!\n" << std::endl;

		}
		count -= 1;
	}
	std::cout << "\nGREAT! It's time to send your fighters in!" << std::endl;
	return;


}