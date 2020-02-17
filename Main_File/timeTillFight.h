#include <iostream>
#include <Windows.h> //include windows.h to use the sleep function. takes innput as milliseconds
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
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

//A working timer in taking key presses whilst counting. It's not working
//reference: https://www.youtube.com/watch?v=Kddn0MUbn4k 


int second = 0, minute = 0, flag = 0;

void printData();
int selection();


int test() {
	std::string tester;
	std::cout << "hope and pray for me\n";
	std::cin >> tester;
	return 1;
}

void delay(int ms)  //delay function
{
	clock_t timeDelay = ms + clock();    //Step up the difference from clock delay
	while (timeDelay > clock());         //stop when the clock is higher than time delay
}

void counter() {
	while (not(_kbhit()) && flag == 0) {     //keep looping while the user didn't hit any key and flag is 0

		if (second > 59) {         //after second is greater than 59, reset second and increase 1 minute
			second = 0; ++minute;
		}
		printData();           //print out the new data, delay for 1000 millisecond and increase 1 second.
		delay(1000); second += 1;
	}
	selection();    //after the user hit the keyboard, call the menu selection
}

void printData() {   //print data to screen
	system("cls");      //clear the screen
	printf("1.Start  2.testFunc  3.Reset  4. End\n");       //menu for user
	printf("***********************************\n");
	printf("            %d:%d\n", minute, second);      //output the data
	printf("***********************************\n");
}

int selection() {      // menu selection
	switch (_getch()) {    //collect input from user
	case 49: flag = 0; break;        //press 1 set flag to 0 means start
	case 50: flag = 0; test(); break;        //press 2 set flag to 1 means stop
	case 51:
		minute = second = 0; flag = 1; //press 3 reset everything, set flag to 1 means stop
		printData();                //print the new data after reset
		break;
	case 52: exit(0);; break;        //press 4, exit the program
	}
}


int timeTillFight()
{
	while (1) {             //keep the program running and never end
		counter();
	}
}
