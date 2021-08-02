#ifndef ELEMENT_H
#define	ELEMENT_H

#include <string.h>
#include <iostream>
#include "Comment.h"
#include "Valoration.h"
using namespace std;

class Element {

	protected:


		unsigned int id_element;
		string title;
		string elementGenre;
		int elementDurationInSec;
		string publicationDate;
		int pegi;
		string description;
		int totalLikes;
		
	
		Comment **array_Comments;
		int dim_arrayComments;

		float punctuation;
		Valoration **array_Valorations;
		int dim_arrayValorations;

		float averagePunctuationOnCatalog;

		/*********+************************/
		/** RESIZES OF THE CLASS ELEMENT **/
		/**********************************/

		/*
	
		 * @brief Decrease the dimension of the array of comments of the class Element.
		 * @pre You want to delete an existing comment.
		 * @post Array will be decreased in 1.
		 * @version 1.0
		 * @author Alejandro Nieto.
		 
		*/
		void resizeArrayCommentsDelete();

		/*
	
		 * @brief Increase the dimension of the array of comments of the class Element.
		 * @pre You want to add a non-existent new comment.
		 * @post Array will be increased in 1.
		 * @version 3.0
		 * @author Alejandro Nieto.
		 
		*/
		void resizeArrayCommentsAdd();

		/*
	
		 * @brief Increase the dimension of the array of valorations of the class Element.
		 * @pre You want to add a non-existent new valoration.
		 * @post Array will be increased in 1.
		 * @version 1.0
		 * @author Alejandro Nieto.
		 
		*/
		void resizeArrayValorationsAdd();

		/*
	
		 * @brief Decrease the dimension of the array of valorations of the class Element.
		 * @pre You want to delete an existing valoration.
		 * @post Array will be decreased in 1.
		 * @version 1.0
		 * @author Alejandro Nieto.
		 
		*/
		void resizeArrayValorationsDelete();


	public:

		/*********+********/
		/** CONSTRUCTORS **/
		/******************/

		//Default constructor.
		Element();

		/*********+*********************/
		/** SETS OF THE CLASS ELEMENT **/
		/*******************************/

		/*

		 *@brief Set an unsigned int id to the attribute id_element of the object.
		 *@param id_elemnt is the unsigned int that we will set.
		 *@pre An object Element it was created.
		 *@post id_elemnt will be the new id of the object.
		 *@return 
		 *@author Alejandro Nieto.
		 *@version: 1.0 

		*/
		inline void setIDElement(unsigned int id_elemnt) { this->id_element = id_elemnt; }

		/*

		 *@brief Set a string titl to the attribute title of the object.
		 *@param titl is the string that we will set.
		 *@pre An object Element it was created.
		 *@post titl will be the new title of the object.
		 *@return 
		 *@author Alejandro Nieto.
		 *@version: 1.0 

		*/
		inline void setTitle(string titl) { this->title = titl; }

		/*

		 *@brief Set a string gnr to the attribute genre of the object.
		 *@param gnr is the string that we will set.
		 *@pre An object Element it was created.
		 *@post gnr will be the new genre of the object.
		 *@return 
		 *@author Alejandro Nieto.
		 *@version: 1.0 

		*/
		inline void setGenre(string gnr) { this->elementGenre = gnr; }

		/*

		 *@brief Set an int sec to the attribute elementDurationSec of the object.
		 *@param sec is the int that we will set.
		 *@pre An object Element it was created.
		 *@post sec will be the new elementDurationInSec of the object.
		 *@return 
		 *@author Alejandro Nieto.
		 *@version: 1.0 

		*/
		inline void setElementDuration(int sec) { this->elementDurationInSec = sec; }

		/*

		 *@brief Set a string date to the attribute publicationDate of the object.
		 *@param publicationDate is the string that we will set.
		 *@pre An object Element it was created.
		 *@post date will be the new publicationDate of the object.
		 *@return 
		 *@author Alejandro Nieto.
		 *@version: 1.0 

		*/
		inline void setPublicationDate(string date) { this->publicationDate = date; }

		/*

		 *@brief Set a string pgi to the attribute pegi of the object.
		 *@param pgi is the string that we will set.
		 *@pre An object Element it was created.
		 *@post pgi will be the new pegi of the object.
		 *@return 
		 *@author Alejandro Nieto.
		 *@version: 1.0 

		*/
		inline void setPegi(int pgi) { this->pegi = pgi; }

		/*

		 *@brief Set a string descrp to the attribute description of the object.
		 *@param descrp is the string that we will set.
		 *@pre An object Element it was created.
		 *@post descrp will be the new description of the object.
		 *@return 
		 *@author Alejandro Nieto.
		 *@version: 1.0 

		*/
		inline void setDescription(string descrp) { this->description = descrp; }


