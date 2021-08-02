#ifndef CRISTOFINITY_H
#define	CRISTOFINITY_H

#include <string>
#include "Element.h"
#include "User.h"
#include "UserNormal.h"
#include "Film.h"
#include <iostream>
#include <stdlib.h>
#include "Administrator.h"



class CristoFinity {

	private:

		Element **array_ExistingElements;
		User **array_ExistingUsers;

		int dim_existingElements;
		int dim_existingUsers;

		User *userActual;
		

		/*********+************************/
		/** RESIZES OF THE CLASS ELEMENT **/
		/**********************************/

		/*
	
		 * @brief Increase the dimension of the array of users of the class CristoFinity.
		 * @pre You want to add a non-existent new user.
		 * @post Array will be increased in 1.
		 * @ver 2.0
		 * @author Alejandro Nieto.
		 
		*/
		void resizeCristoFinityAddUser();

		/*
	
		 * @brief Increase the dimension of the array of elements of the class CristoFinity.
		 * @pre You want to add a non-existent new element.
		 * @post Array will be increased in 1.
		 * @ver 2.0
		 * @author Alejandro Nieto.
		 
		*/
		void resizeCristoFinityAddElement();

		/*
	
		 * @brief Decrease the dimension of the array of users of the class CristoFinity.
		 * @pre You want to delete an existing user.
		 * @post Array will be decreased in 1.
		 * @ver 2.0
		 * @author Alejandro Nieto.
		 
		*/
		void resizeCristoFinityDeleteUser();

		/*
	
		 * @brief Decrease the dimension of the array of elements of the class CristoFinity.
		 * @pre You want to delete an existing element.
		 * @post Array will be decreased in 1.
		 * @ver 2.0
		 * @author Alejandro Nieto.
		 
		*/
		void resizeCristoFinityDeleteElement();


	public:

		/*********+*******/
		/** CONSTRUCTOR **/
		/*****************/

		//Default constructor.
		CristoFinity();

		/*********+*******************************/
		/** FUNCTIONS OF THE CLASS CRISTOFINITY **/
		/*****************************************/

		/*
	
		 *@brief Bring back the value of the attribute dim_existingElements.
		 *@param
		 *@pre An object CristoFinity it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the int value in dim_existingElements.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline int getDimElements() const { return this->dim_existingElements; }

		/*
	
		 *@brief Bring back the value of the attribute dim_existingUsers.
		 *@param
		 *@pre An object CristoFinity it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the int value in dim_existingUsers.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline int getDimUsers() const { return this->dim_existingUsers; }

		/*********+****************************/
		/** PRINTS OF THE CLASS CRISTOFINITY **/
		/**************************************/

		/*

		 *@brief Shows all the objects in the array of users of the object.
		 *@param
		 *@pre An object CristoFinity it was created.
		 *@return
		 *@post All the content of the array of users in the object will be printed on the screen.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		void printUsers();

		/*

		 *@brief Shows all the objects in the array of elements of the object.
		 *@param
		 *@pre An object CristoFinity it was created.
		 *@return
		 *@post All the content of the array of elements in the object will be printed on the screen.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		void printElements();

		/*

		 *@brief Shows all the content of the object.
		 *@param
		 *@pre An object CristoFinity it was created.
		 *@return
		 *@post All the content in the object will be printed on the screen.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		void printCristoFinity();

		/*********+********************************/
		/** DESTRUCTOR OF THE CLASS CRISTOFINITY **/
		/******************************************/

		//Destroyer of class CristoFinity.
		~CristoFinity();


		/*********+*******************************/
		/** FUNCTIONS OF THE CLASS CRISTOFINITY **/
		/*****************************************/

		/*

		 *@brief Adds a non-existing new user in the array of users of the object.
		 *@param userToAdd which is the user we want to set in the array.
		 *@post the array of users will be increased in 1.
		 *@author Alejandro Nieto.
		 *@version: 2.0

		*/
		void addUser(User * userToAdd);

		/*

		 *@brief Adds a non-existing new element in the array of elements of the object.
		 *@param userToAdd which is the element we want to set in the array.
		 *@post the array of elements will be increased in 1.
		 *@author Alejandro Nieto.
		 *@version: 2.0

		*/
		void addElement(Element * elementToAdd);

		/*
		 *@brief Imports all users in the file cristofinity.xml
		 *@param
		 *@pre Cristofinity have been created
		 *@return
		 *@post All the users and all their comments and valorations will be included.
		 *@author Alejandro Nieto
		 *@ver 6.0
		*/
		void importUsersXml();

