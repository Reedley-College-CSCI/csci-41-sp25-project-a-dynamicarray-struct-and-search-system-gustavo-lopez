#include "PlayStation.h"
#include <fstream>
#include <string>

//default constructor
PlayStation::PlayStation() {
	cout << "Default constructor called" << endl;
	arraySize = 100;
	currentGamesInArray = 0;
	currListOfGames = new GameAttributes[arraySize];
}

//constructor to edit arraySize struct attribute
PlayStation::PlayStation(int size) {
	arraySize = size;
	currListOfGames = new GameAttributes[arraySize];
} 

//destructor for a PlayStation object that's created.
PlayStation::~PlayStation() {

	cout << "Destructor called" << endl;
	delete[] currListOfGames;
}

//as the name states, this function displays the main menu
void PlayStation::displayMainMenu() {
	cout << "Welcome user! This program holds PlayStation 4 games in a catalog. Currently, we have" <<
		" 52 titles with their respective \ninformation. Feel free to browse at your leisure." << endl;
	cout << endl << "1. Display all titles" << endl;
	cout << "2. Search for a game" << endl;
	cout << "Enter -1 to close the program." << endl;

	cout << "Choose an option: ";
}

//this function will read in game information from my ext file and write them into my currGameList array
//line by line. I used commas as the seperator for titles, genres, publishers, etc. Easier to iterate
//through and sort accordingly.
void PlayStation::readInGameInfo(const string& extFileName) {
	ifstream inFile(extFileName);
	string line;
	int index = 0;
	int numGamesImported = 0;


	if (inFile.is_open()) {
		while (getline(inFile, line) && index < arraySize) {
			//line of code to skip over lines that are empty in the text file.
			if (line.empty()) {
				continue;
			}
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

			commaPosition = line.find(',');
			currListOfGames[index].publisherName = line.substr(0, commaPosition);
			line = line.substr(commaPosition + 1);

			currListOfGames[index].releaseDate = line;

			index++;
			numGamesImported++;

			
		}
		inFile.close();
		currentGamesInArray = numGamesImported;

		cout << "Game info has been read in and the file has been closed." << endl;
	}
	else {
		cout << "Unable to open file" << endl;
	}
}

//This function only displays the games as they are in the file
void PlayStation::displayGames() const{
	cout << "Displaying current game catalog:" << endl;

	for (int i = 0; i < currentGamesInArray; i++) {
		cout << "Title: " << currListOfGames[i].gameTitle << endl;
		cout << "Genre: " << currListOfGames[i].genre << endl;
		cout << "Developer: " << currListOfGames[i].devName << endl;
		cout << "Publisher: " << currListOfGames[i].publisherName << endl;
		cout << "Release Date: " << currListOfGames[i].releaseDate << endl;
		cout << "----------------------------------------" << endl;
	}
}

//function called when user inputs a game title they're looking for in my catalog
GameAttributes* PlayStation::findGame(const string& userGameTitle) const {
	for (int i = 0; i < currentGamesInArray; i++) {
		if (currListOfGames[i].gameTitle == userGameTitle) {
			return &currListOfGames[i];
		}
	}
	return nullptr;
}

void PlayStation::displaySubMenu(PlayStation* psObject, int& menuChoice) {
	//move do while loop into it's own separate function for better modularity
	string gameToFind;
	GameAttributes* foundGame = nullptr;

	do {
		cin >> menuChoice;
		while (cin.get() != '\n');

		switch (menuChoice) {
		case 1:
			psObject->displayGames();
			break;
		case 2:
			cout << "Enter name of the game you want to find: ";
			getline(cin, gameToFind);
			foundGame = psObject->findGame(gameToFind);

			// Check if the game was found. Should make this a function for better modularity
			if (foundGame) {
				cout << endl << "Game found: " << foundGame->gameTitle << endl;
				cout << "Genre: " << foundGame->genre << endl;
				cout << "Developer: " << foundGame->devName << endl;
				cout << "Publisher: " << foundGame->publisherName << endl;
				cout << "Release Date: " << foundGame->releaseDate << endl << endl;
			}
			else {
				cout << "Game not found." << endl;
			}
			break;
		case -1:
			cout << endl << "Exiting program" << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
		if (menuChoice != -1) {
			cout << "You're back here? Go back and check out one of the other options or hit 3 to leave.";
			cout << endl << endl << "1. Display all titles" << endl;
			cout << "2. Search for a game" << endl;
			cout << "Enter -1 to exit the program (you don't have to though)" << endl;
			cout << "Choose an option: ";
		}
	} while (menuChoice != -1);

}

//FINISH!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//function to sort games A-Z. Use binary search since the array is fairly large.
void PlayStation::displayGamesAlphabetically() const {
	cout << "Called displayGamesAlphabetically function" << endl;
}


