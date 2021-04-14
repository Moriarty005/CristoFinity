#include <iostream>
#include <iomanip>
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"
#define RESTORE "\033[1;0m"
#define amarillo "\033[1;43m"
#define morado "\033[1;45m"
#define cyan "\033[1;46m"
#define verde "\033[1;42m"

#include "Videogame.h"

using namespace std;

		
void Videogame::setDeveloper(string new_developer){

//cout << DEBUG << "debug: getting in setDeveloper" << RESTORE << endl;

	this->developer = new_developer;
}

void Videogame::setEditor(string new_editor){

//cout << DEBUG << "debug: getting in setEditor" << RESTORE << endl;

	this->editor = new_editor;
}

void Videogame::setPlayers(int new_players){

//cout << DEBUG << "debug: getting in setPlayers(" << RESTORE << endl;

	this->players = new_players;
}

void Videogame::setPlatforms(string new_platforms){

//cout << DEBUG << "debug: getting in setPlatforms(" << RESTORE << endl;

	this->platforms = new_platforms;
}

string Videogame::getDeveloper(){

//cout << DEBUG << "debug: getting in getDeveloper" << RESTORE << endl;

	return this->developer;
}

string Videogame::getEditor(){

//cout << DEBUG << "debug: getting in getEditor" << RESTORE << endl;

	return this->editor;
}

int Videogame::getPlayers(){

//cout << DEBUG << "debug: getting in getPlayers" << RESTORE << endl;

	return this->players;
}

string Videogame::getPlatforms(){

//cout << DEBUG << "debug: getting in getPlatforms" << RESTORE << endl;

	return this->platforms;
}

void Videogame::print(){

//cout << DEBUG << "debug: getting in print of the class videogame" << RESTORE << endl;

	this->Media::print();

	cout << this->getDeveloper() << endl;
	cout << this->getEditor() << endl;
	cout << this->getPlayers() << endl;
	cout << this->getPlatforms() << endl;
}