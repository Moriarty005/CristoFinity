#include <iostream>
#include <stdlib.h>
#include <iomanip>
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"
#define RESTORE "\033[1;0m"
#define amarillo "\033[1;43m"
#define morado "\033[1;45m"
#define cyan "\033[1;46m"
#define verde "\033[1;42m"

#include "CristoFinity.h"

using namespace std;

CristoFinity::CristoFinity(){
//cout << DEBUG << "debug: We're going to create the catalog and the users vector." << RESTORE << endl;

	this->users_vector_dimension = 0;
	this->user_vector = 0;
	this->user_vector = new User*[1];
	if(user_vector == 0){
		cerr << "It's unable to save this memory." << endl;
		exit (-1);
	}

	this->catalog_dimension = 0;
	this->catalog = 0;
	this->catalog = new Media*[1];
	if(catalog == 0){
		cerr << "It's unable to save the memory." << endl;
		exit (-1);
	}
//cout << DEBUG << "debug: Catalog and users vector created succesfully" << RESTORE << endl;
}

CristoFinity::~CristoFinity(){

//cout << DEBUG << "debug: Getting in the destructor of class CristoFinity" << RESTORE << endl;

	for(int index = 0; index < this->catalog_dimension; index++){

		this->catalog[index] = 0;
	}
//cout << verde << "debug:aqui tio" << RESTORE << endl;
	//delete []this->catalog;
//cout << verde << "debug:aqui tio 1" << RESTORE << endl;
	for(int index2 = 0; index2 < this->users_vector_dimension; index2++){

		this->user_vector[index2] = 0;
	}
//cout << verde << "debug:aqui tio 2" << RESTORE << endl;
	//delete []this->user_vector;
//cout << verde << "debug:aqui tio 3" << RESTORE << endl;
	this->actual_user = 0;
	delete this->actual_user;
//cout << verde << "debug:aqui tio 4" << RESTORE << endl;
//cout << DEBUG << "debug: Getting out of the destructor of class CristoFinity." << RESTORE << endl;
}

unsigned int CristoFinity::getUserVectorDimension(){

	 return this->users_vector_dimension;
}

unsigned int CristoFinity::getCatalogDimension(){
	 return this->catalog_dimension;
}

void CristoFinity::LogInSystem(){

//cout << DEBUG << "debug: getting in the login method" << RESTORE << endl;

	string user_login;

	cout << morado << "Enter your login: " << RESTORE;
	getline(cin, user_login);

	if(this->searchUserByLogin(user_login) == 0){

		cout << DEBUG << "Sorry, but this user does not exists." << RESTORE << endl;
		this->LogInSystem();
	}else {

		this->actual_user = this->searchUserByLogin(user_login);
		cout << USER << endl << "Login successfully!" << RESTORE << endl;
	}
}

void CristoFinity::commentAMedia(){

//cout << DEBUG << "debug: getting in comment a media." << RESTORE << endl;

	int option = 0;
	int square_to_comment = 0;
	int media_id = 0;
	string media_name;
//cout << DEBUG << "debug: aqui da bro" << RESTORE << endl;
	cout << USER << "Do you want to search the media by ...?" << RESTORE << endl;
	cout << USER << "[0]\t By the Id of the media" << RESTORE << endl;
	cout << USER << "[1]\t By the name of the media" << RESTORE << endl;
	cin >> option;

	if(option == 0){

		cout << USER << "Ok! Which media do you want to comment?" << RESTORE << endl;
		cin >> media_id;
		square_to_comment = this->searchMediaByID(media_id);

	}else if(option == 1){

		cout << USER << "Ok! Which media do you want to comment?" << RESTORE << endl;
		getline(cin, media_name);
		square_to_comment = this->searchMediaByName(media_name);
	}

	Comment *aux_comment;
	aux_comment = this->actual_user->writeComment();

	Punctuation *aux_points;
	aux_points = this->actual_user->giveAPunctuation();

//cout << verde << "amono" << RESTORE << endl;
	this->catalog[square_to_comment]->Media::insertComment(aux_comment);
//cout << verde << "debug: da aqui el maldito error" << RESTORE << endl;
	this->catalog[square_to_comment]->Media::insertPunctuation(aux_points);
//cout << DEBUG << "debug: aqui da bro" << RESTORE << endl;
}

