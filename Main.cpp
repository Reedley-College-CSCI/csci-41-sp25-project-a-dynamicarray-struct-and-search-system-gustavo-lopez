/*
Gustavo Lopez Celestino
For Project A, I am going to take the first 5 games from every letter in the catalog. So I will put in the first 5 games
from letter A, 5 games from letter B, 5 games from letter C, and so on. So the catalog will be 130 games at first.
*/
#include <iostream>
#include "PlayStation.h"
#include <string>
#include <fstream>
using namespace std;

int main() {
	PlayStation object1(100);
	
	object1.displayMainMenu();
	object1.readInGameInfo("PlaystationGames.txt");




	return 0;
}

