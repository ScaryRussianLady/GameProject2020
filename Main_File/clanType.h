#pragma once

#include <iostream>
#include <string>
#include <typeinfo>

#include "GameClasses.h"
#include "createGladiator.h"
#include "sqlite3.h"
#include "Introduction.h"

std::string clanOfType;

int getClan(void* NotUsed, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {

        //std::cout << "HELLO" << argv[i] << std::endl;
        clanOfType = std::string(argv[i]);

    }

    return 0;
}

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

    sql = "SELECT CLANTYPE FROM USERINFO WHERE USERID =" + std::to_string(playerID) + ";";

    rc = sqlite3_exec(db, sql.c_str(), getClan, 0, &zErrMsg);


    sqlite3_close(db);

    Data = clanOfType;

    return Data;
}