void CristoFinity::deleteACommentFromMedia(){

	int option = 0;
	int square_to_delete = 0;
	int comment_id = 0;
	int media_id = 0;
	string media_name = 0;

	cout << USER << "Do you want to search the media by ...?" << RESTORE << endl;
	cout << USER << "[0]\t By the Id of the media" << RESTORE << endl;
	cout << USER << "[1]\t By the name of the media" << RESTORE << endl;
	cin >> option;

	if(option == 0){
		cout << USER << "Ok! Which media do you want to delete?" << RESTORE << endl;
		cin >> media_id;
		square_to_delete = this->searchMediaByID(media_id);

	}else if(option == 1){
		cout << USER << "Ok! Which media do you want to delete?" << RESTORE << endl;
		getline(cin, media_name);
		square_to_delete = this->searchMediaByName(media_name);
	}

	cout << USER << "Which comment do you want to delete?" << RESTORE << endl;
	this->catalog[square_to_delete]->printCommentList();

	cin >> comment_id;

	if(Administrator *a = dynamic_cast<Administrator*>(this->actual_user)){
		this->catalog[square_to_delete]->deleteCommentFromListByID(comment_id);
	}
	if(Normal *n = dynamic_cast<Normal*>(this->actual_user)){

		if(this->actual_user->getId_user() == this->catalog[square_to_delete]->comment_list[comment_id - 1]->getWriter()){

				this->catalog[square_to_delete]->deleteCommentFromListByID(comment_id);
		}else{
			cout << DEBUG << "That commet is not yours!" << RESTORE << endl;
		}
	}
}


unsigned int  CristoFinity::searchMediaByName(string name_to_find){

	string new_string;

	cout << USER << "Introduce the name of the media you want to find: " << RESTORE << endl;
	getline(cin, new_string);

	for(int index = 0; index < this->getCatalogDimension(); index++){

		if(new_string == this->catalog[index]->getTitle()){

			return index;
			this->actual_user->setMediaToSearched(this->catalog[index]);
		}
	}
}

unsigned int CristoFinity::searchMediaByID(unsigned int id_to_find){

	int new_media_id = 0;

	cout << USER << "Introduce the media id you want to find: " << RESTORE << endl;
	cin >> new_media_id;

	for(int index = 0; index < this->getCatalogDimension(); index++){

		if(new_media_id == this->catalog[index]->getMedia_Id()){

			return index;
			this->actual_user->setMediaToSearched(this->catalog[index]);
		}
	}
}

User* CristoFinity::searchUserByLogin(string user_id_to_find){

	for(int index = 0; index < this->getUserVectorDimension(); index++){

		if(this->user_vector[index]->getId_user() == user_id_to_find){

			return this->user_vector[index];
		}
	}
}

void CristoFinity::AddUserInVector(){

	int option = 0;

	cout << USER << "What type of user is?" << RESTORE << endl;
	cout << USER << "[1]\t Admin" << RESTORE << endl;
	cout << USER << "[2]\t Normal" << RESTORE << endl;

	cout << USER << "Option: " << RESTORE << endl;
	cin >> option;

	switch(option){
		case 1:

			this->augmentativeUsersResize();
			this->user_vector[this->getUserVectorDimension() - 1] = this->createAnAdminUser();
		break;

		case 2:

			this->augmentativeUsersResize();
			this->user_vector[this->getUserVectorDimension() - 1] = this->createANormalUser();
		break;
	}
}

Administrator* CristoFinity::createAnAdminUser(){

	string new_id;
	string new_name;
	string new_surname;
	string new_photo;
	int option = 0;


	Administrator *new_admin = 0;
	new_admin = new Administrator();
	if(new_admin == 0){

		cerr << "It's impossible to save memory on the heap." << RESTORE << endl;
		exit (-1);
	}

	
	cout << "Introduce the new users login: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_id);
	new_admin->User::setId_user(new_id);

	cout << "Introduce the new users name: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_name);
	new_admin->User::setUserName(new_name);

	cout << "Introduce the new users surname: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_surname);
	new_admin->User::setUserSurName(new_surname);

	cout << "Introduce the new users photo: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_photo);
	new_admin->User::setUserURL(new_photo);
		
	
	cout << USER << "Is this new admin one of the creators of this App?" << RESTORE << endl;
	cout << USER << "[1]\t Yes" << RESTORE << endl;
	cout << USER << "[2]\t No" << RESTORE << endl;
	cout << USER << "Answer: " << RESTORE << endl;
	cin >> option;

	if(option == 1){

		new_admin->setCreator(true);
	}else if(option == 2){

		new_admin->setCreator(false);
	}

	return new_admin;
}

Normal* CristoFinity::createANormalUser(){

	string new_id;
	string new_name;
	string new_surname;
	string new_photo;
	int option = 0;


	Normal *new_normal = 0;
	new_normal= new Normal();
	if(new_normal == 0){

		cerr << "It's impossible to save memory on the heap." << RESTORE << endl;
		exit (-1);
	}


	cout << "Introduce the new users login: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_id);
	new_normal->User::setId_user(new_id);
	
	cout << "Introduce the new users name: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_name);
	new_normal->User::setUserName(new_name);

	cout << "Introduce the new users surname: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_surname);
	new_normal->User::setUserSurName(new_surname);

	cout << "Introduce the new users photo: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_photo);
	new_normal->User::setUserURL(new_photo);

	return new_normal;
}

