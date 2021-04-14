#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <iomanip>
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"
#define RESTORE "\033[1;0m"
#define amarillo "\033[1;43m"
#define morado "\033[1;45m"
#define cyan "\033[1;46m"
#define verde "\033[1;42m"

#include "Media.h"

using namespace std;

Media::Media(){

//cout << DEBUG << "debug: getting in the default constructor of the class media" << RESTORE << endl;

	this->ID_media = 0;
	this->title = "NULL";
	this->genre = "NULL";
	this->full_duration = 0;
	this->publishing_date = "NULL";
	this->minimum_age_recomendation = 0;
	this->description = "NULL";
	this->views = 0;
	this->rating = 0;
	this->likes = 0;

	this->comment_list_dimension = 0;

	this->comment_list = 0;
	this->comment_list = new Comment*[1];
	if(this->comment_list == 0){

		cerr << "It's impossible to save memory in the Heap" << endl;
		exit (-1);
	}

	this->punctuation_list_dimension = 0;

	this->punctuation_list = 0;
	this->punctuation_list = new Punctuation*[1];
	if(this->punctuation_list == 0){

		cerr << "It's impossible to save memory in the Heap" << endl;
		exit (-1);
	}
}

Media::Media(unsigned int new_ID, string new_title, string new_genre, unsigned int new_duration, string new_publishing_date, unsigned int new_age_recomendation, string new_description, int new_views, float new_rating, int new_likes){

//cout << DEBUG << "debug: getting in contructor by parameters fo the class media" << RESTORE << endl;

	this->ID_media = new_ID;
	this->title = new_title;
	this->genre = new_genre;
	this->full_duration = new_duration;
	this->publishing_date = new_publishing_date;
	this->minimum_age_recomendation = new_age_recomendation;
	this->description = new_description;
	this->views = new_views;
	this->rating = new_rating;
	this->likes = new_likes;

	this->comment_list_dimension = 0;

	this->comment_list = 0;
	this->comment_list = new Comment*[1];
	if(this->comment_list == 0){

		cerr << "It's impossible to save memory in the Heap" << endl;
		exit (-1);
	}

	this->punctuation_list_dimension = 0;

	this->punctuation_list = 0;
	this->punctuation_list = new Punctuation*[1];
	if(this->punctuation_list == 0){

		cerr << "It's impossible to save memory in the Heap" << endl;
		exit (-1);
	}
}

Media::~Media(){

//cout << DEBUG << "debug: getting in the default destructor of the class media" << RESTORE << endl;

	this->ID_media = 0;
	this->title = "NULL";	
	this->genre = "NULL";
	this->full_duration = 0;
	this->publishing_date = "NULL";
	this->minimum_age_recomendation = 0;
	this->description = "NULL";
	this->views = 0;
	this->rating = 0;
	this->likes = 0;
	//this->comment_list_dimension = 0;
	
//cout << DEBUG << "debug: deleting the pointer to the comment vector." << RESTORE << endl;

	for(int index = 0; index < this->comment_list_dimension; index++){

		delete this->comment_list[index];
		this->comment_list[index] = 0;
	}

//cout << DEBUG << "debug: deleted all the pointers to comments" << RESTORE << endl;

	delete []this->comment_list;
	this->comment_list = 0;


	for(int index2 = 0; index2 < this->punctuation_list_dimension; index2++){

		delete this->punctuation_list[index2];
		this->punctuation_list[index2] = 0;
	}

//cout << DEBUG << "debug: deleted all the pointers to comments" << RESTORE << endl;

	delete []this->punctuation_list;
	this->punctuation_list = 0;

//cout << DEBUG << "debug: getting out of the media destructor." << RESTORE << endl;
}

void Media::setMedia_ID(int new_media_id){

//cout << DEBUG << "debug: getting in setmedia" << RESTORE << endl;

	this->ID_media = new_media_id;
}

void Media::setTitle(string new_title){

//cout << DEBUG << "debug: getting in settitle" << RESTORE << endl;

	this->title = new_title;
}

void Media::setGenre(string new_genre){

//cout << DEBUG << "debug: getting in setgenre" << RESTORE << endl;

	this->genre = new_genre;
}

void Media::setDuration(unsigned int new_media_duration){

//cout << DEBUG << "debug: getting in setduration" << RESTORE << endl;

	this->full_duration = new_media_duration;
}

void Media::setPublishing_date(string new_publishing_date){

//cout << DEBUG << "debug: getting in setpublishingdate" << RESTORE << endl;

	this->publishing_date = new_publishing_date;
}

void Media::setAge_recommendations(unsigned int new_minimum_age){

//cout << DEBUG << "debug: getting in setagerecommendation" << RESTORE << endl;

	this->minimum_age_recomendation = new_minimum_age;
}

