
#include <iostream>
#include <string>
#include <stdlib.h>
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
#include "Normal.h"

Normal::~Normal(){

//cout << DEBUG << "debg: getting in the default constructo of the class normaul user" << RESTORE << endl;

	this->user_media_average_punctuation = 0;

	for(int index = 0; index < this->favourite_dimension; index++){

		this->favourite_media_user_vector[index] = 0;
	}

	this->favourite_dimension = 0;

	delete []this->favourite_media_user_vector;
	this->favourite_media_user_vector = 0;
}

void Normal::setUserMediaAveragePunctuation(float new_average_punctuation){

//cout << DEBUG << "debg: getting in the setUserMediaAveragePunctuation" << RESTORE << endl;

	this->user_media_average_punctuation = new_average_punctuation;
}

float Normal::getUserMediaAveragePunctuation(){

//cout << DEBUG << "debg: getting in the getUserMediaAveragePunctuation" << RESTORE << endl;

	return this->user_media_average_punctuation;
}

unsigned int Normal::getFavouriteMediaVectorDimension(){

//cout << DEBUG << "debg: getting in the getFavouriteMediaVectorDimension" << RESTORE << endl;

	return this->favourite_dimension;
}

void Normal::likeAMedia(Media *liked_media){

//cout << DEBUG << "debg: getting in the likeAMedia" << RESTORE << endl;
//cout << DEBUG << "debug: did we did correctly the assignment (pre)?: " << this->favourite_media_user_vector[this->getFavouriteMediaVectorDimension()] << RESTORE << endl;
	this->favourite_media_user_vector[this->getFavouriteMediaVectorDimension()] = liked_media;
//cout << DEBUG << "debug: value of last media: " << this->favourite_media_user_vector[this->getFavouriteMediaVectorDimension()] << RESTORE << endl;

	this->augmentativeFavouriteMediaResize();
cout << DEBUG << "debug: value of last media in dislike (Aresize): " << this->favourite_media_user_vector[this->getFavouriteMediaVectorDimension() - 1] << RESTORE << endl;
}

void Normal::dislikeAMedia(unsigned int media_square_to_dislike){

//cout << DEBUG << "debug: getting in the dislikeAMedia" << RESTORE << endl;


	Media *auxiliar_media = 0;
	auxiliar_media = new Media();
	
//cout << DEBUG << "debug: value of last media in dislike: " << this->favourite_media_user_vector[this->getFavouriteMediaVectorDimension() - 1] << RESTORE << endl;

	auxiliar_media = this->favourite_media_user_vector[this->getFavouriteMediaVectorDimension() - 1];
/*cout << morado << "debug: value of auxiliar_media: " << auxiliar_media << RESTORE << endl;
cout << morado << "debug: this->favourite_media_user_vector[this->getFavouriteMediaVectorDimension() - 1]: " << this->favourite_media_user_vector[this->getFavouriteMediaVectorDimension() - 1] << RESTORE << endl;
cout << morado << "debug: first assignment done" << RESTORE << endl;
*/
	this->favourite_media_user_vector[this->getFavouriteMediaVectorDimension() - 1] = this->favourite_media_user_vector[media_square_to_dislike];
/*cout << verde << "debug: value of this->favourite_media_user_vector[this->getFavouriteMediaVectorDimension() - 1]: " << this->favourite_media_user_vector[this->getFavouriteMediaVectorDimension() - 1] << RESTORE << endl;
cout << verde << "debug: value of this->favourite_media_user_vector[media_square_to_dislike]: " << this->favourite_media_user_vector[media_square_to_dislike] << RESTORE << endl;
cout << verde << "debug: second assignment done" << RESTORE << endl;*/

	this->favourite_media_user_vector[media_square_to_dislike] = auxiliar_media;
/*cout << cyan << "debug: value this->favourite_media_user_vector[media_square_to_dislike]: " << this->favourite_media_user_vector[media_square_to_dislike] << RESTORE << endl;
cout << cyan << "debug: value auxiliar_media: " << auxiliar_media << RESTORE << endl;
*/
//cout << DEBUG << "debug: value of last media in dislike: " << this->favourite_media_user_vector[this->getFavouriteMediaVectorDimension() - 1] << RESTORE << endl;


	//delete this->favourite_media_user_vector[this->getFavouriteMediaVectorDimension()];

	this->diminutiveFavouriteMediaResize();
}

void Normal::printFavouriteMedia(){

//cout << DEBUG << "debg: getting in the printFavouriteMedia" << RESTORE << endl;

//cout << DEBUG << "debug: value of the favourite media vecto rdimension: " << this->getFavouriteMediaVectorDimension() << RESTORE << endl;
//cout << DEBUG << "debug: value of the pointer to emdia of the first square: " << this->favourite_media_user_vector[this->getFavouriteMediaVectorDimension()] << RESTORE << endl;

	cout << USER << "Favourite media of your profile: " << RESTORE << endl;
	if(this->getFavouriteMediaVectorDimension() > 0){
//cout << verde << "debug: value fo the favourite media vector dimension: " << this->getFavouriteMediaVectorDimension() << RESTORE << endl;
		for(int index = 0; index < this->getFavouriteMediaVectorDimension(); index++){
	
//cout << DEBUG << "debug: getting in the loop of the print favourite media" << RESTORE << endl;
			this->favourite_media_user_vector[index]->print();
		}
	}
//cout << DEBUG << "debug: gettting out of printing the favourite media." << RESTORE << endl;
}

