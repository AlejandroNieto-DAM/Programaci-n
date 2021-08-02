#include "CristoFinity.h"
#include <iostream>
#include "Element.h"
#include "Comment.h"
#include "Valoration.h"
#include "Videogame.h"

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

VideoGame::VideoGame(): Element() {

	//cout << DEBUG << " debug: VideoGame constructor " << RESTORE << endl;
	this->developer = "";
	this->editor = "";
	this->players = 0;
	this->platform = "";

}

void VideoGame::printElement(){

	this->Element::printElement();

	cout << USER << "DEVELOPER --> " << this->getDeveloper() << RESTORE << endl;
	cout << USER << "EDITOR --> " << this->getEditor() << RESTORE << endl;
	cout << USER << "PLAYERS --> " << this->getPlayers() << RESTORE << endl;
	cout << USER << "PLATFORM --> " << this->getPlatform() << RESTORE << endl;

}

void VideoGame::printElementAtAll(){

	this->printElement();
	this->printComments();
	this->printValorations();
}

VideoGame::~VideoGame(){

	//cout << DEBUG << " debug: filmDestroyer " << RESTORE << endl;

	this->editor = "";
	this->players = 0;
	this->platform = "";
	
}

VideoGame& VideoGame::operator=(const VideoGame &elementToCopy){

	if(&elementToCopy != this){
		delete [] this->array_Comments;	
		delete [] this->array_Valorations;

		
		this->developer = elementToCopy.developer;
		this->editor = elementToCopy.editor;
		this->players = elementToCopy.players;
		this->platform = elementToCopy.platform;
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

istream& operator>>(istream &flujo, VideoGame * p){

	string title;
	string elementGenre;
	int elementDurationInSec;
	string publicationDate;
	int pegi;
	string description;
	string developer;
	string editor;
	unsigned int players;
	string platform;

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

	cout << USER << "Introduce the developer: " << RESTORE;
	getline(flujo, developer);

	cout << USER << "Introduce the editor: " << RESTORE;
	getline(flujo, editor);

	cout << USER << "Introduce the platform: " << RESTORE;
	getline(flujo, platform);

	cout << USER << "Introduce the duration in sec: " << RESTORE;
	flujo >> elementDurationInSec;

	cout << USER << "Introduce the players: " << RESTORE;
	flujo >> players;

	cout << USER << "Introduce the pegi: " << RESTORE;
	flujo >> pegi;


	p->title = title;
	p->elementGenre = elementGenre;
	p->elementDurationInSec = elementDurationInSec;
	p->publicationDate = publicationDate;
	p->pegi = pegi;
	p->description = description;
	p->developer = developer;
	p->editor = editor;
	p->players = players;
	p->platform = platform;
	
	return flujo;
}

ostream& operator<<(ostream &flujo, VideoGame * p){
	

	p->calculatePunctuation();
	flujo << USER << "MEDIA ID --> " << p->getIDElement() << RESTORE << endl;
	flujo << USER << "TITLE --> " << p->getTitle() << RESTORE << endl;
	flujo << USER << "TITLE --> " << p->getGenre() << RESTORE << endl;
	flujo << USER << "DURATION(IN SEC) --> " << p->getElementDuration() << RESTORE << endl;
	flujo << USER << "PUBLICATION DATE --> " << p->getPublicationDate() << RESTORE << endl;
	flujo << USER << "PEGI --> " <<  p->getPegi() << RESTORE << endl;
	flujo << USER << "DESCRIPTION: " << p->getDescription() << RESTORE << endl;
	flujo << USER << "AVERAGE PUNCTUATION --> " << p->getPunctuation() << RESTORE << endl;
	flujo << USER << "TOTAL LIKES --> " << p->getTotalLikes() << RESTORE << endl;
	flujo << USER << "DEVELOPER --> " << p->getDeveloper() << RESTORE << endl;
	flujo << USER << "EDITOR --> " << p->getEditor() << RESTORE << endl;
	flujo << USER << "PLAYERS --> " << p->getPlayers() << RESTORE << endl;
	flujo << USER << "PLATFORM --> " << p->getPlatform() << RESTORE << endl;
	

	return flujo;
}

void VideoGame::modifyElementAttributes(){

	//cout << DEBUG << " debug: modifyElementAttributes " << RESTORE << endl;

	this->printElement();

	cout << USER << "That were the old attributes introduce the news: " << RESTORE << endl;
	VideoGame *auxiliar = new VideoGame();
	
	cin >> auxiliar;
	auxiliar->setIDElement(this->getIDElement());
	*this = *auxiliar;

	delete auxiliar;
}