#include <iostream>
#include <stdlib.h> 
#include <GameClasses.h>

// [Callum Jones 9406128] Function to train the basic stats of a gladiator
int trainGladiator() {
	bool trained = false;
	int gladChoice = 0;
	int statChoice = 0;
	// need a list of players current gladiators from the player class for now will call Player.gladiators
	std::cout << "Please Choose a the number of the gladiator to train from these options";
	for (int i = 0; i < Player.numOfGladiators; i++) {
		std::cout << i << ":" << Player.gladiators[i].nickname << std::endl;
	}
	std::cin >> gladChoice;
	while (gladChoice < 1 & gladChoice > Player.numOfGladiators) {
		std::cout << "Please enter a valid choice" << std::endl;
		std::cin >> gladChoice;
	}

	std::cout << "These are your chosen gladiators current stats";
	std::cout << Player.gladiators[gladChoice - 1].strength;
	std::cout << Player.gladiators[gladChoice - 1].agility;
	std::cout << Player.gladiators[gladChoice - 1].dexterity;

	while (statChoice < 1 & statChoice > 3) {
		std::cout << "Please choose a stat to train from 1:Strength 2:agility 3:Dexterity" << std::endl;
		std::cin >> statChoice;
	}
	std::cout << "Ok your chosen stat will be trained";

	if (statChoice == 1) {
		Player.gladiators[gladChoice].increaseStrength(2);
		std::cout << "This gladiators strength stat is now" << Player.gladiators[gladChoice].strength;
		trained = true;
	}
	else if (statChoice == 2) {
		Player.gladiators[gladChoice].increaseAgility + 0.05;
		std::cout << "This gladiators agility stat is now" << Player.gladiators[gladChoice].agility;
		trained = true;
	}
	else if (statChoice == 3) {
		Player.gladiators[gladChoice].increaseDexterity + 0.05;
		std::cout << "This gladiators dexterity stat is now" << Player.gladiators[gladChoice].dexterity;
		trained = true;
	}
	if (trained == true) {
		Player.gladiators[gladChoice].adjustHunger(-10);
		Player.gladiators[gladChoice].adjustThirst(-15);
	}
	return gla;