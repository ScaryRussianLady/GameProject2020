#pragma once
#include <iostream>
#include <stdlib.h> 

// [START OF CODE BY: CHRISTIAN ]

class Player {
private:

	// These variables are private so that they cannot be changed and break something
	char name[25];
	char clanType[25];
	char clanName[50];

	// This function sets these player variables up
	void setUp() {

		// This will take the name that the player would like to go by and save it in the player variable
		std::cout << "Hello Chief, what name would you like to be addressed by? >> ";
		std::cin.getline(name, 25);
		name[0] = toupper(name[0]);

		// This will get the player's clan type and it will make sure it's either attack of defence
		while (true) {
			std::cout << "What type of clan would you like to lead? (Attack or Defence?) >> ";
			std::cin.getline(clanType, 25);

			// Turns the user's input into all lowercase so it can be checked to see if it's the correct value
			for (unsigned char i = 0; i < strlen(clanType); i++) {
				clanType[i] = (tolower(clanType[i]));
			}

			// Checks if the user's input is correct. If it is, the while loop will break. If not, the user will be asked to do it again
			if (std::string(clanType) == std::string("attack") || std::string(clanType) == std::string("defence")) {
				break;
			}
			else {
				std::cout << "You need to choose either ATTACK or DEFENCE!" << std::endl;
			}
		}

		// This allows for the player to name their clan.
		std::cout << "And what would you like to name this " << clanType << " type clan of yours, Chief " << name << "? >> ";
		std::cin.getline(clanName, 25);
	}

public:

	// Public variables because it makes sense for them to be changed by other's code
	unsigned int gold;

	unsigned int food;
	unsigned int water;

	// Initialisation of the function which calls for the private setup and gives starting gold, food and water
	// You can change these starting gold, food and water if need be.
	Player()
	{
		gold = 100; //starting golden
		food = 100; //starting food
		water = 100; //starting water

		setUp();
	}

	// Since name is a private variable, this will be used to get the name from this class
	char* getName() {
		return name;
	}

	// Since clan type is a private variable, this will be used to get the name from this class
	char* getClanType() {
		return clanType;
	}

	// Since clan name is a private variable, this will be used to get the name from this class
	char* getClanName() {
		return clanName;
	}
};

// [END OF CODE BY: CHRISTIAN ]

// [START OF CODE BY: CHRISTIAN ]

class Gladiator {
private:

	// private variables so that they cannot be changed.
	// std::string so that they can be made random easily in later code.
	std::string firstname;
	std::string surname;
#	
	// These variables are private so that they can't be made above 100 by other developers by accident
	// there will be a function that deals with these variables to make sure that they don't exceed 100 or fall below 0
	unsigned char hp;
	unsigned char hunger;
	unsigned char thirst;

	// Sets up the private variables and provides a random name for the gladiaor for uniqueness
	void setUp() {
		hp = 100;
		hunger = 100;
		thirst = 100;

		// These arrays have names that will be selected using a random number generator to provide a unique gladiator name
		// there are 672 possible combinations
		std::string firstnameList[28] = { "Augustus", "Cassius", "Cicero", "Domitius", "Felix", "Hadrianus", "Marcellus", "Hortensius",
		"Julius", "Marianus", "Maximus", "Octavius", "Titus", "Valentinus", "Vitus", "Valerius", "Albus", "Antonius",
		"Caesar", "Blasius", "Brutus", "Crispus", "Decimus", "Festus", "Germanus", "Marcus", "Maximus", "Septimius" };

		std::string surnameList[24] = { "Gnaeus", "Flavius", "Pustula", "Lucius", "Calidius", "Maius", "Primus", "Statilius",
			"Comitianus", "Manius", "Memmius", "Ferentinus", "Gallio", "Aquillius", "Gaurus", "Sextus", "Calidius", "Pilus",
			"Arruns", "Pomponius", "Aponius", "Appius", "Sornatius", "Narcissus" };

		// Sets the random names
		firstname = firstnameList[rand() % 27 + 0];
		surname = surnameList[rand() % 24 + 0];

	}

public:

	// Nickname is another way players can make their gladiators more unique
	std::string nickname;

	// Gladiator's stats that'll be used during battle calculations
	unsigned int strength;
	unsigned int defence;
	unsigned int agility;
	unsigned int dexterity;

	// Initialises the gladiator class
	Gladiator() {

		// Provides random stats in a range of 10-5 to further make characters more unique
		strength = rand() % 10 + 5;
		defence = rand() % 10 + 5;
		agility = rand() % 10 + 5;
		dexterity = rand() % 10 + 5;

		setUp();
	}

	// Can be used to get the name of the gladiator (either firstname, surname or the full name)
	std::string getName(std::string nameType) {
		if (nameType == "firstname") {
			return firstname;
		}
		else if (nameType == "surname") {
			return surname;
		}
		else if (nameType == "full") {
			return firstname + " " + surname;
		}
	}

	// These functions adjust the HP private variable to ensure that it does not exceed 100 or proceed 0
	void adjustHP(int changeValue) {
		if (hp + changeValue < 0) {
			hp = 0;
			return;
		}

		if (hp + changeValue > 100) {
			hp = 100;
			return;
		}

		hp = hp + changeValue;
	}

	// These functions adjust the hunger private variable to ensure that it does not exceed 100 or proceed 0
	void adjustHunger(int changeValue) {
		if (hunger + changeValue < 0) {
			hunger = 0;
			return;
		}

		if (hunger + changeValue > 100) {
			hunger = 100;
			return;
		}

		hunger = hunger + changeValue;
	}

	// These functions adjust the thirst private variable to ensure that it does not exceed 100 or proceed 0
	void adjustThirst(int changeValue) {
		if (thirst + changeValue < 0) {
			thirst = 0;
			return;
		}

		if (thirst + changeValue > 100) {
			thirst = 100;
			return;
		}

		thirst = thirst + changeValue;
	}

	// These functions are to get the private variables
	unsigned int getHealth() {
		return hp;
	}

	unsigned int getHunger() {
		return hunger;
	}

	unsigned int getThrist() {
		return thirst;
	}
};

// [END OF CODE BY: CHRISTIAN ]