		/*
		 *@brief Imports all elements in the file cristofinity.xml
		 *@param
		 *@pre Cristofinity have been created
		 *@return
		 *@post All the elements and all their comments and valorations will be included.
		 *@author Alejandro Nieto
		 *@ver 5.0
		*/
		void importMediaXml();

		/*
		 *@brief Export all data in the program to one file.
		 *@param string fich which is the name of the file you want to export all data
		 *@pre Cristofinity have been created
		 *@return
		 *@post All data in the program will be exported to a existing or new file.
		 *@author Alejandro Nieto
		 *@ver 3.0
		*/
		void exportXml(string fich);

		/*
		 *@brief Export all data in the program to one file when is called by users.
		 *@param
		 *@pre Cristofinity have been created
		 *@return
		 *@post All data in the program will be exported to a existing or new file.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void exportXMLbyUsers();

		/*
		 *@brief Will show the menu of login or exit.
		 *@param
		 *@pre Cristofinity have been created.
		 *@return
		 *@post Depending of the option taken you will be send to menu() or you will exit
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void menuLogin();

		/*
		 *@brief Will show the menu of normal user.
		 *@param
		 *@pre Cristofinity have been created and one normal user have been created.
		 *@return
		 *@post This menu will show all the options that can do a normal user
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void menuUser();

		/*
		 *@brief Will show the menu of admin.
		 *@param
		 *@pre Cristofinity have been created and userActual is an admin.
		 *@return
		 *@post This menu will show all the options that can do an admin
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void menuAdmin();

		/*
		 *@brief Asks for the login of the user.
		 *@param
		 *@pre Cristofinity have been created && dim_existingUsers.
		 *@return
		 *@post Depending if your admin or normal, you will be sent to other menu for your type.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void menu();

		/*
		 *@brief Allows one admin to register a normal user.
		 *@param
		 *@pre Cristofinity have been created and userActual is an admin.
		 *@return
		 *@post One user normal will be added to Cristofinity && getDimUsers will be increased in 1
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void normalUserRegister();

		/*
		 *@brief Allows one admin to register an admin user.
		 *@param
		 *@pre Cristofinity have been created and userActual is an admin.
		 *@return
		 *@post One admin user will be added to Cristofinity && dim_existingUsers will be increased in 1
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void administratorUserRegister();

		/*
		 *@brief Shows to one admin the option to register a normal user or admin user.
		 *@param
		 *@pre Cristofinity have been created and userActual is an admin.
		 *@return
		 *@post Depending of the option selected one user (normal | admin) will be register.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void userRegister();

		/*
		 *@brief Allows one admin to delete one user.
		 *@param
		 *@pre Cristofinity have been created and userActual is an admin.
		 *@return
		 *@post The user selected will be erased && dim_existingUsers.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void deleteUser();

		/*
		 *@brief Allows one admin 3 options of find users.
		 *@param
		 *@pre Cristofinity have been created and userActual is an admin.
		 *@return
		 *@post options selected will be printed on screen.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void findUser();

		/*
		 *@brief Allows one admin to find one user.
		 *@param
		 *@pre Cristofinity have been created and userActual is an admin.
		 *@return int which is the position of the user find
		 *@post The user will be printed with all his elements associated.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		int findIDUser();

		/*
		 *@brief Allows one admin to modify one user.
		 *@param
		 *@pre Cristofinity have been created and userActual is an admin.
		 *@return 
		 *@post The user selected will be modified.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void modifyUser();

		/*
		 *@brief Allows one normal user to modify himself.
		 *@param
		 *@pre Cristofinity have been created and userActual is a UserNormal.
		 *@return 
		 *@post The user selected will be modified.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void modifyMyUser();

		/*
		 *@brief Allows one normal user to add to his list of elements one element.
		 *@param
		 *@pre Cristofinity have been created && userActual is a UserNormal  && dim_existingElements != 0.
		 *@return 
		 *@post One element will be included in th array_visualizations of the user.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void addElementToUserNormal();

		/*
		 *@brief Allows one normal user to add one comment of one element in his list of elements.
		 *@param
		 *@pre Cristofinity have been created && userActual is a UserNormal  && dim_visualizations != 0.
		 *@return 
		 *@post One comment will be added to the element selected.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void userComment();

		/*
		 *@brief Allows one admin to comment one element in array_existingElements.
		 *@param
		 *@pre Cristofinity have been created && userActual is an admin  && dim_existingElements != 0.
		 *@return 
		 *@post One comment will be added to the element selected.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void adminComment();

		/*
		 *@brief Allows one admin to delete one comment of one element in array_existingElements.
		 *@param
		 *@pre Cristofinity have been created && userActual is an admin  && dim_existingElements != 0 && dimComments != 0 of this element.
		 *@return 
		 *@post One comment will be delete to the element selected.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void adminDeleteComment();

		/*
		 *@brief Allows one user to delete one comment of one element in his array_visualizations.
		 *@param
		 *@pre Cristofinity have been created && userActual is a user  && dim_visualizations != 0 && dimComments != 0 of this element.
		 *@return 
		 *@post One comment will be delete to the element selected.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void deleteCommentInMedia();

		/*
		 *@brief Find one introduced id in the ids of array_existingElements.
		 *@param
		 *@pre Cristofinity have been created.
		 *@return int position of the element searched
		 *@post The position of the element searched will be returned.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		int findIDElement();

		/*
		 *@brief Find one introduced id in the ids of array_visualizations in normal user.
		 *@param
		 *@pre Cristofinity have been created && dim_arrayVisualizations.
		 *@return int position of the element searched
		 *@post The position of the element searched will be returned.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		int findElementInNormalUser();

		/*
		 *@brief organize the elements by their IDs.
		 *@param
		 *@pre Cristofinity have been created && dim_existingUsers.
		 *@return
		 *@post the array_existingElements will be organized.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void organizeElementsByID();

		/*
		 *@brief Creates one new film and it will be added to the array_existingElements.
		 *@param
		 *@pre Cristofinity have been created.
		 *@return
		 *@post A new film will be added to array_existingElements.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void addFilm();

		/*
		 *@brief Creates one new series and it will be added to the array_existingElements.
		 *@param
		 *@pre Cristofinity have been created.
		 *@return
		 *@post A new series will be added to array_existingElements.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void addSeries();

		/*
		 *@brief Creates one new song and it will be added to the array_existingElements.
		 *@param
		 *@pre Cristofinity have been created.
		 *@return
		 *@post A new song will be added to array_existingElements.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void addSong();

		/*
		 *@brief Creates one new videogame and it will be added to the array_existingElements.
		 *@param
		 *@pre Cristofinity have been created.
		 *@return
		 *@post A new videogame will be added to array_existingElements.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void addVideoGame();

		/*
		 *@brief Shows the menu for create a type of element.
		 *@param
		 *@pre Cristofinity have been created && userActual needs to be an admin.
		 *@return
		 *@post Depending of the option taken one element of a specific type will be registered.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void elementRegister();

		/*
		 *@brief Asks for the user to introduce the id of one element to delete.
		 *@param
		 *@pre Cristofinity have been created && userActual needs to be an admin.
		 *@return
		 *@post the media selected will be deleted of array_existingElements and of all array_visualizations of the users and all his comments and valorations too.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void deleteElement();

		/*
		 *@brief Asks for the user to introduce the id of one element to modify.
		 *@param
		 *@pre Cristofinity have been created && userActual needs to be an admin.
		 *@return
		 *@post the element selected will be modified at all.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void modifyElement();

		/*
		 *@brief Calculates the id for elements when they are registered.
		 *@param
		 *@pre Cristofinity have been created && userActual needs to be an admin.
		 *@return
		 *@post a new id will be calculated for the new element.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		int nextID();

		/*
		 *@brief Calculates the totalLikes for all elements.
		 *@param One normal user have to add one media in his array_visualizations or is delete. 
		 *@pre Cristofinity have been created.
		 *@return
		 *@post a new totalLikes will be calculated for the elements.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void calculateTotalLikes();

		/*
		 *@brief Calculates the average punctuation on array_existingElements (following one formula) for all elements.
		 *@param 
		 *@pre Cristofinity have been created.
		 *@return
		 *@post a new average puntuaction will be calculated for the elements.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void consultAveragePunctuationOfElement();

		/*
		 *@brief Shows the average punctuations of all element.
		 *@param 
		 *@pre Cristofinity have been created.
		 *@return
		 *@post the average punctuation of elements will be printed.
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void seeAllAveragePunctuations();

		/*
		 *@brief Show options to find elements in array_ExitingElements
		 *@param
		 *@pre this->getDimElements() != 0
		 *@return
		 *@post All the options to find elements by parameters will be shown
		 *@author Alejandro Nieto.
		 *@ver 3.0
		*/
		void findElement();

