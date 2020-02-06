//Main_File.cpp : This file contains the 'main' function. Program execution begins and ends there.
//If you want to run the file just press Ctrl + F5. Debugging can be found in the tabs above.

#include <iostream>
#include <conio.h> //Functions for console input and output. Can change stuff like the background colour, text colour, etc.
//conio documentation: https://www.includehelp.com/c-tutorial/c-language-conio-h-in-c-programming-tutorial.aspx
#include <stdlib.h> //Used for getting the input from the user and output the result back to the monitor. 
//Please try to avoid using 'using namespace std;' if possible in all of your files as this is a bad habit. Avoiding this habit will be more beneficial for the future.

int main()
{
    //I produced a very simple function where the player is able to give the name of their clan and which side they want to be on.
    //This should be used as a template to begin the game and give everyone a sense of how this shoud be structured.
    char nameOfClan[25];
    std::cout << "The Gladiator" << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "\nWhat would you like to name your clan, Chief?" << std::endl;
    std::cin.getline(nameOfClan, 25);
    std::cout << "\nAs the Chief of " << nameOfClan << " you must decide whether you will be Attack or Defence." << std::endl;
    char typeOfClan[25];
    std::cout << "\nWould you like to pick Attack or Defence?" << std::endl;
    std::cin.getline(typeOfClan, 25);
    return 0;
}
