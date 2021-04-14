#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <string>
#include "User.h"

using namespace std;

class Administrator : public User{

	private:

		bool creator;


	public:

		/**
		 * @brief Default constructor of the class Administrator
		 * @author Alex Munioz
		 * @date 21/05/2019 
		 * @version 0.1
		**/
		Administrator() : User(){

			this->creator = false;
		};

		/**
		 * @brief Constructor by parameters of the class Administrator
		 * @author Alex Munioz
		 * @date 01/06/2019 
		 * @version 0.1
		**/
		Administrator(string new_user_id, string new_user_name, string new_user_surname, string new_url_photo, bool new_creator) : User( new_user_id, new_user_name, new_user_surname, new_url_photo){

			this->creator = new_creator;
		};

		/**
		 * @brief Default destructor of the class Administrator
		 * @author Alex Munioz
		 * @date 21/05/2019 
		 * @version 0.1
		**/
		~Administrator();

		/**
		 * @brief Method that will allocate a bool to the creator field
		 * @author Alex Munioz
		 * @date 01/06/2019 
		 * @version 0.1
		**/
		void setCreator(bool new_creator);

		/**
		 * @brief Method that will return the value of the field creator in the class Administrator
		 * @author Alex Munioz
		 * @date 01/06/2019 
		 * @version 0.1
		**/
		bool getCreator();

		/**
		 * @brief Method that will print on screen the info of the admin user
		 * @author Alex Munioz
		 * @date 01/06/2019 
		 * @version 0.1
		**/
		void printUser();
};

#endif /* ADMINISTRATOR_H */