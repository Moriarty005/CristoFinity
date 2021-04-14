#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"
#define RESTORE "\033[1;0m"
#define amarillo "\033[1;43m"
#define morado "\033[1;45m"
#define cyan "\033[1;46m"
#define verde "\033[1;42m"

#include "User.h"

using namespace std;

User::User(){

//cout << DEBUG << "debug: getting in default constructor of the class user" << RESTORE << endl;

	this->id_user = "NULL";
	this->user_name = "NULL";
	this->user_surname = "NULL";
	this->url_photo = "NULL";

	this->searched_media_vector_dimension = 0;
	this->searched_media_vector = new Media*[1];
	if(this->searched_media_vector == 0){
		cout << "It's impossible to save space in the heap" << endl;
		exit (-1);
	}
}

User::User(string new_user_id, string new_user_name, string new_user_surname, string new_url_photo){

//cout << DEBUG << "debug: getting in cosntructor by parameter of the class user" << RESTORE << endl;

	this->id_user = new_user_id;
	this->user_name = new_user_name;
	this->user_surname = new_user_surname;
	this->url_photo = new_url_photo;

	this->searched_media_vector_dimension = 0;
	this->searched_media_vector = new Media*[1];
	if(this->searched_media_vector == 0){
		cout << "It's impossible to save space in the heap" << endl;
		exit (-1);
	}
}

User::~User(){

//cout << DEBUG << "debug: getting in the default destrcutor of the class user" << RESTORE << endl;

	this->id_user = "NULL";
	this->user_name = "NULL";
	this->user_surname = "NULL";
	this->url_photo = "NULL";

	for(int index = 0; index <= this->searched_media_vector_dimension; index++){

		delete this->searched_media_vector[index];
		this->searched_media_vector[index] = 0;
	}

	delete this->searched_media_vector;
	this->searched_media_vector = 0;
}

void User::setId_user(string new_id_user){

//cout << DEBUG << "debug: getting in setId_user" << RESTORE << endl;

	this->id_user = new_id_user;
}

void User::setUserName(string new_user_name){

//cout << DEBUG << "debug: getting in etUserName" << RESTORE << endl;

	this->user_name = new_user_name;
}

void User::setUserSurName(string new_user_surname){

//cout << DEBUG << "debug: getting insetUserSurName" << RESTORE << endl;

	this->user_surname = new_user_surname;
}

void User::setUserURL(string new_url_photo){

//cout << DEBUG << "debug: getting in setUserURL" << RESTORE << endl;

	this->url_photo = new_url_photo;
}

string User::getId_user(){

//cout << DEBUG << "debug: getting in getId_user" << RESTORE << endl;

	return this->id_user;
}

string User::getUserName(){

//cout << DEBUG << "debug: getting in getUserName" << RESTORE << endl;

	return this->user_name;
}

string  User::getUserSurName(){

//cout << DEBUG << "debug: getting in getUserSurName" << RESTORE << endl;

	return this->user_surname;
}

string  User::getUserURL(){

//cout << DEBUG << "debug: getting in getUserURL" << RESTORE << endl;

	return url_photo;
}

unsigned int User::getSearchedMediaVectorDimension(){

//cout << DEBUG << "debug: getting in getSearchedMediaVectorDimension" << RESTORE << endl;

	return this->searched_media_vector_dimension;
}

unsigned int User::getFavouriteMediaVectorDimension(){

//cout << DEBUG << "debug: getting in getFavouriteMediaVectorDimension" << RESTORE << endl;

	return this->favourite_media_vector_dimension;
}


void User::setMediaToSearched(Media *new_searched_media){

//cout << DEBUG << "debug: getting in setMediaToSearched" << RESTORE << endl;

	this->searched_media_vector[searched_media_vector_dimension] = new_searched_media;

	this->augmentativeSearchedMediaResize();
}

Comment* User::writeComment(){

//cout << DEBUG << "debug: getting in writeComment" << RESTORE << endl;

	Comment *new_comment;
	new_comment = new Comment();

	string new_comment_text;

	new_comment->setWriter(this->getId_user());

	cout << USER << "Write your comment: " << RESTORE << endl;
	
	cin >> new_comment_text;
	getline(cin, new_comment_text);
	new_comment->setComment_text(new_comment_text);
//cout << amarillo << "debug: auqi tio no te rayes" << RESTORE << endl;
	return new_comment;
//cout << amarillo << "debug: auqi tio no te rayes" << RESTORE << endl;
}

Punctuation* User::giveAPunctuation(){

cout << DEBUG << "debug: getting in the give a punctuation" << RESTORE << endl;

	Punctuation* new_score;
	new_score = new Punctuation();

	new_score->setReviewer(this->getId_user());

	int score = 0;

	cout << USER << "Your mark to this media: " <<  RESTORE << endl;
	cin >> score;

	new_score->setPoints(score);

	return new_score;
}

