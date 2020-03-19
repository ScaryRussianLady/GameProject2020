#pragma once

#include "GameClasses.h"
#include "Introduction.h"

#include <sstream>
#include <fstream>
#include <limits>
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <functional>

// [START OF CODE BY: CHRISTIAN]

// This function takes the gladiatorobject created in another function and saves it to the database using SQL commands
void saveData(PlayerGladiator gladiatorObj) {

    std::string playerIDstr = std::to_string(gladiatorObj.getPlayerID());

    sqlite3* db;
    char* zErrMsg = 0;
    int rc;
    std::string sql;
    rc = sqlite3_open("GladiatorDatabase.db", &db);

    if (rc)
    {
        std::cout << "Database error: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }

    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

    // This SQL command inserts a new record containing the gladiator's data
    sql = "INSERT INTO PlayerGladiators ('gladiatorID', 'playerID', 'firstName', 'surname' , 'nickname', 'hp', 'hunger', 'thirst', 'strength', 'defence', 'agility', 'dexterity') VALUES (NULL, '" + std::to_string(gladiatorObj.getPlayerID()) + "', '" + gladiatorObj.getName("firstname") + "' ,'" + gladiatorObj.getName("surname") + "', '" + gladiatorObj.nickname + "', " + std::to_string(gladiatorObj.getHealth()) + ", " + std::to_string(gladiatorObj.getHunger()) + ", " + std::to_string(gladiatorObj.getThrist()) + ", " + std::to_string(gladiatorObj.strength) + ", " + std::to_string(gladiatorObj.defence) + ", " + std::to_string(gladiatorObj.agility) + ", " + std::to_string(gladiatorObj.dexterity) + ");";

    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    sqlite3_close(db);
    return;
}

// This function will update the gladiator's data in the database based on the attribute argument passedd into it
void updateData(loadGladiator gladiatorObj, std::string attribute) {

    std::string value;

    sqlite3* db;
    char* zErrMsg = 0;
    int rc;
    std::string sql;
    rc = sqlite3_open("GladiatorDatabase.db", &db);

    if (rc)
    {
        std::cout << "Database error: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }

    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

    // Depending on the attribute argument, the database will update different attributes of the gladiator record
    if (attribute == "hp") {
        value = std::to_string(gladiatorObj.getHealth());
    }
    else if (attribute == "hunger") {
        value = std::to_string(gladiatorObj.getHunger());
    }
    else if (attribute == "thirst") {
        value = std::to_string(gladiatorObj.getThrist());
    }
    else if (attribute == "strength") {
        value = std::to_string(gladiatorObj.strength);
    }
    else if (attribute == "defence") {
        value = std::to_string(gladiatorObj.defence);
    }
    else if (attribute == "agility") {
        value = std::to_string(gladiatorObj.agility);
    }
    else if (attribute == "dexterity") {
        value = std::to_string(gladiatorObj.dexterity);
    }
    else if (attribute == "nickname") {
        value = gladiatorObj.nickname;
    }

    // The SQL commands to update the attribute
    sql = "UPDATE PlayerGladiators SET " + attribute + " = " + value + " WHERE gladiatorID = " + std::to_string(gladiatorObj.getGladiatorID()) + ";";

    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    sqlite3_close(db);
    return;
}


// This function creates a player gladiator and then calls the function to save this data to the database.
// If the isNPC is true, then it won't be saved to the database.
Gladiator createGladiator(int playerID, bool isNPC) {

	if (isNPC == true) {
		Gladiator newNPC;

		return newNPC;
	}

	PlayerGladiator newGladiatior(playerID);

    saveData(newGladiatior);

    return newGladiatior;

}

// [END OF CODE BY: CHRISTIAN]