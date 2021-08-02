#ifndef SONG_H
#define	SONG_H

#include <string.h>
#include <iostream>
#include "Element.h"
using namespace std;


class Song: public Element {

	private: 

		string artist;
		string album;

	public:

		/*********+*******/
		/** CONSTRUCTOR **/
		/*****************/

		//Default constructor.
		Song();

		/*********+******************/
		/** SETS OF THE CLASS SONG **/
		/****************************/

		/*

		 *@brief Set a string artist to the attribute artist of the object.
		 *@param artist is the string that we will set.
		 *@pre An object Song it was created.
		 *@post artist will be the new value of artist in the object.
		 *@return 
		 *@author Alejandro Nieto.
		 *@version: 1.0 

		*/
		inline void setArtist(string artist) { this->artist = artist; }

		/*

		 *@brief Set a string album to the attribute album of the object.
		 *@param album is the string that we will set.
		 *@pre An object Song it was created.
		 *@post album will be the new value of album in the object.
		 *@return 
		 *@author Alejandro Nieto.
		 *@version: 1.0 

		*/
		inline void setAlbum(string album) { this->album = album; }


		/*********+***********************/
		/** FUNCTIONS OF THE CLASS SONG **/
		/*********************************/

		/*
	
		 *@brief Bring back the value of the attribute artist.
		 *@param
		 *@pre An object Song it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the string value of artist.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline string getArtist() const { return this->artist; }

		/*
	
		 *@brief Bring back the value of the attribute album.
		 *@param
		 *@pre An object Song it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the string value of album.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline string getAlbum() const { return this->album; }

		

		/*********+********************/
		/** PRINTS OF THE CLASS SONG **/
		/******************************/

		/*

		 *@brief Shows all the attributes of the object.
		 *@param
		 *@pre An object Song it was created.
		 *@return
		 *@post All the attributes without the comments and the valorations of the object will be printed on the screen.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		virtual void printElement();

		/*

		 *@brief Shows all the content of the object.
		 *@param
		 *@pre An object Film it was created and dim_arrayComments != 0 && dim_arrayValorations = 0.
		 *@return
		 *@post All the content of the object will be printed on the screen.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		virtual void printElementAtAll();

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

		/*********+***********************/
		/** OVERLOADS OF THE CLASS SONG **/
		/*********************************/

		/*
		 *@brief Overload of the operator =
		 *@author Alejandro Nieto.
		 *@version: 1.0
		*/
		Song& operator=(const Song &elementToCopy);

		/*
		 *@brief Overload of the operator <<
		 *@author Alejandro Nieto.
		 *@version: 2.0
		*/
		friend ostream& operator<<(ostream &flujo, const Song * p);

		/*
		 *@brief Overload of the operator >>
		 *@author Alejandro Nieto.
		 *@version: 2.0
		*/
		friend istream& operator>>(istream &flujo, Song * p);

		/*********+************************/
		/** DESTRUCTOR OF THE CLASS SONG **/
		/**********************************/

		//Destructor of Song.
		~Song();

};

#endif