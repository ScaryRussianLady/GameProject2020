#pragma once
#include <iostream>

// Required headerfiles to calculate the fighters
#include "gladiatorListing.h"
#include "GameClasses.h"
#include "sqlite3.h"

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "Indicators.h"
#include <iomanip>

// [START OF CODE BY: CHRISTIAN ]

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

void fightDay(int userid) {
	std::string gladiatorChoice;
	std::string weaponChoice;

	std::string yesNo;

	gladiatorData gladData;

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
			std::cout << "This the dude" << gladData.plrId << std::endl;
			break;
		}
	}
	
	std::cout << "\nWhat weapon do you want your gladiator to bring with them?: \n" << std::endl;
	std::cin >> weaponChoice;

	// Verification goes here

	// Plugging the data into the fight calculator
	// fightCalc()

}

// [END OF CODE BY: CHRISTIAN ]

// This function will do the fight calculation and return and object the results
bool fightCalc(Gladiator plr_fighter, Gladiator comp_fighter, unsigned char minHealth) {

	return true;

}

// [END OF CODE BY: CHRISTIAN ]

// [START OF CODE BY: CHRISTIAN ]

bool battleOver(unsigned char hp, unsigned char minHealth, int dmg){
	
	if (hp - dmg < minHealth) {
		return true;
	}
	else {
		return false;
	}

}
// [END OF CODE BY: CHRISTIAN ]