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

/*
	INCLUDE DatabaseInfo;
	INCLUDE player, weapon and gladiator class;
	gameHealthOfPlayer = currentHealthOfPlayer;

	FOR EVERY gladiator IN player
		computerGladiatorsNumber = playerGladiatorsNumber;
	ENDFOR

	FOR EVERY weapon IN player
		computerWeapon[] = playerWeapon[];
		FOR EVERY computerWeapon[]
			newWeapons = weapon.stats + (randomNumberGenerator); //this will generate a random number between -5 and +5
		ENDFOR
	ENDFOR

	*/

// [START OF CODE BY: CHRISTIAN ]

void fightDay(int userid, std::string clanType) {

	std::string gladiatorChoice;
	std::string weaponChoice;

	std::string yesNo;

	gladiatorData gladData;
	weaponData wpnData;

	std::cout << std::setfill('+') << std::setw(60) << "FIGHT DAY";
	std::cout << std::setfill('+') << std::setw(59) << "+" << std::endl;

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

	//Create plr objects
	loadGladiator plrGlad(
		gladData.gladId, gladData.plrId, gladData.fn, gladData.ln, gladData.nn, gladData.hp, gladData.hng, gladData.thr,
		gladData.stg, gladData.def, gladData.agi, gladData.dex);
	Weapon plrWeap(wpnData.name, wpnData.quality, wpnData.damage, wpnData.attackSpeed, wpnData.critChance);


	//Create NPC objects
	Gladiator npcGlad = createGladiator(0, true);
	Weapon npcWeap("Gladius", 1, 7, 2, 20);

	// Plugging the data into the fight calculator
	bool win = fightCalc(plrGlad, plrWeap, npcGlad, npcWeap, 0);

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

bool battleOver(int hp, int minHealth, int dmg){
	
	if (hp - dmg <= minHealth) {
		return true;
	}
	else {
		return false;
	}

}
// [END OF CODE BY: CHRISTIAN ]