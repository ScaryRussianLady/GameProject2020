#pragma once
#include <iostream>

// Required headerfiles to calculate the fighters
#include "Gladiator.h"

// [START OF CODE BY: CHRISTIAN SHAW]

// This function will store the results of the fight calculations
class fightResults {
public:

	// TRUE means that the player won, FALSE means that the player lost
	bool win;
	
	// The player's gladiator's losses in stats
	unsigned char plr_hpLost;
	unsigned char plr_hungerLost;
	unsigned char plr_thirstLost;

	// The computers's gladiator's losses in stats
	unsigned char comp_hpLost;
	unsigned char comp_hungerLost;
	unsigned char comp_thirstLost;
};

// [END OF CODE BY: CHRISTIAN SHAW]

// [START OF CODE BY: CHRISTIAN SHAW]

// This function will do the fight calculation and return and object the results
fightResults fightCalculation(gladiator plr_fighter, gladiator comp_fighter, unsigned char minHealth) {
	
	// Can't write more code without knowing how the weapons work

}

// [END OF CODE BY: CHRISTIAN SHAW]

// [START OF CODE BY: CHRISTIAN SHAW]

bool battleOver(unsigned char hp, unsigned char minHealth, int dmg){
	
	if (hp - dmg < minHealth) {
		return true;
	}
	else {
		return false;
	}

}

// [END OF CODE BY: CHRISTIAN SHAW]