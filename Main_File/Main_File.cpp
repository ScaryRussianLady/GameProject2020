//Main_File.cpp : This file contains the 'main' function. Program execution begins and ends there.
//If you want to run the file just press Ctrl + F5. Debugging can be found in the tabs above.

//IMPORTANT NOTICE: This is a link to how to install vcpkg, if you are unable to follow it, drop me a message (Annija) https://www.youtube.com/watch?v=wRnjahwxZ8A.

#include <windows.h>
#include <iostream>
//conio documentation: https://www.includehelp.com/c-tutorial/c-language-conio-h-in-c-programming-tutorial.aspx
//Please try to avoid using 'using namespace std;' if possible in all of your files as this is a bad habit. Avoiding this habit will be more beneficial for the future.
#include "GameClasses.h"
#include "MainScreen.h"
#include "Introduction.h"

//Beginning of code by [Annija Balode 9102828].
int main()
{   
    mainMenu();
    system("CLS");
    MainScreen();

    return (0);
}


