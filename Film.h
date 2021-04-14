#ifndef FILM_H
#define FILM_H
 
 #include <string>
 #include <iostream>
 #include "Media.h"

 using namespace std;

 class Film : public Media{

 	private:
 		string cast;
 		string director;
 		string script_team;
 		string producer;

 	public:

 		/**
 		 * @brief Default constructor of the class Film
 		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
 		**/
 		Film() : Media(){

 			this->cast = "NULL";
 			this->director = "NULL";
 			this->script_team = "NULL";
 			this->producer = "NULL";
 		};

 		/**
 		 * @brief Constructor by parameters of the class Film
 		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
 		**/
 		Film(unsigned int new_ID, string new_title, string new_genre, unsigned int new_duration, string new_publishing_date, unsigned int new_age_recomendation, string new_description, int new_views, float new_rating, int new_likes ,string new_cast, string new_director, string new_script_team, string new_producer) : Media(new_ID, new_title, new_genre, new_duration, new_publishing_date, new_age_recomendation, new_description, new_views, new_rating, new_likes){

 			this->cast = new_cast;
 			this->director = new_director;
 			this->script_team = new_script_team;
 			this->producer = new_producer;
 		};

		/**
 		 * @brief Default destructor of the class Film
 		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
 		**/
 		~Film(){

 			this->cast = "NULL";
 			this->director = "NULL";
 			this->script_team = "NULL";
 			this->producer = "NULL";
 		};

 		/**
 		 * @brief Method that will alocate a string to the Cast field of the class Film
 		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
 		**/
 		void setCast(string new_cast);

 		/**
 		 * @brief Method that will alocate a string to the Director field of the class Film
 		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
 		**/
 		void setDirector(string new_director);

 		/**
 		 * @brief Method that will alocate a string to the Script_team field of the class Film
 		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
 		**/
 		void setScriptTeam(string new_script_team);

 		/**
 		 * @brief Method that will alocate a string to the Producer field of the class Film
 		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
 		**/
 		void setProducer(string new_producer);

 		/**
 		 * @brief Method that will print on the screen the cast field
 		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
 		**/
 		string getCast();

 		/**
 		 * @brief Method that will print on the screen the director field
 		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
 		**/
 		string getDirector();

		/**
 		 * @brief Method that will print on the screen the script_team field
 		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
 		**/
 		string getScriptTeam();

 		/**
 		 * @brief Method that will print on the screen the producer field
 		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
 		**/
 		string getProducer();

 		/**
		 * @brief Method that will print on the screen the info of the object film
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
 		virtual void print();
 }; 

 #endif /* SERIES_H */