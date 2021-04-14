#ifndef VIDEOJUEGO_H 
#define VIDEOJUEGO_H

#include <string>
#include <iostream>
#include "Media.h"

class Videogame : public Media{

	private:
		string developer;
		string editor;
		int players;
		string platforms;

	public:

		/**
		 * @brief Default constructor of the class videogame
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		Videogame() : Media(){

			this->developer = "NULL";
			this->editor = "NULL";
			this->players = 0;
			this->platforms = "NULL";
		};

		/**
		 * @brief Constructor by parameters of the class Videogame
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		Videogame(unsigned int new_ID, string new_title, string new_genre, unsigned int new_duration, string new_publishing_date, unsigned int new_age_recomendation, string new_description, int new_views, float new_rating, int new_likes ,string new_developer, string new_editor, int new_players, string new_platforms) : Media(new_ID, new_title, new_genre, new_duration, new_publishing_date, new_age_recomendation, new_description, new_views, new_rating, new_likes){

			this->developer = new_developer;
			this->editor = new_editor;
			this->players = new_players;
			this->platforms = new_platforms;
		};

		/**
		 * @brief Default destructor of the class videogame
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		~Videogame(){

			this->developer = "NULL";
			this->editor = "NULL";
			this->players = 0;
			this->platforms = "NULL";
		};

		/**
		 * @brief Method that will allocate a string to the developer field
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		void setDeveloper(string new_developer);

		/**
		 * @brief Method that will allocate a string to the editor field
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		void setEditor(string new_editor);

		/**
		 * @brief Method that will allocate a string to the players field
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		void setPlayers(int new_players);

		/**
		 * @brief Method that will allocate a string to the platforms field
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		void setPlatforms(string new_platforms);

		/**
		 * @brief Method that will return the value of the develorper field
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		string getDeveloper();

		/**
		 * @brief Method that will return the value of the editorfield
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		string getEditor();

		/**
		 * @brief Method that will return the value of the players field
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		int getPlayers();

		/**
		 * @brief Method that will return the value of the platforms field
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		string getPlatforms();

		/**
		 * @brief Method that will print on the screen the info of the object videogame
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		void print();

};

#endif /* VIDEOJUEGO_H */