void Media::setDescription(string new_description){

//cout << DEBUG << "debug: getting in setdescription" << RESTORE << endl;

	this->description = new_description;
}

void Media::setViews(int new_views){

//cout << DEBUG << "debug: getting in setviews" << RESTORE << endl;

	this->views = new_views;
}

void Media::setRating(float new_rating){

//cout << DEBUG << "debug: getting in setrating" << RESTORE << endl;

	this->rating = new_rating;
}

void Media::setLikes(int new_likes_number){

//cout << DEBUG << "debug: getting in setlikes" << RESTORE << endl;

	this->likes = new_likes_number;
}

unsigned int Media::getMedia_Id(){

//cout << DEBUG << "debug: getting in getmediaid" << RESTORE << endl;

	return this->ID_media;
}

string Media::getTitle(){

//cout << DEBUG << "debug: getting in gettitle" << RESTORE << endl;

	return this->title;
}

string Media::getGenre(){

//cout << DEBUG << "debug: getting in getgenre" << RESTORE << endl;

	return this->genre;
}

unsigned int Media::getFull_duration(){

//cout << DEBUG << "debug: getting in getfull duration" << RESTORE << endl;

	return this->full_duration;
}

string Media::getPublishing_date(){

//cout << DEBUG << "debug: getting in getpusblishing date" << RESTORE << endl;

	return this->publishing_date;
}

unsigned int Media::getAge_recommendation(){

//cout << DEBUG << "debug: getting in getagereocmmendation" << RESTORE << endl;

	return this->minimum_age_recomendation;
}

//string Media::getDescription(){

cout << DEBUG << "debug: getting in getdescription" << RESTORE << endl;

	return this->description;
}

int Media::getViews(){

//cout << DEBUG << "debug: getting in getviews" << RESTORE << endl;

	return this->views;
}

float Media::getRating(){

//cout << DEBUG << "debug: getting in getrating" << RESTORE << endl;

	return this->rating;
}

int Media::getLikes(){

//cout << DEBUG << "debug: getting in the getLikes" << RESTORE << endl;

	return this->likes;
}

unsigned int Media::getCommentListDimension(){

//cout << DEBUG << "debug: getting in the getCommentListDimension" << RESTORE << endl;

	return this->comment_list_dimension;
}

unsigned int Media::getPunctuationListDimension(){

//cout << DEBUG << "debug: getting in the getPunctuationListDimension" << RESTORE << endl;

	return this->punctuation_list_dimension;
}

void Media::insertComment(Comment *new_comment){

//cout << DEBUG << "debug: getting in the insert comment in the list of the class media" << RESTORE << endl;

//cout << DEBUG << "debug: something wrong is happening here." << RESTORE << endl;

//cout << DEBUG << "debug: comment list dimension value: " << this->getCommentListDimension() << RESTORE << endl;

	if(this->getCommentListDimension() == 0){
//cout << amarillo << "sap boi" << RESTORE << endl;
		new_comment->setCommentID(1);

	}else {
//cout << amarillo << "sap boi" << RESTORE << endl;
		new_comment->setCommentID(this->comment_list[this->getCommentListDimension() - 2]->getCommentID() + 1);
	}
//cout << DEBUG << "buano que tal tio" << RESTORE << endl;

	this->augmentativeCommentResize();
//cout << DEBUG << "buano que tal tio 2" << RESTORE << endl;

	this->comment_list[this->getCommentListDimension() - 1] = new_comment;
//cout << DEBUG << "buano que tal tio 3" << RESTORE << endl;
	new_comment = 0;
	delete new_comment;
//cout << DEBUG << "buano que tal tio 4" << RESTORE << endl;
//cout << verde << "debug: comments list dimension: " << this->comment_list_dimension - 1 << RESTORE << endl;

//cout << DEBUG << "debug getting out of the InsertComment of the media class." << RESTORE << endl;
	
}

void Media::insertPunctuation(Punctuation *new_punctuation){

//cout << DEBUG << "debug: getting in the insertPunctuation." << RESTORE << endl;

	this->augmentativePunctuationResize();

	this->punctuation_list[this->getPunctuationListDimension() - 1] = new_punctuation;
}

