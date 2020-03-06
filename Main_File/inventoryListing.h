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
    for (int i = 0; i < argc; i++) {


        if (i % 4 != 0) {
            continue;
        }

        std::cout << "[" << i + 1 << "] " << argv[i] << std::endl;
        std::cout << "[" << i + 2 << "] " << argv[i + 1] << std::endl;
        std::cout << "[" << i + 3 << "] " << argv[i + 2] << std::endl;
        std::cout << "[" << i + 4 << "] " << argv[i + 3] << std::endl;

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
