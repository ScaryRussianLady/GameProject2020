#pragma once
#include <iostream>
#include "Indicators.h"
#include "timeTillFight.h"

//Beginning of code by [Annija Balode 9102828]
void MainScreen(int userid, std::string clanType)
{
    std::cout << "Days Left: " << timeTillFight(userid, clanType) << std::endl;

}
//End of code by [Annija Balode 9102828]

   //Beginning of code by [Rishikesh]
   //{
   // int x = 0;
   // if (getSaved() == true)
   //    (
   //      center(" select: ");
   //      center(" 1.restart");
   //     center("2. resume from save ");
   //         do
   //        {
   //            cin >> x;
   //           } while (x != 1 && x != 2 &&);
   //)
   // else(
   //     center(" Select: ");
   //      center(" 1.Play game");
   //    center("2. Exit");
   //     )
   //     do

   //         cin >> x;
   //         } while (x != 1 && x);      )
   //End of code by [Rishikesh]

