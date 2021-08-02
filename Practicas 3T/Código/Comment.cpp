#include <iostream>
#include "Comment.h"
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

Comment::Comment(){

	//cout << DEBUG << " debug: default constructor Comment " << RESTORE << endl;

	this->id_comment = 0;
	this->id_userInComment = "NULL";
	this->valoration = "";

}

Comment::Comment(unsigned int id_comnt, string id_usr, string descrp){

	//cout << DEBUG << " debug: constructor by parameters Comment " << RESTORE << endl;

	this->id_comment = id_comnt;
	this->id_userInComment = id_usr;
	this->valoration = descrp;

}

Comment::Comment(const Comment& commt){

	//cout << DEBUG << " debug: constructor per copy Comment " << RESTORE << endl;

	this->id_comment = commt.getIDComment();
	this->id_userInComment = commt.getIDUserInComment();
	this->valoration = commt.getValoration();

}

Comment::~Comment(){

	//cout << DEBUG << " debug: destructorComment " << RESTORE << endl;

	this->id_comment = 0;
	this->id_userInComment = "NULL";
	this->valoration = "";

}

void Comment::printComment(){

	//cout << DEBUG << " debug: printComment " << RESTORE << endl;

	cout << GREEN <<"IDCOMMENT --> " << this->getIDComment() << RESTORE << endl;
	cout << GREEN << "USER --> " << this->getIDUserInComment() << RESTORE << endl;
	cout << GREEN << "COMMENT: " << this->getValoration() << RESTORE << endl;
	
}

Comment& Comment::operator=(const Comment &example){

	if(this != &example){

		this->id_comment = example.getIDComment();
		this->id_userInComment = example.getIDUserInComment();
		this->valoration = example.getValoration();
	}

	return *this;
}