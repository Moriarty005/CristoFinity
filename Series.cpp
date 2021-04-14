#include <iostream>
#include <iomanip>
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"
#define RESTORE "\033[1;0m"
#define amarillo "\033[1;43m"
#define morado "\033[1;45m"
#define cyan "\033[1;46m"
#define verde "\033[1;42m"

#include "Series.h"


void Series::setSeasons(int new_seasons){

//cout << DEBUG << "debug: getting in setSeasons" << RESTORE << endl;

	this->seasons = new_seasons;
}

void Series::setEpisodes(int new_episodes){

//cout << DEBUG << "debug: getting in setEpisodes" << RESTORE << endl;

	this->episodes = new_episodes;
}

void Series::setStage(bool new_stage){

//cout << DEBUG << "debug: getting in setStage" << RESTORE << endl;

	this->stage = new_stage;
}

int Series::getSeasons(){

//cout << DEBUG << "debug: getting in getSeasons" << RESTORE << endl;

	return this->seasons;
}

int Series::getEpisodes(){

//cout << DEBUG << "debug: getting in getEpisodes" << RESTORE << endl;

	return this->episodes;
}

bool Series::getStage(){

//cout << DEBUG << "debug: getting in getStage" << RESTORE << endl;

	return this->stage;
}

void Series::print(){

//cout << DEBUG << "debug: getting in print of the class series" << RESTORE << endl;

	this->Film::print();

	cout << this->getSeasons() << endl;
	cout << this->getEpisodes() << endl;
	cout << this->getStage() << endl;
}
