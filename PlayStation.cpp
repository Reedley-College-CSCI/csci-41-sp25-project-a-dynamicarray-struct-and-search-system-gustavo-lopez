#include "PlayStation.h"

//default constructor
PlayStation::PlayStation() {
	title = "No title";
	genre = "No genre";
	devName = "No developer";
	publisherName = "No publisher";
	releaseMonth = 01;
	releaseDay = 01;
	releaseYear = 2013;
}

//getTitle() function that returns title of a game.
string PlayStation::getTitle() {
	return title;
}

PlayStation::~PlayStation() {}



