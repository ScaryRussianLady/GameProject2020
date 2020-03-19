#pragma once
#include <sstream>
#include <fstream>
#include <limits>
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <functional>
//research from: https://en.cppreference.com/w/cpp/string/basic_string/hash

//Beginning of code by [Annija Balode 9102828] and referenced from https://codereview.stackexchange.com/questions/124194/user-registration-and-login-program.
template <typename T>
T getInput(const std::string& strQuery);

std::string getDesiredUsername();
std::string getDesiredPassword();
std::string getLoginUsername();
std::string getLoginPassword();

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


//The following function retrieves the desired password by the user when creating an account for the game.
std::string getDesiredPassword()
{
    //The password gets checked twice to ensure that they are entering the details correctly.
    std::string password1 = getInput <std::string>("Please enter your desired password.");
    //This gets hashed which can be pushed to the database. Avoids anybody knowing the password when accessing the database.
    std::size_t hashPass = std::hash<std::string>{}(password1);
    std::string hashPass1 = std::to_string(hashPass);
    std::string password2 = getInput <std::string>("Please re-enter your desired password.");

    //If the passwords do not match, the user enters a while loop till they have matching passwords.
    while (password1 != password2) {
        std::cout << "Error! Passwords do not match." "\n";
        password1 = getInput <std::string>("Please enter your desired password.");
        std::size_t hashPass = std::hash<std::string>{}(password1);
        std::string hashPass1 = std::to_string(hashPass);
        password2 = getInput <std::string>("Please re-enter your desired password.");
    }
    return hashPass1;
}

//This functions retrieves the desired username for the user when creating an account for the game.
std::string getDesiredUsername()
{
    std::string username = getInput <std::string>("\nPlease enter your desired username:");
    std::cout << "Username: \"" << username << "\"\n";

    //Ensure that the user is able to choose a different username if they change their mind last name.
    //This is a confirmation stage.
    while (getInput <int>("\n Confirm? [0 (NO) | 1 (YES)]") != 1) {
        username = getInput <std::string>("Please enter your desired username:");
        std::cout << "Username: \"" << username << "\"\n";
    }

    return username;
}

//The same function as previously seen when retrieving a password, just with slightly different wording for logging in instead of registering.
std::string getLoginPassword()
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

//Same function as seen previously for retrieving the username, just different wording for logging in instead of registering.
std::string getLoginUsername()
{
    std::string username = getInput <std::string>("\nPlease enter your username:");
    std::cout << "Username: \"" << username << "\"\n";

    while (getInput <int>("\n Confirm? [0 (NO) | 1 (YES)]") != 1) {
        username = getInput <std::string>("Please enter your username:");
        std::cout << "Username: \"" << username << "\"\n";
    }

    return username;
}

//A function to display the main menu which gives the user two options: login or register depending on whether they have played before or not.
int mainMenu()
{
    int userIdentity;

    system("color 0F");
    //Gives the title of the game and fills the spaces with a symbol for a more aesthetic look.
    std::cout << "The Gladiator" << std::endl;
    std::cout << std::setfill('+') << std::setw(120) << "+";
    int usersChoice = getInput <int>(
        "Welcome to The Gladiator!\n\nFirst of all, would you like to Login or Register, Chief?" "\n"
        "[1] Login" "\n"
        "[2] Register");


    //A switch case depending on which number the user inputs, this will run the certain function necessary.
    switch (usersChoice)
    {
    case 1:
        //login();
        userIdentity = loginUser();
        return userIdentity;
        _getch();
        break;
    case 2:
        registerUser();
        return 0;
        break;
    }

}


//A function for outputting letter by letter no matter what the string of text is.
void singularWordOutput(const std::string& text)
{
    //The following loops through each character in the text.
    for (std::size_t i = 0; i < text.size(); ++i)
    {
        //Outputs one character at a time and flushes to ensure there is no delay.
        std::cout << text[i] << std::flush;

        //Sleeps for 30 milliseconds to visually show that the characters are being displayed one at a time.
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
    }
}

//The following functions holds the number of results, holds each column that is returned and the value.
int callback(void* NotUsed, int argc, char** argv, char** azColName) 
{
    for (int i = 0; i < argc; i++) 
    {
        //Shows the column name and value.
        std::cout << azColName[i] << ": " << argv[i] << std::endl;

    }

    //Inserst a new line for every new data piece.
    std::cout << std::endl;
   
    return(0);
}