		/*
		 *@brief Shows all media with punctuation +=5
		 *@param
		 *@pre this->getDimElements() != 0
		 *@return
		 *@post All the elements with +=5 punctuation will be printed.
		 *@author Alejandro Nieto.
		 *@ver 1.0
		*/
		void elementPlus5();

		/*
		 *@brief Shows all media with punctuation -5
		 *@param
		 *@pre this->getDimElements() != 0
		 *@return
		 *@post All the elements with -5 punctuation will be printed.
		 *@author Alejandro Nieto.
		 *@ver 1.0
		*/
		void elementLess5();

		/*
		 *@brief Organize all elements by their comments
		 *@param
		 *@pre this->getDimElements() != 0
		 *@return
		 *@post All the elements will be organized.
		 *@author Alejandro Nieto.
		 *@ver 3.0
		*/
		void organizeElementByComments();

		/*
		 *@brief Organize all elements by their name
		 *@param
		 *@pre this->getDimElements() != 0
		 *@return
		 *@post All the elements will be organized.
		 *@author Alejandro Nieto.
		 *@ver 3.0
		*/
		void organizeElementByName();

		/*
		 *@brief Calculates all comments for one user
		 *@param the user of who we want his comments
		 *@pre this->getDimComments() != 0
		 *@return
		 *@post the number of the total comments will be returned.
		 *@author Alejandro Nieto.
		 *@ver 1.0
		*/
		int calculateTotalCommentsOfUser(User *auxiliar);

