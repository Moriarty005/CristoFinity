#ifndef MEDIA_H 
#define MEDIA_H

#include <string>
#include <iostream>
#include "Comment.h"
#include "Punctuation.h"

using namespace std;

class Media{
	
	public:
		unsigned int ID_media;
		string title;
		string genre;
		unsigned int full_duration;
		string publishing_date;
		unsigned int minimum_age_recomendation;
		string description;
		int views;
		float rating;
		int likes;

		unsigned int punctuation_list_dimension;
		Punctuation **punctuation_list;

		unsigned int comment_list_dimension;
		Comment **comment_list;
		

	public:

		/**
		 * @brief Default constructor of the class Media
		 * @author Alex Munioz
		 * @date 21/05/2019 
		 * @version 0.1
		**/
		Media();

		/**
		 * @brief Class Media cosntructor by parameters
		 * @author Alex Munioz
		 * @date 21/05/2019 
		 * @version 0.1
		**/
		Media(unsigned int new_ID, string new_title, string new_genre, unsigned int new_duration, string new_publishing_date, unsigned int new_age_recomendation, string new_description, int new_views, float new_rating, int new_likes);

		/**
		 * @brief Defaul destrcutor of the class Media
		 * @author Alex Munioz
		 * @date 21/05/2019 
		 * @version 0.1
		**/
		~Media();

		/**
		 * @brief Method that will allocate to the ID_media field of the class Media a value
		 * @pre Must exist a Media object
		 * @post Must have been allocated a vavlue to the media_ID field
		 * @params 'new_media_id' is the string we will asign to the field
		 * @author Alex Munioz
		 * @date 21/05/2019 
		 * @version 0.1
		**/
		void setMedia_ID(int new_media_id);

		/**
		 * @brief Method that will allocate a string to the title field
		 * @params 'new'title' it's the string that the method will allocate to the field
		 * @author Alex Munioz
		 * @date 21/05/2019 
		 * @version 0.1
		**/
		void setTitle(string new_title);

		/**
		 * @brief Method that will allocate a string to the genre field
		 * @params 'new_genre' it's the string that the method will allocate to the field
		 * @author Alex Munioz
		 * @date 21/05/2019 
		 * @version 0.1
		**/
		void setGenre(string new_genre);

		/**
		 * @brief Method that will allocate a string to the full_duration field
		 * @params 'new_media_duration' it's the string that the method will allocate to the field
		 * @author Alex Munioz
		 * @date 21/05/2019 
		 * @version 0.1
		**/
		void setDuration(unsigned int new_media_duration);

		/**
		 * @brief Method that will allocate a string to the publishing_date field
		 * @params 'new_publishing_date' is the new string that the method will allocate to the field
		 * @author Alex Munioz
		 * @date 21/05/2019 
		 * @version 0.1
		**/
		void setPublishing_date(string new_publishing_date);

		/**
		 * @brief Method that will allocate a int to the minimum_age_recomendation field
		 * @params 'new_minimum_age' is the new int that the method will allocate to the field
		 * @author Alex Munioz
		 * @date 21/05/2019 
		 * @version 0.1
		**/
		void setAge_recommendations(unsigned int new_minimum_age);

		/**
		 * @brief Method that will allocate a string to the description field
		 * @params 'new_description' is the new string that the method will allocate to the field
		 * @author Alex Munioz
		 * @date 21/05/2019 
		 * @version 0.1
		**/
		void setDescription(string new_description);

		/**
		 * @brief Method that will allocate a int to the views field
		 * @params 'new_views' is the new int that the method will allocate to the field
		 * @author Alex Munioz
		 * @date 21/05/2019 
		 * @version 0.1
		**/
		void setViews(int new_views);

		/**
		 * @brief Method that will allocate a float to the rating field
		 * @params 'new_rating' is the new float that the method will allocate to the field
		 * @author Alex Munioz
		 * @date 21/05/2019 
		 * @version 0.1
		**/
		void setRating(float new_rating);

		/**
		 * @brief Method that will allocate a string to the rating field
		 * @params 'new_likes_number' is the new float that the method will allocate to the field
		 * @author Alex Munioz
		 * @date 21/05/2019 
		 * @version 0.1
		**/
		void setLikes(int new_likes_number);

		/**
		 * @brief Method that will return the value of the Comment_ID field
		 * @author Alex Munioz
		 * @date 21/05/2019 
		 * @version 0.1
		**/
		unsigned int getMedia_Id();

		/**
		 * @brief Method that will return the value of the title field
		 * @author Alex Munioz
		 * @date 21/05/2019 
		 * @version 0.1
		**/
		string getTitle();

		/**
		 * @brief Method that will return the value of the genre field
		 * @author Alex Munioz
		 * @date 21/05/2019 
		 * @version 0.1
		**/
		string getGenre();

		/**
		 * @brief Method that will return the value of the full_duration field
		 * @author Alex Munioz
		 * @date 21/05/2019 
		 * @version 0.1
		**/
		unsigned int getFull_duration();

