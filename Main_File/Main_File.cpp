//Main_File.cpp : This file contains the 'main' function. Program execution begins and ends there.
//If you want to run the file just press Ctrl + F5. Debugging can be found in the tabs above.

//IMPORTANT NOTICE: This is a link to how to install vcpkg, if you are unable to follow it, drop me a message (Annija) https://www.youtube.com/watch?v=wRnjahwxZ8A.

#include "timeTillFight.h"
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
#include <cctype>
#include "GameClasses.h"
#include <sstream>
#include <fstream>
#include <limits>
#include "Indicators.h"


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



template <typename T>
T get_input(const std::string& strQuery);

std::string get_username();
std::string get_password();
void save_user(const std::string& username, const std::string& password);

void login();
void register_user();
void main_menu();

void centerstring(char* s)
{
    int l = strlen(s);
    int pos = (int)((80 - l) / 2);
    for (int i = 0; i < pos; i++)
        std::cout << " " << std::endl;
    std::cout << s << std::endl;
}

//#########################################################################
//Beginning of code by [Annija Balode 9102828].
int main()
{   
    output();
    main_menu();
    system("CLS");
    system("color 8F");//changes colour of terminal and text.

    /*char nameOfClan[25];
    char userName[25];
    std::cout << "The Gladiator" << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;
    singularWordOutput("Welcome to The Gladiator.\nWhat is your name, Chief?\n");


    //std::cout << "Welcome to The Gladiator.\nWhat is your name, Chief?" << std::endl;
    std::cin.getline(userName, 25);*/
    //std::string users_name = userName;
    //*********
    //std::string users_name = test.getName;




    /*singularWordOutput(std::string(userName) + "! Emperor Macrinus is setting up new camps for Gladiators to train in!\n");
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
    }*/
    
    //std::string type_clan = typeOfClan;
    //*********
    //std::string type_clan = test.getClanType;
 
    //#########################################################################
    //Beginning of code by [Gerald] with help from [Annija Balode 9102828].
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
    //End of code by [Gerald] with help from [Annija Balode 9102828].
    //#########################################################################

    //Annija Balode
    //std::string clan_name = nameOfClan;
    //*********
    //std::string clan_name = test.getClanName();

    Player test(1);

    test.getName();
    std::cout << test.getName() << std::endl;

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

   //sql = "CREATE TABLE USERINFO (" \"USERID INTEGER PRIMARY KEY AUTOINCREMENT," \"USERNAME TEXT NOT NULL, " \"CLANTYPE TEXT NOT NULL, " \"CLANNAME TEXT NOT NULL, " \"NUM_GLADIATORS INTEGER);";

    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

    //sql = "INSERT INTO USERINFO ('USERID', 'USERNAME', 'CLANTYPE', 'CLANNAME', 'NUM_GLADIATORS') VALUES (NULL, '" + users_name + "', '" + type_clan + "', '" + clan_name + "', NULL);";

    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    sqlite3_close(db);


       /* std::cout << "\n-----------------------------------------------------------------------------------------------------" << std::endl;
        singularWordOutput("\nBefore you can begin training your clan, Chief " + std::string(userName) + ", you must first be informed on what is expected of you.");
        singularWordOutput("\nWhen you begin, you will have 7 days to prepare your gladiators for your next fight.\nDuring this preparation time, you must ensure that your thirst and hunger levels are kept up, \nyou don't want your clan to die of starvation or dehydration!");
        singularWordOutput("\nYou will be given 500 pieces of gold to begin your training.");
        singularWordOutput("\nDon't waste any time Chief! Emperor Macrinus is relying on you to bring victory to our nation!");*/

        //This gives time for the user to read everything they want and begin when they want to.
        std::cout << "\n\nPress any key to begin your journey...";
        _getch();

        system("CLS");//is used to clear the text on the terminal. conio's clrscn() did not work

        return (0);
}

template <typename T>
T get_input(const std::string& strQuery)
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

std::string get_password()
{
    std::string password1 = get_input <std::string>("Please enter your password.");
    std::string password2 = get_input <std::string>("Please re-enter your password.");

    while (password1 != password2) {
        std::cout << "Error! Passwords do not match." "\n";
        password1 = get_input <std::string>("Please enter your password.");
        password2 = get_input <std::string>("Please re-enter your password.");
    }

    return password1;
}

std::string get_username()
{
    std::string username = get_input <std::string>("Please enter your username:");
    std::cout << "Username: \"" << username << "\"\n";

    while (get_input <int>("Confirm? [0 (NO) | 1 (YES)]") != 1) {
        username = get_input <std::string>("Please enter your username:");
        std::cout << "Username: \"" << username << "\"\n";
    }

    return username;
}



void main_menu()
{
    system("color 0F");
    int choice = get_input <int>(
        "Welcome to The Gladiator!\nFirst of all, would you like to Login or Register Chief?" "\n"
        "[1] Login" "\n"
        "[2] Register");

    switch (choice)
    {
    case 1:
        login();
        break;
    case 2:
        register_user();
        break;
    }

}

void register_user()
{
    std::string username = get_username();
    std::string password = get_password();
    save_user(username, password);
}

void save_user(const std::string& username, const std::string& password)
{
    std::string filename = username + ".txt";
    std::ofstream file(filename);
    file << password << "\n";
}

std::string temp;

void login()
{
    std::string username = get_username();
    std::string password = get_password();
    std::cout << "You are being logged in!\n" << std::endl;
}

//https://codereview.stackexchange.com/questions/124194/user-registration-and-login-program

/*std::string save_data()
{
    //attempt
    std::cout << "saving game progress...please finalise details" << std::endl;
    std::string clan_name2;
    std::cout << "Enter Clan name?" << std::endl;
    std::cin >> clan_name2;

    std:: string typeOfClan2;
    std::cout << "Choose Attack or Defence";
    std::cin >> typeOfClan2;

    std::ofstream file_("PlayerData.txt");

    if(file_.is_open()){

    file_<< clan_name2;
    file_<< typeOfClan2;
    }
    std::cin.get();
    return 0;
}

std::string load_data()
{
    std::ifstream file_("PlayerData.txt");
    std::string clan_name = test.getClanName;
    std::string type_clan = test.getClanType;

    if (file_.is_open())
    {

        while(file_>> nameOfClan >>typeOfClan)
            {
                std::cout << " Current saved progress: ";
                std::cout<<nameOfClan<<" " typeOfClan<<'\n';
            }
        file_.close();
    }

    else
    {
        std::cout<<"file is not open"<< '\n';
        std::cin.get();
        return 0;
    }

}
*/

