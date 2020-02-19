#include <iostream>
#include <stdlib.h> 
#include "GameClasses.h"

// [Callum Jones 9406128] Function to train the basic stats of a gladiator
int trainGladiator(Gladiator& gladiator) {
	bool trained = false;
	int statChoice = 0;

	std::cout << "These are your chosen gladiators current stats";
	std::cout << gladiator.strength;
	std::cout << gladiator.agility;
	std::cout << gladiator.dexterity;

	while (statChoice < 1 && statChoice > 3) {
		std::cout << "Please choose a stat to train from 1:Strength 2:agility 3:Dexterity" << std::endl;
		std::cin >> statChoice;
	}
	std::cout << "Ok your chosen stat will be trained";

	if (statChoice == 1) {
		gladiator.strength + 2;
		std::cout << "This gladiators strength stat is now" << gladiator.strength;
		trained = true;
	}
	else if (statChoice == 2) {
		gladiator.agility + 0.05;
		std::cout << "This gladiators agility stat is now" << gladiator.agility;
		trained = true;
	}
	else if (statChoice == 3) {
		gladiator.dexterity + 0.05;
		std::cout << "This gladiators dexterity stat is now" << gladiator.dexterity;
		trained = true;
	}
	if (trained == true) {
		gladiator.adjustHunger(-10);
		gladiator.adjustThirst(-15);
	}
}