void Media::deleteCommentFromListByID(unsigned int comment_id_to_delete){

//cout << DEBUG << "debug: getting in the delete comment from comment list method" << RESTORE << endl;

	bool found_the_comment = false;

	for(int index = 0; index < this->getCommentListDimension() && found_the_comment == false; index++){

		if(this->comment_list[index]->getCommentID() == comment_id_to_delete){

//cout << DEBUG << "debug: gettign in the lopp of the method deleteCommentFromListByID." << RESTORE << endl;

			Comment *auxiliar_comment;

//cout << DEBUG << "debug: value of the pointer to comment that is in the las comment vector square: " << this->comment_list[this->getCommentListDimension()] << RESTORE << endl;


//cout << cyan << "debug: value of the dimension of the comment list: " << this->getCommentListDimension() << RESTORE << endl;

			auxiliar_comment = this->comment_list[this->getCommentListDimension() - 1];
			this->comment_list[this->getCommentListDimension() - 1] = this->comment_list[index];
			this->comment_list[index] = auxiliar_comment;

//cout << DEBUG << "debug: value of the auxiliar pointer to comment: " << auxiliar_comment << RESTORE << endl;
//cout << DEBUG << "debug: value of the pointer to comment in the vector after the exchange that should be the same that auxiliar_comment: " << this->comment_list[index] << RESTORE << endl;

			found_the_comment = true;

			auxiliar_comment = 0;
			delete auxiliar_comment;
		}
	}

	delete this->comment_list[this->getCommentListDimension()];

	disminutiveCommentResize();
}

void Media::printCommentList(){

//cout << DEBUG << "debug: getting in the print all comments from the comment list of the class media" << RESTORE << endl;
//cout << verde << "debug: value of the comment list dimension: " << this->getCommentListDimension() << RESTORE << endl;

	for(int index = 0; index < this->getCommentListDimension(); index++){

//cout << DEBUG << "debug: value of the square when printing: " << this->comment_list[index] << RESTORE << endl;

//cout << DEBUG << "debug: getting in the loop of the print comments method." << RESTORE << endl;
		cout << "[" << index << "]" << endl;
		cout << *this->comment_list[index] << endl;
	}

	cout << endl;
}

unsigned int Media::serachCommentByID(unsigned int comment_id_to_find){

	for(int index = 0; index < this->getCommentListDimension(); index++){

		if(this->comment_list[index]->getCommentID() == comment_id_to_find){

			return this->comment_list[index]->getCommentID();
		}
	}
}



ostream& operator<<(ostream &flux, Media &media_object_to_print){

//cout << DEBUG << "debug: getting in the overloading of the operator << of the class media." << RESTORE << endl;

	flux << endl;
	flux << "Media ID: " << media_object_to_print.ID_media<< endl;
	flux << "Title: " << media_object_to_print.title << endl;
	flux << "Genre: " << media_object_to_print.genre << endl;
	flux << "Duration: " << media_object_to_print.full_duration << endl;
	flux << "Publishing date: " << media_object_to_print.publishing_date << endl;
	flux << "Recommended for higher ages than: " << media_object_to_print.minimum_age_recomendation << endl;
	flux << "Description: " << media_object_to_print.description << endl;
	flux << "Views: " << media_object_to_print.views<< endl;
	flux << "Rating: " << media_object_to_print.rating << endl;
	flux << "Likes: " << media_object_to_print.likes << endl;
	flux << "Numbers of comments: " << media_object_to_print.comment_list_dimension << endl;

	flux << "Comments of the media " << media_object_to_print.title << ": " << endl;

	media_object_to_print.printCommentList();
}

void Media::augmentativeCommentResize(){

//cout << DEBUG << "debug: getting in the augmentative resize of the comment list of the class media" << RESTORE << endl;

	int new_dimension = this->getCommentListDimension();

	Comment **auxiliar_comment;
	auxiliar_comment = 0;
	auxiliar_comment = new Comment*[new_dimension + 1];
	if(auxiliar_comment == 0){

		cerr  << "It's impossible to save memory in the Heap." << endl;
		exit (-1);
	}

	for(int index2 = 0; index2 <= new_dimension; index2++){

		auxiliar_comment[index2] = 0;
	}

	for(int index = 0; index <= this->getCommentListDimension(); index++){

		auxiliar_comment[index] = this->comment_list[index];
		this->comment_list[index] = 0;
//cout << DEBUG << "debug: comments pointers assigments." << RESTORE << endl;
	}
//cout << DEBUG << "debug: getting out of the comments pointers assigments." << RESTORE << endl;

	delete [] this->comment_list;
//cout << DEBUG << "debug: this->comment_list: " << this->comment_list << endl;
//cout << DEBUG << "debug: auxiliar_comment: " << auxiliar_comment << endl;
	this->comment_list = auxiliar_comment;
//cout << DEBUG << "debug: this->comment_list: " << this->comment_list << endl;
//cout << DEBUG << "debug: auxiliar_comment: " << auxiliar_comment << endl;

	auxiliar_comment = 0;

	this->comment_list_dimension++;
//cout << DEBUG << "debug:getting out of the augmentative resize." << RESTORE << endl;

}

