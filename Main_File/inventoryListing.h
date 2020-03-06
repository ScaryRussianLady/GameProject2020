#pragma once

#include <iostream>
#include <string>
#include <typeinfo>

#include "GameClasses.h"
#include "sqlite3.h"
#include "Introduction.h"

int inventoryCounter = 0;
//int selNum;
int printInventory(void* NotUsed, int argc, char** argv, char** azColName) {
    std::cout << "Test" << std::endl;
    for (int i = 0; i < argc; i++) {

        std::cout << "Test2" << std::endl;

        //if (i % 4 != 0) {
        //    continue;
        //}

        inventoryCounter++;

        //if (selNum != 0) {
        //    if (inventoryCounter != selNum) {
        //        continue;
        //    }
        //}

        std::cout << "[" << inventoryCounter << "] " << argv[i] << std::endl;

        std::cout << std::endl;

    }

    // Return successful
    return 0;
}

void showInventory(int playerID, int selectedNum) {

    selNum = selectedNum;

    inventoryCounter = 0;

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