void CristoFinity::deleteUserFromVector(){

	int option = 0;

	cout << USER << "Which user do you want to delete?" << RESTORE << endl;
	this->printUsersVector();

	cout << USER << "Option: " << RESTORE;
	cin >> option;

	User *aux_user = 0;
	aux_user = new User();
	if(aux_user == 0){

		cerr << "It's impossible to save memory in the heap." << endl;
		exit (-1);
	}

	aux_user = this->user_vector[this->getUserVectorDimension() - 1];
	this->user_vector[this->getUserVectorDimension()] = this->user_vector[option];
	this->user_vector[option] = aux_user;

	this->disminutiveUsersResize();
}

void CristoFinity::print(){

//cout << DEBUG << "debug: getting in the CristoFinity print" << RESTORE << endl;

	if(Administrator *a = dynamic_cast<Administrator*>(this->actual_user)){

		this->printCatalog();
		this->printUsersVector();
	}else if(Normal *n = dynamic_cast<Normal*>(this->actual_user)){

		this->printCatalog();
	}
}

void CristoFinity::printCatalog(){

//cout << DEBUG << "debug: getting in the print catalog" << RESTORE << endl;
	for(int index = 0; index < this->getCatalogDimension(); index++){

		if(Film *f = dynamic_cast<Film*>(this->catalog[index])){

			f->print();
		}else if(Series *s = dynamic_cast<Series*>(this->catalog[index])){

			s->print();
		}else if(Videogame *v = dynamic_cast<Videogame*>(this->catalog[index])){
			
			v->print();
		}else if(Song *S = dynamic_cast<Song*>(this->catalog[index])){
			
			S->print();
		}
	}
}

void CristoFinity::printUsersVector(){

//cout << DEBUG << "debug: getting in the print users vector" << RESTORE << endl;
	for(int index = 0; index < this->getUserVectorDimension(); index++){

		cout << USER << "[" << index << "]" << RESTORE << endl;
		if(Administrator *A = dynamic_cast<Administrator*>(this->user_vector[index])){

			A->printUser();
		}else if(Normal *N = dynamic_cast<Normal*>(this->user_vector[index])){

			N->printUser();
		}
	}
}

void CristoFinity::changeUser(){

	int option = 0;

	cout << USER << "Do you want to use other account? Well those are the one that are avilable: " << RESTORE << endl;
	this->printUsersVector();

	cout << USER << "Which one do you to change for?" << RESTORE;
	cin >> option;

	this->actual_user = this->user_vector[option];
}

void CristoFinity::changeUserInfo(){

	string new_name;
	string new_surname;
	string new_photo;


	cout << amarillo << "Which is your new name? " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_name);
	this->actual_user->setUserName(new_name);

	cout << amarillo << "Which is your new surname? " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_surname);
	this->actual_user->setUserSurName(new_surname);

	cout << amarillo << "Which is your new photo? " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_photo);
	this->actual_user->setUserURL(new_photo);

	cout << amarillo "Done!" << RESTORE << endl;
}

void CristoFinity::addMediaToCatalog(){

	int type = 0;

	cout << morado << "What type of media do you want to create?" << RESTORE << endl;
	cout << morado << "[1]\t a film" << RESTORE << endl;
	cout << morado << "[2]\t a serie" << RESTORE << endl;
	cout << morado << "[3]\t a videogame" << RESTORE << endl;
	cout << morado << "[4]\t a Song" << RESTORE << endl;

	cout << morado << "Option: " << RESTORE << endl;
	cin >> type;



	if(type == 1){

		this->augmentativeCatalogResize();
		this->catalog[this->getCatalogDimension() - 1] = this->createAFilm();
	}else if(type == 2){

		this->augmentativeCatalogResize();
		this->catalog[this->getCatalogDimension() - 1] = this->createASeries();
	}else if(type == 3){
		
		this->augmentativeCatalogResize();
		this->catalog[this->getCatalogDimension() - 1] = this->createAVideogame();
	}else if(type == 4){
		
		this->augmentativeCatalogResize();
		this->catalog[this->getCatalogDimension() - 1] = this->createASong();
	}
}

