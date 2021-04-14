#ifndef USER_H
#define USER_H

#include <string>
#include "Media.h"

using namespace std;

class User{

	protected:
		string id_user;
		string user_name;
		string user_surname;
		string url_photo;

		unsigned int searched_media_vector_dimension;
		Media **searched_media_vector;

		unsigned int favourite_media_vector_dimension;
		Media **favourite_media_vector;

	public:

		/**
		 * @brief Default User constructor
		 * @author Alex Munioz
		 * @date 21/05/2019 
		 * @version 0.1
		**/
		User();

		/**
		 * @brief User constructor by parameters
		 * @author Alex Munioz
		 * @date 21/05/2019 
		 * @version 0.1
		**/
		User(string new_user_id, string new_user_name, string new_user_surname, string new_url_photo);

		/**
		 * @brief Default destructor of the class User
		 * @author Alex Munioz
		 * @date 21/05/2019 
		 * @version 0.1
		**/
		~User();

		/**
		 * @brief Method that will allocate a value to the id_user field of the object
		 * @author Alex Munioz
		 * @date 20/05/2019 
		 * @version 0.1
		**/
		void setId_user(string new_id_user);

		/**
		 * @brief Method that will allocate a value to the user_name field of the object
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		void setUserName(string new_user_name);

		/**
		 * @brief Method that will allocate a value to the user_surname field of the object
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		void setUserSurName(string new_user_surname);

		/**
		 * @brief Method that will allocate a value to the url_photofield of the object
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		void setUserURL(string new_url_photo);

		/**
		 * @brief Method that will return the valueo of the id_user field;
		 * @author Alex Munioz
		 * @date 20/05/2019 
		 * @version 0.1
		**/
		string getId_user();

		/**
		 * @brief Method that will return the valueo of the user_name field;
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		string getUserName();

		/**
		 * @brief Method that will return the valueo of the user_surname field;
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		string getUserSurName();

		/**
		 * @brief Method that will return the valueo of the url_photo field;
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		string getUserURL();


		/**
		 * @brief Method that will return the value of the SearchedMediaVectorDimension field;
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		unsigned int getSearchedMediaVectorDimension();

		/**
		 * @brief Method that will return the value of the FavouriteMediaVectorDimension field;
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		unsigned int getFavouriteMediaVectorDimension();

		/**
		 * @brief Method that will allocate a media to the searched media vector
		 * @pre The searched media vector must be created
		 * @post The searched media vector dimension must have been increased in one
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		void setMediaToSearched(Media *new_searched_media);

		/**
		 * @brief Method that will ask the administrator to fill all the fields of a comment object
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		Comment* writeComment();

		/**
		 * @brief Method that will ask the administrator to fill all the fields of a punctuation object
		 * @author Alex Munioz
		 * @date 02/06/2019 
		 * @version 0.1
		**/
		Punctuation* giveAPunctuation();

		/**
		 * @brief Method that will print on the screen the 5 media objects previously searched
		 * @pre The searched media vector must be created
		 * @author Alex Munioz
		 * @date 01/06/2019 
		 * @version 0.1
		**/
		void printSearchedMedia();

		/**
		 * @brief Method that will remove a Media object from the searched media vector
		 * @pre Must exits at least one media object in the vector
		 * @post The searched media vector dimension must have been decreased in one
		 * @author Alex Munioz
		 * @date 20/05/2019 
		 * @version 0.1
		**/
		void deleteMediaFromSearchedMedia(int favourite_media_selected_to_delete);

		/**
		 * @brief Method that will print all the user data
		 * @author Alex Munioz
		 * @date 20/05/2019 
		 * @version 0.1
		**/
		virtual void printUser();

		/**
		 * @brief Method that will allocate a media to the favourite media vector
		 * @pre The favourite media vector must be created
		 * @post The favourite media vector dimension must have been increased in one
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		void likeAFavouriteMedia(Media *media_to_like);

		/**
		 * @brief Method that will remove a Media object from the favourite media vector
		 * @pre Must exits at least one media object in the vector
		 * @post The favourite media vector dimension must have been decreased in one
		 * @author Alex Munioz
		 * @date 20/05/2019 
		 * @version 0.1
		**/
		void deleteMediaFromFavouriteMedia(int favourite_media_selected_to_delete);

	private:

		/**
		 * @brief Method that will decrease the dimension of the searched media vector in 1
		 * @pre The searched media vector must have been created
		 * @post The dimension fo the vector must have been increased in one
		 * @author Alex Munioz
		 * @date 25/05/2019 
		 * @version 0.1
		**/
		void augmentativeSearchedMediaResize();

		/**
		 * @brief Method that will decrease the dimension of the searched media vector in 1
		 * @pre The searched media vector must have been created
		 * @post The dimension fo the vector must have been decreased in one
		 * @author Alex Munioz
		 * @date 25/05/2019 
		 * @version 0.1
		**/
		void disminutiveSearchedMediaResize();

		/**
		 * @brief Method that will decrease the dimension of the Favourite media vector in 1
		 * @pre The favourite media vector must have been created
		 * @post The dimension fo the vector must have been increased in one
		 * @author Alex Munioz
		 * @date 25/05/2019 
		 * @version 0.1
		**/
		void augmentativeFavouriteMediaResize();

		/**
		 * @brief Method that will decrease the dimension of the Favourite media vector in 1
		 * @pre The favourite media vector must have been created
		 * @post The dimension fo the vector must have been decreased in one
		 * @author Alex Munioz
		 * @date 25/05/2019 
		 * @version 0.1
		**/
		void disminutiveFavouriteMediaResize();


};

#endif /*USER_H*/