		/*

		 *@brief Set a float punctuation to the attribute punctuation of the object.
		 *@param punctuation is the float that we will set.
		 *@pre An object Element it was created.
		 *@post punctuation will be the new value of punctuation in the object.
		 *@return 
		 *@author Alejandro Nieto.
		 *@version: 1.0 

		*/
		inline void setPunctuation(float punctuation) { this->punctuation = punctuation; }

		/*

		 *@brief Set an int totalLikes to the attribute totalLikes of the object.
		 *@param totalLikes is the int that we will set.
		 *@pre An object Element it was created.
		 *@post totalLikes will be the new value of totalLikes in the object.
		 *@return 
		 *@author Alejandro Nieto.
		 *@version: 1.0 

		*/
		inline void setTotalLikes(int totalLikes) { this->totalLikes = totalLikes; }

		/*

		 *@brief Set a float averagePunctuationOnCatalog to the attribute averagePunctuationonCatalog of the object.
		 *@param averagePunctuationOnCatalog is the float that we will set.
		 *@pre An object Element it was created.
		 *@post averagePunctuationOnCatalog will be the new value of averagePunctuationOnCatalog in the object.
		 *@return 
		 *@author Alejandro Nieto.
		 *@version: 1.0 

		*/
		inline void setAveragePunctuation(float averagePunctuationOnCatalog) { this->averagePunctuationOnCatalog = averagePunctuationOnCatalog; }

		/*********+*********************/
		/** GETS OF THE CLASS ELEMENT **/
		/*******************************/

		/*
	
		 *@brief Bring back the value of the attribute id_element.
		 *@param
		 *@pre An object Element it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the unsigned int value in id_element.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline unsigned int getIDElement() const { return this->id_element; }

		/*
	
		 *@brief Bring back the value of the attribute title.
		 *@param
		 *@pre An object Element it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the string value of title.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline string getTitle() const { return this->title; }

		/*
	
		 *@brief Bring back the value of the attribute elementGenre.
		 *@param
		 *@pre An object Element it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the string value of elementGenre.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline string getGenre() const { return this->elementGenre; }

		/*
	
		 *@brief Bring back the value of the attribute elementDurationInSec.
		 *@param
		 *@pre An object Element it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the int value of elementDurationInSec.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline int getElementDuration() const { return this->elementDurationInSec; }

		/*
	
		 *@brief Bring back the value of the attribute publicationDate.
		 *@param
		 *@pre An object Element it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the string value of publicationDate.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline string getPublicationDate() const { return this->publicationDate; }

		/*
	
		 *@brief Bring back the value of the attribute pegi.
		 *@param
		 *@pre An object Element it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the int value of pegi.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline int getPegi() const { return this->pegi; }

		/*
	
		 *@brief Bring back the value of the attribute description.
		 *@param
		 *@pre An object Element it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the string value of description.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline string getDescription() const { return this->description; }

		
		/*
	
		 *@brief Bring back the value of the attribute punctuation.
		 *@param
		 *@pre An object Element it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the float value of punctuation.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline float getPunctuation() const { return this->punctuation; }


		/*
	
		 *@brief Bring back the value of the attribute totalLikes.
		 *@param
		 *@pre An object Element it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the int value of totalLikes.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline int getTotalLikes() const { return this->totalLikes; }

		/*
	
		 *@brief Bring back the value of the attribute dim_arrayComments.
		 *@param
		 *@pre An object Element it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the int value of dim_arrayComments.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline int getDimComments() const { return this->dim_arrayComments; }

		/*
	
		 *@brief Bring back the value of the attribute dim_arrayValorations.
		 *@param
		 *@pre An object Element it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the int value of dim_arrayValorations.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline int getDimValorations() const { return this->dim_arrayValorations; }

		/*
	
		 *@brief Bring back the value of the attribute averagePunctuationOnCatalog.
		 *@param
		 *@pre An object Element it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the float value of averagePunctuationOnCatalog.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline float getAveragePunctuation() const { return this->averagePunctuationOnCatalog; }

		/*
	
		 *@brief Bring back the value of the id of the comment in the position [i].
		 *@param int position which is the position of the comment we want the id
		 *@pre An object Element it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the int value of the id of comment.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline int getIDCommentInElement(int position) const { return this->array_Comments[position]->getIDComment();}

		/*
	
		 *@brief Bring back the login of the user who creates the comment in the position [i].
		 *@param int position which is the position of the comment we want the login
		 *@pre An object Element it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the string value of the login in comment.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline string getIDUserInComment(int position) const { return this->array_Comments[position]->getIDUserInComment();}

		/*
	
		 *@brief Bring back the description of the user who creates the comment in the position [i].
		 *@param int position which is the position of the comment we want the description
		 *@pre An object Element it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the string value of the description in comment.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline string getValorationInElement(int position) const { return this->array_Comments[position]->getValoration();}

		/*
	
		 *@brief Bring back the login of the user who creates the valoration in the position [i].
		 *@param int position which is the position of the valoration we want the login
		 *@pre An object Element it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the string value of the login in valoration.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline string getIDUserValoration(int position) const { return this->array_Valorations[position]->getIDUserValoration();}

		/*
	
		 *@brief Bring back the value of the valoration points of the valoration in the position [i].
		 *@param int position which is the position of the valoration we want the valoration points
		 *@pre An object Element it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the float value of the valoration points of valoration.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline float getValorationPoints(int position) const { return this->array_Valorations[position]->getValorationPoints();}


		/*
	
		 *@brief Bring back the value of the id of the valoration in the position [i].
		 *@param int position which is the position of the valoration we want the id
		 *@pre An object Element it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the int value of the id of valoration.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline unsigned int getIDValoration(int position) const { return this->array_Valorations[position]->getIDValoration();}

		/*********+**************************/
		/** FUNCTIONS OF THE CLASS ELEMENT **/
		/************************************/