Series* CristoFinity::createASeries(){

//cout << DEBUG << "debug: getting in the create a series" << RESTORE << endl;

	Series *new_series = 0;
	new_series = new Series();
	if(new_series == 0){

		cerr << "There's no space in the heap." << endl;
		exit (-1);
	}

	if(this->getCatalogDimension() == 0){

		new_series->Media::setMedia_ID(1);

	}else {

		new_series->Media::setMedia_ID(this->catalog[this->getCatalogDimension() - 2]->getMedia_Id() + 1);
	}

	string new_title;
	string new_genre;
	unsigned int new_media_duration = 0;
	string new_publishing_date;
	unsigned int new_minimum_age = 0;
	string new_description;
	int new_views = 0;
	float new_rating = 0;
	int new_episodes = 0;
	int new_seasons = 0;
	bool new_stage = false;


	cout << USER << "Introduce the series title: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_title);
	new_series->Media::setTitle(new_title);

	cout << USER << "Introduce the series genre: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_genre);
	new_series->Media::setGenre(new_genre);

	cout << USER << "Introduce the series duration: " << RESTORE << endl;
	cin >> new_media_duration;
	new_series->Media::setDuration(new_media_duration);

	cout << USER << "Introduce the series publishing date: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_publishing_date);
	new_series->Media::setPublishing_date(new_publishing_date);

	cout << USER << "Introduce the series minimum age recommendation: " << RESTORE << endl;
	cin >> new_minimum_age;
	new_series->Media::setAge_recommendations(new_minimum_age);

	cout << USER << "Introduce the series description: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_description);
	new_series->Media::setDescription(new_description);

	cout << USER << "Introduce the series views: " << RESTORE << endl;
	cin >> new_views;
	new_series->Media::setViews(new_views);

	cout << USER << "Introduce the series rating: " << RESTORE << endl;
	cin >> new_rating;
	new_series->Media::setRating(new_rating);

	cout << USER << "Introduce the series seasons: " << RESTORE << endl;
	cin >> new_seasons;
	new_series->setSeasons(new_seasons);

	cout << USER << "Introduce the series episodes: " << RESTORE << endl;
	cin >> new_episodes;
	new_series->setEpisodes(new_episodes);

	return new_series;

}

Film* CristoFinity::createAFilm(){

//cout << DEBUG << "debug: getting in the create a series" << RESTORE << endl;

	Film *new_film = 0;
	new_film = new Film();
	if(new_film == 0){

		cerr << "There's no space in the heap." << endl;
		exit (-1);
	}

	if(this->getCatalogDimension() == 0){

		new_film->Media::setMedia_ID(1);

	}else {

		new_film->Media::setMedia_ID(this->catalog[this->getCatalogDimension() - 2]->getMedia_Id() + 1);
	}

	string new_title;
	string new_genre;
	unsigned int new_media_duration = 0;
	string new_publishing_date;
	unsigned int new_minimum_age = 0;
	string new_description;
	int new_views = 0;
	float new_rating = 0;
	string new_cast;
	string new_director;
	string new_script_team;
	string new_producer;


	cout << USER << "Introduce the film title: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_title);
	new_film->Media::setTitle(new_title);

	cout << USER << "Introduce the film genre: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_genre);
	new_film->Media::setGenre(new_genre);

	cout << USER << "Introduce the film duration: " << RESTORE << endl;
	cin >> new_media_duration;
	new_film->Media::setDuration(new_media_duration);

	cout << USER << "Introduce the film publishing date: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_publishing_date);
	new_film->Media::setPublishing_date(new_publishing_date);

	cout << USER << "Introduce the film minimum age recommendation: " << RESTORE << endl;
	cin >> new_minimum_age;
	new_film->Media::setAge_recommendations(new_minimum_age);

	cout << USER << "Introduce the film description: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_description);
	new_film->Media::setDescription(new_description);

	cout << USER << "Introduce the film views: " << RESTORE << endl;
	cin >> new_views;
	new_film->Media::setViews(new_views);

	cout << USER << "Introduce the film rating: " << RESTORE << endl;
	cin >> new_rating;
	new_film->Media::setRating(new_rating);

	cout << USER << "Introduce the film casting: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_cast);
	new_film->setCast(new_cast);

	cout << USER << "Introduce the film director: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_director);
	new_film->setDirector(new_director);

	cout << USER << "Introduce the film scrpt team: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_script_team);
	new_film->setScriptTeam(new_script_team);

	cout << USER << "Introduce the film producer: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_producer);
	new_film->setProducer(new_producer);

	return new_film;

}


