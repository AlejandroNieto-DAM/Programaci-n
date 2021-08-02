#ifndef VIDEOGAME_H
#define	VIDEOGAME_H

#include <string.h>
#include <iostream>
#include "Element.h"
using namespace std;

class VideoGame: public Element {

	private:

		string developer;
		string editor;
		unsigned int players;
		string platform;

	public:

		/*********+********/
		/** CONSTRUCTORS **/
		/******************/

		//Default constructor.
		VideoGame();


		/*********+***********************/
		/** SETS OF THE CLASS VIDEOGAME **/
		/*********************************/

		/*

		 *@brief Set a string developer to the attribute developer of the object.
		 *@param developer is the string that we will set.
		 *@pre An object VideoGame it was created.
		 *@post developer will be the new value of developer in the object.
		 *@return 
		 *@author Alejandro Nieto.
		 *@version: 1.0 

		*/
		inline void setDeveloper(string developer) { this->developer = developer; }
		
		/*

		 *@brief Set a string editor to the attribute editor of the object.
		 *@param editor is the string that we will set.
		 *@pre An object VideoGame it was created.
		 *@post editor will be the new value of editor in the object.
		 *@return 
		 *@author Alejandro Nieto.
		 *@version: 1.0 

		*/
		inline void setEditor(string editor) { this->editor = editor; }

		/*

		 *@brief Set an unsigned int players to the attribute players of the object.
		 *@param players is the string that we will set.
		 *@pre An object VideoGame it was created.
		 *@post players will be the new value of players in the object.
		 *@return 
		 *@author Alejandro Nieto.
		 *@version: 1.0 

		*/
		inline void setPlayers(unsigned int players) { this->players = players; }
		
		/*

		 *@brief Set a string platform to the attribute platform of the object.
		 *@param platform is the string that we will set.
		 *@pre An object VideoGame it was created.
		 *@post platform will be the new value of platform in the object.
		 *@return 
		 *@author Alejandro Nieto.
		 *@version: 1.0 

		*/
		inline void setPlatform(string platform) { this->platform = platform; }

		
		/*********+****************************/
		/** FUNCTIONS OF THE CLASS VIDEOGAME **/
		/**************************************/

		/*
	
		 *@brief Bring back the value of the attribute developer.
		 *@param
		 *@pre An object VideoGame it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the string value of developer.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline string getDeveloper() const { return this->developer; }

		/*
	
		 *@brief Bring back the value of the attribute editor.
		 *@param
		 *@pre An object VideoGame it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the string value of editor.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline string getEditor() const { return this->editor; }

		/*
	
		 *@brief Bring back the value of the attribute players.
		 *@param
		 *@pre An object VideoGame it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the unsigned int value of players.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline unsigned int getPlayers() const { return this->players; }

		/*
	
		 *@brief Bring back the value of the attribute platform.
		 *@param
		 *@pre An object VideoGame it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the string value of platform.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline string getPlatform() const { return this->platform; }

		
		/*********+*************************/
		/** PRINTS OF THE CLASS VIDEOGAME **/
		/***********************************/

		/*

		 *@brief Shows all the attributes of the object.
		 *@param
		 *@pre An object VideoGame it was created.
		 *@return
		 *@post All the attributes without the comments and the valorations of the object will be printed on the screen.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		void printElement();

		/*

		 *@brief Shows all the content of the object.
		 *@param
		 *@pre An object VideoGame it was created and dim_arrayComments != 0 && dim_arrayValorations != 0..
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

		/*********+***********************/
		/** OVERLOADS OF THE CLASS FILM **/
		/*********************************/

		/*
		 *@brief Overload of the operator =
		 *@author Alejandro Nieto.
		 *@version: 1.0
		*/
		VideoGame& operator=(const VideoGame &elementToCopy);

		/*
		 *@brief Overload of the operator <<
		 *@author Alejandro Nieto.
		 *@version: 2.0
		*/
		friend ostream& operator<<(ostream &flujo, const VideoGame * p);

		/*
		 *@brief Overload of the operator >>
		 *@author Alejandro Nieto.
		 *@version: 2.0
		*/
		friend istream& operator>>(istream &flujo, VideoGame * p);

		
		/*********+*****************************/
		/** DESTRUCTOR OF THE CLASS VIDEOGAME **/
		/***************************************/

		//Destructor of VideoGame.
		~VideoGame();



};

#endif