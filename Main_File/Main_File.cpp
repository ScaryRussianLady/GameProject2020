//Main_File.cpp : This file contains the 'main' function. Program execution begins and ends there.
//If you want to run the file just press Ctrl + F5. Debugging can be found in the tabs above.

//IMPORTANT NOTICE: This is a link to how to install vcpkg, if you are unable to follow it, drop me a message (Annija) https://www.youtube.com/watch?v=wRnjahwxZ8A.

//#include "timeTillFight.h"
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
#include "MainScreen.h"
#include "Introduction.h"


void centerstring(char* s)
{
    int l = strlen(s);
    int pos = (int)((80 - l) / 2);
    for (int i = 0; i < pos; i++)
        std::cout << " " << std::endl;
    std::cout << s << std::endl;
}

//Beginning of code by [Annija Balode 9102828].
int main()
{   
    mainMenu();
    system("CLS");
    MainScreen();

    return (0);
}