Videogame* CristoFinity::createAVideogame(){

//cout << DEBUG << "debug: getting in the create a series" << RESTORE << endl;

	Videogame *new_game = 0;
	new_game  = new Videogame();
	if(new_game  == 0){

		cerr << "There's no space in the heap." << endl;
		exit (-1);
	}

	if(this->getCatalogDimension() == 0){

		new_game ->Media::setMedia_ID(1);

	}else {

		new_game ->Media::setMedia_ID(this->catalog[this->getCatalogDimension() - 2]->getMedia_Id() + 1);
	}

	string new_title;
	string new_genre;
	unsigned int new_media_duration = 0;
	string new_publishing_date;
	unsigned int new_minimum_age = 0;
	string new_description;
	int new_views = 0;
	float new_rating = 0;
	string new_developer;
	string new_editor;
	int new_players;
	string new_platforms;


	cout << USER << "Introduce the game title: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_title);
	new_game->Media::setTitle(new_title);

	cout << USER << "Introduce the game genre: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_genre);
	new_game->Media::setGenre(new_genre);

	cout << USER << "Introduce the game duration: " << RESTORE << endl;
	cin >> new_media_duration;
	new_game->Media::setDuration(new_media_duration);

	cout << USER << "Introduce the game publishing date: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_publishing_date);
	new_game->Media::setPublishing_date(new_publishing_date);

	cout << USER << "Introduce the game minimum age recommendation: " << RESTORE << endl;
	cin >> new_minimum_age;
	new_game->Media::setAge_recommendations(new_minimum_age);

	cout << USER << "Introduce the game description: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_description);
	new_game->Media::setDescription(new_description);

	cout << USER << "Introduce the game views: " << RESTORE << endl;
	cin >> new_views;
	new_game->Media::setViews(new_views);

	cout << USER << "Introduce the game rating: " << RESTORE << endl;
	cin >> new_rating;
	new_game->Media::setRating(new_rating);

	cout << USER << "Introduce the game developer: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_developer);
	new_game->setDeveloper(new_developer);

	cout << USER << "Introduce the game editor: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_editor);
	new_game->setEditor(new_editor);

	cout << USER << "Introduce the game players: " << RESTORE << endl;
	cin >> new_players;
	new_game->setPlayers(new_players);

	cout << USER << "Introduce the game platforms: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_platforms);
	new_game->setPlatforms(new_platforms);

	return new_game ;
}

Song* CristoFinity::createASong(){

//cout << DEBUG << "debug: getting in the create a series" << RESTORE << endl;

	Song *new_song = 0;
	new_song  = new Song();
	if(new_song  == 0){

		cerr << "There's no space in the heap." << endl;
		exit (-1);
	}

	if(this->getCatalogDimension() == 0){

		new_song ->Media::setMedia_ID(1);

	}else {

		new_song ->Media::setMedia_ID(this->catalog[this->getCatalogDimension() - 2]->getMedia_Id() + 1);
	}

	string new_title;
	string new_genre;
	unsigned int new_media_duration = 0;
	string new_publishing_date;
	unsigned int new_minimum_age = 0;
	string new_description;
	int new_views = 0;
	float new_rating = 0;
	string new_artist;
	string new_album;


	cout << USER << "Introduce the song title: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_title);
	new_song->Media::setTitle(new_title);

	cout << USER << "Introduce the song genre: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_genre);
	new_song->Media::setGenre(new_genre);

	cout << USER << "Introduce the song duration: " << RESTORE << endl;
	cin >> new_media_duration;
	new_song->Media::setDuration(new_media_duration);

	cout << USER << "Introduce the song publishing date: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_publishing_date);
	new_song->Media::setPublishing_date(new_publishing_date);

	cout << USER << "Introduce the song minimum age recommendation: " << RESTORE << endl;
	cin >> new_minimum_age;
	new_song->Media::setAge_recommendations(new_minimum_age);

	cout << USER << "Introduce the song description: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_description);
	new_song->Media::setDescription(new_description);

	cout << USER << "Introduce the song views: " << RESTORE << endl;
	cin >> new_views;
	new_song->Media::setViews(new_views);

	cout << USER << "Introduce the song rating: " << RESTORE << endl;
	cin >> new_rating;
	new_song->Media::setRating(new_rating);

	cout << USER << "Introduce the song artist: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_artist);
	new_song->setArtist(new_artist);

	cout << USER << "Introduce the song album: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_album);
	new_song->setAlbum(new_album);

	return new_song;
}

void CristoFinity::deleteMediasFromCatalog(){

	int option = 0;

	cout << USER << "Which media do you want to delete?" << RESTORE << endl;
	this->printCatalog();

	cout << USER << "Option: " << RESTORE;
	cin >> option;

	Media *aux_media = 0;
	aux_media = new Media();
	if(aux_media == 0){

		cerr << "It's impossible to save memory in the heap." << endl;
		exit (-1);
	}

	aux_media = this->catalog[this->getCatalogDimension() - 1];
	this->catalog[this->getCatalogDimension()] = this->catalog[option];
	this->catalog[option] = aux_media;

	this->disminutiveCatalogResize();

}

