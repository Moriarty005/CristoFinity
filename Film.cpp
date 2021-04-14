#include <iostream>
#include <iomanip>
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"
#define RESTORE "\033[1;0m"
#define amarillo "\033[1;43m"
#define morado "\033[1;45m"
#define cyan "\033[1;46m"
#define verde "\033[1;42m"

#include "Film.h"

using namespace std;


void Film::setCast(string new_cast){

//cout << DEBUG << "debug: getting in setCast" << RESTORE << endl;

	this->cast = new_cast;
}

void Film::setDirector(string new_director){

//cout << DEBUG << "debug: getting in setDirector" << RESTORE << endl;

	this->director = new_director;
}

void Film::setScriptTeam(string new_script_team){

//cout << DEBUG << "debug: getting in setScriptTeam" << RESTORE << endl;

	this->script_team = new_script_team;
}

void Film::setProducer(string new_producer){

///cout << DEBUG << "debug: getting in setProducer" << RESTORE << endl;

	this->producer = new_producer;
}

string Film::getCast(){

//cout << DEBUG << "debug: getting in getCast" << RESTORE << endl;

	return this->cast;
}

string Film::getDirector(){

//cout << DEBUG << "debug: getting in getDirector" << RESTORE << endl;

	return this->director;
}

string Film::getScriptTeam(){

//cout << DEBUG << "debug: getting in getScriptTeam" << RESTORE << endl;

	return this->script_team;
}

string Film::getProducer(){

//cout << DEBUG << "debug: getting in getProducer" << RESTORE << endl;

	return this->producer;
}

void Film::print(){

//cout << DEBUG << "debug: getting in print of the class film" << RESTORE << endl;

	this->Media::print();

	cout << this->getCast() << endl;
	cout << this->getDirector() << endl;
	cout << this->getScriptTeam() << endl;
	cout << this->getProducer() << endl;
}