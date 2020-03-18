#pragma once
#include <sstream>
#include <fstream>
#include <limits>
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <functional>
//https://en.cppreference.com/w/cpp/string/basic_string/hash

//Beginning of code by [Annija Balode 9102828]
template <typename T>
T getInput(const std::string& strQuery);

std::string getDesiredUsername();
std::string getDesiredPassword();
std::string getNewUsername();
std::string getNewPassword();

void saveUser(const std::string& username, const std::string& password);

int registerUser();
int mainMenu();
int loginUser();


template <typename T>
T getInput(const std::string& strQuery)
{
    std::cout << strQuery << "\n> ";
    T out = T();

    while (!(std::cin >> out)) {
        std::cin.clear();
        //std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
        std::cout << "Error!" "\n";
        std::cout << strQuery << "\n> ";
    }

    return out;
}


std::string getDesiredPassword()
{
    std::string password1 = getInput <std::string>("Please enter your desired password.");
    std::size_t hashPass = std::hash<std::string>{}(password1);
    std::string hashPass1 = std::to_string(hashPass);
    std::string password2 = getInput <std::string>("Please re-enter your desired password.");

    while (password1 != password2) {
        std::cout << "Error! Passwords do not match." "\n";
        password1 = getInput <std::string>("Please enter your desired password.");
        std::size_t hashPass = std::hash<std::string>{}(password1);
        std::string hashPass1 = std::to_string(hashPass);
        password2 = getInput <std::string>("Please re-enter your desired password.");
    }
    return hashPass1;
}

std::string getDesiredUsername()
{
    std::string username = getInput <std::string>("\nPlease enter your desired username:");
    std::cout << "Username: \"" << username << "\"\n";

    while (getInput <int>("\n Confirm? [0 (NO) | 1 (YES)]") != 1) {
        username = getInput <std::string>("Please enter your desired username:");
        std::cout << "Username: \"" << username << "\"\n";
    }

    return username;
}

std::string getNewPassword()
{
    std::string password1 = getInput <std::string>("Please enter your password.");
    std::size_t hashPass = std::hash<std::string>{}(password1);
    std::string hashPass1 = std::to_string(hashPass);
    std::string password2 = getInput <std::string>("Please re-enter your password.");

    while (password1 != password2) {
        std::cout << "Error! Passwords do not match." "\n";
        password1 = getInput <std::string>("Please enter your password.");
        std::size_t hashPass = std::hash<std::string>{}(password1);
        std::string hashPass1 = std::to_string(hashPass);
        password2 = getInput <std::string>("Please re-enter your password.");
    }

    return hashPass1;
}


std::string getNewUsername()
{
    std::string username = getInput <std::string>("\nPlease enter your username:");
    std::cout << "Username: \"" << username << "\"\n";

    while (getInput <int>("\n Confirm? [0 (NO) | 1 (YES)]") != 1) {
        username = getInput <std::string>("Please enter your username:");
        std::cout << "Username: \"" << username << "\"\n";
    }

    return username;
}

int mainMenu()
{
    int userid;

    system("color 0F");
    std::cout << "The Gladiator" << std::endl;
    std::cout << std::setfill('+') << std::setw(120) << "+";
    int choice = getInput <int>(
        "Welcome to The Gladiator!\n\nFirst of all, would you like to Login or Register, Chief?" "\n"
        "[1] Login" "\n"
        "[2] Register");

    switch (choice)
    {
    case 1:
        //login();
        userid = loginUser();
        std::cout << "Press any key to continue.." << std::endl;
        return userid;
        //_getch();
        break;
    case 2:
        registerUser();
        return 0;
        break;
    }

}

void singularWordOutput(const std::string& text)
{
    // loop through each character in the text
    for (std::size_t i = 0; i < text.size(); ++i)
    {
        // output one character
        // flush to make sure the output is not delayed
        std::cout << text[i] << std::flush;

        // sleep 30 milliseconds
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
    }
}

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


