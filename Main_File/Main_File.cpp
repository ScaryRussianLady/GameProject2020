//Main_File.cpp : This file contains the 'main' function. Program execution begins and ends there.
//If you want to run the file just press Ctrl + F5. Debugging can be found in the tabs above.

#include "timeTillFight.h"
#include "ClanFood.h"
#include <windows.h>
#include <iostream>
//conio documentation: https://www.includehelp.com/c-tutorial/c-language-conio-h-in-c-programming-tutorial.aspx
#include <stdlib.h> //Used for getting the input from the user and output the result back to the monitor. 
//Please try to avoid using 'using namespace std;' if possible in all of your files as this is a bad habit. Avoiding this habit will be more beneficial for the future.
#include <sqlite3.h>
#include <stdio.h>
#include <thread>
#include <conio.h>
#include <locale>
#include <string>
#include <cstring>
#include "healthManagement.h"
#include <cctype>
#include "GameClasses.h"


//Please ignore this section of the code for now.
/*static int callback(void* NotUsed, int argc, char** argv, char** azColName)
{
    int i;
    for (i = 0; i < argc; i++)
    {
        std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << "\n";
    }
    std::cout << "\n";
    return 0;
}*/

//https://stackoverflow.com/questions/33882822/output-letters-one-at-a-time-in-c


//Annija Balode
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

//Annija Balode
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

//[Annija Balode 9102828] and referenced from https://www.dreamincode.net/forums/topic/228382-make-text-to-appear-letter-by-letter-in-console/
int main()
{ 
  


    //https://www.youtube.com/watch?v=wRnjahwxZ8A

    //I produced a very simple function where the player is able to give the name of their clan and which side they want to be on.
    //This should be used as a template to begin the game and give everyone a sense of how this shoud be structured.

    system("color 8F");//changes colour of terminal and text. couldn't get conio to work. use "color %" to view all available colours
    char nameOfClan[25];
    char userName[25];
    std::cout << "The Gladiator" << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;
    singularWordOutput("Welcome to The Gladiator.\nWhat is your name, Chief?\n");


    //std::cout << "Welcome to The Gladiator.\nWhat is your name, Chief?" << std::endl;
    std::cin.getline(userName, 25);
    std::string users_name = userName;




    singularWordOutput(std::string(userName) + "! Emperor Macrinus is setting up new camps for Gladiators to train in!\n");
    singularWordOutput("It says on this rock here that he has now put you in charge of this camp,\nyour first order is to give it a name...\n");
    singularWordOutput("\nWhat would you like to name your clan, Chief " + std::string(userName) + "?\n");
    std::cin.getline(nameOfClan, 25);
    singularWordOutput("\nAs the official Chief of " + std::string(nameOfClan) + " you must decide whether you will be Attack or Defence.\n");
    char typeOfClan[25];

    //Improved version of Gerald's code by Annija.
    while (true)
    {

        singularWordOutput("\nWhich one will it be?\n");
        std::cin.getline(typeOfClan, 25);
        std::string type_string = typeOfClan;
        int length = type_string.length();

        for (int i = 0; i < length; i++)
        {
            int c = type_string[i];
            type_string[i] = toupper(c);
        }

        if (type_string == "ATTACK")
        {
            std::cout << "Good, strong choice, all nations need muscle!" << std::endl;
            break;
        }

        if (type_string == "DEFENCE")
        {
            std::cout << "All nations need defending!" << std::endl;
            break;
        }
        
        else
        {
            std::cout << "Try again!" << std::endl;
            char typeOfClan[25];
            continue;
        }
    }
    
    std::string type_clan = typeOfClan;
 
  
    //fixed gerald's while statement to ensure that it can come out of the loop and print the necessary stuff.
    /*while (true)
    {
        singularWordOutput("\nWhich one will it be?\n");
        std::cin.getline(typeOfClan, 25);
        if (strcmp(typeOfClan, "attack") == 0) {
            singularWordOutput("Good, strong choice!");

            break;
        }
        else if (strcmp(typeOfClan, "Attack") == 0) {
            singularWordOutput("Good, strong choice!");

            break;
        }
        else if (strcmp(typeOfClan, "ATTACK") == 0) {
            singularWordOutput("Good, strong choice!");

            break;
        }


        if (strcmp(typeOfClan, "defence") == 0) {
            singularWordOutput("All nations need defending!");

            break;
        }
        else if (strcmp(typeOfClan, "Defence") == 0) {
            singularWordOutput("All nations need defending!");

            break;
        }
        else if (strcmp(typeOfClan, "DEFENCE") == 0) {
            singularWordOutput("All nations need defending!");

            break;
        }
        else {
            singularWordOutput("Sorry that was not an option, please try again.\n");
            char typeOfClan[25];
            continue;
        }
    }*/

    //Annija Balode
    std::string clan_name = nameOfClan;

    sqlite3* db;
    char* zErrMsg = 0;
    int rc;
    std::string sql;
    rc = sqlite3_open("GladiatorDatabase.db", &db);
    if (rc)
    {
        std::cout << "Database error: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return(1);
    }

   //sql = "CREATE TABLE USERINFO (" \
        "USERID INTEGER PRIMARY KEY AUTOINCREMENT," \
        "USERNAME TEXT NOT NULL, " \
        "CLANTYPE TEXT NOT NULL, " \
        "CLANNAME TEXT NOT NULL, " \
        "NUM_GLADIATORS INTEGER);";

    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

    sql = "INSERT INTO USERINFO ('USERID', 'USERNAME', 'CLANTYPE', 'CLANNAME', 'NUM_GLADIATORS') VALUES (NULL, '" + users_name + "', '" + type_clan + "', '" + clan_name + "', NULL);";

    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    //std::cout << rc << std::endl;
    sqlite3_close(db);


        std::cout << "\n-----------------------------------------------------------------------------------------------------" << std::endl;
        singularWordOutput("\nBefore you can begin training your clan, Chief " + std::string(userName) + ", you must first be informed on what is expected of you.");
        singularWordOutput("\nWhen you begin, you will have 7 days to prepare your gladiators for your next fight.\nDuring this preparation time, you must ensure that your thirst and hunger levels are kept up, \nyou don't want your clan to die of starvation or dehydration!");
        singularWordOutput("\nYou will be given 500 pieces of gold to begin your training.");
        singularWordOutput("\nDon't waste any time Chief! Emperor Macrinus is relying on you to bring victory to our nation!");

        //This gives time for the user to read everything they want and begin when they want to.
        std::cout << "\n\nPress any key to begin your journey...";
        _getch();

        system("CLS");//is used to clear the text on the terminal. conio's clrscn() did not work

        //timeTillFight();//called the time function for testing
    // Water & Food starting levels
        int CurrentFoodLevel = 50;
        int CurrentWaterLevel = 50;

        //std::cout << "good job jay pat on the back";
        //ClanFood(CurrentFoodLevel, CurrentWaterLevel);
        return (0);
}

