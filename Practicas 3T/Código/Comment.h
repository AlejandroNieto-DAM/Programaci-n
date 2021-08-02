#ifndef COMMENT_H
#define	COMMENT_H

#include <string.h>
#include <iostream>
using namespace std;

class Comment {

	private:

		unsigned int id_comment;
		string id_userInComment;
		string valoration;

	public:

		/*********+********/
		/** CONSTRUCTORS **/
		/******************/

		//Default constructor.
		Comment();
		//Constructor by parameters.
		Comment(unsigned int id_comnt, string id_usr, string descrp);
		//Constructor per copy.
		Comment(const Comment& commt);

		/*********+*********************/
		/** SETS OF THE CLASS COMMENT **/
		/*******************************/

		/*

		 *@brief Set a string id_comnt to the attribute id_comment of the object.
		 *@param id_comnt is the string that we will set.
		 *@pre An object Comment it was created.
		 *@post id_comnt will be the new id_comment of the object.
		 *@return 
		 *@author Alejandro Nieto.
		 *@version: 1.0 

		*/
		inline void setIDComment(unsigned int id_cmnt) { this->id_comment = id_cmnt; }

		/*

		 *@brief Set a string id_usr to the attribute id_userInComment of the object.
		 *@param id_usr is the string that we will set.
		 *@pre An object Comment it was created.
		 *@post id_usr will be the new id_comment of the object.
		 *@return 
		 *@author Alejandro Nieto.
		 *@version: 1.0 

		*/
		inline void setIDUserInComment(string id_usr) { this->id_userInComment = id_usr; }

		/*

		 *@brief Set a string descrp to the attribute valoration of the object.
		 *@param descrp is the string that we will set.
		 *@pre An object Comment it was created.
		 *@post descrp will be the new valoration of the object.
		 *@return 
		 *@author Alejandro Nieto.
		 *@version: 1.0 

		*/
		inline void setValoration(string descrp) { this->valoration = descrp; }


		/*********+*********************/
		/** GETS OF THE CLASS COMMENT **/
		/*******************************/

		/*
	
		 *@brief Bring back the value of the attribute id_comment.
		 *@param
		 *@pre An object Comment it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the string value in id_comment.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline unsigned int getIDComment() const { return this->id_comment; }

		/*
	
		 *@brief Bring back the value of the attribute id_userInComment.
		 *@param
		 *@pre An object Comment it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the string value in id_userInComment.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline string getIDUserInComment() const { return this->id_userInComment; }

		/*
	
		 *@brief Bring back the value of the attribute valoration.
		 *@param
		 *@pre An object Comment it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the string value in valoration.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline string getValoration() const { return this->valoration; }


		/*********+***********************/
		/** PRINTS OF THE CLASS COMMENT **/
		/*********************************/

		/*

		 *@brief Shows all the content of the object.
		 *@param
		 *@pre An object Comment it was created.
		 *@return
		 *@post All the content of the object will be printed on the screen.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		void printComment();

		/*********+*************************/
		/** OVERLOAD OF THE CLASS COMMENT **/
		/***********************************/

		/*
		 *@brief Overload of the operator = 
		 *@author Alejandro Nieto.
		 *@version: 1.0
		*/
		Comment& operator=(const Comment &example);

		/*********+***************************/
		/** DESTRUCTOR OF THE CLASS COMMENT **/
		/*************************************/

		//Destructor of Valoration.
		~Comment();



};


#endif
