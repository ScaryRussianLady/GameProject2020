#pragma once
#include <iostream>
#include <stdlib.h>
#include <sqlite3.h>
#include <stdio.h>
#include <thread>
#include <conio.h>
#include <locale>
#include <string>
#include <cstring>
#include "healthManagement.h"
#include <cctype>
#include "GameClasses.h"
#include "goldManagement.h"
#include "clanFood.h"
#include "healthManagement.h"

// [START OF CODE BY: CHRISTIAN]

class Player {
private:

	// Variable for the database
	//int userID;

	char userName[25];
	char typeOfClan[25];
	char nameOfClan[25];
	std::string stringClan = nameOfClan;
	std::string stringName = userName;
	std::string stringTypeClan = typeOfClan;


	// These variables are private so that they cannot be changed and break something


	// The number of gladiators the player has
	unsigned int numOfGladiators;


	//#########################################################################
	//Beginning of code by [Annija Balode 9102828] and referenced from https://stackoverflow.com/questions/30426205/c-print-one-letter-at-the-time-how-to with adjustments.
	//Function for spelling out words letter by letter.
	/*void singularWordOutput(const std::string& text)
	{
		// loop through each character in the text
		for (std::size_t i = 0; i < text.size(); ++i)
		{
			// output one character
			// flush to make sure the output is not delayed
			std::cout << text[i] << std::flush;

			// sleep 30 milliseconds
			std::this_thread::sleep_for(std::chrono::milliseconds(30));
		}
	}*/
	//End of code by [Annija Balode 9102828] and referenced from https://stackoverflow.com/questions/30426205/c-print-one-letter-at-the-time-how-to with adjustments.
	//#########################################################################


	// This function sets these player variables up
	/*void setUp() 
	{

		//#########################################################################
		//Beginning of code by [Annija Balode 9102828]
		// This will take the name that the player would like to go by and save it in the player variable
		std::cout << "The Gladiator" << std::endl;
		std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;
		singularWordOutput("Welcome to The Gladiator.\nWhat is your name, Chief?\n");
		std::cin.getline(userName, 25);
		std::string users_name = userName;
		userName[0] = toupper(userName[0]);

		singularWordOutput(std::string(userName) + "! Emperor Macrinus is setting up new camps for Gladiators to train in!\n");
		singularWordOutput("It says on this rock here that he has now put you in charge of this camp,\nyour first order is to give it a name...\n");
		singularWordOutput("\nWhat would you like to name your clan, Chief " + std::string(userName) + "?\n");
		std::cin.getline(nameOfClan, 25);
		singularWordOutput("\nAs the official Chief of " + std::string(nameOfClan) + " you must decide whether you will be Attack or Defence.\n");


		while (true)
		{
			singularWordOutput("\nWhich one will it be?\n");
			std::cin.getline(typeOfClan, 25);
			std::string type_string = typeOfClan;
			int length = type_string.length();

			for (int i = 0; i < length; i++)
			{
				int upperCase = type_string[i];
				type_string[i] = toupper(upperCase);
			}

			if (type_string == "ATTACK")
			{
				std::cout << "Good, strong choice, all nations need muscle!" << std::endl;
				break;
			}

			if (type_string == "DEFENCE")
			{
				std::cout << "All nations need defending!" << std::endl;
				break;
			}

			else
			{
				std::cout << "Try again!" << std::endl;
				char typeOfClan[25];
				continue;
			}
		}


		//End of code by [Annija Balode 9102828]
		//#########################################################################


		// This will get the player's clan type and it will make sure it's either attack of defence
		/*while (true) {

			std::cout << "What type of clan would you like to lead? (Attack or Defence?) >> ";
			std::cin.getline(typeOfClan, 25);

			// Turns the user's input into all lowercase so it can be checked to see if it's the correct value
			for (unsigned char i = 0; i < strlen(typeOfClan); i++) {
				typeOfClan[i] = (tolower(typeOfClan[i]));
			}

			// Checks if the user's input is correct. If it is, the while loop will break. If not, the user will be asked to do it again
			if (std::string(typeOfClan) == std::string("attack") || std::string(typeOfClan) == std::string("defence")) {
				break;
			}
			else {
				std::cout << "You need to choose either ATTACK or DEFENCE!" << std::endl;
			}
		}

		// This allows for the player to name their clan.
		std::cout << "And what would you like to name this " << typeOfClan << " type clan of yours, Chief " << userName << "? >> ";
		std::cin.getline(nameOfClan, 25);
	}*/

public:

	// Public variables because it makes sense for them to be changed by other's code
	unsigned int amountGold;

	unsigned int amountFood;
	unsigned int amountWater;

	unsigned int amountHealth;

	// Initialisation of the function which calls for the private setup and gives starting gold, food and water
	// You can change these starting gold, food and water if need be.
	Player(int ID)
	{
		//setUp();
		//#########################################################################
		//Beginning of code by [Annija Balode 9102828]
		//Imports the function which manages the amount of gold the user currently has.
		//amountGold = playerGold(); 
		//Imports the function which manages the amount of food and water the user currently has.
		amountFood = 100;
		amountWater = 100;
		//Imports the function which manages the amount of health the user currently has.
		//amountHealth = healthManagement();

		//#########################################################################
		//End of code by [Annija Balode 9102828]

		//userID = ID;
		numOfGladiators = 0;

		

		
	}

