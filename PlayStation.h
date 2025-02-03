#ifndef PLAYSTATION_H
#define PLAYSTATION_H
#include <iostream>
#include <string>
using namespace std;


class PlayStationGame {
private:
	string title;
	string genre;
	string devName;
	string publisherName;
	int releaseMonth;
	int releaseDay;
	int releaseYear;

public:
	//constructors and destructors
	PlayStationGame();
	PlayStationGame(string title);
	PlayStationGame(int listArray[]);
	~PlayStationGame();

	//getters
	string getTitle();
	string getGenre();
	string getDeveloper();
	string getPublisher();
	//Need to figure out how to get all three integers (releaseDay, releaseMonth, releaseYear) 
	// into this function since I want it to output month/day/year
	int getReleaseDate();

	//setters
	void setGenre();
	void setDeveloper();
	void setPublisher();
	void setReleaseDate();

};

PlayStationGame::PlayStationGame() {
	title = "No title";
	genre = "No genre";
	devName = "No developer";
	publisherName = "No publisher";
	releaseMonth = 01;
	releaseDay = 01;
	releaseYear = 2013;
}

string PlayStationGame::getTitle() {
	return title;
}




















#endif

 