		/*
		 *@brief Filters all films and you pass it for the search array of the userActual
		 *@param
		 *@pre this->getDimElements() != 0
		 *@return
		 *@post the array of the userActual will be shown with the ranking of films.
		 *@author Alejandro Nieto.
		 *@ver 3.0
		*/
		void topFilms();

		/*
		 *@brief Filters all series and you pass it for the search array of the userActual
		 *@param
		 *@pre this->getDimElements() != 0
		 *@return
		 *@post the array of the userActual will be shown with the ranking of series.
		 *@author Alejandro Nieto.
		 *@ver 1.0
		*/
		void topSeries();

		/*
		 *@brief Filters all songs and you pass it for the search array of the userActual
		 *@param
		 *@pre this->getDimElements() != 0
		 *@return
		 *@post the array of the userActual will be shown with the ranking of songs.
		 *@author Alejandro Nieto.
		 *@ver 1.0
		*/
		void topSongs();

		/*
		 *@brief Filters all videogames and you pass it for the search array of the userActual
		 *@param
		 *@pre this->getDimElements() != 0
		 *@return
		 *@post the array of the userActual will be shown with the ranking of videogames.
		 *@author Alejandro Nieto.
		 *@ver 1.0
		*/
		void topVideoGames();

		/*
		 *@brief Shows all the options that are for the rankings
		 *@param
		 *@pre this->getDimElements() != 0
		 *@return
		 *@post you will go to the ranking selected.
		 *@author Alejandro Nieto.
		 *@ver 1.0
		*/
		void rankings();

		/*
		 *@brief Filters all elements by some parameters
		 *@param
		 *@pre this->getDimElements() != 0
		 *@return
		 *@post the array of the userActual will be shown with the ranking of best media.
		 *@author Alejandro Nieto.
		 *@ver 1.0
		*/
		void topBestMedia();

		/*
		 *@brief Shows the options of ranking of type of elements
		 *@param
		 *@pre this->getDimElements() != 0
		 *@return
		 *@post the array of the userActual will be shown with the ranking of the option selected.
		 *@author Alejandro Nieto.
		 *@ver 1.0
		*/
		void topMediaByType();

		/*
		 *@brief Filters all users by some parameters
		 *@param
		 *@pre this->getDimUsers() != 0
		 *@return
		 *@post the users selected will be printed.
		 *@author Alejandro Nieto.
		 *@ver 1.0
		*/
		void topUsers();

		/*
		 *@brief Allows one admin to find one user by his login and print at all him
		 *@param
		 *@pre dim_existingUsers != 0
		 *@return
		 *@post the user selected will be printed on screen
		 *@author Alejandro Nieto
		 *@ver 2.0
		*/
		void findUserById();

		/*
		 *@brief Allows one admin to find users with +=3 elements associated
		 *@param
		 *@pre dim_existingUsers != 0
		 *@return
		 *@post the users selected will be printed on screen
		 *@author Alejandro Nieto
		 *@ver 2.0
		*/
		void findUsersPlus3();

		/*
		 *@brief Allows one admin to find users with +=3 elements associated
		 *@param
		 *@pre dim_existingUsers != 0
		 *@return
		 *@post the users selected will be printed on screen
		 *@author Alejandro Nieto
		 *@ver 1.0
		*/
		void findUsersLess3();

};



#endif


