#include "User.h"
#include "CristoFinity.h"
#include "Element.h"
#include "Comment.h"
#include <iostream>
#include <stdlib.h>

#define RESTORE   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define DEBUG   "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define USER  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"  

User::User(){

	this->id_user = "NULL";
	this->surnames = "";
	this->username = "NULL";
	this->urlPerfilPhoto = "";
	this->dim_search = 0;
	this->search = new Element * [1]; 

}

void User::resizeSearchDelete(){

	//cout << DEBUG << "debug: resizeSearchDelete " << RESTORE << endl;

	int nuevaDim = this->getDimSearch();

	Element **auxiliar;
	auxiliar = new Element * [nuevaDim];

	if (auxiliar == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }

    for(int i = 0; i <= nuevaDim; i++){
		auxiliar[i] = 0;
	}

    for(int i = 0; i < nuevaDim; i++){
    	auxiliar[i] = this->search[i];
    }

    delete [] this->search;

    this->search = auxiliar;

    this->dim_search--;

    auxiliar = 0;

}

void User::resizeSearchAdd(){

	//cout << DEBUG << "debug: resizeSearchAdd " << RESTORE << endl;

	int nuevaDim = this->getDimSearch();

	Element **auxiliar;
	auxiliar = new Element * [nuevaDim + 1];

	if (auxiliar == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }

    for(int i = 0; i <= nuevaDim; i++){
		auxiliar[i] = 0;
	}

    for(int i = 0; i < this->getDimSearch(); i++){
    	auxiliar[i] = this->search[i];
    }

    delete [] this->search;

    this->search = auxiliar;

    this->dim_search++;

    auxiliar = 0;

}

void User::addElementToSearch(Element * elementToAdd){
	//cout << DEBUG << " debug: addElementToSearch " << RESTORE << endl;

	this->resizeSearchAdd();
	this->search[this->getDimSearch() - 1] = elementToAdd;
}

void User::deleteElementInSearch(int position){

	//cout << DEBUG << " debug: deleteElementToSearch " << RESTORE << endl;

	Element *auxiliar = 0;

    auxiliar = this->search[this->getDimSearch() - 1];
    this->search[this->getDimSearch() - 1] = this->search[position];
    this->search[position] = auxiliar;

    this->resizeSearchDelete();

}


void User::printUser() const {
	//cout << DEBUG << " debug: printUser " << RESTORE << endl;

	cout << endl;
	cout << USER << "USER --> " << this->getID() << RESTORE << endl;
	cout << USER << "NAME --> " << this->getUsername() << RESTORE << endl;
	cout << USER << "SURNAMES --> " << this->getSurnames() << RESTORE << endl;
	cout << USER << "PERFILPHOTO -->" << this->getUrlPerfilPhoto() << RESTORE << endl;

}

User::~User(){

	//cout << DEBUG << " debug: userDestroyer " << RESTORE << endl;

	this->id_user = "NULL";
	this->surnames = "";
	this->username = "NULL";
	this->urlPerfilPhoto = "";

	for(int i = 0; i < this->getDimSearch(); i++){
		this->search[i] = 0;
	}

	delete [] this->search;
	this->dim_search = 0;

}

User& User::operator=(const User &example){
	if(&example != this){

		delete [] this->search;
		this->dim_search = 0;

		this->setID(example.getID());
		this->setSurnames(example.getSurnames());
		this->setUsername(example.getUsername());
		this->setUrlPerfilPhoto(example.getUrlPerfilPhoto());

		this->search = new Element * [1];

		for(int i = 0; i < example.getDimSearch(); i++){
			this->resizeSearchAdd();
			this->search[i] = example.search[i];
		}
	}
	return *this;

}


istream& operator>>(istream &flujo, User * p){

	string id_user;
	string surnames;
	string username;
	string urlPerfilPhoto;

	cout << USER << "Introduce your login: " << RESTORE;
	flujo >> id_user;

	cout << USER << "Introduce your surnames: " << RESTORE;
    getline(cin, surnames);

    cout << USER << "Introduce your name: " << RESTORE;
    getline(cin, surnames);

    cout << USER << "Introduce your urlPerfilPhoto: " << RESTORE;
    getline(cin, surnames);

	p->setID(id_user);
	p->setSurnames(surnames);
	p->setUsername(username);
	p->setUrlPerfilPhoto(urlPerfilPhoto);
	
	return flujo;
}

ostream& operator<<(ostream &flujo, const User * p){
	
	flujo << USER << " USER --> " << p->getID() << RESTORE << endl;
	flujo << USER << " NAME --> " << p->getUsername() << RESTORE << endl;
	flujo << USER << " SURNAMES --> " << p->getSurnames() << RESTORE << endl;
	flujo << USER << " PERFILPHOTO -->" << p->getUrlPerfilPhoto() << RESTORE << endl;

	return flujo;
}

