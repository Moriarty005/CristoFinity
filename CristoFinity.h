#ifndef CRISTOFINITY_H
#define CRISTOFINITY_H

#include <string>
#include "User.h"
#include "Media.h"
#include "Film.h"
#include "Videogame.h"
#include "Song.h"
#include "Series.h"
#include "Administrator.h"
#include "Normal.h"

using namespace std;

class CristoFinity{

	protected:

		unsigned int users_vector_dimension;
		User **user_vector;

		unsigned int catalog_dimension;
		Media **catalog;

		User *actual_user;

	public:

		/**
		 * @brief This is the default constructor of the clas CristoFinity
		 * @author Alex Munioz
		 * @date 20/05/2019 
		 * @version 0.1
		**/
		CristoFinity();

		/**
		 * @brief Deafult Media constructor
		 * @author Alex Munioz
		 * @date 20/05/2019 
		 * @version 0.1
		**/
		~CristoFinity();

		/**
		 * @brief Method that will return the value of the catalog dimension field
		 * @author Alex Munioz
		 * @date 02/06/2019 
		 * @version 0.1
		**/
		unsigned int getCatalogDimension();

		/**
		 * @brief Method that will return the value of the user vector dimension field
		 * @author Alex Munioz
		 * @date 02/06/2019 
		 * @version 0.1
		**/
		unsigned int getUserVectorDimension();

		/**
		 * @brief Method that will verify that the user introduced is already created in the users vector
		 * @author Alex Munioz
		 * @date 02/06/2019 
		 * @version 0.1
		**/
		void LogInSystem();

		/**
		 * @brief This method have to insert a pointer to user into the pointers to users' vector
		 * @pre Whatever is passed to this method must be of the class User
		 * @post After this method act, the pointers to users' vector must have increased it's dimension in 1, and of course the pointer to user passed through must have been inserted into the vector
		 * @params 'pointer_to_user' is a pointer to a user, and it's what we are goig to insert into the vector
		 * @author Alex Munioz
		 * @date 20/05/2019 
		 * @version 0.1
		**/
		void insertUserInVector();

		/**
		 * @brief Method htat will allocate a comment to the media selected
		 * @author Alex Munioz
		 * @date 02/06/2019 
		 * @version 0.1
		**/
		void commentAMedia();

		/**
		 * @brief Method that will delete a selected comment
		 * @author Alex Munioz
		 * @date 02/06/2019 
		 * @version 0.1
		**/
		void deleteACommentFromMedia();

		/**
		 * @brief Method that will return the posistion of the media that has the same id as the passed throught
		 * @author Alex Munioz
		 * @date 02/06/2019 
		 * @version 0.1
		**/
		unsigned int searchMediaByID(unsigned int id_to_find);

		/**
		 * @brief Method that will return the posistion of the media that has the same name as the passed throught
		 * @author Alex Munioz
		 * @date 02/06/2019 
		 * @version 0.1
		**/
		unsigned int searchMediaByName(string name_to_find);

		/**
		 * @brief Method that will return the pointer to user htat has the same id that the one passed through
		 * @author Alex Munioz
		 * @date 02/06/2019 
		 * @version 0.1
		**/
		User* searchUserByLogin(string user_id_to_find);

		/**
		 * @brief This method have to insert a pointer to media content into the pointers to media's vector
		 * @pre Whatever is passed to this method must be of the class Media
		 * @post After this method act, the pointers to media's vector must have increased it's dimension in 1, and of course the pointer to media passed through must have been inserted into the vector
		 * @params 'pointer_to_media_content' is a pointer to media and it's what we are going to insert into the vector
		 * @author Alex Munioz
		 * @date 20/05/2019 
		 * @version 0.1
		**/
		void insertANewMedia(Media *pointer_to_media_content);

		/**
		 * @brief Method that will created a new user of the type the administrator decide and will add it ot users vector
		 * @pre The users vector must have been created
		 * @post The users vector dimension must have been increased in one
		 * @author Alex Munioz
		 * @date 02/06/2019 
		 * @version 0.1
		**/
		void AddUserInVector();

		/**
		 * @brief Method that will delete an user from the users vector
		 * @pre The media must have been created
		 * @post The dimension must have been decreased in one
		 * @author Alex Munioz
		 * @date 02/06/2019 
		 * @version 0.1
		**/
		void deleteUserFromVector();

		/**
		 * @brief Method that will create an admin user and will return its pointer
		 * @author Alex Munioz
		 * @date 02/06/2019 
		 * @version 0.1
		**/
		Administrator* createAnAdminUser();

		/**
		 * @brief Method that will create a normal user and will return its pointer
		 * @author Alex Munioz
		 * @date 02/06/2019 
		 * @version 0.1
		**/
		Normal* createANormalUser();

		/**
		 * @brief Method that will print some info or another depending of what type of user you are in this moment
		 * @pre Both vectors of the class cristofinity must be created
		 * @author Alex Munioz
		 * @date 02/06/2019 
		 * @version 0.1
		**/
		void print();