void CristoFinity::likeAMedia(){

	int option = 0;

	cout << USER << "Which media did you like?" << RESTORE << endl;
	this->printCatalog();

	cout << USER << "Media to like: " << RESTORE;
	cin >> option;

	this->actual_user->likeAFavouriteMedia(this->catalog[option]);
	this->catalog[option]->setLikes(this->catalog[option]->getLikes() + 1);
	cout << USER << "Done!" << RESTORE << endl;


}

void CristoFinity::dislikeAMedia(){

	int option = 0;

	cout << USER << "Which media did you like?" << RESTORE << endl;
	this->printCatalog();

	cout << USER << "Media to like: " << RESTORE;
	cin >>option;

	this->actual_user->deleteMediaFromFavouriteMedia(option);
	cout << USER << "Done!" << RESTORE << endl;
}

void CristoFinity::changeMediaInfo(){

	string new_title;
	string new_genre;
	unsigned int new_media_duration = 0;
	string new_publishing_date;
	unsigned int new_minimum_age = 0;
	string new_description;
	int new_views = 0;
	float new_rating = 0;

	cout << USER << "Introduce the new media title: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_title);
	this->catalog[this->getCatalogDimension()]->setTitle(new_title);

	cout << USER << "Introduce the new media genre: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_genre);
	this->catalog[this->getCatalogDimension()]->setGenre(new_genre);

	cout << USER << "Introduce the new media duration: " << RESTORE << endl;
	cin >> new_media_duration;
	this->catalog[this->getCatalogDimension()]->setDuration(new_media_duration);

	cout << USER << "Introduce the new media publishing date: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_publishing_date);
	this->catalog[this->getCatalogDimension()]->setPublishing_date(new_publishing_date);

	cout << USER << "Introduce the new media minimum age recommendation: " << RESTORE << endl;
	cin >> new_minimum_age;
	this->catalog[this->getCatalogDimension()]->setAge_recommendations(new_minimum_age);

	cout << USER << "Introduce the new media description: " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, new_description);
	this->catalog[this->getCatalogDimension()]->setDescription(new_description);

	cout << USER << "Introduce the new media views: " << RESTORE << endl;
	cin >> new_views;
	this->catalog[this->getCatalogDimension()]->setViews(new_views);

	cout << USER << "Introduce the new media rating: " << RESTORE << endl;
	cin >> new_rating;
	this->catalog[this->getCatalogDimension()]->setRating(new_rating);
}

void CristoFinity::userMediaSeachingByID(){

	int media_id_to_find;

	cout << USER << "Which is the Id of the media you want? " << RESTORE << endl;
	cin >> media_id_to_find;

	for(int index = 0; index < this->getCatalogDimension(); index++){

		if(media_id_to_find == this->catalog[index]->Media::getMedia_Id()){
			cout << cyan << "Found!" << RESTORE << endl;
			this->catalog[index]->print();
		}
	}

}

void CristoFinity::userMediaSeachingByName(){

	string media_name_to_find;

	cout << USER << "Which is the Id of the media you want? " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	getline(cin, media_name_to_find);

	for(int index = 0; index < this->getCatalogDimension(); index++){

		if(media_name_to_find == this->catalog[index]->Media::getTitle()){
			cout << cyan << "Found!" << RESTORE << endl;
			this->catalog[index]->print();
		}
	}
}

void CristoFinity::userSearchMediaMenu(){

	int option = 0;

	cout << amarillo << "You want to search a media by...?" << RESTORE << endl;
	cout << amarillo << "[1]\t ID" << RESTORE << endl;
	cout << amarillo << "[2]\t Title" << RESTORE << endl;

	cout << amarillo << "Option: " << RESTORE;
	cin >> option;

	if(option == 1){

		this->userMediaSeachingByID();
	}else if(option == 2){

		this->userMediaSeachingByName();
	}else {
		cout << DEBUG << "That's not an option." << RESTORE << endl;
	}
}


