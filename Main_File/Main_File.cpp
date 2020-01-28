//Main_File.cpp : This file contains the 'main' function. Program execution begins and ends there.
//If you want to run the file just press Ctrl + F5. Debugging can be found in the tabs above.

#include <iostream>
#include <conio.h> //Functions for console input and output. Can change stuff like the background colour, text colour, etc.
//conio documentation: https://www.includehelp.com/c-tutorial/c-language-conio-h-in-c-programming-tutorial.aspx
#include <stdlib.h> //Used for getting the input from the user and output the result back to the monitor. 
using namespace std;

int main()
{
    //Simply takes in the users name and returns this.
    char name[25];
    cout << "What is your name?" << endl;
    cin.getline(name, 25);
    cout << "Nice to meet you, " << name << ". Hope to see you around more!" << endl;
    cout << "\n----------------------Press any key to continue----------------------" << endl;
    return 0;
}
