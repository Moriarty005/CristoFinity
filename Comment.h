#ifndef COMMENT_H
#define COMMENT_H

#include <string>
#include <iostream>

using namespace std;

class Comment{

	private:
		unsigned int comment_id;
		string writer;
		string comment_text;

	public:

		/**
		 * @brief Default contructor of the Comment class.
		 * @author Alex Munioz
		 * @date 24/05/2019 
		 * @version 0.1
		**/
		Comment();

		/**
		 * @brief Contructor by parameters of the class Comment
		 * @author Alex Munioz
		 * @date 24/05/2019 
		 * @version 0.1
		**/
		Comment(unsigned int new_comment_id, string new_writer, string new_comment_text);

		/**
		 * @brief Default destructor of the class Comment
		 * @author Alex Munioz
		 * @date 24/05/2019 
		 * @version 0.1
		**/
		~Comment();

		/**
		 * @brief Method that will allocate an unsigned int to the comment_id field
		 * @params 'new_comment_id'
		 * @author Alex Munioz
		 * @date 24/05/2019 
		 * @version 0.1
		**/
		void setCommentID(unsigned int new_comment_id);

		/**
		 * @brief Method that will allocate a string to the writer field
		 * @params 'new_writer'
		 * @author Alex Munioz
		 * @date 24/05/2019 
		 * @version 0.1
		**/
		void setWriter(string new_writer);

		/**
		 * @brief Method that will allocate a string to the writer field
		 * @params 'new_text'
		 * @author Alex Munioz
		 * @date 24/05/2019 
		 * @version 0.1
		**/
		void setComment_text(string new_text);

		/**
		 * @brief Method that will return the value of the comment_id field
		 * @author Alex Munioz
		 * @date 24/05/2019 
		 * @version 0.1
		**/
		unsigned int getCommentID();

		/**
		 * @brief Method that will return the value of the criter field
		 * @author Alex Munioz
		 * @date 24/05/2019 
		 * @version 0.1
		**/
		string getWriter();

		/**
		 * @brief Method that will return the value of the comment_text field
		 * @author Alex Munioz
		 * @date 24/05/2019 
		 * @version 0.1
		**/
		string getComment_text();

		/**
		 * @brief This is the overloading of the operator cout <<
		 * @author Alex Munioz
		 * @date 24/05/2019 
		 * @version 0.1
		**/
		friend ostream& operator<<(ostream &flux, Comment comment_to_print);

		/**
		 * @brief Overloading of the operator =
		 * @author Alex Munioz
		 * @date 30/05/2019 
		 * @version 0.1
		**/
		void operator=(Comment comment_info);

};


#endif /* COMMENT_H */