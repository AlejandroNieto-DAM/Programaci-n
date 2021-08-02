#include "User.h"
#include "CristoFinity.h"
#include "Element.h"
#include "Comment.h"
#include "UserNormal.h"
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

UserNormal::UserNormal(): User() {
	
	this->array_visualizations = new Element * [1];
	this->dim_arrayVisualizations = 0;
}


void UserNormal::printUser() const {
	//cout << DEBUG << " debug: printNormalUser " << RESTORE << endl;

	this->User::printUser();
	
}

void UserNormal::resizeArrayVisualizationsDelete(){

	//cout << DEBUG << "debug: resizeArrayVisualizationsDelete " << RESTORE << endl;

	int nuevaDim = this->getDimVisualizations();

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
    	auxiliar[i] = this->array_visualizations[i];
    	this->array_visualizations[i] = 0;
    }

    delete [] this->array_visualizations;

    this->array_visualizations = auxiliar;

    this->dim_arrayVisualizations--;

    auxiliar = 0;

}

void UserNormal::resizeArrayVisualizationsAdd(){

	//cout << DEBUG << "debug: resizeArrayVisualizationsAdd " << RESTORE << endl;

	int nuevaDim = this->getDimVisualizations();

	Element **auxiliar;
	auxiliar = new Element * [nuevaDim + 1];

	if (auxiliar == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }

    for(int i = 0; i <= nuevaDim; i++){
		auxiliar[i] = 0;
	}

    for(int i = 0; i < this->getDimVisualizations(); i++){
    	auxiliar[i] = this->array_visualizations[i];
    }

    delete [] this->array_visualizations;

    this->array_visualizations = auxiliar;

    this->dim_arrayVisualizations++;

    auxiliar = 0;

}

void UserNormal::addElementToNormalUser(Element * elementToAdd){

	//cout << DEBUG << " debug: addElementToNormalUser" << RESTORE << endl;

	bool find = false;

	if(this->getDimVisualizations() != 0){
		for(int i = 0; i < this->getDimVisualizations(); i++){
			if(elementToAdd->getIDElement() == array_visualizations[i]->getIDElement()){
				find = true;
			}
		}
	}
   
	if(find == true){

		cout << USER << "Sorry but we can´t include this element, this element is already included! " << RESTORE << endl;

	} else {

		this->resizeArrayVisualizationsAdd();
		this->array_visualizations[this->getDimVisualizations() - 1] = elementToAdd;
		cout << USER << "Well, the element has been included! " << RESTORE << endl;

	}
}

void UserNormal::addElement(Element * elementToAdd){

	//cout << DEBUG << " debug: addElement" << RESTORE << endl;

	this->resizeArrayVisualizationsAdd();
	this->array_visualizations[this->getDimVisualizations() - 1] = elementToAdd;
	//cout << USER << "Well, the element has been included! " << RESTORE << endl;

}

void UserNormal::deleteElementInUser(int position){

	//cout << DEBUG << " debug: deleteElementInUser " << RESTORE << endl;

	Element *auxiliar = 0;
	bool find = false;
	int commentPosition = 0;

    auxiliar = this->array_visualizations[this->getDimVisualizations() - 1];
    this->array_visualizations[this->getDimVisualizations() - 1] = this->array_visualizations[position];
    this->array_visualizations[position] = auxiliar;

    this->resizeArrayVisualizationsDelete();

}

void UserNormal::deleteElementToNormalUser(){

	//cout << DEBUG << " debug: deleteElementToNormalUser " << RESTORE << endl;

	int id = 0;
	int position = 0;
	bool find = false;

	this->printElementsInUser();

	cout << USER << "Introduce the id of the media you want to remove " << RESTORE;
	cin >> id;

	for(int i = 0; i < this->getDimVisualizations(); i++){
		if(id == this->array_visualizations[i]->getIDElement()){
			position = i;
			find = true;
		}
	}

	if(find == true){

		this->deleteElementInUser(position);

	} else {

		cout << MAGENTA << "You dont have that media :( " << RESTORE << endl;
	}



}

void UserNormal::printElementsInUser() const {

	//cout << DEBUG << " debug: printElementInNormalUser " << RESTORE << endl;

	if(this->getDimVisualizations() != 0){
		for(int i = 0; i < this->getDimVisualizations(); i++){
			this->array_visualizations[i]->printElementAtAll();
		}
	} else {
		cout << MAGENTA << "You dont have any media associated..." << RESTORE << endl;
	}
}

void UserNormal::printUserAtAll() const {

	//cout << DEBUG << " debug: printElementInNormalUserAtAll " << RESTORE << endl;

	this->printUser();
	this->printElementsInUser();

}

ostream& operator<<(ostream &flujo, const UserNormal *p){

	flujo << USER << " USER --> " << p->getID() << RESTORE << endl;
	flujo << USER << " NAME --> " << p->getUsername() << RESTORE << endl;
	flujo << USER << " SURNAMES --> " << p->getSurnames() << RESTORE << endl;
	flujo << USER << " PERFILPHOTO -->" << p->getUrlPerfilPhoto() << RESTORE << endl;

	return flujo;
}

istream& operator>>(istream &flujo, UserNormal *p){

	string id_user;
	string surnames;
	string username;
	string urlPerfilPhoto;

	cin.clear();
	cin.ignore(256, '\n');
	cin.sync();

	cout << USER << "Introduce login: " << RESTORE;
	getline(flujo, id_user);

	cout << USER << "Introduce the surnames: " << RESTORE;
    getline(cin, surnames);

    cout << USER << "Introduce the name: " << RESTORE;
    getline(cin, username);

    cout << USER << "Introduce the urlPerfilPhoto: " << RESTORE;
    getline(cin, urlPerfilPhoto);

	p->setID(id_user);
	p->setSurnames(surnames);
	p->setUsername(username);
	p->setUrlPerfilPhoto(urlPerfilPhoto);
	
	return flujo;
	
}

UserNormal& UserNormal::operator=(const UserNormal &example){
	if(&example != this){

		delete [] this->array_visualizations;

		this->setID(example.getID());
		this->setSurnames(example.getSurnames());
		this->setUsername(example.getUsername());
		this->setUrlPerfilPhoto(example.getUrlPerfilPhoto());
		this->dim_arrayVisualizations = 0;

		this->array_visualizations = new Element * [1];

		for(int i = 0; i < example.getDimVisualizations(); i++){
			this->resizeArrayVisualizationsAdd();
			this->array_visualizations[i] = example.array_visualizations[i];
		}

	}

	return *this;

}


UserNormal::~UserNormal(){

	//cout << DEBUG << " debug: userNormalDestroyer " << RESTORE << endl;

	for(int i = 0; i < this->getDimVisualizations(); i++){
		this->array_visualizations[i] = 0;
	}

	delete [] this->array_visualizations;
	this->dim_arrayVisualizations = 0;

}

void UserNormal::modifyUserAttributes(){

	//cout << DEBUG << " debug: modifyUserAttributes " << RESTORE << endl;

	this->printUser();
	cin >> this;
	
}

void UserNormal::insertComment(int position){
	//cout << DEBUG << " debug: insertComment USer" << RESTORE << endl;

	this->array_visualizations[position]->insertComment(this->getID());
}