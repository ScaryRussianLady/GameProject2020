#pragma once
#include <string>
#include <iostream>
#include <vector>

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
int gladStats() {
	gladiator gladiator1;
	std::cout << "Please choose a name for your gladiator: ";
	std::cin >> gladiator1.allias;
	gladiator1.hp = 100;
	gladiator1.hunger = 50;
	gladiator1.thirst = 50;


	std::cout << "Curernt hp: " << gladiator1.hp << std::endl;
	std::cout << "Food level: " << gladiator1.hunger << std::endl;
	std::cout << "Water level: " << gladiator1.thirst << std::endl;

	return 1;
}