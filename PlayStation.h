#ifndef PLAYSTATION_H
#define PLAYSTATION_H
#include <iostream>
#include <string>
#include <fstream>
 
using namespace std;

//Reference 2.1 notes
struct GameAttributes {
	//write in variables
	string gameTitle;
	string genre;
	string devName;
	string publisherName;
	int releaseDate;

};


class PlayStation {
private:
	int gameArraySize;
	int gameArrayCapacity;
	//Reference 1.29-1.31 notes
	void updateArraySize();

public:
	GameAttributes* currListOfGames;
	//int for array size
	int arraySize;
	//constructors and destructors
	PlayStation();
	PlayStation(int arraySize);
	~PlayStation();

	void displayMainMenu() {}

	//getters and setters
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	void readInGameInfo(const string& extFileName);
	void addGameInfo();
	void removeGameInfo(const string& gameTitle);

	//functions to manipulate data. I would like for the user to be able to be able to organize games
	//alphabetically or by release date.
	void displayAlphabetically() const;
	void displayGames() const;
	GameAttributes* findGame(const string& gameTitle) const;
	

};
















#endif

 
