#include <iostream>
#include <string>
#include <iomanip>
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"
#define RESTORE "\033[1;0m"
#define amarillo "\033[1;43m"
#define morado "\033[1;45m"
#define cyan "\033[1;46m"
#define verde "\033[1;42m"

#include "Administrator.h"

using namespace std;

Administrator::~Administrator(){

//cout << DEBUG << "debug: getting in the default destructor of the class adminsitrator" << RESTORE << endl;

	this->creator = false;
}

void Administrator::setCreator(bool new_creator){

	this->creator = new_creator;
}

bool Administrator::getCreator(){

//cout << DEBUG << "debug: getting in  getCreator" << RESTORE << endl;

	return this->creator;
}

void Administrator::printUser(){

//cout << DEBUG << "debug: getting in printUser" << RESTORE << endl;

	this->User::printUser();

	cout << USER << "Is the administrator one of the creator of the app? " << this->getCreator() << RESTORE << endl;
}