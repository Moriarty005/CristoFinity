#include <iostream>
#include <iomanip>
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"
#define RESTORE "\033[1;0m"
#define amarillo "\033[1;43m"
#define morado "\033[1;45m"
#define cyan "\033[1;46m"
#define verde "\033[1;42m"

#include "Song.h"

using namespace std;

void Song::setArtist(string new_artist){

cout << DEBUG << "debug: getting in setArtist" << RESTORE << endl;

	this->artist = new_artist;
}

void Song::setAlbum(string new_album){

cout << DEBUG << "debug: getting in setAlbum" << RESTORE << endl;

	this->album = new_album;
}

string Song::getArtist(){

cout << DEBUG << "debug: getting in getArtist" << RESTORE << endl;

	return this->artist;
}

string Song::getAlbum(){

cout << DEBUG << "debug: getting in getAlbum" << RESTORE << endl;

	return this->album;
}

void Song::print(){

cout << DEBUG << "debug: getting in print of the class print" << RESTORE << endl;

	this->Media::print();

	cout << this->getArtist() << endl;
	cout << this->getAlbum() << endl;
}