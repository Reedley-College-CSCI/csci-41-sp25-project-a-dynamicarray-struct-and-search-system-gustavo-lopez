#include "PlayStation.h"
#include <fstream>
#include <string>

//default constructor
PlayStation::PlayStation() {
	cout << "Default constructor called" << endl;
	//concrete array size, need to make it dynamic to be able to change the size of the array.
	arraySize = 100;
	currListOfGames = new GameAttributes[arraySize];
}

//constructor to edit array size
PlayStation::PlayStation(int size) {
	arraySize = size;
	currListOfGames = new GameAttributes[arraySize];
} 

//destructors
PlayStation::~PlayStation() {
	cout << "Destructor called" << endl;

	delete[] currListOfGames;
}

void PlayStation::displayMainMenu() {
	cout << "Welcome user! This program holds PlayStation 4 games in a catalog. Currently, we have" <<
		" 52 titles with their respective \ninformation. Feel free to browse at your leisure." << endl;
	cout << endl << "1. Display All Titles" << endl;
	cout << "2. Search For A Game" << endl;
	cout << "3. Exit the program" << endl;
	cout << "Choose an option: ";
}

//this function will read in game information from my ext file and write them into my currGameList array
void PlayStation::readInGameInfo(const string& extFileName) {
	ifstream inFile(extFileName);
	string line;
	int index = 0;


	if (inFile.is_open()) {
		while (getline(inFile, line) && index < arraySize) {
			int commaPosition = 0;

			commaPosition = line.find(',');
			currListOfGames[index].gameTitle = line.substr(0, commaPosition);
			line = line.substr(commaPosition + 1);

			commaPosition = line.find(',');
			currListOfGames[index].genre = line.substr(0, commaPosition);
			line = line.substr(commaPosition + 1);

			commaPosition = line.find(',');
			currListOfGames[index].devName = line.substr(0, commaPosition);
			line = line.substr(commaPosition + 1);

			currListOfGames[index].releaseDate = line;

			index++;

			
		}
		inFile.close();

		cout << "Game info has been read in and the file has been closed." << endl;
	}
	else {
		cout << "Unable to open file" << endl;
	}

	
}

void PlayStation::displayGames() const{
	//fill in displayGames function. This function only displays the games as they are in the file
	cout << "displayGames function has been called" << endl;


}

//function to sort games A-Z. Use binary search since the array is fairly large.
void PlayStation::displayGamesAlphabetically() const {
	cout << "Called displayGamesAlphabetically function" << endl;
}
