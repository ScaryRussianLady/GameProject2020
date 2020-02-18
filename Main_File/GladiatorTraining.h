#pragma once
#include <iostream>
#include <stdlib.h>

#include "Gladiator.h"

void trainGladiator() {

	// Introductory dialogue
	std::cout << "Looking to toughen up your boys, eh?" << std::endl;
	std::cout << "Who has the displeasure of being put through my training today? >> ";

	char Trainee[25];
	std::cin.getline(Trainee, 25);

	std::cout << "Which skill do you want to improve?" << std::endl;

	// Needs skills to complete
	std::cout << "LIST SKILLS >> ";

	char Skill[10];
	std::cin.getline(Skill, 10);
	
}

void giveTraining() {
	
}