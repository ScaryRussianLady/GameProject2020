#pragma once
#include <iostream>
#include <stdlib.h> 

// [START OF CODE BY: CHRISTIAN ]

class Player {
private:

	char name[25];
	char clanType[25];
	char clanName[50];

	void setUp() {
		std::cout << "Hello Chief, what name would you like to be addressed by? >> ";
		std::cin.getline(name, 25);
		name[0] = toupper(name[0]);

		while (true) {
			std::cout << "What type of clan would you like to lead? (Attack or Defence?) >> ";
			std::cin.getline(clanType, 25);

			for (unsigned char i = 0; i < strlen(clanType); i++) {
				clanType[i] = (tolower(clanType[i]));
			}

			if (std::string(clanType) == std::string("attack") || std::string(clanType) == std::string("defence")) {
				break;
			}
			else {
				std::cout << "You need to choose either ATTACK or DEFENCE!" << std::endl;
			}
		}

		std::cout << "And what would you like to name this " << clanType << " type clan of yours, Chief " << name << "? >> ";
		std::cin.getline(clanName, 25);
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

// [START OF CODE BY: CHRISTIAN ]

class Gladiator {
private:

	std::string firstname;
	std::string surname;
#
	unsigned char hp;
	unsigned char hunger;
	unsigned char thirst;

	void setUp() {
		hp = 100;
		hunger = 100;
		thirst = 100;

		// Going to set up a random name generator
		std::string firstnameList[28] = { "Augustus", "Cassius", "Cicero", "Domitius", "Felix", "Hadrianus", "Marcellus", "Hortensius",
		"Julius", "Marianus", "Maximus", "Octavius", "Titus", "Valentinus", "Vitus", "Valerius", "Albus", "Antonius",
		"Caesar", "Blasius", "Brutus", "Crispus", "Decimus", "Festus", "Germanus", "Marcus", "Maximus", "Septimius" };

		std::string surnameList[24] = { "Gnaeus", "Flavius", "Pustula", "Lucius", "Calidius", "Maius", "Primus", "Statilius",
			"Comitianus", "Manius", "Memmius", "Ferentinus", "Gallio", "Aquillius", "Gaurus", "Sextus", "Calidius", "Pilus",
			"Arruns", "Pomponius", "Aponius", "Appius", "Sornatius", "Narcissus" };

		firstname = firstnameList[rand() % 27 + 0];
		surname = surnameList[rand() % 24 + 0];

	}

public:

	std::string nickname;

	// Gladiator's stats that'll be used during battles
	unsigned int strength;
	unsigned int defence;
	unsigned int agility;
	unsigned int dexterity;

	Gladiator() {

		strength = rand() % 10 + 5;
		defence = rand() % 10 + 5;
		agility = rand() % 10 + 5;
		dexterity = rand() % 10 + 5;

		setUp();
	}

	void changeNickname(std::string newName) {
		nickname = newName;
	}

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
};

// [END OF CODE BY: CHRISTIAN ]