//Main_File.cpp : This file contains the 'main' function. Program execution begins and ends there.
//If you want to run the file just press Ctrl + F5. Debugging can be found in the tabs above.

//Testing

#include "timeTillFight.h"
#include <windows.h>
#include <iostream>
//conio documentation: https://www.includehelp.com/c-tutorial/c-language-conio-h-in-c-programming-tutorial.aspx
#include <stdlib.h> //Used for getting the input from the user and output the result back to the monitor. 
//Please try to avoid using 'using namespace std;' if possible in all of your files as this is a bad habit. Avoiding this habit will be more beneficial for the future.
//#include <sqlite3.h>
//#include <stdio.h>
#include <thread>

void singularWordOutput(const std::string& text)
{
    // loop through each character in the text
    for (std::size_t i = 0; i < text.size(); ++i)
    {
        // output one character
        // flush to make sure the output is not delayed
        std::cout << text[i] << std::flush;

        // sleep 60 milliseconds
        std::this_thread::sleep_for(std::chrono::milliseconds(80));
    }
}

//[Annija Balode 9102828] and referenced from https://www.dreamincode.net/forums/topic/228382-make-text-to-appear-letter-by-letter-in-console/
int main()
{

    //I produced a very simple function where the player is able to give the name of their clan and which side they want to be on.
    //This should be used as a template to begin the game and give everyone a sense of how this shoud be structured.

    system("color 8F");//changes colour of terminal and text. couldn't get conio to work. use "color %" to view all available colours
    char nameOfClan[25];
    char userName[25];
    std::cout << "The Gladiator" << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;
    singularWordOutput("Welcome to The Gladiator.\nWhat is your name, Chief?\n");
    //char str[] = { "Welcome to The Gladiator\nWhat is your name, Chief?\n" };
    //int length = strlen(str);
    //for (int i = 0; i < length; i++)
    //{
    //    putchar(str[i]);
      //  Sleep(70);
    //}

    //std::cout << "Welcome to The Gladiator.\nWhat is your name, Chief?" << std::endl;
    std::cin.getline(userName, 25);
    singularWordOutput(std::string(userName) + "! Emperor Macrinus is setting up new camps for Gladiators to train in!\n");
    singularWordOutput("It says on this rock here that he has now put you in charge of this camp,\nyour first order is to give it a name...\n");
    singularWordOutput("\nWhat would you like to name your clan, Chief " + std::string(userName) + "?\n");
    std::cin.getline(nameOfClan, 25);
    singularWordOutput("\nAs the official Chief of " + std::string(nameOfClan) + " you must decide whether you will be Attack or Defence.\n");
    char typeOfClan[25];
    singularWordOutput("\nWould you like to be Attack or Defence?");
    std::cin.getline(typeOfClan, 25);



    system("CLS");//is used to clear the text on the terminal. conio's clrscn() did not work

    timeTillFight();//called the time function for testing
    return (0);
}
