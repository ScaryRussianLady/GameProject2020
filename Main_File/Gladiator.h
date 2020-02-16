#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <windows.h>

class gladiator {
public:

	std::string mame;

	//core
	std::string allias;
	int hp;
	int hunger;
	int thirst;

	//some other stats probably will be implemented

	//imt strength; - dladiator may have a base damage. 
	                  //potentially added on top of weapons they use
	//int agility; - gladiator may have base dodge/blobk chance
	//float dexterity - gladiator may have a base crit chance

	//stats max capacity. maybe make this part private? idk
	int hpMax = 100;
	int maxHung = 100;
	int maxThirst = 100;

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

int seeGlads() {

}