void Normal::printUser(){

//cout << DEBUG << "debg: getting in the print of the class normal user" << RESTORE << endl;

	this->User::printUser();
//cout << verde << "debug: hey you whatsup" << RESTORE << endl;
	cout << USER << "Yout favourite media is/are: " << RESTORE << endl;
	this->printFavouriteMedia();
//cout << verde << "debug: hey you whatsup" << RESTORE << endl;
	this->calculateTheMediaAveragePunctuation();
	cout << USER << "The value of the average of your favourte medias punctuation is: " << this->getUserMediaAveragePunctuation() << RESTORE << endl;
}

void Normal::calculateTheMediaAveragePunctuation(){

//cout << DEBUG << "debg: getting in the calculateTheMediaAveragePunctuation" << RESTORE << endl;

	float media = 0;
	float all_punctuations = 0;

	if(this->getFavouriteMediaVectorDimension() > 0){

		for(int index = 0; index < this->getFavouriteMediaVectorDimension(); index++){

			all_punctuations = all_punctuations + this->favourite_media_user_vector[index]->getRating();
		}

		media = all_punctuations / this->getFavouriteMediaVectorDimension();
		this->setUserMediaAveragePunctuation(media);
	}

//cout << DEBUG << "debug: getting out of the calculating the average" << RESTORE << endl;
}

void Normal::augmentativeFavouriteMediaResize(){

//cout << DEBUG << "debg: getting in the augmentativeFavouriteMediaResize" << RESTORE << endl;

//cout << DEBUG << "DEUBG: TODO EN MAYUSCULAS: " << this->favourite_media_user_vector[this->getFavouriteMediaVectorDimension()] << RESTORE << endl;

	int new_dimension = this->getFavouriteMediaVectorDimension();

	Media **auxiliar_media_vector;
	auxiliar_media_vector = 0;
	auxiliar_media_vector = new Media*[new_dimension + 1];
	if(auxiliar_media_vector == 0){

		cerr  << "It's impossible to save memory in the Heap." << endl;
		exit (-1);
	}

	for(int index2 = 0; index2 <= new_dimension; index2++){

		auxiliar_media_vector[index2] = 0;
	}

//cout << amarillo << "DEUBG: haha: " << this->favourite_media_user_vector[this->getFavouriteMediaVectorDimension()] << RESTORE << endl;

	for(int index = 0; index <= this->getFavouriteMediaVectorDimension(); index++){

		auxiliar_media_vector[index] = this->favourite_media_user_vector[index];
		this->favourite_media_user_vector[index] = 0;
//cout << amarillo << "debug: amo a ve cuanto vale ar aurzilia (deberia tener un valor): " << auxiliar_media_vector[index] << RESTORE << endl;
	}

//cout << DEBUG << "DEUBG: TODO EN MAYUSCULAS2: " << this->favourite_media_user_vector[this->getFavouriteMediaVectorDimension()] << RESTORE << endl;

	delete [] this->favourite_media_user_vector;

	this->favourite_media_user_vector = auxiliar_media_vector;

	auxiliar_media_vector = 0;
	this->favourite_dimension++;
}

void Normal::diminutiveFavouriteMediaResize(){

//cout << DEBUG << "debg: getting in the diminutiveFavouriteMediaResize" << RESTORE << endl;

	int new_dimension = this->getFavouriteMediaVectorDimension();

	Media **auxiliar_media_vector;
	auxiliar_media_vector = 0;
	auxiliar_media_vector = new Media*[new_dimension];
	if(auxiliar_media_vector == 0){

		cerr  << "It's impossible to save memory in the Heap." << endl;
		exit (-1);
	}

	for(int index2 = 0; index2 < new_dimension; index2++){

		auxiliar_media_vector[index2] = 0;
	}

	for(int index = 0; index < this->getFavouriteMediaVectorDimension(); index++){
//cout << DEBUG << "debugg: index " << index << RESTORE << endl;
//cout << DEBUG << "debug: value of the  pointer to media of favourites: " << this->favourite_media_user_vector[index] << RESTORE << endl;
//cout << DEBUG << "debug: value of the  pointer to media of auxiliar: " << auxiliar_media_vector[index] << RESTORE << endl;

		auxiliar_media_vector[index] = this->favourite_media_user_vector[index];
		this->favourite_media_user_vector[index] = 0;
	}

//cout << DEBUG << "DEBUG: chacho es aqui." << RESTORE << endl;
	delete [] this->favourite_media_user_vector;
//cout << DEBUG << "DEBUG: chacho es aqui." << RESTORE << endl;
	this->favourite_media_user_vector = auxiliar_media_vector;

	auxiliar_media_vector = 0;

	this->favourite_dimension--;
}