void CristoFinity::administratorMenu(){

	bool exit = false;
	int option = 0;

	do{

		cout << USER << "Hello " << this->actual_user->getUserName() << "!" << RESTORE << endl;
		cout << USER << "Those are the functuonalities you can do as an admin user." << RESTORE << endl;

		cout << cyan << "[1]\t Change the user info." << RESTORE << endl;
		cout << cyan << "[2]\t Add a media to the system" << RESTORE << endl;
		cout << cyan << "[3]\t Delete a media to the system" << RESTORE << endl; //Method: deleteMediaFromCatalog() onlyadmin
		cout << cyan << "[4]\t Add a comment to a media" << RESTORE << endl; //Method commentAMedia()
		cout << cyan << "[5]\t Delete a comment from a media" << RESTORE << endl; //Method: deleteACommentFromMedia() 
		cout << cyan << "[6]\t Delete an user from the system" << RESTORE << endl; //Method: deleteAUserFromSystem()
		cout << cyan << "[7]\t Show the media catalog" << RESTORE << endl; //Method: printCatalog()
		cout << cyan << "[8]\t Show all the users registered in the system" << RESTORE << endl; //onlyadmin
		cout << cyan << "[9]\t Search a media" << RESTORE << endl;
		cout << cyan << "[10]\t Change the media info." << RESTORE << endl; 
		//cout << cyan << "[9]\t Show the top 3 best valorated medias" << RESTORE << endl; //Method: showRanking()
		cout << cyan << "[0]\t Logout and exit" << RESTORE << endl; //Method: logout

		cout << amarillo << "What do you want to do?" << RESTORE << endl;
		cin >> option;

		switch(option){
			case 1:
				this->changeUserInfo();
			break;
				
			case 2:
				this->addMediaToCatalog();
			break;

			case 3:
				this->deleteMediasFromCatalog();
			break;

			case 4:
				cout << DEBUG << "debug: entra aqui." << RESTORE << endl;
				this->commentAMedia();
			break;

			case 5:
				this->deleteACommentFromMedia();
			break;

			case 6:
				this->deleteUserFromVector();
			break;

			case 7:
				this->printCatalog();
			break;

			case 8:
				this->printUsersVector();
			break;

			case 9:
				this->userSearchMediaMenu();
			break;

			case 10:
				this->changeMediaInfo();
			break;

			case 0:
				exit = true;
			break;
		}

	}while(exit == false);
}

void CristoFinity::normalMenu(){

	bool exit = false;
	int option = 0;

	do{

		cout << USER << "Hello " << this->actual_user->getUserName() << "!" << RESTORE << endl;
		cout << USER << "Those are the functuonalities you can do as an normal user." << RESTORE << endl;

		cout << cyan << "[1]\t Show the media catalog" << RESTORE << endl; //Method: printCatalog()
		cout << cyan << "[2]\t Like a media" << RESTORE << endl; //Method: likeAMedia()
		cout << cyan << "[3]\t Dislike a media" << RESTORE << endl; //Method: dislikeAMedia()
		cout << cyan << "[4]\t Search a media" << RESTORE << endl; //Method: searchMediaMenu()
		cout << cyan << "[5]\t Write a comment in a media" << RESTORE << endl; //Method: commentAMedia
		cout << cyan << "[6]\t Delete a comment to a media" << RESTORE << endl; //Method: deleteACommentFromMedia() 
		//cout << cyan << "[7]\t Show the top 3 best valorated medias" << RESTORE << endl; //Method: showRanking()
		cout << cyan << "[7]\t Change the user info." << RESTORE << endl;
		cout << cyan << "[0]\t Logout and exit" << RESTORE << endl; // logout

		cout << amarillo << "What do you want to do?" << RESTORE << endl;
		cin >> option;

		switch(option){
			case 1:
				this->printCatalog();
			break;
				
			case 2:
				this->likeAMedia();
			break;

			case 3:
				this->dislikeAMedia();	
			break;

			case 4:
				this->userSearchMediaMenu();
			break;

			case 5:
				this->commentAMedia();
			break;

			case 6:
				this->deleteACommentFromMedia();
			break;

			case 7:
				this->changeUserInfo();
			break;

			case 0:
				exit = true;
			break;
		}

	}while(exit == false);
}

void CristoFinity::MainMenu(){

	cout << amarillo << "Welcome to CristoFinity!" << RESTORE << endl;
	this->LogInSystem();

	if(Administrator *a = dynamic_cast<Administrator*>(this->actual_user)){

		this->administratorMenu();
	}
	if(Normal *n = dynamic_cast<Normal*>(this->actual_user)){

		this->normalMenu();
	}
}

void CristoFinity::augmentativeUsersResize(){

//cout << DEBUG << "debug: getting in the augmentative users resize" << RESTORE << endl;

	int new_dimension = this->getUserVectorDimension();

	User **auxiliar_user_vector;
	auxiliar_user_vector = 0;
	auxiliar_user_vector = new User*[new_dimension + 1];
	if(auxiliar_user_vector == 0){

		cerr  << "It's impossible to save memory in the Heap." << endl;
		exit (-1);
	}
//cout << amarillo << "here1" << RESTORE << endl;
	for(int index2 = 0; index2 <= new_dimension; index2++){

		auxiliar_user_vector[index2] = 0;
	}
//cout << amarillo << "here2" << RESTORE << endl;
	for(int index = 0; index < this->getUserVectorDimension(); index++){

		auxiliar_user_vector[index] = this->user_vector[index];
		this->user_vector[index] = 0;
	}
//cout << amarillo << "here3" << RESTORE << endl;

	delete [] this->user_vector;
//cout << amarillo << "here4" << RESTORE << endl;
	this->user_vector = auxiliar_user_vector;

	auxiliar_user_vector = 0;
//cout << amarillo << "here5" << RESTORE << endl;
	this->users_vector_dimension++;

//cout << DEBUG << "debug: getting out the augmentative users resize" << RESTORE << endl;
}

