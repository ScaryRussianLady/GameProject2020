#pragma once
#include <Windows.h>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <conio.h>
#include <string.h>
#include "timeTillFight.h"
#include "GameClasses.h"

// shields, weapons, food, water, medical, supplies


int Market(Player& player , Weapon& weapon) {

	int playeritemchoice = 0;
	int itemAmmount = 0;
	int cost;
	std::cout << "Welcome to The Market";
	while (playeritemchoice < 1 or playeritemchoice > 4) {
		std::cout << "What can we help you with today 1:Food 2:Water 3:Weapons 4:Medical Supplies";
		std::cin >> playeritemchoice;
	}
	if (playeritemchoice == 1) {
		std::cout << "So your after some food, one stack of 5 food will cost you 2 gold, want to continue";
		while (itemAmmount > 0 && player.amountFood + (itemAmmount * 5) > 100) {
			std::cout << "How many stacks of food would you like";
			std::cin >> itemAmmount;
		}
		cost = itemAmmount * 2;
		player.amountGold = player.amountGold - cost;
		player.amountFood = player.amountFood + (itemAmmount * 5);
	}
	if (playeritemchoice == 2) {
		std::cout << "So your after some food, one barrel of 10 water will cost you 2 gold, want to continue";
		while (itemAmmount < 1 && player.amountFood + (itemAmmount * 10) > 100) {
			std::cout << "How many stacks of food would you like";
			std::cin >> itemAmmount;
		}
		cost = itemAmmount * 2;
		player.amountGold = player.amountGold - cost;
		player.amountWater = player.amountWater + (itemAmmount * 10);
	}
	if (playeritemchoice == 3) {
		std::cout << "So your after some new weapons";
		std::cout << "Here's your options" ;
		Newweapon = Weapon::Weapon()
		while (itemAmmount < 1 && itemAmmount > 3) {
			std::cout << "Which weapon would you like";
			std::cin >> itemAmmount;
		}
		cost = itemAmmount;
		player.amountGold = player.amountGold - cost;
	}
}


	
