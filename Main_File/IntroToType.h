//This function will be used to give the player an rundown on their type of clan
//And what the game entails
#include <iostream>
#include <windows.h>

void IntroToType(std::string type) {

	if (type == "Attack") {
		std::cout << "You have chosen Ataack" << std::endl;
		Sleep(2000);
		std::cout << "your fighters will focus on Barbaric, Heavy, Uncontrolled hits";
		Sleep(3000);
	}
}