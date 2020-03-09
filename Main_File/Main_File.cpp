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

#include "createGladiator.h"
#include "gladiatorListing.h"
#include "clanType.h"

// Variable which stores the userID once the player logs in
int userID;
std::string clanType;

//Beginning of code by [Annija Balode 9102828].
int main()
{  
    userID = mainMenu();
    clanType = getClanType(userID);

    system("CLS");

    MainScreen(userID, clanType);

    return (0);
}
///void main()
//{//
    //int x = 0;
    //if (getSaved() == true)
       // (
         //   center(" select: ");
           // center(" 1.restart");
//            center("2. resume from save ");
//
  //          do
    //        {
         //       cin >> x;
      ///      } while (x != 1 && x != 2 &&);
          // )
  //  else(
    //    center(" Select: ");
        //center(" 1.Play game");
      ///  center("2. Exit");
        //)
        
        /// ///do
         ///
 ///cin >> x;
          ///} while (x != 1 && x); ///        ) ///
 ///