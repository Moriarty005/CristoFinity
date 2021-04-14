#ifndef SONG_H 
#define SONG_H

#include <string>
#include <iostream>
#include "Media.h"

using namespace std;

class Song : public Media{

	private:
		string artist;
		string album;

	public:

		/**
		 * @brief Defaul constructor of the class Song
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		Song() : Media(){

			this->artist = "NULL";
			this->album = "NULL";
		};

		/**
		 * @brief Contructor by parameters of the class Song
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		Song(unsigned int new_ID, string new_title, string new_genre, unsigned int new_duration, string new_publishing_date, unsigned int new_age_recomendation, string new_description, int new_views, float new_rating, int new_likes ,string new_artist, string new_album) : Media(new_ID, new_title, new_genre, new_duration, new_publishing_date, new_age_recomendation, new_description, new_views, new_rating, new_likes){

			this->artist = new_artist;
			this->album = new_album;
		};

		/**
		 * @brief Default destructor of the class song
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		~Song(){

			this->artist = "NULL";
			this->album = "NULL";
		};

		/**
		 * @brief Method that will allocate a string to the artist field
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		void setArtist(string new_artist);

		/**
		 * @brief Method that will allocate a string to the album field
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		void setAlbum(string new_album);

		/**
		 * @brief Method that will return the value of the artist field
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		string getArtist();

		/**
		 * @brief Method that will return the value of the album field
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		string getAlbum();

		/**
		 * @brief MEthod that will print on screen the info of the class Song
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		void print();
};

#endif /* SONG_H */