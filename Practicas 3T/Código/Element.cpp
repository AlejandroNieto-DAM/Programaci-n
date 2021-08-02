#include "CristoFinity.h"
#include <iostream>
#include "Comment.h"
#include "Valoration.h"
#include <stdlib.h>
#include <limits>

#define RESTORE   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define DEBUG   "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define USER  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"  

Element::Element(){
	this->id_element = 0;
	this->title = "";
	this->elementGenre = "";
	this->elementDurationInSec = 0;
	this->publicationDate = "";
	this->pegi = 0;
	this->description = "";
	this->punctuation = 0.0;
	this->totalLikes = 0;
	this->dim_arrayComments = 0;
	this->array_Comments = new Comment * [1];
	this->dim_arrayValorations = 0;
	this->array_Valorations = new Valoration * [1];
	this->averagePunctuationOnCatalog = 0;
}

void Element::printElement(){

	//cout << DEBUG << " debug: printElement " << RESTORE << endl;

	this->calculatePunctuation();

	cout << endl;
	cout << USER << "MEDIA ID --> " << this->getIDElement() << RESTORE << endl;
	cout << USER << "TITLE --> " << this->getTitle() << RESTORE << endl;
	cout << USER << "GENRE --> " <<this->getGenre() << RESTORE << endl;
	cout << USER << "DURATION(IN SEC) --> " << this->getElementDuration() << RESTORE << endl;
	cout << USER << "PUBLICATION DATE --> " << this->getPublicationDate() << RESTORE << endl;
	cout << USER << "PEGI --> " << this->getPegi() << RESTORE << endl;
	cout << USER << "DESCRIPTION: " << this->getDescription() << RESTORE << endl;
	cout << USER << "PUNCTUATION --> " << this->getPunctuation() << RESTORE << endl;
	cout << USER << "TOTAL LIKES --> " << this->getTotalLikes() << RESTORE << endl;
	cout << USER << "AVERAGE PUNCTUATION --> " << this->getAveragePunctuation() << RESTORE << endl;

}

void Element::printElementAtAll(){

	//cout << DEBUG << " debug: printElementAtAll " << RESTORE << endl;

	this->printElement();

	if(this->getDimComments() != 0){
		this->printComments();
	}

	if(this->getDimValorations() != 0){
		this->printValorations();
	}

}

Element::~Element(){

	//cout << DEBUG << " debug: elementDestroyer " << this->getIDElement() << RESTORE << endl;

	this->id_element = 0;
	this->title = "";
	this->elementGenre = "";
	this->elementDurationInSec = 0;
	this->publicationDate = "";
	this->pegi = 0;
	this->description = "";
	this->punctuation = 0.0;
	this->totalLikes = 0;
	this->averagePunctuationOnCatalog = 0;


	for(int i = 0; i < this->getDimComments(); i++){
		delete this->array_Comments[i];
	}
	
	for(int i = 0; i < this->getDimValorations(); i++){
		delete this->array_Valorations[i];
	}
	
	delete [] this->array_Comments;
	this->array_Comments = 0;
	delete [] this->array_Valorations;
	this->array_Valorations = 0;
}

