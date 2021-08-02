
#ifndef USER_H
#define	USER_H

#include <string.h>
#include "Element.h"
using namespace std;

class User {

	protected: 
		
		string id_user;
		string surnames;
		string username;
		string urlPerfilPhoto;

		Element **search;
		int dim_search;

		void resizeSearchAdd();
		void resizeSearchDelete();

	public:

		/*********+********/
		/** CONSTRUCTORS **/
		/******************/

		//Default constructor.
		User();

		/*********+******************/
		/** SETS OF THE CLASS USER **/
		/****************************/

		/*

		 *@brief Set a string id to the attribute id_user of the object.
		 *@param id is the string that we will set.
		 *@pre An object User it was created.
		 *@post id will be the new id of the object.
		 *@return 
		 *@author Alejandro Nieto.
		 *@version: 1.0 

		*/
		inline void setID(string id) { this->id_user = id;}

		/*

		 *@brief Set a string surnms to the attribute surnames of the object.
		 *@param surnms is the string that we will set.
		 *@pre An object User it was created.
		 *@post surnms will be the new valur of surnames in the object.
		 *@return 
		 *@author Alejandro Nieto.
		 *@version: 1.0 

		*/
		inline void setSurnames(string surnms) { this->surnames = surnms;}

		/*

		 *@brief Set a string name to the attribute username of the object.
		 *@param name is the string that we will set.
		 *@pre An object User it was created.
		 *@post name will be the new username of the object.
		 *@return 
		 *@author Alejandro Nieto.
		 *@version: 1.0 

		*/
		inline void setUsername(string name) { this->username = name;}

		/*

		 *@brief Set a string url to the attribute urlPerfilPhoto of the object.
		 *@param url is the string that we will set.
		 *@pre An object User it was created.
		 *@post url will be the new urlPerfilPhoto of the object.
		 *@return 
		 *@author Alejandro Nieto.
		 *@version: 1.0 

		*/
		inline void setUrlPerfilPhoto(string url) { this->urlPerfilPhoto = url;}


		/*********+******************/
		/** GETS OF THE CLASS USER **/
		/****************************/

		/*
	
		 *@brief Bring back the value of the attribute id_user.
		 *@param
		 *@pre An object User it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the int value in id_user.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline string getID() const { return this->id_user; }

		/*
	
		 *@brief Bring back the value of the attribute surnames.
		 *@param
		 *@pre An object User it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the string value in surnames.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline string getSurnames() const { return this->surnames; }

		/*
	
		 *@brief Bring back the value of the attribute username.
		 *@param
		 *@pre An object User it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the string value in username.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline string getUsername() const { return this->username; }

		/*
	
		 *@brief Bring back the value of the attribute urlPerfilPhoto.
		 *@param
		 *@pre An object User it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the string value in urlPerfilPhoto.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline string getUrlPerfilPhoto() const { return this->urlPerfilPhoto;}

		/*
	
		 *@brief Bring back the value of the attribute dim_search.
		 *@param
		 *@pre An object User it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the int value in dim_search.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline int getDimSearch() const { return this->dim_search; }

		/*
	
		 *@brief Bring back the value of the attribute of the average punctuation of one element in the array search.
		 *@param position which is the position of the element we want the average punctuation.
		 *@pre An object User it was created && dim_search != 0.
		 *@post the value of the attribute will be returned.
		 *@return returns the int value in the element selected.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline int getAveragePunctuationInElementInUser(int position) const { return this->search[position]->getAveragePunctuation(); } 

		/*
	
		 *@brief Bring back the value of the attribute id of the element selected in search.
		 *@param position which is the position of the element we want the id
		 *@pre An object User it was created && dim_search != 0.
		 *@post the value of the attribute will be returned.
		 *@return returns the int value in the element selected.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline int getIDElementInSearch(int position) const { return this->search[position]->getIDElement(); } 


		/*********************************/
		/** FUNCTIONS OF THE CLASS USER **/
		/*********************************/

		
		/*
		 *@brief Add one element to the array of search
		 *@param elementToAdd which is the element we want to add
		 *@pre An object User it was created.
		 *@return
		 *@post the dim_search will increase in one and the element will be included.
		 *@author
		 *@ver 1.0
		*/
		void addElementToSearch(Element * elementToAdd);

