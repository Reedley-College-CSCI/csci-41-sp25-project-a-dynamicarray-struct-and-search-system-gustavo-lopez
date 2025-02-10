/*
Gustavo Lopez Celestino
For Project A, I am going to take the first 2 games from every letter in the catalog. So I will put in the first 2 games
from letter A, 2 games from letter B, 2 games from letter C, and so on. So the catalog will be 52 games at first.
*/
#include <iostream>
#include "PlayStation.h"
#include <string>
#include <fstream>
using namespace std;

int main() {
	PlayStation* object1 = new PlayStation(100);
	int mainMenuChoice;
	string gameToFind;

	//line to read in text files
	object1->readInGameInfo("PlaystationGames.txt");
	object1->displayMainMenu();

	do {
		cin >> mainMenuChoice;

		switch (mainMenuChoice) {
			case 1:
				object1->displayGames();
				break;
			case 2:
				cout << "Enter game you want to find: ";
				cin >> gameToFind;
				//object1.findGame(gameToFind);
				break;
			case 3:
				cout << "Exiting program" << endl;
				break;
			default:
				cout << "Invalid choice. Please try again." << endl;
		}
	} while (mainMenuChoice != 3);

	delete object1;
	return 0;
}

