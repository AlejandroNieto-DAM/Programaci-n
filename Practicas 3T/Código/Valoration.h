#ifndef VALORATION_H
#define	VALORATION_H

#include <string.h>
#include <iostream>
using namespace std;

class Valoration {

	private:

		unsigned int id_valoration;
		string id_userValoration;
		float valoration;

	public:

		/*********+********/
		/** CONSTRUCTORS **/
		/******************/

		//Default constructor.
		Valoration();
		//Constructor by parameters.
		Valoration( unsigned int id, string id_userValoration, float descrp);
		//Constructor per copy.
		Valoration(const Valoration& valoration);

		/*********+************************/
		/** SETS OF THE CLASS VALORATION **/
		/**********************************/

		inline void setIDValoration(unsigned int id) { this->id_valoration = id;}

		/*

		 *@brief Set a string userValoration to the attribute id_userInComment of the object.
		 *@param userValoration is the string that we will set.
		 *@pre An object Valoration it was created.
		 *@post userValoration will be the new id_userValoration of the object.
		 *@return 
		 *@author Alejandro Nieto.
		 *@version: 1.0 

		*/
		inline void setUserValoration(string iduser) { this->id_userValoration = iduser; }

		/*

		 *@brief Set a float valoration to the attribute valoration of the object.
		 *@param valoration is the float that we will set.
		 *@pre An object Valoration it was created.
		 *@post valoration will be the new valoration of the object.
		 *@return 
		 *@author Alejandro Nieto.
		 *@version: 1.0 

		*/
		inline void setValorationPoints(float valoration) { this->valoration = valoration; }


		/*********+************************/
		/** GETS OF THE CLASS VALORATION **/
		/**********************************/


		/*
	
		 *@brief Bring back the value of the attribute id_userValoration.
		 *@param
		 *@pre An object Valoration it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the string value in id_userValoration.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline string getIDUserValoration() const { return this->id_userValoration; }

		/*
	
		 *@brief Bring back the value of the attribute valoration.
		 *@param
		 *@pre An object Valoration it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the float value in valoration.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline float getValorationPoints() const { return this->valoration; }


		/*
	
		 *@brief Bring back the value of the attribute id_valoration.
		 *@param
		 *@pre An object Valoration it was created.
		 *@post the value of the attribute will be returned.
		 *@return returns the unsigned int value in id_valoration.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		inline unsigned int getIDValoration() const { return this->id_valoration; }


		/*********+**************************/
		/** PRINTS OF THE CLASS VALORATION **/
		/************************************/

		/*

		 *@brief Shows all the content of the object.
		 *@param
		 *@pre An object Valoration it was created.
		 *@return
		 *@post All the content of the object will be printed on the screen.
		 *@author Alejandro Nieto.
		 *@version: 1.0

		*/
		void printValoration();

		/*********+****************************/
		/** OVERLOAD OF THE CLASS VALORATION **/
		/**************************************/

		/*
		 *@brief Overload of the operator = 
		 *@author Alejandro Nieto.
		 *@version: 1.0
		*/
		Valoration& operator=(const Valoration &example);

		/*********+******************************/
		/** DESTRUCTOR OF THE CLASS VALORATION **/
		/****************************************/

		//Destructor of Valoration.
		~Valoration();



};


#endif