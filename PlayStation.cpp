#include "PlayStation.h"
#include <fstream>
#include <string>

//default constructor
PlayStation::PlayStation() {
	cout << "Default constructor called" << endl;
}
PlayStation::PlayStation(int arraySize) {
	currListOfGames = new GameAttributes[arraySize];
} 

//destructors
PlayStation::~PlayStation() {
	cout << "Destructor called" << endl;

	delete[] currListOfGames;
}

void PlayStation::displayMainMenu() {
	cout << "Welcome user! This program holds PlayStation 4 games in a catalog. Currently, we have" <<
		" 52 titles with their respective information. Feel free to browse at your leisure." << endl;
	cout << endl << "1. Display All Titles" << endl;
	cout << "2. Search For A Game" << endl;
	cout << "3. Exit the program" << endl;
	cout << "Choose an option: ";


}

void PlayStation::readInGameInfo(const string& extFileName) {
	ifstream inFile(extFileName);
	string line;


	if (inFile.is_open()) {
		while (getline(inFile, line)) {
			cin >> line;
		}
		
		inFile.close();

		cout << "Game info has been read in and the file has been closed." << endl;
	}
	else {
		cout << "Unable to open file" << endl;
	}

	
}
