#pragma once

#include <iostream>
#include <string>
#include <typeinfo>

#include "GameClasses.h"
#include "sqlite3.h"
#include "Introduction.h"

std::string typeOfClan;
int plrID;

int printWeaponStats(void* NotUsed, int argc, char** argv, char** azColName) {

    for (int i = 0; i < argc; i++) {


        if (i % 4 != 0) {
            continue;
        }

        std::cout << "Quality         : " << argv[i] << " | ";
        std::cout << "Damage          : " << argv[i + 1] << " | ";
        std::cout << "Attack Speed    : " << argv[i + 2] << " | ";
        std::cout << "Crit/Block Chance    : " << argv[i + 3] << std::endl;

        std::cout << std::endl;

    }

    // Return successful
    return 0;
}

void showWeaponStats(std::string weaponName) {

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

    if (typeOfClan == "Attack") {
        sql = "SELECT quality, damage, attack_speed, critical_chance FROM Attack WHERE weapon_name = '" + weaponName + "';";
    }
    else if (typeOfClan == "Defence") {
        sql = "SELECT quality, damage, attack_speed, block_chance FROM Defence WHERE weapon_name = '" + weaponName + "';";
    }


    rc = sqlite3_exec(db, sql.c_str(), printWeaponStats, 0, &zErrMsg);

    sqlite3_close(db);
    return;
}


//int selNum;
int printInventory(void* NotUsed, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {


        if (i % 4 != 0) {
            continue;
        }

        if (argv[i] == NULL) { std::cout << "[EMPTY INVENTORY]" << std::endl; return 0; }

        std::cout << "[" << i + 1<< "] " << argv[i] << std::endl;
        showWeaponStats(std::string(argv[i]));

        if (argv[i + 1] == NULL) {return 0;}

        std::cout << "[" << i + 2 << "] " << argv[i + 1] << std::endl;
        showWeaponStats(std::string(argv[i+1]));

        if (argv[i + 2] == NULL) { return 0; }

        std::cout << "[" << i + 3 << "] " << argv[i + 2] << std::endl;
        showWeaponStats(std::string(argv[i+2]));

        if (argv[i + 3] == NULL) { return 0; }

        std::cout << "[" << i + 4 << "] " << argv[i + 3] << std::endl;
        showWeaponStats(std::string(argv[i+3]));

        std::cout << std::endl;

    }

    // Return successful
    return 0;
}

void showInventory(int playerID, int selectedNum, std::string clanType) {

    typeOfClan = clanType;

    plrID = playerID;

    selNum = selectedNum;

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

    sql = "SELECT INVENTORYONE, INVENTORYTWO, INVENTORYTHREE, INVENTORYFOUR FROM INVENTORY WHERE PLAYERID =" + std::to_string(playerID) + ";";

    rc = sqlite3_exec(db, sql.c_str(), printInventory, 0, &zErrMsg);

    sqlite3_close(db);
    return;
}