//A function that sets the user up if it is their first time playing the game (registering).
int setUp()
{
    system("CLS");
   
    //Following lines of code gather important information about the user, their name, what name they want for their clan and the type they wish to be.
    std::string usersName = getInput <std::string>("Let's get you registered! First things first though, what is your name, Chief?\n");
    usersName[0] = toupper(usersName[0]);
    singularWordOutput(usersName + "! Emperor Macrinus is setting up new camps for Gladiators to train in!\n");
    singularWordOutput("It says on this rock here that he has now put you in charge of this camp,\nyour first order is to give it a name...\n");
    std::string nameOfClan = getInput <std::string>("\nWhat would you like to name your clan, Chief " + usersName + "?\n");
    nameOfClan[0] = toupper(nameOfClan[0]);
    singularWordOutput("\nAs the official Chief of " + nameOfClan + " you must decide whether you will be Attack or Defence.\n");
    std::string typeOfClan = getInput <std::string>("\nWhich one will it be?\n");

    //A while loop to ensure that the user only chooses attack or defence, giving the appropriate response depending on which one they have chosen.
    while (true)
    {
        
        std::string type_string = typeOfClan;
        int length = type_string.length();

        //Changes each character of the text to uppercase for more efficient checking.
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

    //Gathers the username and password from the user by branching off to the appropriate functions.
    std::string username = getDesiredUsername();
    std::string password = getDesiredPassword();
    system("CLS");

    //Simple breakdown of the game and how things will work when they begin.
    singularWordOutput("Before you can begin training your clan, Chief " + usersName + ", you must first be informed on what is expected of you.");
    singularWordOutput("\nWhen you begin, you will have 7 days to prepare your gladiators for your next fight.\nDuring this preparation time, you must ensure that your thirst and hunger levels are kept up, \nyou don't want your clan to die of starvation or dehydration!");
    singularWordOutput("\nYou will be given 500 pieces of gold to begin your training.");
    singularWordOutput("\nDon't waste any time Chief! Emperor Macrinus is relying on you to bring victory to our nation!");

    std::cout << "\n\nPress any key to begin your journey...";
    _getch();
    //saveUser(username, password);


    //The following opens the database and ensures that there are no errors, if there are any, these are printed out.
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
    
    //Simply creates the table that is required for the user info, this has been commented out as it does not need creating every time the program is ran. But this is how it was created.
    //sql = "CREATE TABLE USERINFO (" \"USERID INTEGER PRIMARY KEY AUTOINCREMENT," \"USERNAME TEXT NOT NULL," \"PASSWORD TEXT NOT NULL," \"USERFIRSTNAME TEXT NOT NULL, " \"CLANTYPE TEXT NOT NULL, " \"CLANNAME TEXT NOT NULL, " \"NUM_GLADIATORS INTEGER);";

    //The same concept, however, it is a table for the inventory the user is holding.
    //sql = "CREATE TABLE INVENTORY (" \
        "INVENTORYONE TEXT," \
        "INVENTORYTWO TEXT," \
        "INVENTORYTHREE TEXT," \
        "INTENTORYFOUR TEXT);";

    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

    //Everything that the user has provided to the game gets inserted into the database so this way the user can login and retrieve all their information.
    sql = "INSERT INTO USERINFO ('USERID', 'USERNAME', 'PASSWORD', 'USERFIRSTNAME' , 'CLANTYPE', 'CLANNAME', 'NUM_GLADIATORS') VALUES (NULL, '" + username + "', '" + password + "' ,'" + usersName + "', '" + typeOfClan + "', '" + nameOfClan + "', NULL);";

    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    sqlite3_close(db);
    return (0);

}


//Function for registering the user, takes them to the setUp() function.
int registerUser()
{
    setUp();
    return(0);
}

//This function was originally used to save the users details as a text file for testing to ensure everything was being saved correctly.
//After this, it was moved to database with SQL.
/*void saveUser(const std::string& username, const std::string& password)
{
    std::string filename = username + ".txt";
    std::ofstream file(filename);
    file << password << "\n";
}*/

int userGlobal;


int callbackSingleData(void* NotUsed, int argc, char** argv, char** azColName) {

    std::string s = argv[0];
    int g = std::stoi(s);
    userGlobal = g;
    return 0;
}


//A function for retreiving the user ID according to the username for use in the other classes.
int collectUserID(std::string username){

    sqlite3* db;
    char* zErrMsg = 0;
    int rc;
    std::string sql;
    
    //Opens the database and selects the user ID depending on what username has been provided.
    rc = sqlite3_open("GladiatorDatabase.db", &db);

    sql = "SELECT USERID FROM USERINFO WHERE USERNAME ='" + username + "'";

    rc = sqlite3_exec(db, sql.c_str(), callbackSingleData, 0, &zErrMsg);

    return userGlobal;
}

//A function for logging in the user, retrieving their username and password then checking against the database.
int loginUser()
{
    std::string username = getLoginUsername();
    std::string password = getLoginPassword();

    int userID = collectUserID(username);

    sqlite3* db;
    char* zErrMsg = 0;
    int rc;
    std::string sql;

    //Once again, opens the database and throws an error if there are any problems.
    rc = sqlite3_open("GladiatorDatabase.db", &db);
    if (rc)
    {
        std::cout << "Database error: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return (1);
        _getch();
    }

    //Prints the output of the SQL statement.
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

    //Selects the appropriate password and username from the database, however the password being retreived is the hashed version.
    //sql = "SELECT PASSWORD, USERNAME FROM USERINFO WHERE EXISTS(SELECT * FROM USERINFO WHERE PASSWORD ='" + password + "' AND USERNAME ='" + username + "')";
    sql = "SELECT USERNAME, PASSWORD FROM USERINFO WHERE PASSWORD = '" + password + "'";

    //Need to create a catch for if the data is not present in the database.
    //std::string pass = "SELECT PASSWORD FROM USERINFO WHERE PASSWORD ='" + password + "' AND USERNAME ='" + username + "'";

    if (zErrMsg)
    {
        std::cerr << "Error opening Gladiator Database: " << sqlite3_errmsg(db) << std::endl;
        return (-1);
    }

    //rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    //std::string usersPass = sql;
    //std::cout << usersPass + "\n" + password << std::endl;
    //std::cout << sql << std::endl;
    int num = rc;
    //std::cout << num << std::endl;
    //std::string idk = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);


    //Checks the return value of the password and username, then provides the user with whether they need to create an account or can log in.
    if (num = 0)
    {
        std::cout << "You need to create an account" << std::endl;
        registerUser();
    }

    if (num = 1)
    {
        std::cout << "Successfully logged in!" << std::endl;
        _getch();
    }
    sqlite3_close(db);
    //return (0);
    _getch();
    return userID;
}

//End of code by [Annija Balode 9102828] and referenced from https://codereview.stackexchange.com/questions/124194/user-registration-and-login-program.