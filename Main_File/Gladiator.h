#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <windows.h>

//Start of code [Jamie warnock: ID 9328082]
class gladiator {
public:

	std::string mame;

	//core
	std::string allias;
	int hp;
	int hunger;
	int thirst;
	int strength;
	int agility;
	int dexterity;


	//some other stats probably will be implemented

	//imt strength; - dladiator may have a base damage. 
	                  //potentially added on top of weapons they use
	//int agility; - gladiator may have base dodge/blobk chance
	//float dexterity - gladiator may have a base crit chance

	//stats max capacity. maybe make this part private? idk
	int hpMax = 100;
	int maxHung = 100;
	int maxThirst = 100;
	int strengthMax = 50;
	float agilityMax = 1;
	float dexterityMax = 1;

};
//just testing around with the gladiator class
int firstGlads() {
	gladiator gladiator[3];


	for (int i = 0; i < 3; i++) {
		std::cout << "Please choose a name for your gladiator: ";
		std::cin >> gladiator[i].allias;
		gladiator[i].hp = 100;
		gladiator[i].hunger = 50;
		gladiator[i].thirst = 50;

		std::cout << "Curernt hp: " << gladiator[i].hp << std::endl;
		std::cout << "Food level: " << gladiator[i].hunger << std::endl;
		std::cout << "Water level: " << gladiator[i].thirst << std::endl;
		}
	system("CLS");
	std::cout << "Your Gladiators \n----------------------------\n";
	for (int i = 0; i < 3; i++) {
		std::cout << gladiator[i].allias << " | " << "HP: " << gladiator[i].hp;
		std::cout << "/" << gladiator[i].hpMax << std::endl;
		std::cout << "Hunger: " << gladiator[i].hunger << "/100" << std::endl;
		std::cout << "Thirst: " << gladiator[i] .thirst << "/100" << std::endl;
		std::cout << "--------------------------------------------------\n";
		}
	return 1;
}
//End of block [Jamie Warnock: ID 9328082]


// [Callum Jones 9406128] Function to train the basic stats of a gladiator
int trainGladiator() {
	bool trained = false;
	int gladChoice = 0;
	int statChoice = 0;
	gladiator gladiator[3];
	std::cout << "Please Choose a gladiator to train from these options";
	for (int i = 0; i < 3; i++) {
		std::cout << i << ":" << gladiator[i].allias << std::endl;
	}
	std::cin >> gladChoice;
	while (gladChoice < 1 and gladChoice < 3) {
		std::cout << "Please enter a valid choice" << std::endl;
		std::cin >> gladChoice;
	}
	
	std::cout << "These are your chosen gladiators current stats" ;
	std::cout << gladiator[gladChoice - 1].strength;
	std::cout << gladiator[gladChoice - 1].agility;
	std::cout << gladiator[gladChoice - 1].dexterity;

	while (statChoice < 1 and statChoice > 3) {
		std::cout << "Please choose a stat to train from 1:Strength 2:agility 3:Dexterity"<< std::endl;
		std::cin >> statChoice;
	}
	std::cout << "Ok your chosen stat will be trained";
	if (statChoice == 1) {
		gladiator[gladChoice].strength + 2;
		std::cout << "This gladiators strength stat is now" << gladiator[gladChoice].strength;
		trained = true;
	}
	else if (statChoice == 2) {
		gladiator[gladChoice].agility + 0.05;
		std::cout << "This gladiators agility stat is now" << gladiator[gladChoice].agility;
		trained = true;
	}
	else if (statChoice == 3) {
		gladiator[gladChoice].dexterity + 0.05;
		std::cout << "This gladiators dexterity stat is now" << gladiator[gladChoice].dexterity;
		trained = true;
	}
	if (trained == true) {
		gladiator[gladChoice].hunger - 10;
		gladiator[gladChoice].thirst - 15;
	}
	return 1;
	

}