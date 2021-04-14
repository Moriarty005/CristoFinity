#ifndef PUNCTUATION_H
#define PUNCTUATION_H

#include <string>

using namespace std;


class Punctuation{

	private:
		string reviewer;
		float points;

	public:

		/**
		 * @brief Default constructor of the class Punctuation
		 * @author Alex Munioz
		 * @date 01/06/2019 
		 * @version 0.1
		**/
		Punctuation();

		/**
		 * @brief Contructor by parameters of the class Punctuation
		 * @author Alex Munioz
		 * @date 01/06/2019 
		 * @version 0.1
		**/
		Punctuation(string new_reviewer, float new_points);

		/**
		 * @brief Default destructor of the class Punctuation
		 * @author Alex Munioz
		 * @date 01/06/2019 
		 * @version 0.1
		**/
		~Punctuation();

		/**
		 * @brief Method that will allocate a string to the reviewer field 
		 * @author Alex Munioz
		 * @date 01/06/2019 
		 * @version 0.1
		**/
		void setReviewer(string new_reviewer);

		/**
		 * @brief Method that will allocate a string to the points field 
		 * @author Alex Munioz
		 * @date 01/06/2019 
		 * @version 0.1
		**/
		void setPoints(float new_points);

		/**
		 * @brief Method that will return the value of the reviewer field
		 * @author Alex Munioz
		 * @date 01/06/2019 
		 * @version 0.1
		**/
		string getReviewer();

		/**
		 * @brief Method that will return the value of the points field
		 * @author Alex Munioz
		 * @date 01/06/2019 
		 * @version 0.1
		**/
		float getPoints();
};

#endif /* PUNCTUATION_H */