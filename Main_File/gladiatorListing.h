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

        if (selNum != 0) {
            if (gladiatorCounter != selNum) {
                continue;
            }
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

struct gladiatorData {
    int gladId;
    int plrId;

    std::string fn;
    std::string ln;
    std::string nn;

    int hp;
    int hng;
    int thr;

    int stg;
    int def;
    int agi;
    int dex;
};

int gladiatorCounter2 = 0;
int selNum2;
gladiatorData gladStruct;

int getGladData(void* NotUsed, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {

        if (i % 12 != 0) {
            continue;
        }

        gladiatorCounter2++;

        if (selNum2 != 0) {
            if (gladiatorCounter2 != selNum2) {
                continue;
            }
        }

        //gladiatorData gladStruct;

        gladStruct.gladId = std::stoi(argv[i]);

        gladStruct.plrId = std::stoi(argv[i + 1]);

        gladStruct.fn = std::string(argv[i + 2]);
        gladStruct.ln = std::string(argv[i + 3]);
        gladStruct.nn = std::string(argv[i + 4]);

        gladStruct.hp = std::stoi(argv[i + 5]);
        gladStruct.hng = std::stoi(argv[i + 6]);
        gladStruct.thr = std::stoi(argv[i + 7]);

        gladStruct.stg = std::stoi(argv[i + 8]);
        gladStruct.def = std::stoi(argv[i + 9]);
        gladStruct.agi = std::stoi(argv[i + 10]);
        gladStruct.dex = std::stoi(argv[i + 11]);

        //std::cout << "I ahte this" << typeid(gladStruct.gladId).name() << std::endl;

        //std::cout << gladStruct.plrId << std::endl;

        break;
    }

    // Return successful
    return 0;
}


gladiatorData importGladiatorData(int playerID, int selectedNum) {
   
    selNum2 = selectedNum;
 
    gladiatorCounter2 = 0;

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

    sql = "SELECT gladiatorID, playerID, firstName, surname, nickname, hp, hunger, thirst, strength, defence, agility, dexterity FROM PlayerGladiators WHERE playerID =" + std::to_string(playerID) + ";";

    rc = sqlite3_exec(db, sql.c_str(), getGladData, 0, &zErrMsg);


    sqlite3_close(db);

    //std::cout << "fuck off " << gladStruct.gladId << std::endl;

    return gladStruct;
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