void User::modifyUserAttributes(){

	//cout << DEBUG << " debug: modifyUserAttributes " << RESTORE << endl;

	cin >> this;
	
}

void User::printSearch() const{

	cout << DEBUG << " debug: printSearch " << RESTORE << endl;

	for(int i = 0; i < this->getDimSearch(); i++){
		this->search[i]->printElement();
	}
}

void User::searchToZero(){

	//cout << DEBUG << " debug: searchToZero " << RESTORE << endl;

	delete [] this->search;
	this->search = new Element * [1];
	this->dim_search = 0;
}

void User::topFilms(){

	//cout << DEBUG << " debug: topFilms " << RESTORE << endl;

	Element *auxiliar;

	for(int i = 0; i < this->getDimSearch(); i++){
		for(int j = 0; j < this->getDimSearch(); j++){
			if(this->search[i]->getAveragePunctuation() > this->search[j]->getAveragePunctuation()){
				auxiliar = search[j];
				search[j] = search[i];
				search[i] = auxiliar;
			}
		}
	}

	if(this->getDimSearch() > 3){
		for(int i = 3; i < this->getDimSearch(); i++){
			this->deleteElementInSearch(i);
		}
	}
	int oldDim =  this->getDimSearch();

	
	Element *auxiliar2;
	float minPunctuation = 10.0;

	for(int i = 0; i < this->getDimSearch(); i++){
		if(this->search[i]->getAveragePunctuation() <= minPunctuation){
			auxiliar2 = this->search[i];
			minPunctuation = this->search[i]->getAveragePunctuation();
		}
	}


	this->addElementToSearch(auxiliar2);

	Element *auxiliar3;
	minPunctuation = 10.0;
	int maxComments = 0;
	for(int i = 0; i < this->getDimSearch(); i++){
		if(this->search[i]->getAveragePunctuation() <= minPunctuation && this->search[i]->getDimComments() > maxComments){
			auxiliar3 = this->search[i];
			minPunctuation = this->search[i]->getAveragePunctuation();
			maxComments = this->search[i]->getDimComments();
		}
	}

	this->addElementToSearch(auxiliar3);

	for(int i = 0; i < this->getDimSearch(); i++){
		if(i <  oldDim){
			cout << BLUE << "IN TOP " << i + 1 << RESTORE << endl;
			this->search[i]->printElement();
		} else if (i ==  this->getDimSearch() - 2){
			cout << BLUE << "FILM HATED" << RESTORE << endl;
			this->search[i]->printElement();
		} else if(i == this->getDimSearch() - 1){
			cout << BLUE << "FILM POLEMIC " << RESTORE << endl;
			this->search[i]->printElement();
			cout << USER << "TOTAL COMMENTS --> " << this->search[i]->getDimComments() << RESTORE << endl;
		}
	}

	oldDim = 0;			

}

void User::topSeries(){

	//cout << DEBUG << " debug: topSeries " << RESTORE << endl;

	Element *auxiliar;

	for(int i = 0; i < this->getDimSearch(); i++){
		for(int j = 0; j < this->getDimSearch(); j++){
			if(this->search[i]->getAveragePunctuation() > this->search[j]->getAveragePunctuation()){
				auxiliar = search[j];
				search[j] = search[i];
				search[i] = auxiliar;
			}
		}
	}

	if(this->getDimSearch() > 3){
		for(int i = 3; i < this->getDimSearch(); i++){
			this->deleteElementInSearch(i);
		}
	}
	int oldDim =  this->getDimSearch();

	
	Element *auxiliar2;
	float minPunctuation = 10.0;

	for(int i = 0; i < this->getDimSearch(); i++){
		if(this->search[i]->getAveragePunctuation() <= minPunctuation){
			auxiliar2 = this->search[i];
			minPunctuation = this->search[i]->getAveragePunctuation();
		}
	}


	this->addElementToSearch(auxiliar2);

	Element *auxiliar3;
	minPunctuation = 10.0;
	int maxComments = 0;
	for(int i = 0; i < this->getDimSearch(); i++){
		if(this->search[i]->getAveragePunctuation() <= minPunctuation && this->search[i]->getDimComments() > maxComments){
			auxiliar3 = this->search[i];
			minPunctuation = this->search[i]->getAveragePunctuation();
			maxComments = this->search[i]->getDimComments();
		}
	}

	this->addElementToSearch(auxiliar3);

	//cout << this->getDimSearch() << endl;

	for(int i = 0; i < this->getDimSearch(); i++){
		if(i <  oldDim){
			cout << BLUE << "IN TOP " << i + 1 << RESTORE << endl;
			this->search[i]->printElement();
		} else if (i ==  this->getDimSearch() - 2){
			cout << BLUE << "SERIES HATED" << RESTORE << endl;
			this->search[i]->printElement();
		} else if(i == this->getDimSearch() - 1){
			cout << BLUE << "SERIES POLEMIC " << RESTORE << endl;
			this->search[i]->printElement();
			cout << USER << "TOTAL COMMENTS --> " << this->search[i]->getDimComments() << RESTORE << endl;
		}
	}

	oldDim = 0;			

}

