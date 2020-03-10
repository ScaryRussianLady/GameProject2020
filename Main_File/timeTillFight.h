#include <iostream>
#include <Windows.h> //include windows.h to use the sleep function. takes innput as milliseconds
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
//#include "clear.h"
#include "Indicators.h"
#include <iomanip>
#include "gladiatorListing.h"

#include "fightDay.h"

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

// the function below is broken atm
/*
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
*/

//A working timer in taking key presses whilst counting.

//Start of code [Jamie warnock: ID 9328082]
//reference: https://www.youtube.com/watch?v=Kddn0MUbn4k 



int second = 0, day = 7, flag = 0;
bool snap = true;
int resourceLevel = 50;

void printData();
int selection(int userid, std::string clanType);


int testCase1() {		//this function is here for display purposes only
	std::cout << "----------------Market----------------\n ";
	std::cout << "*Will eventially link this with other function*\n";
	std::cout << "this is just to show that other functions can be called.";
	Sleep(3000);
	return 1;
}

int showFightersCase(int userid) {		//this function is here for display purposes only
	std::cout << "----------------Fighers----------------\n";
	showGladiators(userid, 0);
	//std::cout << "*Will eventially link this with other function*\n";
	//std::cout << "this is just to show that other functions can be called.";
	Sleep(3000);
	return 1;
}

int showInventoryCase(int userid, std::string clanType) {		//this function is here for display purposes only
	std::cout << "---------------Inventory---------------\n";
	showInventory(userid, 0, clanType, false);
	//std::cout << "*Will eventially link this with other function*\n";
	//std::cout << "this is just to show that other functions can be called.";
	Sleep(3000);
	return 1;
}

int FightDayTest() {		//this function is a placeholder for testing only
	std::string choice;
	std::cout << std::setfill('+') << std::setw(60) << "FIGHT DAY";
	std::cout << std::setfill('+') << std::setw(59) << "+";
	std::cout << "\nit's time for your Gladiators to prove themselves in battle\n\n";

	std::cout << "please select your gladiator:";
	std::cin >> choice;
	day = 7;
	printData();
	return 1;
}
/* Decided to just use the Sleep function instead
void delay(int ms)  //delay function
{
	clock_t timeDelay = ms + clock();    //Step up the difference from clock delay
	while (timeDelay > clock());         //stop when the clock is higher than time delay
}
*/
void counter(int userid, std::string clanType) {
	while (not(_kbhit()) && flag == 0) {     //keep looping while the user didn't hit any key and flag is 0

		if (second > 1) {         //after second is greater than 5, reset second and increase 1 day
			second = 0; day -= 1; resourceLevel -= 5;
			system("cls");
			printData();
		}
		if (day < 1) {
			system("CLS");
			//FightDayTest();
			fightDay(userid, clanType);
			day = 7;
		}

      //print out the new data, delay for 1000 millisecond and increase 1 second.
		Sleep(1000); second += 1;
	}
	selection(userid, clanType);    //after the user hit the keyboard, call the menu selection
}

void print(int& x) {
	x = resourceLevel;
}




void printData() {   //print data to screen
	system("CLS");      //clear the screen
	
	output();
	std::cout << std::setfill('+') << std::setw(120) << "+";
	printf("\nDays Till Fight: %d \n", day);      //output the data
	printf("[1] View Market | [2] View Fighters | [3] See Inventory | [4] End\n");       //menu for user
}

int selection(int userid, std::string clanType) {      // menu selection
	switch (_getch()) {    //collect input from user
	case 48: flag = 0; break;        //press 0 set flag to 0 means start. incase clock stops for some reason. it shouldn't
	case 49: flag = 0; testCase1(); break;		  //press 1 to see testCase1	
	case 50: flag = 0; showFightersCase(userid); break;        //press 2 to see showFightersCase
	case 51: flag = 0; showInventoryCase(userid, clanType); break; // press 3 to see ShowInventoryCase
		day = second = 0; flag = 1; //press 3 reset everything, set flag to 1 means stop
		output();
		printData();                //print the new data after reset
		break;
	case 52: snap = false;  return snap;; break;        //press 4, exit the program
	}
	return 1;
}


int timeTillFight(int userid, std::string clanType)
{
	printData();
	while (snap == true) 
	{             //keep the program running end only if snap is false
		counter(userid, clanType);
	}
	return 1;
}
//End of block [Jamie Warnock: ID 9328082]