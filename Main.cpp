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
	PlayStation* object1 = new PlayStation(500);
	int mainMenuChoice = 0;
	string gameToFind;
	GameAttributes* foundGame = nullptr;

	object1->readInGameInfo("PlaystationGames.txt");
	object1->displayMainMenu();
	object1->displaySubMenu(object1, mainMenuChoice);

	delete object1;
	return 0;
}