Element& Element::operator=(const Element &elementToCopy){
	if(&elementToCopy != this){
		delete [] this->array_Comments;
		delete [] this->array_Valorations;
		

		this->id_element = elementToCopy.id_element;
		this->title = elementToCopy.title;
		this->elementGenre = elementToCopy.elementGenre;
		this->elementDurationInSec = elementToCopy.elementDurationInSec;
		this->publicationDate = elementToCopy.publicationDate;
		this->pegi = elementToCopy.pegi;
		this->description = elementToCopy.description;
		this->punctuation = elementToCopy.punctuation;
		this->totalLikes = elementToCopy.totalLikes;
		this->averagePunctuationOnCatalog = elementToCopy.averagePunctuationOnCatalog;

		this->dim_arrayComments = 0;
		this->array_Comments = new Comment * [1];

		for(int i = 0; i < elementToCopy.getDimComments(); i++){
			this->array_Comments[i] = elementToCopy.array_Comments[i];
			this->resizeArrayCommentsAdd();
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

void Element::resizeArrayValorationsAdd(){

	//cout << DEBUG << "debug: resizeArrayValorationsAdd " << RESTORE << endl;

	int nuevaDim = this->getDimValorations();

	Valoration **auxiliar;
	auxiliar = new Valoration * [nuevaDim + 1];

	if (auxiliar == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }

    for(int i = 0; i <= nuevaDim; i++){
		auxiliar[i] = 0;
	}

    for(int i = 0; i < this->dim_arrayValorations; i++){
    	auxiliar[i] = this->array_Valorations[i];
    }

    delete [] this->array_Valorations;

    this->array_Valorations = auxiliar;

    this->dim_arrayValorations++;

    auxiliar = 0;
	
}

void Element::resizeArrayCommentsAdd(){

	//cout << DEBUG << "debug: resizeArrayCommentsAdd " << RESTORE << endl;

	int nuevaDim = this->getDimComments();

	Comment **auxiliar;
	auxiliar = new Comment * [nuevaDim + 2];

	if (auxiliar == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }

    for(int i = 0; i <= nuevaDim; i++){
		auxiliar[i] = 0;
	}

    for(int i = 0; i < this->dim_arrayComments; i++){
    	auxiliar[i] = this->array_Comments[i];
    }

    delete [] this->array_Comments;

    this->array_Comments = auxiliar;

    //cout << DEBUG << this->getDimComments() << RESTORE << endl;

    this->dim_arrayComments++;

    auxiliar = 0;
	
}

void Element::resizeArrayValorationsDelete(){

	//cout << DEBUG << "debug: resizeArrayValorationsDelete " << RESTORE << endl;

	int nuevaDim = this->getDimValorations();

	Valoration **auxiliar;
	auxiliar = new Valoration * [nuevaDim];

	if (auxiliar == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }

    for(int i = 0; i < nuevaDim; i++){
		auxiliar[i] = 0;
	}

    for(int i = 0; i < nuevaDim; i++){
    	auxiliar[i] = this->array_Valorations[i];
    	this->array_Valorations[i] = 0;
    }

    delete [] this->array_Valorations;

    this->array_Valorations = auxiliar;

    this->dim_arrayValorations--;

    auxiliar = 0;

}

void Element::resizeArrayCommentsDelete(){

	//cout << DEBUG << "debug: resizeArrayCommentDelete " << RESTORE << endl;

	int nuevaDim = this->getDimComments();

	Comment **auxiliar;
	auxiliar = new Comment * [nuevaDim];

	if (auxiliar == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }

    for(int i = 0; i <= nuevaDim; i++){
		auxiliar[i] = 0;
	}

    for(int i = 0; i < nuevaDim; i++){
    	auxiliar[i] = this->array_Comments[i];
    	this->array_Comments[i] = 0;
    }

    delete [] this->array_Comments;

    this->array_Comments = auxiliar;

    this->dim_arrayComments--;

    auxiliar = 0;

}

void Element::addComment(Comment * commentToAdd){

	//cout << DEBUG << " debug: addComment " << RESTORE << endl;

	this->resizeArrayCommentsAdd();
	this->array_Comments[this->getDimComments() - 1] = commentToAdd;

}

void Element::addValoration(Valoration * valorationToAdd){

	//cout << DEBUG << " debug: addValoration " << RESTORE << endl;

	this->resizeArrayValorationsAdd();
	this->array_Valorations[this->getDimValorations() - 1] = valorationToAdd;

}

void Element::deleteComment(int position){

	//cout << DEBUG << " debug: deleteComment " << RESTORE << endl;

	Comment *auxiliar;

	auxiliar = this->array_Comments[position];
	this->array_Comments[position] = this->array_Comments[this->getDimComments() - 1];
	this->array_Comments[this->getDimComments() - 1] = auxiliar;

	this->resizeArrayCommentsDelete();

}

void Element::deleteValoration(int position){

	//cout << DEBUG << " debug: deleteValoration " << RESTORE << endl;

	Valoration *auxiliar;

	auxiliar = this->array_Valorations[position];
	this->array_Valorations[position] = this->array_Valorations[this->getDimValorations() - 1];
	this->array_Valorations[this->getDimValorations() - 1] = auxiliar;

	this->resizeArrayValorationsDelete();

}

void Element::printComments(){

	for(int i = 0; i < this->getDimComments(); i++){
		//cout << USER << "Comment " << i << " : " << RESTORE << endl;
		this->array_Comments[i]->printComment();
	}
}

void Element::printValorations(){

	for(int i = 0; i < this->getDimValorations(); i++){
		//cout << USER << "Valoration " << i << " : " << RESTORE << endl;
		this->array_Valorations[i]->printValoration();
	}
}

void Element::insertComment(string login){

	//cout << DEBUG << " debug: insertComment " << RESTORE << endl;

	int option = 0;
	string descp;
	float punctuation;
	int newIDComment = 0;
	int newIDValoration = 0;

	Comment *newComment = new Comment;
	Valoration *newValoration = new Valoration;
	do{
		cout << USER << "Introduce the punctuation: " << RESTORE;
		cin >> punctuation;
	}while(punctuation < 0 || punctuation > 10);

	cout << USER <<"Introduce the comment: " << RESTORE;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, descp);
	
	newComment->setIDUserInComment(login);
	newValoration->setUserValoration(login);
	newComment->setValoration(descp);
	newValoration->setValorationPoints(punctuation);

	if(this->getDimComments() == 0){
		newComment->setIDComment(1);
		newValoration->setIDValoration(1);
	} else {
		newIDComment = ((this->array_Comments[this->getDimComments() - 1]->getIDComment()) + 1);
		newIDValoration = ((this->array_Valorations[this->getDimValorations() - 1]->getIDValoration()) + 1);
		newComment->setIDComment(newIDComment);
		newValoration->setIDValoration(newIDValoration);
	}

	this->addComment(newComment);
	this->addValoration(newValoration);

	newComment = 0;
	newValoration = 0;

}

void Element::deleteCommentInElement(){

	//cout << DEBUG << " debug: deleteCommentInElement " << RESTORE << endl;

	this->printComments();

	int id = 0;
	int position = 0;

	cout << USER << " Introduce the id of the comment you want to delete: " << RESTORE;
	cin >> id;

	for(int i = 0; i < this->getDimComments(); i++){
		if(id == this->array_Comments[i]->getIDComment()){
			position = i;
		}
	}

	this->deleteComment(position);
	this->deleteValoration(position);

	this->organizeCommentsValorations();

}


istream& operator>>(istream &flujo, Element * p){

	string title;
	string elementGenre;
	int elementDurationInSec;
	string publicationDate;
	int pegi;
	string description;
	
	cin.clear();
	cin.ignore(1000, '\n');
    cin.sync();

	cout << USER << "Introduce the title: " << RESTORE;
	getline(flujo, title);

	cout << USER << "Introduce the genre: " << RESTORE;
	getline(flujo, elementGenre);

	cout << USER << "Introduce the duration in sec: " << RESTORE;
	flujo >> elementDurationInSec;

	cout << USER << "Introduce the publication date: " << RESTORE;
	flujo >> publicationDate;

	cout << USER << "Introduce the pegi: " << RESTORE;
	flujo >> pegi;

	
	cout << USER << "Introduce the description: " << RESTORE;
	cin.clear();
	cin.ignore(1000, '\n');
    cin.sync();
	getline(flujo, description);

	p->title = title;
	p->elementGenre = elementGenre;
	p->elementDurationInSec = elementDurationInSec;
	p->publicationDate = publicationDate;
	p->pegi = pegi;
	p->description = description;
	
	return flujo;
}

ostream& operator<<(ostream &flujo, Element * p){
	
	p->calculatePunctuation();
	flujo << USER << "MEDIA ID --> " << p->getIDElement() << RESTORE << endl;
	flujo << USER << "TITLE --> " << p->getTitle() << RESTORE << endl;
	flujo << USER << "TITLE --> " << p->getGenre() << RESTORE << endl;
	flujo << USER << "DURATION(IN SEC) --> " << p->getElementDuration() << RESTORE << endl;
	flujo << USER << "PUBLICATION DATE --> " << p->getPublicationDate() << RESTORE << endl;
	flujo << USER << "PEGI --> " <<  p->getPegi() << RESTORE << endl;
	flujo << USER << "DESCRIPTION: " << p->getDescription() << RESTORE << endl;
	flujo << USER << "PUNCTUATION --> " << p->getPunctuation() << RESTORE << endl;
	flujo << USER << "TOTAL LIKES --> " << p->getTotalLikes() << RESTORE << endl;
	flujo << USER << "AVERAGE PUNCTUATION --> " << p->getAveragePunctuation() << RESTORE << endl;


	return flujo;
}

void Element::calculatePunctuation(){

	double plus = 0;
	double average = 0;

	if(this->getDimValorations() != 0){
		for(int i = 0; i < this->getDimValorations(); i++){
			plus += this->array_Valorations[i]->getValorationPoints();
		}
	}
	
	if(this->getDimValorations() != 0){

		average = plus/dim_arrayValorations;
		this->setPunctuation(average);

	} else {

		this->setPunctuation(0.0);

	}
}

void Element::organizeCommentsValorations(){

	//cout << DEBUG << " debug: organizeCommentsValorations " << RESTORE << endl;

	Comment *auxiliar;

	for(int i = 0; i < this->getDimComments(); i++){
		for(int j = 0; j < this->getDimComments(); j++){
			if(this->array_Comments[i]->getIDComment() > this->array_Comments[j]->getIDComment()){
				auxiliar = this->array_Comments[i];
				this->array_Comments[i] = this->array_Comments[j];
				this->array_Comments[j] = auxiliar;
 			}
		}
	}

	Valoration *auxiliar2;

	for(int i = 0; i < this->getDimValorations(); i++){
		for(int j = 0; j < this->getDimValorations(); j++){
			if(this->array_Valorations[i]->getIDValoration() > this->array_Valorations[j]->getIDValoration()){
				auxiliar2 = this->array_Valorations[i];
				this->array_Valorations[i] = this->array_Valorations[j];
				this->array_Valorations[j] = auxiliar2;
 			}
		}
	}

}


void Element::modifyElementAttributes(){

	//cout << DEBUG << " debug: modifyElementAttributes " << RESTORE << endl;

	this->printElement();

	cout << USER << "That were the old attributes introduce the news: " << RESTORE << endl;
	Element *auxiliar = new Element();
	
	cin >> auxiliar;
	auxiliar->setIDElement(this->getIDElement());
	*this = *auxiliar;

	delete auxiliar;

}

