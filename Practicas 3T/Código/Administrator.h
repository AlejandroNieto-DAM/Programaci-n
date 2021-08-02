#ifndef ADMINISTRATOR_H
#define	ADMINISTRATOR_H

#include <string.h>
#include "Element.h"
#include "User.h"
#include "UserNormal.h"
#include "CristoFinity.h"
#include "Film.h"
#include "Comment.h"
#include "Valoration.h"
#include "Song.h"
#include "Videogame.h"
#include "Series.h"

using namespace std;

class Administrator: public User {


	public:

		/*********+********/
		/** CONSTRUCTORS **/
		/******************/

		//Default constructor.
		Administrator(): User(){};

		/*********+************************/
		/** DESTRUCTOR OF THE CLASS USER **/
		/**********************************/

		//Destructor of User
		~Administrator();

		/*********+****************************/
		/** OVERLOAD OF THE CLASS USERNORMAL **/
		/**************************************/

		/*
		 *@brief Overload of the operator =
		 *@author Alejandro Nieto.
		 *@version: 1.0
		*/
		Administrator& operator=(const Administrator &example);

		/*
		 * @brief Overload of the operator >> when there is a User to print their values.
		 *@author Alejandro Nieto.
		 *@version: 1.0
		*/
		friend istream& operator>>(istream &flujo, Administrator *p);

		/*
		 * @brief Overload of the operator << when there is a User to introduce their values.
		 *@author Alejandro Nieto.
		 *@version: 1.0
		*/
		friend ostream& operator<<(ostream &flujo, const Administrator *p);

		/*********+***********************/
		/** FUNCTIONS OF THE CLASS FILM **/
		/*********************************/

		/*
		 *@brief Changes the attributes of the user.
		 *@param
		 *@pre An object Administrator it was created
		 *@return
		 *@post The object will change their attributes.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void modifyUserAttributes();

};

#endif