void User::topSongs(){

	//cout << DEBUG << " debug: topFilms " << RESTORE << endl;



	Element *auxiliar;

	for(int i = 0; i < this->getDimSearch(); i++){
		for(int j = 0; j < this->getDimSearch(); j++){
			if(this->search[i]->getAveragePunctuation() > this->search[j]->getAveragePunctuation()){
				auxiliar = search[j];
				search[j] = search[i];
				search[i] = auxiliar;
			}
		}
	}

	if(this->getDimSearch() > 3){
		for(int i = 3; i < this->getDimSearch(); i++){
			this->deleteElementInSearch(i);
		}
	}
	int oldDim =  this->getDimSearch();

	
	Element *auxiliar2;
	float minPunctuation = 10.0;

	for(int i = 0; i < this->getDimSearch(); i++){
		if(this->search[i]->getAveragePunctuation() <= minPunctuation){
			auxiliar2 = this->search[i];
			minPunctuation = this->search[i]->getAveragePunctuation();
		}
	}


	this->addElementToSearch(auxiliar2);

	Element *auxiliar3;
	minPunctuation = 10.0;
	int maxComments = 0;
	for(int i = 0; i < this->getDimSearch(); i++){
		if(this->search[i]->getAveragePunctuation() <= minPunctuation && this->search[i]->getDimComments() > maxComments){
			auxiliar3 = this->search[i];
			minPunctuation = this->search[i]->getAveragePunctuation();
			maxComments = this->search[i]->getDimComments();
		}
	}

	this->addElementToSearch(auxiliar3);

	//cout << this->getDimSearch() << endl;

	for(int i = 0; i < this->getDimSearch(); i++){
		if(i <  oldDim){
			cout << BLUE << "IN TOP " << i + 1 << RESTORE << endl;
			this->search[i]->printElement();
		} else if (i ==  this->getDimSearch() - 2){
			cout << BLUE << "SONGS HATED" << RESTORE << endl;
			this->search[i]->printElement();
		} else if(i == this->getDimSearch() - 1){
			cout << BLUE << "SONGS POLEMIC " << RESTORE << endl;
			this->search[i]->printElement();
			cout << USER << "TOTAL COMMENTS --> " << this->search[i]->getDimComments() << RESTORE << endl;
		}
	}

	oldDim = 0;			

}

void User::topVideoGames(){

	//cout << DEBUG << " debug: topVideoGame " << RESTORE << endl;

	Element *auxiliar;

	for(int i = 0; i < this->getDimSearch(); i++){
		for(int j = 0; j < this->getDimSearch(); j++){
			if(this->search[i]->getAveragePunctuation() > this->search[j]->getAveragePunctuation()){
				auxiliar = search[j];
				search[j] = search[i];
				search[i] = auxiliar;
			}
		}
	}

	if(this->getDimSearch() > 3){
		for(int i = 3; i < this->getDimSearch(); i++){
			this->deleteElementInSearch(i);
		}
	}
	int oldDim =  this->getDimSearch();

	
	Element *auxiliar2;
	float minPunctuation = 10.0;

	for(int i = 0; i < this->getDimSearch(); i++){
		if(this->search[i]->getAveragePunctuation() <= minPunctuation){
			auxiliar2 = this->search[i];
			minPunctuation = this->search[i]->getAveragePunctuation();
		}
	}


	this->addElementToSearch(auxiliar2);

	Element *auxiliar3;
	minPunctuation = 10.0;
	int maxComments = 0;
	for(int i = 0; i < this->getDimSearch(); i++){
		if(this->search[i]->getAveragePunctuation() <= minPunctuation && this->search[i]->getDimComments() > maxComments){
			auxiliar3 = this->search[i];
			minPunctuation = this->search[i]->getAveragePunctuation();
			maxComments = this->search[i]->getDimComments();
		}
	}

	this->addElementToSearch(auxiliar3);

	cout << this->getDimSearch() << endl;

	for(int i = 0; i < this->getDimSearch(); i++){
		if(i <  oldDim){
			cout << BLUE << "IN TOP " << i + 1 << RESTORE << endl;
			this->search[i]->printElement();
		} else if (i ==  this->getDimSearch() - 2){
			cout << BLUE << "VIDEOGAME HATED" << RESTORE << endl;
			this->search[i]->printElement();
		} else if(i == this->getDimSearch() - 1){
			cout << BLUE << "VIDEOGAME POLEMIC " << RESTORE << endl;
			this->search[i]->printElement();
			cout << USER << "TOTAL COMMENTS --> " << this->search[i]->getDimComments() << RESTORE << endl;
		}
	}

	oldDim = 0;			

}