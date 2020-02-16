#pragma once
#include <string>
#include <iostream>
#include <vector>

class gladiator {
public:
	//core
	std::string mame;
	int hp;
	int hunger;
	int thirst;

	//stats max capacity. maybe make this part private? idk
	int hpMax;
	int maxHung;
	int maxThirst;

};

int gladStats() {
	gladiator gladiator1;
	gladiator1.hp = 100;
	gladiator1.hunger = 50;
	gladiator1.thirst = 50;

	gladiator1.hpMax = 100;
	gladiator1.maxHung = 100;
	gladiator1.maxThirst = 100;

	std::cout << "Curernt hp: " << gladiator1.hp << std::endl;
	std::cout << "Food level: " << gladiator1.hunger << std::endl;
	std::cout << "Water level: " << gladiator1.thirst << std::endl;
}