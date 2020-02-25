#pragma once
#include <sstream>
#include <fstream>
#include <limits>
#include <iostream>

template <typename T>
T get_input(const std::string& strQuery);

std::string get_username();
std::string get_password();
void save_user(const std::string& username, const std::string& password);

void login();
void register_user();
void main_menu();


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

std::string getDesiredPassword()
{
    std::string password1 = get_input <std::string>("Please enter your desired password.");
    std::string password2 = get_input <std::string>("Please re-enter your desired password.");

    while (password1 != password2) {
        std::cout << "Error! Passwords do not match." "\n";
        password1 = get_input <std::string>("Please enter your desired password.");
        password2 = get_input <std::string>("Please re-enter your desired password.");
    }

    return password1;
}

std::string getDesiredUsername()
{
    std::string username = get_input <std::string>("\nPlease enter your desired username:");
    std::cout << "Username: \"" << username << "\"\n";

    while (get_input <int>("\n Confirm? [0 (NO) | 1 (YES)]") != 1) {
        username = get_input <std::string>("Please enter your desired username:");
        std::cout << "Username: \"" << username << "\"\n";
    }

    return username;
}

std::string getNewPassword()
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

std::string getNewUsername()
{
    std::string username = get_input <std::string>("\nPlease enter your username:");
    std::cout << "Username: \"" << username << "\"\n";

    while (get_input <int>("\nConfirm? [0 (NO) | 1 (YES)]") != 1) {
        username = get_input <std::string>("Please enter your username:");
        std::cout << "Username: \"" << username << "\"\n";
    }

    return username;
}


void main_menu()
{
    system("color 0F");
    std::cout << "The Gladiator" << std::endl;
    std::cout << std::setfill('+') << std::setw(120) << "+";
    int choice = get_input <int>(
        "Welcome to The Gladiator!\n\nFirst of all, would you like to Login or Register, Chief?" "\n"
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

void setUp()
{
    system("CLS");
    //#########################################################################
    //Beginning of code by [Annija Balode 9102828]
    // This will take the name that the player would like to go by and save it in the player variable
    std::string usersName = get_input <std::string>("Let's get you registered! First things first though, what is your name, Chief?\n");
    //userName[0] = toupper(userName[0]);

    singularWordOutput(usersName + "! Emperor Macrinus is setting up new camps for Gladiators to train in!\n");
    singularWordOutput("It says on this rock here that he has now put you in charge of this camp,\nyour first order is to give it a name...\n");
    std::string nameOfClan = get_input <std::string>("\nWhat would you like to name your clan, Chief " + usersName + "?\n");
    singularWordOutput("\nAs the official Chief of " + nameOfClan + " you must decide whether you will be Attack or Defence.\n");


    while (true)
    {
        std::string typeOfClan = get_input <std::string>("\nWhich one will it be?\n");
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
            char typeOfClan[25];
            continue;
        }
    }
}

void register_user()
{
    setUp();
    std::string username = getDesiredUsername();
    std::string password = getDesiredPassword();
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
    std::string username = getNewUsername();
    std::string password = getNewPassword();
    std::cout << "You are being logged in!\n" << std::endl;
}

//https://codereview.stackexchange.com/questions/124194/user-registration-and-login-program