#pragma once
#include <Windows.h>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <conio.h>
#include <string.h>
#include "GameClasses.h"

// shields, weapons, food, water,


int Market(Player& player , Weapon& weapon1 , Weapon& weapon2) {
	int playeritemchoice = 0;
	int itemAmmount = 0;
	int cost;
	std::cout << "Welcome to The Market";
	while (playeritemchoice < 1 or playeritemchoice > 4) {
		std::cout << "What can we help you with today 1:Food 2:Water 3:Weapons" << std::endl;
		std::cout << "1:Food" << std::endl;
		std::cout << "2:Water" << std::endl;
		std::cout << "3:Weapons" << std::endl;
		std::cout << "4 Visit the forge" << std::endl;
		std::cin >> playeritemchoice;
	}
	if (playeritemchoice == 1) {
		buyFood(player);
	}
	else if (playeritemchoice == 2) {
		buyWater(player);
	}
	else if (playeritemchoice == 3) {
		buyweapon(player , weapon1 , weapon2);
	}
	else if (playeritemchoice == 4) {
		forge(player, weapon1);
	}
	std::cout << "Thank you for your custom today";
}

int forge(Player &player , Weapon & weapon) {
	int playerChoice = 0;
	int weaponChoice = 0;
	std::cout<< "Welcome to the forge how can we help yout today" << std::endl;
	std::cout << "1: improve weapon " << std::endl;
	std::cout << "2: scrap a weapon " << std::endl;
	while (playerChoice < 1 && playerChoice > 2); {
		std::cout << "Please enter your Choice";
		std::cin >> playerChoice;
	}
	if (playerChoice == 1) {
		std::cout << "Which weapon would you like to improve";
		for (int i = 0; i < player.getWeaponNum; i++) {
			std::cout << i , player.weapons[i];
		}
		std::cin >> weaponChoice;
		//int costToImprove = player.weapons[weaponChoice].getQuality * 7;
		int costToImprove = 8;
		if (player.amountGold > costToImprove) {
			std::cout << "you cant afford to improve this weapon";
		}
		//else if (player.weapons[weaponChoice].getQuality = 10) {
		//	std::cout << "you cant improve this weapon it is already at its highest quality";
		//}
		else {
			std::cout << "Improvement successful." << std::endl;
			//player.weapons[weaponChoice].improveWeapon;
		}
		
	}
	if (playerChoice == 2) {
		std::cout << "which weapon would you like to scrap";
	}

}

void buyweapon( Player &player,  Weapon &weapon1 , Weapon &weapon2){
	int weaponChoice = 0;
	std::cout << "So your after a new weapon";
	std::cout << "Here's your options";
	std::cout << "Here is Weapon 1 " << " Weapon Type " << weapon1.getType << " Weapon name" << weapon1.getName << " Weapon Damage" << weapon1.getDamage << " Weapon Attack Speed" << weapon1.getAttackSpeed << " Weapon Crit Chance" << weapon1.getCritChance << " Weapon Quality" << weapon1.getQuality << " Weapon cost" << weapon1.getCost << std::endl;
	std::cout << "And here is Weapon 2 " << "Weapon Type " << weapon2.getType << " Weapon name" << weapon2.getName << " Weapon Damage" << weapon2.getDamage << " Weapon Attack Speed" << weapon2.getAttackSpeed << " Weapon Crit Chance" << weapon2.getCritChance << " Weapon Quality" << weapon2.getQuality << " Weapon cost" << weapon2.getCost << std::endl;
	while (weaponChoice < 1 && weaponChoice > 2) {
		std::cout << "Which weapon would you like";
		std::cin >> weaponChoice;
	}
	if (weaponChoice == 1) {
		player.amountGold = player.amountGold - weapon1.getCost;
		player.addWeapon;
		player.weapons[player.getWeaponNum] = weapon1;

	}
	else if (weaponChoice == 2) {
		player.amountGold = player.amountGold - weapon2.getCost;
		player.addWeapon;
		player.weapons[player.getWeaponNum] = weapon2;
	}
}


void buyFood( Player &player) {
	int itemAmmount = 0;
	int cost = 0;
	std::cout << "So your after some food, one stack of 5 food will cost you 2 gold, want to continue";
	while (itemAmmount > 0 && player.amountFood + (itemAmmount * 5) > 100) {
		std::cout << "How many stacks of food would you like";
		std::cin >> itemAmmount;
	}
	cost = itemAmmount * 2;
	player.amountGold = player.amountGold - cost;
	player.amountFood = player.amountFood + (itemAmmount * 5);
}

void buyWater(Player& player) {
	int itemAmmount = 0;
	int cost = 0;
	std::cout << "So your after some food, one barrel of 10 water will cost you 2 gold, want to continue";
	while (itemAmmount < 1 && player.amountFood + (itemAmmount * 10) > 100) {
		std::cout << "How many stacks of food would you like";
		std::cin >> itemAmmount;
	}
	cost = itemAmmount * 2;
	player.amountGold = player.amountGold - cost;
	player.amountWater = player.amountWater + (itemAmmount * 10);

}