void CristoFinity::disminutiveUsersResize(){

cout << DEBUG << "debug: getting in the disminutive users resize" << RESTORE << endl;

	int new_dimension = this->getUserVectorDimension();

	User **auxiliar_user_vector;
	auxiliar_user_vector = 0;
	auxiliar_user_vector = new User*[new_dimension];
	if(auxiliar_user_vector == 0){

		cerr  << "It's impossible to save memory in the Heap." << endl;
		exit (-1);
	}
//cout << amarillo << "here1" << RESTORE << endl;
	for(int index2 = 0; index2 <= new_dimension; index2++){

		auxiliar_user_vector[index2] = 0;
	}
//cout << amarillo << "here2" << RESTORE << endl;
	for(int index = 0; index < this->getUserVectorDimension() - 1; index++){

		auxiliar_user_vector[index] = this->user_vector[index];
		this->user_vector[index] = 0;
	}
//cout << amarillo << "here3" << RESTORE << endl;

	delete [] this->user_vector;
//cout << amarillo << "here4" << RESTORE << endl;
	this->user_vector = auxiliar_user_vector;

	auxiliar_user_vector = 0;
//cout << amarillo << "here5" << RESTORE << endl;
	this->users_vector_dimension--;

//cout << DEBUG << "debug: getting out the disminutive users resize" << RESTORE << endl;
}

void CristoFinity::augmentativeCatalogResize(){

cout << DEBUG << "debug: getting in the aumentative catalog resize" << RESTORE << endl;

	int new_dimension = this->getCatalogDimension();

	Media **auxiliar_media_vector;
	auxiliar_media_vector = 0;
	auxiliar_media_vector = new Media*[new_dimension + 1];
	if(auxiliar_media_vector == 0){

		cerr  << "It's impossible to save memory in the Heap." << endl;
		exit (-1);
	}
//cout << amarillo << "here1" << RESTORE << endl;
	for(int index2 = 0; index2 <= new_dimension; index2++){

		auxiliar_media_vector[index2] = 0;
	}
//cout << amarillo << "here2" << RESTORE << endl;
	for(int index = 0; index < this->getCatalogDimension(); index++){

		auxiliar_media_vector[index] = this->catalog[index];
		this->catalog[index] = 0;
	}
//cout << amarillo << "here3" << RESTORE << endl;

	delete [] this->catalog;
//cout << amarillo << "here4" << RESTORE << endl;
	this->catalog = auxiliar_media_vector;

	auxiliar_media_vector = 0;
//cout << amarillo << "here5" << RESTORE << endl;
	this->users_vector_dimension++;

//cout << DEBUG << "debug: getting out the aumentative catalogresize" << RESTORE << endl;

}

void CristoFinity::disminutiveCatalogResize(){

//cout << DEBUG << "debug: getting in the disminutive catalog resize" << RESTORE << endl;

	int new_dimension = this->getCatalogDimension();

	Media **auxiliar_media_vector;
	auxiliar_media_vector = 0;
	auxiliar_media_vector = new Media*[new_dimension];
	if(auxiliar_media_vector == 0){

		cerr  << "It's impossible to save memory in the Heap." << endl;
		exit (-1);
	}
//cout << amarillo << "here1" << RESTORE << endl;
	for(int index2 = 0; index2 <= new_dimension; index2++){

		auxiliar_media_vector[index2] = 0;
	}
//cout << amarillo << "here2" << RESTORE << endl;
	for(int index = 0; index < this->getCatalogDimension(); index++){

		auxiliar_media_vector[index] = this->catalog[index];
		this->catalog[index] = 0;
	}
//cout << amarillo << "here3" << RESTORE << endl;

	delete [] this->catalog;
//cout << amarillo << "here4" << RESTORE << endl;
	this->catalog = auxiliar_media_vector;

	auxiliar_media_vector = 0;
//cout << amarillo << "here5" << RESTORE << endl;
	this->users_vector_dimension--;

//cout << DEBUG << "debug: getting out the disminutive catalogresize" << RESTORE << endl;

}
