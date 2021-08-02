#include "CristoFinity.h"
#include <iostream>
#include "Element.h"
#include "Comment.h"
#include "Valoration.h"
#include "Film.h"

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

Film::Film(): Element() {

	//cout << DEBUG << " debug: Film constructor " << RESTORE << endl;
	this->cast = "";
	this->direction = "";
	this->script = "";
	this->productor = "";

}

void Film::printElement(){

	//cout << DEBUG << " debug: film print " << RESTORE << endl;

	this->Element::printElement();

	cout << USER << "CAST --> " << this->getCast() << RESTORE << endl;
	cout << USER << "DIRECTION --> " << this->getDirection() << RESTORE << endl;
	cout << USER << "SCRIPT --> " << this->getScript() << RESTORE << endl;
	cout << USER << "PRODUCTOR --> " << this->getProductor() << RESTORE << endl;

}

void Film::printElementAtAll(){

	this->printElement();
	this->printComments();
	this->printValorations();
}

Film::~Film(){

	//cout << DEBUG << " debug: filmDestroyer " << RESTORE << endl;

	this->cast = "";
	this->direction = "";
	this->script = "";
	this->productor = "";
	
}

Film& Film::operator=(const Film &elementToCopy){

	if(&elementToCopy != this){
		delete [] this->array_Comments;	
		delete [] this->array_Valorations;

		this->cast = elementToCopy.cast;
		this->direction = elementToCopy.direction;
		this->script = elementToCopy.script;
		this->productor = elementToCopy.productor;
		this->id_element = elementToCopy.id_element;
		this->title = elementToCopy.title;
		this->elementGenre = elementToCopy.elementGenre;
		this->elementDurationInSec = elementToCopy.elementDurationInSec;
		this->publicationDate = elementToCopy.publicationDate;
		this->pegi = elementToCopy.pegi;
		this->description = elementToCopy.description;
		this->punctuation = elementToCopy.punctuation;
		this->totalLikes = elementToCopy.totalLikes;

		this->array_Comments = new Comment * [elementToCopy.getDimComments() + 1];
		for(int i = 0; i < elementToCopy.getDimComments(); i++){
			this->array_Comments[i] = elementToCopy.array_Comments[i];
		}

		this->array_Valorations = new Valoration * [1];
		this->dim_arrayValorations = 0;

		for(int i = 0; i < elementToCopy.getDimComments(); i++){
			this->array_Comments[i] = elementToCopy.array_Comments[i];
			this->resizeArrayValorationsAdd();
		}
		
	}

	return *this;
}

istream& operator>>(istream &flujo, Film * p){

	unsigned int id_element;
	string title;
	string elementGenre;
	int elementDurationInSec;
	string publicationDate;
	int pegi;
	string description;
	string cast;
	string direction;
	string script;
	string productor;

	cin.clear();
	cin.ignore(1000, '\n');
    cin.sync();

	

	cout << USER << "Introduce the title: " << RESTORE;
	getline(flujo, title);

	cout << USER << "Introduce the genre: " << RESTORE;
	getline(flujo, elementGenre);

	cout << USER << "Introduce the description: " << RESTORE;
	getline(flujo, description);

	cout << USER << "Introduce the cast: " << RESTORE;
	getline(flujo, cast);

	cout << USER << "Introduce the direction: " << RESTORE;
	getline(flujo, direction);

	cout << USER << "Introduce the script: " << RESTORE;
	getline(flujo, script);

	cout << USER << "Introduce the productor: " << RESTORE;
	getline(flujo, productor);

	cout << USER << "Introduce the duration in sec: " << RESTORE;
	flujo >> elementDurationInSec;

	cout << USER << "Introduce the publication date: " << RESTORE;
	cin.clear();
	cin.ignore(1000, '\n');
	getline(flujo, publicationDate);

	cout << USER << "Introduce the pegi: " << RESTORE;
	flujo >> pegi;

	p->id_element = id_element;
	p->title = title;
	p->elementGenre = elementGenre;
	p->elementDurationInSec = elementDurationInSec;
	p->publicationDate = publicationDate;
	p->pegi = pegi;
	p->description = description;
	p->cast = cast;
	p->direction = direction;
	p->script = script;
	p->productor = productor;
	
	return flujo;
}

ostream& operator<<(ostream &flujo, const Film * p){
	

	flujo << USER << "MEDIA ID --> " << p->getIDElement() << RESTORE << endl;
	flujo << USER << "TITLE --> " << p->getTitle() << RESTORE << endl;
	flujo << USER << "TITLE --> " << p->getGenre() << RESTORE << endl;
	flujo << USER << "DURATION(IN SEC) --> " << p->getElementDuration() << RESTORE << endl;
	flujo << USER << "PUBLICATION DATE --> " << p->getPublicationDate() << RESTORE << endl;
	flujo << USER << "PEGI --> " <<  p->getPegi() << RESTORE << endl;
	flujo << USER << "DESCRIPTION: " << p->getDescription() << RESTORE << endl;
	flujo << USER << "AVERAGE PUNCTUATION --> " << p->getPunctuation() << RESTORE << endl;
	flujo << USER << "TOTAL LIKES --> " << p->getTotalLikes() << RESTORE << endl;
	flujo << USER << "CAST --> " << p->getCast() << RESTORE << endl;
	flujo << USER << "DIRECTION --> " << p->getDirection() << RESTORE << endl;
	flujo << USER << "SCRIPT --> " << p->getScript() << RESTORE << endl;
	flujo << USER << "PRODUCTOR --> " << p->getProductor() << RESTORE << endl;
	

	return flujo;
}

void Film::modifyElementAttributes(){

	//cout << DEBUG << " debug: modifyElementAttributes " << RESTORE << endl;

	this->printElement();

	cout << USER << "That were the old attributes introduce the news: " << RESTORE << endl;

	Film *auxiliar = new Film();
	
	cin >> auxiliar;
	auxiliar->setIDElement(this->getIDElement());
	*this = *auxiliar;

	delete auxiliar;

}