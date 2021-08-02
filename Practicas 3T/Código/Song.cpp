#include "CristoFinity.h"
#include <iostream>
#include "Element.h"
#include "Comment.h"
#include "Valoration.h"
#include "Film.h"
#include "Song.h"

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

Song::Song(): Element() {

	//cout << DEBUG << " debug: Song constructor " << RESTORE << endl;
	this->artist = "";
	this->album = "";

}

void Song::printElement(){

	//cout << DEBUG << " debug: Song print " << RESTORE << endl;

	this->Element::printElement();

	cout << USER << "ARTIST --> " << this->getArtist() << RESTORE << endl;
	cout << USER << "ALBUM --> " << this->getAlbum() << RESTORE << endl;
	

}

void Song::printElementAtAll(){

	this->printElement();
	this->printComments();
	this->printValorations();
}

Song::~Song(){

	//cout << DEBUG << " debug: Song Destroyer " << RESTORE << endl;

	this->artist = "";
	this->album = "";
	
}

Song& Song::operator=(const Song &elementToCopy){

	if(&elementToCopy != this){
		delete [] this->array_Comments;	
		delete [] this->array_Valorations;

		this->artist = elementToCopy.artist;
		this->album = elementToCopy.album;
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

istream& operator>>(istream &flujo, Song * p){

	string title;
	string elementGenre;
	int elementDurationInSec;
	string publicationDate;
	int pegi;
	string description;
	string artist;
	string album;
	int totalLikes;

	cin.clear();
	cin.ignore(1000, '\n');
    cin.sync();

	cout << USER << "Introduce the title: " << RESTORE;
	getline(flujo, title);

	cout << USER << "Introduce the genre: " << RESTORE;
	getline(flujo, elementGenre);

	cout << USER << "Introduce the publication date: " << RESTORE;
	getline(flujo, publicationDate);

	cout << USER << "Introduce the description: " << RESTORE;
	getline(flujo, description);

	cout << USER << "Introduce the artist: " << RESTORE;
	getline(flujo, artist);

	cout << USER << "Introduce the album: " << RESTORE;
	getline(flujo, album);

	cout << USER << "Introduce the pegi: " << RESTORE;
	flujo >> pegi;

	cout << USER << "Introduce the duration in sec: " << RESTORE;
	flujo >> elementDurationInSec;
	
	p->title = title;
	p->elementGenre = elementGenre;
	p->elementDurationInSec = elementDurationInSec;
	p->publicationDate = publicationDate;
	p->pegi = pegi;
	p->description = description;
	p->artist = artist;
	p->album = album;
	
	return flujo;
}

ostream& operator<<(ostream &flujo, const Song * p){
	

	flujo << USER << "MEDIA ID --> " << p->getIDElement() << RESTORE << endl;
	flujo << USER << "TITLE --> " << p->getTitle() << RESTORE << endl;
	flujo << USER << "TITLE --> " << p->getGenre() << RESTORE << endl;
	flujo << USER << "DURATION(IN SEC) --> " << p->getElementDuration() << RESTORE << endl;
	flujo << USER << "PUBLICATION DATE --> " << p->getPublicationDate() << RESTORE << endl;
	flujo << USER << "PEGI --> " <<  p->getPegi() << RESTORE << endl;
	flujo << USER << "DESCRIPTION: " << p->getDescription() << RESTORE << endl;
	flujo << USER << "AVERAGE PUNCTUATION --> " << p->getPunctuation() << RESTORE << endl;
	flujo << USER << "TOTAL LIKES --> " << p->getTotalLikes() << RESTORE << endl;
	flujo << USER << "ARTIST --> " << p->getArtist() << RESTORE << endl;
	flujo << USER << "ALBUM --> " << p->getAlbum() << RESTORE << endl;
	

	return flujo;
}

void Song::modifyElementAttributes(){

	//cout << DEBUG << " debug: modifyElementAttributes " << RESTORE << endl;

	this->printElement();

	cout << USER << "That were the old attributes introduce the news: " << RESTORE << endl;
	Song *auxiliar = new Song();
	
	cin >> auxiliar;
	auxiliar->setIDElement(this->getIDElement());
	*this = *auxiliar;

	delete auxiliar;
}