
#include "Punctuation.h"
#include <iostream>
#include <iomanip>
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"
#define RESTORE "\033[1;0m"
#define amarillo "\033[1;43m"
#define morado "\033[1;45m"
#define cyan "\033[1;46m"
#define verde "\033[1;42m"

using namespace std;

Punctuation::Punctuation(){

	this->reviewer = "NULL";
	this->points = 0;
}

Punctuation::Punctuation(string new_reviewer, float new_points){

	this->reviewer = new_reviewer;
	this->points = new_points;
}

Punctuation::~Punctuation(){

	this->reviewer = "NULL";
	this->points = 0;
}

void Punctuation::setReviewer(string new_reviewer){

	this->reviewer = new_reviewer;
}

void Punctuation::setPoints(float new_points){

	this->points = new_points;
}

string Punctuation::getReviewer(){

	return this->reviewer;
}

float Punctuation::getPoints(){

	return this->points;
}