#pragma once

#include <iostream>
#include <string>
#include <typeinfo>

#include "GameClasses.h"
#include "createGladiator.h"
#include "sqlite3.h"
#include "Introduction.h"

int gladiatorCounter = 1;
int printGladiators(void* NotUsed, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {

        if (i % 2 == 1) {
            continue;
        }
        
        std::cout << "[" << gladiatorCounter << "] " << argv[i] << " " << argv[i+1] << std::endl;
        
        gladiatorCounter++;
    }

    // Insert a newline
    std::cout << std::endl;

    // Return successful
    return 0;
}

void showGladiators(int playerID) {
    gladiatorCounter = 1;

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
        return;
    }

    sql = "SELECT firstName AS 'First Name', surname AS 'Last Name' FROM PlayerGladiators WHERE playerID ="+ std::to_string(playerID) + ";";

    rc = sqlite3_exec(db, sql.c_str(), printGladiators, 0, &zErrMsg);


    sqlite3_close(db);
    return;
}


