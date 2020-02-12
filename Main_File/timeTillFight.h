#include <iostream>
#include <Windows.h> //include windows.h to use the sleep function. takes innput as milliseconds
#include <stdlib.h>
#include <string.h>
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
			std::cout << "\n4. Sleep(Ends current day)" << std::endl;

			char choice[23];
			bool day = true;
			while (day == true) {
				std::cout << "\nUser choice: ";
				std::cin >> (choice);
				if (strcmp(choice, "1") == 0) {
					std::cout << "\n----------------------------------------";
					std::cout << "\n*Brings user to the training function*";
					Sleep(750);
					std::cout << "\n*User returns to main screen*" << std::endl;
				}
				else if (strcmp(choice, "2") == 0) {
					std::cout << "\n----------------------------------------";
					std::cout << "\n*Brings user to Market*";
					Sleep(750);
					std::cout << "\n*User returns to main screen*" << std::endl;
				}
				else if (strcmp(choice, "3") == 0) {
					std::cout << "\n----------------------------------------";
					std::cout << "\n*Brings user to their resources e.g. weapons, shields...*";
					Sleep(750);
					std::cout << "\n*User returns to main screen*" << std::endl;
				}
				else if (strcmp(choice, "4") == 0) {
					std::cout << "\n----------------------------------------";
					std::cout << "\nYou have decided to settle in for the day";
					Sleep(750);
					day = false;
				}
			}
			if (count == 0) {

				system("CLS");//clear screen
				std::cout << "IT'S FIGHT DAY!\n" << std::endl;
				Sleep(10000);
			}
			count -= 1;
		}
		//std::cout << "\nGREAT! It's time to send your fighters in!" << std::endl;



	}
}