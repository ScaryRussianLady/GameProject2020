#pragma once
#include <iostream>

// Required headerfiles to calculate the fighters
#include "gladiatorListing.h"
#include "inventoryListing.h"
#include "GameClasses.h"
#include "sqlite3.h"

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "Indicators.h"
#include <iomanip>

// [START OF CODE BY: CHRISTIAN ]

bool battleOver(int hp, int minHealth, int dmg);

// This function will do the fight calculation and return a bool value. TRUE = Player wins | FALSE = Player doesn't win
bool fightCalc(loadGladiator plr_fighter, Weapon plr_weapon, Gladiator comp_fighter, Weapon comp_weapon, int minHealth) {

	// if this variable is true, then the battle will end
	bool over = false;
	int plr_damage = round((int(plr_fighter.strength) + int(plr_weapon.getDamage())) * (100 - comp_fighter.defence)/100);
	int comp_damage = round((int(comp_fighter.strength) + int(comp_weapon.getDamage())) * (100 - plr_fighter.defence)/100);

	// Fight happens in here until a gladiator reaches minimum health

	while (over == false) {

		// if the player's gladiator fights first
		if (plr_fighter.dexterity * int(plr_weapon.getAttackSpeed()) > comp_fighter.dexterity* int(comp_weapon.getAttackSpeed())) {
			// plr first
			if ((rand() % 100 + 1) < comp_fighter.agility) {
				// DODGED
				std::cout << comp_fighter.getName("full") << " has dodged " << plr_fighter.getName("full") << "'s attack!" << std::endl;
			}
			else {
				int critBonus = 0;

				if ((rand() % 100 + 1) < int(plr_weapon.getCritChance())) {
					critBonus = round(plr_damage * 0.40);
				}

				comp_fighter.adjustHP(-(plr_damage + critBonus));
				std::cout << plr_fighter.getName("full") << " has landed a strike on " << comp_fighter.getName("full") << " dealing " << plr_damage + critBonus << " points of damage!" << std::endl;

				if (critBonus != 0) {
					std::cout << "It was a critical strike!" << std::endl;
				}

				if (battleOver(int(comp_fighter.getHealth()), minHealth, plr_damage + critBonus) == true) {
					std::cout << "Thus winning the fight!" << std::endl;
					return true;
				}

			}
			Sleep(3000);
			std::cout << std::endl;
			// comp second
			if ((rand() % 100 + 1) < plr_fighter.agility) {
				// DODGED
				std::cout << plr_fighter.getName("full") << " has dodged " << comp_fighter.getName("full") << "'s attack!" << std::endl;
			}
			else {
				int critBonus = 0;

				if ((rand() % 100 + 1) < int(comp_weapon.getCritChance())) {
					critBonus = round(comp_damage * 0.40);
				}

				plr_fighter.adjustHP(-(comp_damage + critBonus));
				updateData(plr_fighter, "hp");
				std::cout << comp_fighter.getName("full") << " has landed a strike on " << plr_fighter.getName("full") << " dealing " << comp_damage + critBonus << " points of damage!" << std::endl;

				if (critBonus != 0) {
					std::cout << "It was a critical strike!" << std::endl;
				}

				if (battleOver(int(plr_fighter.getHealth()), minHealth, comp_damage + critBonus) == true) {
					std::cout << "Thus winning the fight!" << std::endl;
					return false;
				}

			}

		}
		else {
			// comp first
			if ((rand() % 100 + 1) < plr_fighter.agility) {
				// DODGED
				std::cout << plr_fighter.getName("full") << " has dodged " << comp_fighter.getName("full") << "'s attack!" << std::endl;
			}
			else {
				int critBonus = 0;

				if ((rand() % 100 + 1) < int(comp_weapon.getCritChance())) {
					critBonus = round(comp_damage * 0.40);
				}

				plr_fighter.adjustHP(-(comp_damage + critBonus));
				updateData(plr_fighter, "hp");
				std::cout << comp_fighter.getName("full") << " has landed a strike on " << plr_fighter.getName("full") << " dealing " << comp_damage + critBonus << " points of damage!" << std::endl;

				if (critBonus != 0) {
					std::cout << "It was a critical strike!" << std::endl;
				}

				if (battleOver(int(plr_fighter.getHealth()), minHealth, comp_damage + critBonus) == true) {
					std::cout << "Thus winning the fight!" << std::endl;
					return false;
				}

			}
			Sleep(3000);
			std::cout << std::endl;

			//plr second
			if ((rand() % 100 + 1) < comp_fighter.agility) {
				// DODGED
				std::cout << comp_fighter.getName("full") << " has dodged " << plr_fighter.getName("full") << "'s attack!" << std::endl;
			}
			else {
				int critBonus = 0;

				if ((rand() % 100 + 1) < int(plr_weapon.getCritChance())) {
					critBonus = round(plr_damage * 0.40);
				}

				comp_fighter.adjustHP(-(plr_damage + critBonus));
				std::cout << plr_fighter.getName("full") << " has landed a strike on " << comp_fighter.getName("full") << " dealing " << plr_damage + critBonus << " points of damage!" << std::endl;

				if (critBonus != 0) {
					std::cout << "It was a critical strike!" << std::endl;
				}

				if (battleOver(int(comp_fighter.getHealth()), minHealth, plr_damage + critBonus) == true) {
					std::cout << "Thus winning the fight!" << std::endl;
					return true;
				}

			}
		}

		Sleep(3000);
		std::cout << std::endl;

	}
}

