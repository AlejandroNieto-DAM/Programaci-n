#ifndef FILM_H
#define	FILM_H

#include <string.h>
#include <iostream>
#include "Element.h"
using namespace std;


class Film: public Element {

	protected: 

		string script;
		string productor;
		string cast;
		string direction;

	public:

		/*********+*******/
		/** CONSTRUCTOR **/
		/*****************/

		//Default constructor.
		Film();

		/*********+******************/
		/** SETS OF THE CLASS FILM **/
		/****************************/

		/*

		 *@brief Set a string cast to the attribute cast of the object.
		 *@param cast is the string that we will set.
		 *@pre An object Film it was created.
		 *@post cast will be the new value of cast in the object.
		 *@return 
		 *@author Alejandro Nieto.
		 *@version: 1.0 

		*/
		inline void setCast(string cast) { this->cast = cast; }

		/*

		 *@brief Set a string direction to the attribute visualizations of the object.
		 *@param direction is the int that we will set.
		 *@pre An object Film it was created.
		 *@post direction will be the new value of direction in the object.
		 *@return 
		 *@author Alejandro Nieto.
		 *@version: 1.0 

		*/
		inline void setDirection(string direction) { this->direction = direction; }

		/*

		 *@brief Set a string script to the attribute script of the object.
		 *@param script is the int that we will set.
		 *@pre An object Film it was created.
		 *@post script will be the new value of script in the object.
		 *@return 
		 *@author Alejandro Nieto.
		 *@version: 1.0 

		*/
		inline void setScript(string script) { this->script = script; }

		/*

		 *@brief Set a string productor to the attribute productor of the object.
		 *@param productor is the int that we will set.
		 *@pre An object Film it was created.
		 *@post productor will be the new value of productor in the object.
		 *@return 
		 *@author Alejandro Nieto.
		 *@version: 1.0 

		*/
		inline void setProductor(string productor) { this->productor = productor; }



		/*********+***********************/
		/** FUNCTIONS OF THE CLASS FILM **/
		/*********************************/

		/*
	
		 *@brief Bring back the value of the attribute cast.
		 *@param
		 *@pre An object Element it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the string value of cast.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline string getCast() const { return this->cast; }

		/*
	
		 *@brief Bring back the value of the attribute direction.
		 *@param
		 *@pre An object Element it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the string value of direction.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline string getDirection() const { return this->direction; }

		/*
	
		 *@brief Bring back the value of the attribute script.
		 *@param
		 *@pre An object Element it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the string value of script.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline string getScript() const { return this->script; }

		/*
	
		 *@brief Bring back the value of the attribute productor.
		 *@param
		 *@pre An object Element it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the string value of productor.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline string getProductor() const { return this->productor; }

		/*********+********************/
		/** PRINTS OF THE CLASS FILM **/
		/******************************/

		/*

		 *@brief Shows all the attributes of the object.
		 *@param
		 *@pre An object Film it was created.
		 *@return
		 *@post All the attributes without the comments and valorations of the object will be printed on the screen.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		virtual void printElement();

		/*

		 *@brief Shows all the content of the object.
		 *@param
		 *@pre An object Film it was created and dim_arrayComments != 0 && dim_arrayValorations != 0.
		 *@return
		 *@post All the content of the object will be printed on the screen.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		virtual void printElementAtAll();

		

		/*********+***********************/
		/** OVERLOADS OF THE CLASS FILM **/
		/*********************************/

		/*
		 *@brief Overload of the operator =
		 *@author Alejandro Nieto.
		 *@version: 1.0
		*/
		Film& operator=(const Film &elementToCopy);

		/*
		 *@brief Overload of the operator <<
		 *@author Alejandro Nieto.
		 *@version: 2.0
		*/
		friend ostream& operator<<(ostream &flujo, const Film * p);

		/*
		 *@brief Overload of the operator >>
		 *@author Alejandro Nieto.
		 *@version: 2.0
		*/
		friend istream& operator>>(istream &flujo, Film * p);

		/*********+************************/
		/** DESTRUCTOR OF THE CLASS FILM **/
		/**********************************/

		//Destructor of Film.
		virtual ~Film();

		/*********+***********************/
		/** FUNCTIONS OF THE CLASS FILM **/
		/*********************************/

		/*
		 *@brief Changes the attributes of the element.
		 *@param
		 *@pre An object Element it was created
		 *@return
		 *@post The object will change their attributes.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		virtual void modifyElementAttributes();

};

#endif