int setUp()
{
    system("CLS");
    //#########################################################################
    //Beginning of code by [Annija Balode 9102828]
    // This will take the name that the player would like to go by and save it in the player variable
    std::string usersName = getInput <std::string>("Let's get you registered! First things first though, what is your name, Chief?\n");
    usersName[0] = toupper(usersName[0]);

    singularWordOutput(usersName + "! Emperor Macrinus is setting up new camps for Gladiators to train in!\n");
    singularWordOutput("It says on this rock here that he has now put you in charge of this camp,\nyour first order is to give it a name...\n");
    std::string nameOfClan = getInput <std::string>("\nWhat would you like to name your clan, Chief " + usersName + "?\n");
    nameOfClan[0] = toupper(nameOfClan[0]);
    singularWordOutput("\nAs the official Chief of " + nameOfClan + " you must decide whether you will be Attack or Defence.\n");
    std::string typeOfClan = getInput <std::string>("\nWhich one will it be?\n");

    while (true)
    {
        
        std::string type_string = typeOfClan;
        int length = type_string.length();

        for (int i = 0; i < length; i++)
        {
            int upperCase = type_string[i];
            type_string[i] = toupper(upperCase);
        }

        if (type_string == "ATTACK")
        {
            std::cout << "\nGood, strong choice, all nations need muscle!" << std::endl;
            break;
        }

        if (type_string == "DEFENCE")
        {
            std::cout << "\nAll nations need defending!" << std::endl;
            break;
        }

        else
        {
            std::cout << "Try again!" << std::endl;
            std::string typeOfClan = getInput <std::string>("\nWhich one will it be?\n");
            continue;
        }
    }

    std::string username = getDesiredUsername();
    std::string password = getDesiredPassword();
    system("CLS");

    singularWordOutput("Before you can begin training your clan, Chief " + usersName + ", you must first be informed on what is expected of you.");
    singularWordOutput("\nWhen you begin, you will have 7 days to prepare your gladiators for your next fight.\nDuring this preparation time, you must ensure that your thirst and hunger levels are kept up, \nyou don't want your clan to die of starvation or dehydration!");
    singularWordOutput("\nYou will be given 500 pieces of gold to begin your training.");
    singularWordOutput("\nDon't waste any time Chief! Emperor Macrinus is relying on you to bring victory to our nation!");

    std::cout << "\n\nPress any key to begin your journey...";
    _getch();
    //saveUser(username, password);

    sqlite3* db;
    char* zErrMsg = 0;
    int rc;
    std::string sql;
    rc = sqlite3_open("GladiatorDatabase.db", &db);
    if (rc)
    {
        std::cout << "Database error: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return (1);
    }

    //sql = "CREATE TABLE USERINFO (" \"USERID INTEGER PRIMARY KEY AUTOINCREMENT," \"USERNAME TEXT NOT NULL," \"PASSWORD TEXT NOT NULL," \"USERFIRSTNAME TEXT NOT NULL, " \"CLANTYPE TEXT NOT NULL, " \"CLANNAME TEXT NOT NULL, " \"NUM_GLADIATORS INTEGER);";

    sql = "CREATE TABLE INVENTORY (" \
        "INVENTORYONE TEXT," \
        "INVENTORYTWO TEXT," \
        "INVENTORYTHREE TEXT," \
        "INTENTORYFOUR TEXT);";

    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

    sql = "INSERT INTO USERINFO ('USERID', 'USERNAME', 'PASSWORD', 'USERFIRSTNAME' , 'CLANTYPE', 'CLANNAME', 'NUM_GLADIATORS') VALUES (NULL, '" + username + "', '" + password + "' ,'" + usersName + "', '" + typeOfClan + "', '" + nameOfClan + "', NULL);";

    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    sqlite3_close(db);
    return (0);

}


int registerUser()
{
    setUp();
    return(0);
}

void saveUser(const std::string& username, const std::string& password)
{
    std::string filename = username + ".txt";
    std::ofstream file(filename);
    file << password << "\n";
}

int userGlobal;
int callbackSingleData(void* NotUsed, int argc, char** argv, char** azColName) {

    std::string s = argv[0];
    int g = std::stoi(s);

    userGlobal = g;
    return 0;
}

int collectUserID(std::string username){

    sqlite3* db;
    char* zErrMsg = 0;
    int rc;
    std::string sql;
    rc = sqlite3_open("GladiatorDatabase.db", &db);

    sql = "SELECT USERID FROM USERINFO WHERE USERNAME ='" + username + "'";

    rc = sqlite3_exec(db, sql.c_str(), callbackSingleData, 0, &zErrMsg);

    return userGlobal;
}


int loginUser()
{
   std::string username = getNewUsername();
   std::string password = getNewPassword();

   int userID = collectUserID(username);

    sqlite3* db;
    char* zErrMsg = 0;
    int rc;
    std::string sql;
    rc = sqlite3_open("GladiatorDatabase.db", &db);
    if (rc)
    {
        std::cout << "Database error: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return (1);
    }

    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

    sql = "SELECT PASSWORD FROM USERINFO WHERE PASSWORD ='" + password + "' AND USERNAME ='" + username + "'";

    //Need to create a catch for if the data is not present in the database.
    std::string pass = "SELECT PASSWORD FROM USERINFO WHERE PASSWORD ='" + password + "' AND USERNAME ='" + username + "'";

    if (zErrMsg)
    {
        std::cerr << "Error opening Gladiator Database: " << sqlite3_errmsg(db) << std::endl;
        return (-1);
    }

    //rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    std::string usersPass = sql;

    if (usersPass == pass)
    {
        std::cout << "Successfully logged in!" << std::endl;
    }
    else
    {
        std::cout << "You need to create an account" << std::endl;
    }
    sqlite3_close(db);
    //return (0);
    return userID;
}

//https://codereview.stackexchange.com/questions/124194/user-registration-and-login-program

//End of code by [Annija Balode 9102828]