void Media::disminutiveCommentResize(){

//cout << DEBUG << "debug: getting in the diminutive resize of the comment list of the class media" << RESTORE << endl;

	int new_dimension = this->getCommentListDimension();

	Comment **auxiliar_comment;
	auxiliar_comment = 0;
	auxiliar_comment = new Comment*[new_dimension];
	if(auxiliar_comment == 0){

		cerr  << "It's impossible to save memory in the Heap." << endl;
		exit (-1);
	}

	for(int index2 = 0; index2 <= new_dimension; index2++){

		auxiliar_comment[index2] = 0;
	}

	for(int index = 0; index < this->getCommentListDimension(); index++){

		auxiliar_comment[index] = this->comment_list[index];
		this->comment_list[index] = 0;
	}
//cout << DEBUG << "debug: getting out the diminutive comment resize 2nd loop." << RESTORE << endl;

	delete [] this->comment_list;

//cout << DEBUG << "debug: deleted this->comment_list" << RESTORE << endl;

	this->comment_list = auxiliar_comment;

	auxiliar_comment = 0;

	this->comment_list_dimension--;
//cout << DEBUG << "debug: getting out the diminutive comment resize." << RESTORE << endl;
}


void Media::augmentativePunctuationResize(){

//cout << DEBUG << "debug: getting in the punctuation_list augmentative resize" << RESTORE << endl;

	int new_dimension = this->getPunctuationListDimension();

	Punctuation **auxiliar_punctuation;
	auxiliar_punctuation = 0;
	auxiliar_punctuation = new Punctuation*[new_dimension + 1];
	if(auxiliar_punctuation == 0){

		cerr  << "It's impossible to save memory in the Heap." << endl;
		exit (-1);
	}

	for(int index2 = 0; index2 <= new_dimension; index2++){

		auxiliar_punctuation[index2] = 0;
	}

	for(int index = 0; index < this->getCommentListDimension(); index++){

		auxiliar_punctuation[index] = this->punctuation_list[index];
		this->punctuation_list[index] = 0;
//cout << DEBUG << "debug: comments pointers assigments." << RESTORE << endl;
	}
//cout << DEBUG << "debug: getting out of the comments pointers assigments." << RESTORE << endl;

	delete [] this->punctuation_list;
//cout << DEBUG << "debug: this->comment_list: " << this->comment_list << endl;
//cout << DEBUG << "debug: auxiliar_comment: " << auxiliar_comment << endl;
	this->punctuation_list = auxiliar_punctuation;
//cout << DEBUG << "debug: this->comment_list: " << this->comment_list << endl;
//cout << DEBUG << "debug: auxiliar_comment: " << auxiliar_comment << endl;

	auxiliar_punctuation = 0;

	this->punctuation_list_dimension++;
//cout << DEBUG << "debug:getting out of the augmentative punctuation_list resize." << RESTORE << endl;
}



void Media::orderCommentsByID(){

	int index2 = 0;
	bool change = true;
	int auxiliar = 0;

	for(int index = 1; index < this->getCommentListDimension(); index++){

		change = false;
//cout << endl << "debug: index value: " << index << endl;
	
		for(index2 = this->getCommentListDimension() - 1; index2 > index && change == false; index2--){

//cout << "debug: index2 value: " << index2 << endl;
//cout << endl << "debug: this->comment_list[index2] comment id value: " << this->comment_list[index2]->getCommentID() << endl;
//cout << endl << "debug: this->comment_list[index2 - 1] comment id value: " << this->comment_list[index2 - 1]->getCommentID() << endl;
			if(this->comment_list[index2]->getCommentID() > this->comment_list[index2 - 1]->getCommentID()){

				change = true;

				auxiliar = this->comment_list[index2]->getCommentID();
				this->comment_list[index2]->setCommentID(this->comment_list[index2 - 1]->getCommentID());
				this->comment_list[index2 - 1]->setCommentID(auxiliar);
			}
		}
	}
}

void Media::print(){

//cout << DEBUG << "debug: getting in the overloading of the operator << of the class media." << RESTORE << endl;

	cout << endl;
	cout << "Media ID: " << this->ID_media<< endl;
	cout << "Title: " << this->title << endl;
	cout << "Genre: " << this->genre << endl;
	cout << "Duration: " << this->full_duration << endl;
	cout << "Publishing date: " << this->publishing_date << endl;
	cout << "Recommended for higher ages than: " << this->minimum_age_recomendation << endl;
	cout << "Description: " << this->description << endl;
	cout << "Views: " << this->views<< endl;
	cout << "Rating: " << this->rating << endl;
	cout << "Likes: " << this->likes << endl;
	cout << "Numbers of comments: " << this->comment_list_dimension << endl;

	cout << "Comments of the media " << this->title << ": " << endl;

	this->printCommentList();
}
