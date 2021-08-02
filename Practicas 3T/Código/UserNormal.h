#ifndef USERNORMAL_H
#define	USERNORMAL_H

#include <string.h>
#include "Element.h"
#include "User.h"
using namespace std;

class UserNormal: public User {

	private:

		Element **array_visualizations;
		int dim_arrayVisualizations;

		/*********+***************************/
		/** RESIZES OF THE CLASS USERNORMAL **/
		/*************************************/

		/*
	
		 * @brief Increase the dimension of the array of visualizations of the class UserNormal.
		 * @pre You want to add a non-existent new element.
		 * @post Array will be increased in 1.
		 * @version 1.0
		 * @author Alejandro Nieto.
		 
		*/
		void resizeArrayVisualizationsAdd();

		/*
	
		 * @brief Decrease the dimension of the array of visualizations of the class UserNormal.
		 * @pre You want to delete an existing element.
		 * @post Array will be decreased in 1.
		 * @version 1.0
		 * @author Alejandro Nieto.
		 
		*/
		void resizeArrayVisualizationsDelete();

	public:

		/*********+********/
		/** CONSTRUCTORS **/
		/******************/

		//Default constructor.
		UserNormal();
		
		/*********+***********************/
		/** GET OF THE CLASS USERNORMAL **/
		/*********************************/

		/*
	
		 *@brief Bring back the value of the attribute dim_arrayVisualizations.
		 *@param
		 *@pre An object UserNormal it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the int value in dim_arrayVisualizations.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline int getDimVisualizations() const { return this->dim_arrayVisualizations; }

		/*
	
		 *@brief Bring back the value of the attribute id of one element in the array of visualizations.
		 *@param int position which is the position of the element in array_visualizations of we want his id
		 *@pre An object UserNormal it was created && dim_visualizations != 0.
		 *@post the value of the attribute will be returned.
		 *@return returns the int value in one element in the array of visualizations.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline int getIDElementInUser(int position) const { return this->array_visualizations[position]->getIDElement();}


		/*********+**************************/
		/** PRINTS OF THE CLASS USERNORMAL **/
		/************************************/

		/*

		 *@brief Shows all the attributes of the object.
		 *@param
		 *@pre An object UserNormal it was created.
		 *@return
		 *@post All the attributes of the object will be printed on the screen without the elements.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		void printUser() const;

		/*

		 *@brief Shows all the content of the object.
		 *@param
		 *@pre An object UserNormal it was created.
		 *@return
		 *@post All the attributes of the object will be printed on the screen with the elements.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		void printUserAtAll() const;

		/*

		 *@brief Shows all the elements visualized of the object.
		 *@param
		 *@pre An object UserNormal it was created.
		 *@return
		 *@post All the media visualized in the object.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		void printElementsInUser() const;

		/*********+*****************************/
		/** FUNCTIONS OF THE CLASS USERNORMAL **/
		/***************************************/

		/*
		 *@brief Adds one element in the array of visualizations.
		 *@param elementToAdd which is the element we want to add to this user
		 *@pre An object UserNormal it was created.
		 *@return
		 *@post dim_visualizations will be increased in 1 and the element will be added.
		 *@author Alejandro Nieto.
		 *@version: 1.0
		*/
		void addElement(Element * elementToAdd);

		/*

		 *@brief Adds a new element to the array of visualizations of the object.
		 *@param *elementToAdd which is the element that the user has visualized.
		 *@pre element need to exist.
		 *@return 
		 *@post dim_arrayVisualizations will increase in 1.
		 *@author Alejandro Nieto.
		 *@version: 1.0
		*/
		void addElementToNormalUser(Element * elementToAdd);

		/*

		 *@brief Delete one element of the array_elementVisualizaed.
		 *@param position of the element you want to delete.
		 *@pre element need to exist dim_arrayVisualizations != 0.
		 *@return 
		 *@post dim_arrayVisualizations will dencrease in 1.
		 *@author Alejandro Nieto.
		 *@version: 1.0
		*/
		void deleteElementInUser(int position);

		/*

		 *@brief Asks for the user one position for delete the element visualized.
		 *@pre dim_arrayVisualizations != 0.
		 *@return 
		 *@post dim_arrayVisualizations will decrease in 1.
		 *@author Alejandro Nieto.
		 *@version: 1.0
		*/
		void deleteElementToNormalUser();

		/*
		 *@brief Changes the attributes of the user.
		 *@param
		 *@pre An object User it was created
		 *@return
		 *@post The object will change their attributes.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void modifyUserAttributes();

		/*
		 *@brief Insert a comment in the object in that position.
		 *@param int position which is the position in the array_visualizations of the element we want to inser a comment.
		 *@pre dim_visualizations != 0
		 *@return
		 *@post One comment will be added with the user id to the element.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void insertComment(int position);

		/*********+****************************/
		/** OVERLOAD OF THE CLASS USERNORMAL **/
		/**************************************/

		/*
		 *@brief Overload of the operator =
		 *@author Alejandro Nieto.
		 *@version: 1.0
		*/
		UserNormal& operator=(const UserNormal &example);

		/*
		 * @brief Overload of the operator >> when there is a User to print their values.
		 *@author Alejandro Nieto.
		 *@version: 1.0
		*/
		friend ostream& operator<<(ostream &flujo, const UserNormal *p);
		
		/*
		 * @brief Overload of the operator << when there is a User to introduce their values.
		 *@author Alejandro Nieto.
		 *@version: 1.0
		*/
		friend istream& operator>>(istream &flujo, UserNormal *p);


		/*********+************************/
		/** DESTRUCTOR OF THE CLASS USER **/
		/**********************************/

		//Destructor of User
		~UserNormal();

};

#endif	/* USERNORMAL_H */