		/*
		 *@brief Adds a non-existing comment in the object.
		 *@param *commentToAdd which is the pointer we will set.
		 *@author Alejandro Nieto
		 *@version: 3.0
		*/
		void addComment(Comment * commentToAdd);

		/*
		 *@brief Adds a non-existing valoration in the object.
		 *@param *valorationToAdd which is the pointer we will set.
		 *@author Alejandro Nieto
		 *@version: 3.0
		*/
		void addValoration(Valoration * valorationToAdd);

		/*
		 *@brief Delete an existing comment in the object.
		 *@param position which is the position of the comment we will delete.
		 *@author Alejandro Nieto
		 *@version: 3.0
		*/
		void deleteComment(int position);

		/*
		 *@brief Delete an existing valoraiton in the object.
		 *@param position which is the position of the valoration we will delete.
		 *@author Alejandro Nieto
		 *@version: 3.0
		*/
		void deleteValoration(int position);

		/*

		 *@brief Gives the posibility to add one comment in one Element
		 *@param
		 *@pre An object Element it was created
		 *@post One comment will be set to this element
		 *@return
		 *@author Alejandro Nieto.
		 *@version: 2.0

		*/
		void insertComment(string login);

		/*

		 *@brief Gives the posibility to delete one comment in one Element
		 *@param
		 *@pre An object Element it was created and dim_arrayComments != 0
		 *@post One comment will be delete in this element
		 *@return
		 *@author Alejandro Nieto.
		 *@version: 2.0

		*/
		void deleteCommentInElement();


		/*

		 *@brief Calculates the punctuation addend all the valorations and calculating the average.
		 *@param
		 *@pre dim_arrayValorations != 0
		 *@return
		 *@post The punctuation of the element will be calculated and it will be set.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		void calculatePunctuation();

		/*

		 *@brief Organize the Comments and Valorations by the id.
		 *@param
		 *@pre dim_arrayValorations != 0 && dim_arrayComments != 0
		 *@return
		 *@post The positions int the vector will be changed.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		void organizeCommentsValorations();

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


		/*********+***********************/
		/** PRINTS OF THE CLASS ELEMENT **/
		/*********************************/

		/*

		 *@brief Shows all the attributes of the object.
		 *@param
		 *@pre An object Element it was created and dim_arrayComments != 0.
		 *@return
		 *@post All the attributes without the comments of the object will be printed on the screen.
		 *@author Alejandro Nieto.
		 *@version: 2.0

		*/
		virtual void printElement();

		/*

		 *@brief Shows all the content of the object.
		 *@param
		 *@pre An object Element it was created.
		 *@return
		 *@post All the content of the object will be printed on the screen.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		virtual void printElementAtAll();

		/*

		 *@brief Shows all the comments of the object.
		 *@param
		 *@pre An object Element it was created and dim_arrayComments != 0.
		 *@return
		 *@post All the comments of the object will be printed on the screen.
		 *@author Alejandro Nieto.
		 *@version: 2.0

		*/
		void printComments();

		/*

		 *@brief Shows all the valorations of the object.
		 *@param
		 *@pre An object Element it was created and dim_arrayValorations != 0.
		 *@return
		 *@post All the valorations of the object will be printed on the screen.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		void printValorations();

		/*********+**************************/
		/** OVERLOADS OF THE CLASS ELEMENT **/
		/************************************/

		/*
		 *@brief Overload of the operator =
		 *@author Alejandro Nieto.
		 *@version: 2.0
		*/
		Element& operator=(const Element &elementToCopy);

		/*
		 *@brief Overload of the operator <<
		 *@author Alejandro Nieto.
		 *@version: 2.0
		*/
		friend ostream& operator<<(ostream &flujo, Element * p);

		/*
		 *@brief Overload of the operator >>
		 *@author Alejandro Nieto.
		 *@version: 2.0
		*/
		friend istream& operator>>(istream &flujo, Element * p);

		/*********+***************************/
		/** DESTRUCTOR OF THE CLASS ELEMENT **/
		/*************************************/

		//Destructor of Element.
		virtual ~Element();

};

#endif
