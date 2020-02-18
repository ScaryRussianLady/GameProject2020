#pragma once
#include <iostream>

// [START OF CODE BY: CHRISTIAN ]

class Player {
private:

	char name[25];
	char clanType[25];
	char clanName[50];

	void setUp() {
		std::cout << "Hello Chief, what name would you like to be addressed by? >> ";
		std::cin.getline(name, 25);

		std::cout << "What type of clan would you like to lead? (Attack or Defence?) >> ";
		std::cin.getline(clanType, 25);

		std::cout << "And what would you like to name this " << clanType << " type clan of yours, Chief " << name << "? >> ";
		std::cin.getline(clanType, 25);
	}

public:

	unsigned int gold;

	unsigned int food;
	unsigned int water;

	Player()
	{
		gold = 100; //starting golden
		food = 100; //starting food
		water = 100; //starting water

		setUp();
	}

	char* getName() {
		return name;
	}

	char* getClanType() {
		return clanType;
	}

	char* getClanName() {
		return clanName;
	}
};

// [END OF CODE BY: CHRISTIAN ]