// [START OF CODE BY: CHRISTIAN ]

// This function is used to prepare for the fight calculation by taking the user's Id and clan type and collecting information based off of this information
void fightDay(int userid, std::string clanType) {

	// initialising the variables that will be used for gladiator and weapon selection
	std::string gladiatorChoice;
	std::string weaponChoice;

	std::string yesNo;

	// These the the data structures that the data will be put in before being put into temporary objects
	gladiatorData gladData;
	weaponData wpnData;

	std::cout << std::setfill('+') << std::setw(60) << "FIGHT DAY";
	std::cout << std::setfill('+') << std::setw(59) << "+" << std::endl;

	// this while loop asks the player which gladiator they want to select. if they accidentally select one they don't want to, they can go back and select again
	while (true) {
		std::cout << "\nWhich of your gladiators do you want to send into battle?: \n" << std::endl;
		showGladiators(userid, 0);
		std::cin >> gladiatorChoice;

		system("CLS");

		// Verification goes here
		std::cout << "You have selected:\n" << std::endl;
		showGladiators(userid, std::stoi(gladiatorChoice));
		std::cout << "Is this the gladiator you wanted to select?\nYES[1] NO[0]\n" << std::endl;
		std::cin >> yesNo;

		system("CLS");

		if (std::stoi(yesNo) == 1) {
			gladData = importGladiatorData(userid, std::stoi(gladiatorChoice));
			//std::cout << "This the dude" << gladData.nn << std::endl;

			break;
		}
	}

	// This while loop asks for which wepaon the user wants to select. if the wrong one is select, the loop goes back and asks the user to select again.
	while (true) {
		std::cout << "\nWhat weapon do you want your gladiator to bring with them?: \n" << std::endl;
		showInventory(userid, 0, clanType, false);
		std::cin >> weaponChoice;

		system("CLS");

		std::cout << "You have selected:\n" << std::endl;
		showInventory(userid, std::stoi(weaponChoice), clanType, false);
		std::cout << "Is this the weapon you wanted to select?\nYES[1] NO[0]\n" << std::endl;
		std::cin >> yesNo;

		system("CLS");

		if (std::stoi(yesNo) == 1) {

			wpnData = showInventory(userid, std::stoi(weaponChoice), clanType, true);
	

			break;
		}
	}

	singularWordOutput("THEN,\nLET\nTHE\nBATTLE\nBEGIN!!!\n");

	system("CLS");

	// Objects for the player and npc are created here to be used in the fight calculation function

	//Create plr objects
	loadGladiator plrGlad(
		gladData.gladId, gladData.plrId, gladData.fn, gladData.ln, gladData.nn, gladData.hp, gladData.hng, gladData.thr,
		gladData.stg, gladData.def, gladData.agi, gladData.dex);
	Weapon plrWeap(wpnData.name, wpnData.quality, wpnData.damage, wpnData.attackSpeed, wpnData.critChance);


	//Create NPC objects
	Gladiator npcGlad = createGladiator(0, true);
	Weapon npcWeap("Gladius", 1, 7, 2, 20);

	// Plugging the data into the fight calculator
	// true = the fight was won
	// false = the fight was lost
	bool win = fightCalc(plrGlad, plrWeap, npcGlad, npcWeap, 0);

	std::cout << std::endl;

	// depending on the win/loss status, the player is told if they won or lost the fight
	if (win == true) {
		singularWordOutput("Your gladiator has won this fight!");
		Sleep(3000);
	}
	else {
		singularWordOutput("Your gladiator has won this fight!");
		Sleep(3000);
	}

	system("cls");

}

// [END OF CODE BY: CHRISTIAN ]

bool battleOver(int hp, int minHealth, int dmg);


// [END OF CODE BY: CHRISTIAN ]

// [START OF CODE BY: CHRISTIAN ]

// this function calculates whether damage will end a fight depending on what the minimum health is. if the minimum health is 0, fights will go to the death.
bool battleOver(int hp, int minHealth, int dmg){
	
	if (hp - dmg <= minHealth) {
		return true;
	}
	else {
		return false;
	}

}
// [END OF CODE BY: CHRISTIAN ]