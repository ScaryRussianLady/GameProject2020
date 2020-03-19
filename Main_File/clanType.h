#pragma once

#include <iostream>
#include <string>
#include <typeinfo>

#include "GameClasses.h"
#include "createGladiator.h"
#include "sqlite3.h"
#include "Introduction.h"

// [START OF CODE BY: CHRISTIAN]

std::string clanOfType;

// This callback function returns the clanType from the database of the player
int getClan(void* NotUsed, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {

        // This stores the clanType into the variable TypeOfClan
        clanOfType = std::string(argv[i]);

    }

    return 0;
}

// This function opens the database and allows SQL to be input into the database through C++
std::string getClanType(int playerID) {

    std::string Data;

    sqlite3* db;
    char* zErrMsg = 0;
    int rc;
    std::string sql;
    rc = sqlite3_open("GladiatorDatabase.db", &db);

    if (rc)
    {
        std::cout << "Database error: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        //return;
    }
    
    // This SQL here creates a query to search for the user's clantype depending on their playerID which is input into thise function
    sql = "SELECT CLANTYPE FROM USERINFO WHERE USERID =" + std::to_string(playerID) + ";";

    rc = sqlite3_exec(db, sql.c_str(), getClan, 0, &zErrMsg);


    sqlite3_close(db);

    Data = clanOfType;

    // The type of clan is then returned
    return Data;
}

// [END OF CODE BY: CHRISTIAN]