void User::printSearchedMedia(){

	cout << USER << "Media prevously searched: " << RESTORE << endl;
	for(int index = 0; index < this->getSearchedMediaVectorDimension(); index++){

		this->searched_media_vector[index]->print();
	}
}

void User::printUser(){

//cout << DEBUG << "debug: getting in printUser" << RESTORE << endl;

	cout << USER << "User: " << this->getId_user() << RESTORE << endl;
	cout << USER << "User name: " << this->getUserSurName() << RESTORE << endl;
	cout << USER << "User surname: " << this->getUserName() << RESTORE << endl;
	cout << USER << "User photo: " << this->getUserURL() << RESTORE << endl;

	this->printSearchedMedia();
}


void User::augmentativeSearchedMediaResize(){

//cout << DEBUG << "debug: getting in the augmentative Media resize of the class User" << RESTORE << endl;

	int new_dimension = this->getSearchedMediaVectorDimension();

	Media**auxiliar_media_vector;
	auxiliar_media_vector = 0;
	auxiliar_media_vector = new Media*[new_dimension + 1];
	if(auxiliar_media_vector == 0){

		cerr  << "It's impossible to save memory in the Heap." << endl;
		exit (-1);
	}

	for(int index2 = 0; index2 <= new_dimension; index2++){

		auxiliar_media_vector[index2] = 0;
	}

	for(int index = 0; index < this->getSearchedMediaVectorDimension(); index++){

		auxiliar_media_vector[index] = this->searched_media_vector[index];
		this->searched_media_vector[index] = 0;
	}

	delete [] this->searched_media_vector;

	this->searched_media_vector= auxiliar_media_vector;

	auxiliar_media_vector = 0;

	this->searched_media_vector_dimension++;
}

void User::likeAFavouriteMedia(Media *media_to_like){

	this->augmentativeFavouriteMediaResize();

	this->favourite_media_vector[this->getFavouriteMediaVectorDimension() - 1] = media_to_like;
}

void User::deleteMediaFromFavouriteMedia(int favourite_media_selected_to_delete){

	Media *aux_media = 0;
	aux_media = new Media();
	if(aux_media == 0){

		cerr << "It's not possible to save memory in the heap." << endl;
		exit (-1);
	}

	aux_media = this->favourite_media_vector[this->getFavouriteMediaVectorDimension() - 1];
	this->favourite_media_vector[this->getFavouriteMediaVectorDimension() - 1] = this->favourite_media_vector[favourite_media_selected_to_delete];
	this->favourite_media_vector[favourite_media_selected_to_delete] = aux_media;

	this->disminutiveFavouriteMediaResize();
}

void User::augmentativeFavouriteMediaResize(){

//cout << DEBUG << "debug: getting in the augmentative Media resize of the class User 1" << RESTORE << endl;

	int new_dimension = this->getFavouriteMediaVectorDimension();

	Media**auxiliar_media_vector;
	auxiliar_media_vector = 0;
	auxiliar_media_vector = new Media*[new_dimension + 1];
	if(auxiliar_media_vector == 0){

		cerr  << "It's impossible to save memory in the Heap." << endl;
		exit (-1);
	}

	for(int index2 = 0; index2 <= new_dimension; index2++){

		auxiliar_media_vector[index2] = 0;
	}

	for(int index = 0; index < this->getFavouriteMediaVectorDimension(); index++){

		auxiliar_media_vector[index] = this->favourite_media_vector[index];
		this->favourite_media_vector[index] = 0;
	}

	delete [] this->favourite_media_vector;

	this->favourite_media_vector= auxiliar_media_vector;

	auxiliar_media_vector = 0;

	this->favourite_media_vector_dimension++;
}

void User::disminutiveFavouriteMediaResize(){

	int new_dimension = this->getFavouriteMediaVectorDimension();

	Media**auxiliar_media_vector;
	auxiliar_media_vector = 0;
	auxiliar_media_vector = new Media*[new_dimension];
	if(auxiliar_media_vector == 0){

		cerr  << "It's impossible to save memory in the Heap." << endl;
		exit (-1);
	}

	for(int index2 = 0; index2 <= new_dimension; index2++){

		auxiliar_media_vector[index2] = 0;
	}

	for(int index = 0; index < this->getFavouriteMediaVectorDimension() - 1; index++){

		auxiliar_media_vector[index] = this->favourite_media_vector[index];
		this->favourite_media_vector[index] = 0;
	}

	delete [] this->favourite_media_vector;

	this->favourite_media_vector= auxiliar_media_vector;

	auxiliar_media_vector = 0;

	this->favourite_media_vector_dimension--;
}
