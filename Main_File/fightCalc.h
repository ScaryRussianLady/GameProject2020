#pragma once
#include <iostream>

// Required headerfiles to calculate the fighters
#include "Gladiator.h"
#include "GameClasses.h"
#include "sqlite3.h"

// [START OF CODE BY: CHRISTIAN ]

// This function will store the results of the fight calculations
class fightResults {
public:

	// TRUE means that the player won, FALSE means that the player lost
	bool win;
	
	// The player's gladiator's losses in stats
	unsigned char plr_hpLost;
	unsigned char plr_hungerLost;
	unsigned char plr_thirstLost;
	unsigned char plr_gladiatorsLostGame;
	unsigned char plr_gladiatorsLost;

	//The computer's losses.
	unsigned char comp_hpLost;
	//unsigned char comp_hungerLost;
	//unsigned char comp_thirstLost;
	unsigned char comp_gladiatorsLostGame;
};

// [END OF CODE BY: CHRISTIAN ]

// [START OF CODE BY: CHRISTIAN ]

// This function will do the fight calculation and return and object the results
fightResults fightCalculation(gladiator plr_fighter, gladiator comp_fighter, unsigned char minHealth) {


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