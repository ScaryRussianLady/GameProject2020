#include <iostream>
#include <Windows.h> //include windows.h to use the sleep function. takes innput as milliseconds
#include <stdlib.h>
//#include "clear.h"


void time() {
	int count = 7;
	while (count >= 0) {
		if (count > 0) {
			system("CLS");//clear screen
			std::cout << "days till next fight: " << count << std::endl;
			Sleep(3000);//set to three seconds right now just for testing purposes
		}
		if (count == 0) {
			system("CLS");//clear screen
			std::cout << "IT'S FIGHT DAY!\n" << std::endl;
			
		}
		count -= 1;
	}
	std::cout << "\nGREAT! It's time to send your fighters in" << std::endl;


}