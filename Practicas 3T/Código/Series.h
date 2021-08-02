#ifndef SERIE_H
#define	SERIE_H

#include <string.h>
#include <iostream>
#include "Element.h"
#include "Film.h"
using namespace std;

class Series: public Film {

	private:

		unsigned int seasons;
		unsigned int chapters;
		bool inEmision;

	public:

		/*********+********/
		/** CONSTRUCTORS **/
		/******************/

		//Default constructor.
		Series();

		/*********+********************/
		/** SETS OF THE CLASS SERIES **/
		/******************************/

		/*

		 *@brief Set an unsigned int value to the attribute seasons of the object.
		 *@param seasons is the unsinged int that we will set.
		 *@pre An object Series it was created.
		 *@post seasons will be the new value of seasons in the object.
		 *@return 
		 *@author Alejandro Nieto.
		 *@version: 1.0 

		*/
		inline void setSeasons(unsigned int seasons) { this->seasons = seasons; }

		/*

		 *@brief Set an unsigned int value to the attribute chapters of the object.
		 *@param chapters is the unsinged int that we will set.
		 *@pre An object Series it was created.
		 *@post chapters will be the new value of chapters in the object.
		 *@return 
		 *@author Alejandro Nieto.
		 *@version: 1.0 

		*/
		inline void setChapters(unsigned int chapters) { this->chapters = chapters; }

		/*

		 *@brief Set a bool value to the attribute inEmision of the object.
		 *@param state is the unsinged int that we will set.
		 *@pre An object Series it was created.
		 *@post state will be the new value of inEmision in the object.
		 *@return 
		 *@author Alejandro Nieto.
		 *@version: 1.0 

		*/
		inline void setEmision(bool state) { this->inEmision = state; }



		/*********+********************/
		/** GETS OF THE CLASS SERIES **/
		/******************************/

		/*
	
		 *@brief Bring back the value of the attribute seasons.
		 *@param
		 *@pre An object Series it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the unsigned int value in seasons.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline unsigned int getSeasons() const { return this->seasons; }

		/*
	
		 *@brief Bring back the value of the attribute chapters.
		 *@param
		 *@pre An object Series it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the unsigned int value in chapters.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline unsigned int getChapters() const { return this->chapters; }

		/*
	
		 *@brief Bring back the value of the attribute inEmision.
		 *@param
		 *@pre An object Series it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the bool value in chapters.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline bool getEmision() const { return this->inEmision; }


		/*********+**********************/
		/** PRINTS OF THE CLASS SERIES **/
		/********************************/

		/*

		 *@brief Shows all the attributes of the object.
		 *@param
		 *@pre An object Series it was created.
		 *@return
		 *@post All the attributes without the comments of the object will be printed on the screen.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		void printElement();

		/*

		 *@brief Shows all the content of the object.
		 *@param
		 *@pre An object Series it was created and dim_arrayComments != 0.
		 *@return
		 *@post All the content of the object will be printed on the screen.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		void printElementAtAll();

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
		void modifyElementAttributes();

		/*********+*************************/
		/** OVERLOADS OF THE CLASS SERIES **/
		/***********************************/

		/*
		 *@brief Overload of the operator =
		 *@author Alejandro Nieto.
		 *@version: 1.0
		*/
		Series& operator=(const Series &elementToCopy);

		/*
		 *@brief Overload of the operator <<
		 *@author Alejandro Nieto.
		 *@version: 1.0
		*/
		friend ostream& operator<<(ostream &flujo, const Series * p);

		/*
		 *@brief Overload of the operator >>
		 *@author Alejandro Nieto.
		 *@version: 1.0
		*/
		friend istream& operator>>(istream &flujo, Series * p);


		/*********+***************************/
		/** DESTRUCTOR OF THE CLASS ELEMENT **/
		/*************************************/

		//Destructor of Series.
		~Series();

};

#endif