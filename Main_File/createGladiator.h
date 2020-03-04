#pragma once

#include "GameClasses.h"

#include <sstream>
#include <fstream>
#include <limits>
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <functional>

int callback(void* NotUsed, int argc, char** argv, char** azColName) {

    // int argc: holds the number of results
    // (array) azColName: holds each column returned
    // (array) argv: holds each value

    for (int i = 0; i < argc; i++) {

        // Show column name, value, and newline
        std::cout << azColName[i] << ": " << argv[i] << std::endl;

    }

    // Insert a newline
    std::cout << std::endl;

    // Return successful
    return 0;
}

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

    //sql = "CREATE TABLE USERINFO (" \"USERID INTEGER PRIMARY KEY AUTOINCREMENT," \"USERNAME TEXT NOT NULL," \"PASSWORD TEXT NOT NULL," \"USERFIRSTNAME TEXT NOT NULL, " \"CLANTYPE TEXT NOT NULL, " \"CLANNAME TEXT NOT NULL, " \"NUM_GLADIATORS INTEGER);";

    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

    sql = "INSERT INTO PlayerGladiators ('gladiatorID', 'playerID', 'firstName', 'surname' , 'nickname', 'hp', 'hunger', 'thirst', 'strength', 'defence', 'agility', 'dexterity') VALUES (NULL, '" + std::to_string(gladiatorObj.getPlayerID()) + "', '" + gladiatorObj.getName("firstname") + "' ,'" + gladiatorObj.getName("surname") + "', '" + gladiatorObj.nickname + "', '" + std::to_string(gladiatorObj.getHealth()) + "', '" + std::to_string(gladiatorObj.getHunger()) + "', '" + std::to_string(gladiatorObj.getThrist()) + "', '" + std::to_string(gladiatorObj.strength) + "', '" + std::to_string(gladiatorObj.defence) + "', '" + std::to_string(gladiatorObj.agility) + "', '" + std::to_string(gladiatorObj.dexterity) + "', NULL);";

    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    sqlite3_close(db);
    return;
}

Gladiator createGladiator(int playerID, bool isNPC) {

	if (isNPC == true) {
		Gladiator newNPC;

		return newNPC;
	}

	PlayerGladiator newGladiatior(playerID);



}