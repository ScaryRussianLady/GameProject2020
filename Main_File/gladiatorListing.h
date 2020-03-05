#pragma once

#include <iostream>
#include <string>
#include <typeinfo>

#include "GameClasses.h"
#include "createGladiator.h"
#include "sqlite3.h"
#include "Introduction.h"

int gladiatorCounter = 0;
int selNum;
int printGladiators(void* NotUsed, int argc, char** argv, char** azColName) {
    for (int i = 0 ; i < argc; i++) {

        if (i % 9 != 0) {
            continue;
        }

        gladiatorCounter++;

        if (gladiatorCounter != selNum) {
            continue;
        }

        std::cout << "[" << gladiatorCounter << "] " << argv[i] << " " << argv[i+1] << std::endl;

        std::cout << "Health : " << argv[i + 2] << "/100 | ";
        std::cout << "Hunger : " << argv[i + 3] << "/100 | ";
        std::cout << "Thirst : " << argv[i + 4] << "/100" << std::endl;

        std::cout << "Strength  : " << argv[i + 5] << " | ";
        std::cout << "Defence   : " << argv[i + 6] << " | ";
        std::cout << "Agility   : " << argv[i + 7] << " | ";
        std::cout << "Dexterity : " << argv[i + 8] << std::endl;

        std::cout << std::endl;
        
    }

    // Return successful
    return 0;
}

void showGladiators(int playerID, int selectedNum) {

    
    selNum = selectedNum;
    

    gladiatorCounter = 0;

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

    sql = "SELECT firstName, surname, hp, hunger, thirst, strength, defence, agility, dexterity FROM PlayerGladiators WHERE playerID ="+ std::to_string(playerID) + ";";

    rc = sqlite3_exec(db, sql.c_str(), printGladiators, 0, &zErrMsg);


    sqlite3_close(db);
    return;
}


