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
	GameAttributes* foundGame = nullptr;

	//line to read in text files
	object1->readInGameInfo("PlaystationGames.txt");
	object1->displayMainMenu();

	do {
		cin >> mainMenuChoice;
		while (cin.get() != '\n');

		switch (mainMenuChoice) {
			case 1:
				object1->displayGames();
				break;
			case 2: 
				cout << "Enter name of the game you want to find: ";
				getline(cin, gameToFind);
				foundGame = object1->findGame(gameToFind);

				// Check if the game was found
				if (foundGame) {
					cout << "Game found: " << foundGame->gameTitle << endl;
					cout << "Genre: " << foundGame->genre << endl;
					cout << "Developer: " << foundGame->devName << endl;
					cout << "Publisher: " << foundGame->publisherName << endl;
					cout << "Release Date: " << foundGame->releaseDate << endl;
				}
				else {
					cout << "Game not found." << endl;
				}
				break;
			case 3:
				cout << "Exiting program" << endl;
				break;
			default:
				cout << "Invalid choice. Please try again." << endl;
		}
		object1->displayMainMenu();
	} while (mainMenuChoice != 3);

	delete object1;
	return 0;
}