		/*
		 *@brief Delete one element to the array of search
		 *@param position which is the position of the element we want to delete
		 *@pre An object User it was created.
		 *@return
		 *@post the dim_search will decrease in one and the element will be deleted.
		 *@author
		 *@ver 1.0
		*/
		void deleteElementInSearch(int position);

		/*
		 *@brief Filters all films and organize then by parameters
		 *@param
		 *@pre this->getDimElements() != 0
		 *@return
		 *@post the array of the userActual will be shown with the ranking of films.
		 *@author
		 *@ver 1.0
		*/
		void topFilms();

		/*
		 *@brief Filters all series and organize then by parameters
		 *@param
		 *@pre this->getDimElements() != 0
		 *@return
		 *@post the array of the userActual will be shown with the ranking of series.
		 *@author
		 *@ver 1.0
		*/
		void topSeries();

		/*
		 *@brief Filters all songs and organize then by parameters
		 *@param
		 *@pre this->getDimElements() != 0
		 *@return
		 *@post the array of the userActual will be shown with the ranking of songs.
		 *@author
		 *@ver 1.0
		*/
		void topSongs();

		/*
		 *@brief Filters all videogames and organize then by parameters
		 *@param
		 *@pre this->getDimElements() != 0
		 *@return
		 *@post the array of the userActual will be shown with the ranking of videogames.
		 *@author
		 *@ver 1.0
		*/
		void topVideoGames();

		/*
		 *@brief Changes the attributes of the user.
		 *@param
		 *@pre An object User it was created
		 *@return
		 *@post The object will change their attributes.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		virtual void modifyUserAttributes();

		/*
		 *@brief Deletes all the contenct of the search.
		 *@param
		 *@pre An object User it was created
		 *@return
		 *@post The object will change their attributes.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void searchToZero();

		/*********+*******************/
		/** PRINT OF THE CLASS USER **/
		/*****************************/

		/*

		 *@brief Shows the attributes of the object.
		 *@param
		 *@pre An object User it was created.
		 *@return
		 *@post All the attributes of the object will be printed on the screen.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		virtual void printUser() const;

		/*

		 *@brief Shows all the attributes of the object.
		 *@param
		 *@pre An object User it was created.
		 *@return
		 *@post All the attributes of the object will be printed on the screen.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		virtual inline void printElementsInUser() const {};

		/*

		 *@brief Shows all the searchs of the object.
		 *@param
		 *@pre An object User it was created.
		 *@return
		 *@post All the elements in search of the object will be printed on the screen.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		void printSearch() const;

		/*

		 *@brief Shows one element in search of the object.
		 *@param position of the element we want to print
		 *@pre An object User it was created.
		 *@return
		 *@post All the attributes of the element will be printed on the screen.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline void printElementInSearch(int position) const { return this->search[position]->printElement(); }

		/*********+**********************/
		/** OVERLOAD OF THE CLASS USER **/
		/********************************/

		/*
		 *@brief Overload of the operator =
		 *@author Alejandro Nieto.
		 *@version: 1.0
		*/
		User& operator=(const User &example);

		/*
		 * @brief Overload of the operator >> when there is a User to print their values.
		 *@author Alejandro Nieto.
		 *@version: 1.0
		*/
		friend istream& operator>>(istream &flujo, User * p);

		/*
		 * @brief Overload of the operator << when there is a User to introduce their values.
		 *@author Alejandro Nieto.
		 *@version: 1.0
		*/
		friend ostream& operator<<(ostream &flujo, const User * p);


		/*********+************************/
		/** DESTRUCTOR OF THE CLASS USER **/
		/**********************************/

		//Destructor of User
		virtual ~User();
};



#endif	/* USER_H */