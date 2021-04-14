#ifndef SERIES_H
#define SERIES_H

#include "Film.h"

using namespace std;

class Series : public Film{

	private:
		int seasons;
		int episodes;
		bool stage;

	public:

		/**
		 * @brief Default constructor of the clas Series
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		Series() : Film(){

			this->seasons = 0;
			this->episodes = 0;
			this->stage = false;
		};

		/**
		 * @brief Constructor by parameters of the class Series
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		Series(unsigned int new_ID, string new_title, string new_genre, unsigned int new_duration, string new_publishing_date, unsigned int new_age_recomendation, string new_description, int new_views, float new_rating, int new_likes ,string new_cast, string new_director, string new_script_team, string new_producer, int new_seasons, int new_episodes, bool new_stage) : Film(new_ID, new_title, new_genre, new_duration, new_publishing_date, new_age_recomendation, new_description, new_views, new_rating, new_likes ,new_cast, new_director, new_script_team, new_producer){

			this->seasons = new_seasons;
			this->episodes = new_episodes;
			this->stage = new_stage;
		};

		/**
		 * @brief Default destructor of the clas Series
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		~Series(){

			this->seasons = 0;
			this->episodes = 0;
			this->stage = false;
		};

		/**
		 * @brief Method that will allocate an int into the season field
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		void setSeasons(int new_seasons);

		/**
		 * @brief Method that will allocate an int into the episodes field
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		void setEpisodes(int new_episodes);

		/**
		 * @brief Method that  will allocate an int into the stage field
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		void setStage(bool new_stage);

		/**
		 * @brief Method that will return the value of the seasons field
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		int getSeasons();

		/**
		 * @brief Method that will return the value of the eisodes field
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		int getEpisodes();

		/**
		 * @brief Method that will return the value of the stage field
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		bool getStage();

		/**
		 * @brief Method that will print on the screen the info of the object series
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		void print();
};

#endif /* SERIES_H */