	// Adds another gladiator to the number of gladiators variable
	void addGladiator() {
		numOfGladiators = numOfGladiators + 1;
	}

	// Since name is a private variable, this will be used to get the name from this class
	unsigned int getGladiatorNum() {
		return numOfGladiators;
	}

	// Since name is a private variable, this will be used to get the name from this class
	char* getName() {

		return userName;
	}

	// Since clan type is a private variable, this will be used to get the name from this class
	char* getClanType() {
		return typeOfClan;
	}

	// Since clan name is a private variable, this will be used to get the name from this class
	char* getClanName() {
		return nameOfClan;
	}
};

// [END OF CODE BY: CHRISTIAN ]

// [START OF CODE BY: CHRISTIAN & ANNIJA]

class Weapon {

private:

	// Name of the weapon
	std::string name;
	// Bool indicates the type of weapon this is. If it's an attack type weapon, it's TRUE, if it's defence, it's FALSE
	bool TypeAttack;

	// These are the weapon stats that will be used in battle calculations
	unsigned char quality;
	unsigned char damage;
	unsigned char attackSpeed;
	unsigned char critChance;
	unsigned char cost;

	// This is the limit to which weapons can be improved to
	const unsigned char MaxQuality = 10;

public:

	// Initialises the weapon using the input provided by the programmer. After this, the programmer can't change these variables directly
	Weapon(std::string weaponName, unsigned char weaponQuality, unsigned char weaponBaseDamage,
		unsigned char weaponAttackSpeed, unsigned char weaponCritChance) {

		name = weaponName;

		quality = weaponQuality;
		damage = weaponBaseDamage;
		attackSpeed = weaponAttackSpeed;
		critChance = weaponCritChance;
		cost = weaponQuality * 20;

	}

	// The following Getter functions get the private variables and returns it to the programmer
	std::string getName() {
		return name;
	}

	bool getType() {
		return TypeAttack;
	}

	unsigned char getQuality() {
		return quality;
	}

	unsigned char getDamage() {
		return damage;
	}

	unsigned char getAttackSpeed() {
		return attackSpeed;
	}

	unsigned char getCritChance() {
		return critChance;
	}
	//callum jones added cost based on quality
	unsigned char getCost() {
		return cost;
	}

	// Restricts weapons from being improved beyond the limit and scales the weapon stats accordingly
	void improveWeapon() {

		// If the weapon quality is already at it's limit, return and don't go any further
		if (quality == MaxQuality) {
			std::cout << "Sorry, this weapon cannot be improved any further!" << std::endl;
			return;
		}
		// If not, increase the quality by one and then begin the improvement scaling calculations
		quality = quality + 1;

		// Weapon improvement scaling done here (Make these values more suitable if need be)
		damage = damage + 2;
		attackSpeed = attackSpeed + 2;
		critChance = critChance + 1;

	}

};

// [END OF CODE BY: CHRISTIAN ]

// [START OF CODE BY: CHRISTIAN ]

class Gladiator {
protected:

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

	//

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
			// Deconstructs the gladiator class when it dies
			Gladiator::~Gladiator();
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

	// This section of the code handles attacking conducted by the gladiator

	void gladiatorAttack(Gladiator target, Weapon wpn) {

		int damage; // this will be how much damage the gladiator will deal

		// Damage calculation is done here (this can be alerted to suit the needs of the game)
		unsigned int baseDamage = strength + unsigned int(wpn.getDamage()); // This calculates damage on strength and weapon damage alone

		// If a crit is successful, then add 20% damage to the base damage
		if ((rand() % 100 + 0) < wpn.getCritChance() + unsigned int(dexterity)) {
			baseDamage = baseDamage * 1.2;
		}

		// Subtract the defense stat from the baseDamage to create the overall damage the opponent gladiator takes
		damage = baseDamage - target.defence;

		target.adjustHP(-damage); // this will deal the damage to the gladiator

	}

};

// A subclass in order to differenciate player gladiators and npc gladiators
class PlayerGladiator : public Gladiator {

private:

	// Variable that contains which player the gladiator belongs to (reserved for multiplayer)
	int playerID;

public:

	PlayerGladiator(int ID) {

		// Assign's the player's ID to this variable for identification of who owns the gladiator
		playerID = ID;
	}

	int getPlayerID() {
		return playerID;
	}
};

// A subclass in order for database information to be pushed to a gladiator class
class loadGladiator : public Gladiator {
private:

	int gladiatorID;
	int playerID;

public:

	loadGladiator(
		int gladID, 
		int plrID, 
		std::string fname, 
		std::string sname, 
		std::string nickname, 
		int hitpoints, 
		int hung, 
		int thir, 
		int streng,
		int def,
		int agil,
		int dext) {
		 
		gladiatorID = gladID;
		playerID = plrID;

		firstname = fname;
		surname = sname;

		hp = hitpoints;
		hunger = hung;
		thirst = thir;

		strength = streng;
		defence = def;
		agility = agil;
		dexterity = dext;

	}

	int getGladiatorID() {
		return gladiatorID;
	}

	int getPlayerID() {
		return gladiatorID;
	}

};

// [END OF CODE BY: CHRISTIAN ]