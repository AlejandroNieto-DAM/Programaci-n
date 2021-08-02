#include <iostream>
#include "Valoration.h"
#include <stdlib.h>
#include "CristoFinity.h"

#define RESTORE   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define DEBUG   "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define USER  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"  

Valoration::Valoration(){

	//cout << DEBUG << " debug: default constructor Valoration " << RESTORE << endl;

	this->id_valoration = 0;
	this->id_userValoration = "NULL";
	this->valoration = 0.0;

}

Valoration::Valoration(unsigned int id, string id_userValoration, float valoration){

	//cout << DEBUG << " debug: constructor by parameters Valoration " << RESTORE << endl;
	this->id_valoration = id;
	this->id_userValoration = id_userValoration;
	this->valoration = valoration;

}

Valoration::Valoration(const Valoration& valoration){

	//cout << DEBUG << " debug: constructor per copy Valoration " << RESTORE << endl;

	this->id_valoration = valoration.getIDValoration();
	this->id_userValoration = valoration.getIDUserValoration();
	this->valoration = valoration.getValorationPoints();

}

Valoration::~Valoration(){

	//cout << DEBUG << " debug: destructorValoration " << RESTORE << endl;
	this->id_valoration = 0;
	this->id_userValoration = "NULL";
	this->valoration = 0.0;

}

void Valoration::printValoration(){

	//cout << DEBUG << " debug: printValoration " << RESTORE << endl;
	
	cout << BLUE << "IDVALORATION --> " << this->getIDValoration() << endl;
	cout << "USER --> " << this->getIDUserValoration() << endl;
	cout << "VALORATION: " << this->getValorationPoints() << RESTORE <<endl;
	
}

Valoration& Valoration::operator=(const Valoration &example){

	if(this != &example){
		this->id_valoration = example.getIDValoration();
		this->id_userValoration = example.getIDUserValoration();
		this->valoration = example.getValorationPoints();
	}

	return *this;

}