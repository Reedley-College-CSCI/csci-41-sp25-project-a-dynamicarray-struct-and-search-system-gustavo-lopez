#ifndef PLAYSTATION_H
#define PLAYSTATION_H
#include <iostream>
#include <string>
#include <fstream>
 
using namespace std;

//Reference 2.1 notes
struct GameAttributes {
	string gameTitle;
	string genre;
	string devName;
	string publisherName;
	string releaseDate;

};

class PlayStation {
	private:
		GameAttributes* currListOfGames;
		int currentGamesInArray;
		//Reference 1.29-1.31 notes
		void updateArraySize();
		int arraySize;

	public:
		//constructors and destructors
		PlayStation();
		PlayStation(int size);
		~PlayStation();

		void displayMainMenu();
		void readInGameInfo(const string& extFileName);
		//TO DO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		void addGameInfo();
		void removeGameInfo(const string& gameTitle);

		//functions to manipulate data. I would like for the user to be able to be able to organize games
		//alphabetically or by release date.
		void displayGamesByReleaseDate() const;
		void displayGamesAlphabetically() const;
		void displayGames() const;
		GameAttributes* findGame(const string& userGameTitle) const;
	

};

#endif