		/**
		 * @brief Method that will print on screen all the medias of the catalog
		 * @author Alex Munioz
		 * @date 02/06/2019 
		 * @version 0.1
		**/
		void printCatalog();

		/**
		 * @brief Method that will print on screen all the users of the users_vector
		 * @author Alex Munioz
		 * @date 02/06/2019 
		 * @version 0.1
		**/
		void printUsersVector();

		/**
		 * @brief Method that will change your profile
		 * @author Alex Munioz
		 * @date 02/06/2019 
		 * @version 0.1
		**/
		void changeUser();

		/**
		 * @brief Method that will allow the administrator its profile info
		 * @author Alex Munioz
		 * @date 02/06/2019 
		 * @version 0.1
		**/
		void changeUserInfo();

		/**
		 * @brief Methos that will allocate a new Media to the catalog
		 * @pre The catalog must be created
		 * @post The catalog dimension must have been increased in one
		 * @author Alex Munioz
		 * @date 02/06/2019 
		 * @version 0.1
		**/
		void addMediaToCatalog();

		/**
		 * @brief Method that will create a Film and will return its pointer
		 * @author Alex Munioz
		 * @date 02/06/2019 
		 * @version 0.1
		**/
		Film* createAFilm();

		/**
		 * @brief Method that will create a Series and will return its pointer
		 * @author Alex Munioz
		 * @date 02/06/2019 
		 * @version 0.1
		**/
		Series* createASeries();

		/**
		 * @brief Method that will create a Videogame and will return its pointer
		 * @author Alex Munioz
		 * @date 02/06/2019 
		 * @version 0.1
		**/
		Videogame* createAVideogame();

		/**
		 * @brief Method that will create a Song and will return its pointer
		 * @author Alex Munioz
		 * @date 02/06/2019 
		 * @version 0.1
		**/
		Song* createASong();

		/**
		 * @brief Method that will delete every user in the catalog
		 * @pre The catalog must have at least one media 
		 * @post The catalog must have, after this method act, just one square and must be empty
		 * @author Alex Munioz
		 * @date 22/05/2019 
		 * @version 0.1
		**/
		void deleteMediasFromCatalog();

		/**
		 * @brief Method that will add a media to the users favourite media vector
		 * @author Alex Munioz
		 * @date 02/06/2019 
		 * @version 0.1
		**/
		void likeAMedia();

		/**
		 * @brief Method that will delete a media from the users favourite media vector
		 * @author Alex Munioz
		 * @date 02/06/2019 
		 * @version 0.1
		**/
		void dislikeAMedia();

		/**
		 * @brief Method that will allow you to change the info of a media
		 * @author Alex Munioz
		 * @date 02/06/2019 
		 * @version 0.1
		**/
		void changeMediaInfo();

		/**
		 * @brief Front method that will print on the screen the administrator want to
		 * @author Alex Munioz
		 * @date 02/06/2019 
		 * @version 0.1
		**/
		void userMediaSeachingByID();

		/**
		 * @brief Front method that will print on the screen the administrator want to
		 * @author Alex Munioz
		 * @date 02/06/2019 
		 * @version 0.1
		**/
		void userMediaSeachingByName();

		/**
		 * @brief Method that will show on the screen all the options of searching medias
		 * @author Alex Munioz
		 * @date 03/06/2019 
		 * @version 0.1
		**/
		void userSearchMediaMenu();

		/**
		 * @brief Menu of an administrator user
		 * @author Alex Munioz
		 * @date 02/06/2019 
		 * @version 0.1
		**/
		void administratorMenu();

		/**
		 * @brief Menu of a normal user
		 * @author Alex Munioz
		 * @date 02/06/2019 
		 * @version 0.1
		**/
		void normalMenu();

		/**
		 * @brief Default menu
		 * @author Alex Munioz
		 * @date 02/06/2019 
		 * @version 0.1
		**/
		void MainMenu();


	private:

		/**
		 * @brief Method that will increase the dimension of the users' vector in 1
		 * @author Alex Munioz
		 * @date 20/05/2019 
		 * @version 0.1
		**/
		void augmentativeUsersResize();

		/**
		 * @brief Method that will decrase the dimension of the users' vector in 1
		 * @author Alex Munioz
		 * @date 20/05/2019 
		 * @version 0.1
		**/
		void disminutiveUsersResize();

		/**
		 * @brief Method that will increase the dimension of the media vector
		 * @author Alex Munioz
		 * @date 20/05/2019 
		 * @version 0.1
		**/
		void augmentativeCatalogResize();

		/**
		 * @brief Method that will decrease the dimension of the media vector
		 * @author Alex Munioz
		 * @date 20/05/2019 
		 * @version 0.1
		**/
		void disminutiveCatalogResize();
};


#endif /*CRISTOFINITY_H*/
