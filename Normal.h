#ifndef NORMAL_H
#define NORMAL_H

#include <stdlib.h>

#include "User.h"

using namespace std;

class Normal : public User {

	private:

		float user_media_average_punctuation;
		Media **favourite_media_user_vector;
		unsigned int favourite_dimension;


	public:

		/**
		 * @brief Default cosntructor of the class Nomarl (User)
		 * @author Alex Munioz
		 * @date 01/06/2019 
		 * @version 0.1
		**/
		Normal() : User(){

			this->user_media_average_punctuation = 0;

			this->favourite_dimension = 0;

			this->favourite_media_user_vector = 0;
			this->favourite_media_user_vector = new Media*[1];
			if(this->favourite_media_user_vector == 0){

				cerr << "It's impossible to save memory in the Heap" << endl;
				exit (-1);
			}
		};

		Normal(string new_user_id, string new_user_name, string new_user_surname, string new_url_photo) : User(new_user_id, new_user_name, new_user_surname, new_url_photo){

			this->user_media_average_punctuation = 0;

			this->favourite_dimension = 0;

			this->favourite_media_user_vector = 0;
			this->favourite_media_user_vector = new Media*[1];
			if(this->favourite_media_user_vector == 0){

				cerr << "It's impossible to save memory in the Heap" << endl;
				exit (-1);
			}
		};

		/**
		 * @brief Constructor by parameters of the class Normal (User)
		 * @author Alex Munioz
		 * @date 01/06/2019 
		 * @version 0.1
		**/
		~Normal();

		/**
		 * @brief Method that will allocate a value to the media_average_punctuation field
		 * @author Alex Munioz
		 * @date 01/06/2019 
		 * @version 0.1
		**/
		void setUserMediaAveragePunctuation(float new_average_punctuation);

		/**
		 * @brief Method that will return the value of the media_average_punctuation field
		 * @author Alex Munioz
		 * @date 01/06/2019 
		 * @version 0.1
		**/
		float getUserMediaAveragePunctuation();

		/**
		 * @brief Method that will return the value of the field favourite dimension
		 * @author Alex Munioz
		 * @date 01/06/2019 
		 * @version 0.1
		**/
		unsigned int getFavouriteMediaVectorDimension();

		/**
		 * @brief Method htat will allocate a media from hte catalog to the favourite_media_vector
		 * @author Alex Munioz
		 * @date 01/06/2019 
		 * @version 0.1
		**/
		void likeAMedia(Media *liked_media);

		/**
		 * @brief Method htat will delete a media from hte catalog to the favourite_media_vector
		 * @author Alex Munioz
		 * @date 01/06/2019 
		 * @version 0.1
		**/
		void dislikeAMedia(unsigned int media_square_to_dislike);

		/**
		 * @brief Method that will print on the screen all the medias of the user's favourite media vector
		 * @author Alex Munioz
		 * @date 01/06/2019 
		 * @version 0.1
		**/
		void printFavouriteMedia();

		/**
		 * @brief Method that will print on the screen all the info from the normal user
		 * @author Alex Munioz
		 * @date 01/06/2019 
		 * @version 0.1
		**/
		void printUser();

		/**
		 * @brief Method that will calculate the average of the favourite medias punctuation
		 * @pre Must be created the favourite media vector
		 * @post Must allocate the result of the average to the  user_media_average_punctuation field
		 * @author Alex Munioz
		 * @date 01/06/2019 
		 * @version 0.1
		**/
		void calculateTheMediaAveragePunctuation();

	private:

		/**
		 * @brief Method htat will increase the Favourite media dimension in one
		 * @pre The favourite media vector must have been created
		 * @post The favourite media dimension must have been increased in one
		 * @author Alex Munioz
		 * @date 01/06/2019 
		 * @version 0.1
		**/
		void augmentativeFavouriteMediaResize();

		/**
		 * @brief Method htat will decrease the Favourite media dimension in one
		 * @pre The favourite media vector must have been created and have at least one square
		 * @post The favourite media dimension must have been decreased in one
		 * @author Alex Munioz
		 * @date 01/06/2019 
		 * @version 0.1
		**/
		void diminutiveFavouriteMediaResize();
};

#endif /* NORMAL_H */