		/**
		 * @brief Method that will return the value of the publishing_date field
		 * @author Alex Munioz
		 * @date 21/05/2019 
		 * @version 0.1
		**/
		string getPublishing_date();

		/**
		 * @brief Method that will return the value of the minimum_age_recomendation field
		 * @author Alex Munioz
		 * @date 21/05/2019 
		 * @version 0.1
		**/
		unsigned int getAge_recommendation();

		/**
		 * @brief Method that will return the value of the description field
		 * @author Alex Munioz
		 * @date 21/05/2019 
		 * @version 0.1
		**/
		string getDescription();

		/**
		 * @brief Method that will return the value of the views field
		 * @author Alex Munioz
		 * @date 21/05/2019 
		 * @version 0.1
		**/
		int getViews();

		/**
		 * @brief Method that will return the value of the rating field
		 * @author Alex Munioz
		 * @date 21/05/2019 
		 * @version 0.1
		**/
		float getRating();

		/**
		 * @brief Method that will return the value of the likes field
		 * @author Alex Munioz
		 * @date 21/05/2019 
		 * @version 0.1
		**/
		int getLikes();

		/**
		 * @brief Method that will return the value of the comment_list_dimension field
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		unsigned int getCommentListDimension();

		/**
		 * @brief Method that will return the value of the punctuation_list_dimension field
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		unsigned int getPunctuationListDimension();

		/**
		 * @brief Method that will allocate a Comment int he comment list
		 * @pre Must exists the comment vector
		 * @post The comment vector dimension must have been increased in 1 square
		 * @author Alex Munioz
		 * @date 25/05/2019 
		 * @version 0.1
		**/
		void insertComment(Comment *new_comment);

		/**
		 * @brief Method that will allocate a Punctuationint he punctuation list
		 * @pre Must exists the punctuation vector
		 * @post The punctuation vector dimension must have been increased in 1 square
		 * @author Alex Munioz
		 * @date 01/06/2019 
		 * @version 0.1
		**/
		void insertPunctuation(Punctuation *new_punctuation);

		/**
		 * @brief Method that will order the comment vector by their ID
		 * @pre Must exists a comment vector
		 * @author Alex Munioz
		 * @date 25/05/2019 
		 * @version 0.1
		**/
		void orderCommentsByID();

		/**
		 * @brief Method that will delete a comment from the comment list of the media object by its ID
		 * @pre Must exists the comment list and must have at least a comment in
		 * @author Alex Munioz
		 * @date 25/05/2019 
		 * @version 0.1
		**/
		void deleteCommentFromListByID(unsigned int comment_id_to_delete);

		/**
		 * @brief Method that will print all the comments of the list
		 * @pre Must exists the comment vector
		 * @post The comments info must have been printed on the screen
		 * @author Alex Munioz
		 * @date 24/05/2019 
		 * @version 0.1
		**/
		void printCommentList();

		/**
		 * @brief Method htat will return the value of the square of the comment htat have the id that is same as the comment id passed throught
		 * @author Alex Munioz
		 * @date 24/05/2019 
		 * @version 0.1
		**/
		unsigned int serachCommentByID(unsigned int comment_id_to_find);

		/**
		 * @brief Method that will print all the Punctuation of the list
		 * @pre Must exists the Punctuation vector
		 * @post The punctuations info must have been printed on the screen
		 * @author Alex Munioz
		 * @date 01/06/2019 
		 * @version 0.1
		**/
		void printPunctuationList();

		/**
		 * @brief Method that will print on the screen the Media data.
		 * @author Alex Munioz
		 * @date 24/05/2019 
		 * @version 0.1
		**/
		friend ostream& operator<<(ostream &flux, Media &media_object_to_print);

		/**
		 * @brief Method that will print on screen the info of the class media
		 * @author Alex Munioz
		 * @date 31/05/2019 
		 * @version 0.1
		**/
		virtual void print();

	private:

		/**
		 * @brief Method that will increase the dimension of the comments vector in 1
		 * @author Alex Munioz
		 * @date 25/05/2019 
		 * @version 0.1
		**/
		void augmentativeCommentResize();

		/**
		 * @brief Method that will decrease the dimension of the comments vector in 1
		 * @author Alex Munioz
		 * @date 25/05/2019 
		 * @version 0.1
		**/
		void disminutiveCommentResize();

		/**
		 * @brief Method that will increase the dimension of the  punctuation vector in 1
		 * @author Alex Munioz
		 * @date 01/06/2019 
		 * @version 0.1
		**/
		void augmentativePunctuationResize();

		/**
		 * @brief Method that will decrease the dimension of the punctuation vector in 1
		 * @author Alex Munioz
		 * @date 01/06/2019 
		 * @version 0.1
		**/
		void disminutivePunctuationResize();
};

#endif /*MEDIA_H*/