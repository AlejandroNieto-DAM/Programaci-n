#include "User.h"
#include "Element.h"
#include "Comment.h"
#include "UserNormal.h"
#include <iostream>
#include "Administrator.h"
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


Administrator::~Administrator(){

	//cout << DEBUG << " debug: administratorDestroyer " << RESTORE << endl;

    this->id_user = "NULL";
    this->surnames = "";
    this->username = "NULL";
    this->urlPerfilPhoto = "";
}

ostream& operator<<(ostream &flujo, const Administrator *p){

	flujo << USER << " USER --> " << p->getID() << RESTORE << endl;
	flujo << USER << " NAME --> " << p->getUsername() << RESTORE << endl;
	flujo << USER << " SURNAMES --> " << p->getSurnames() << RESTORE << endl;
	flujo << USER << " PERFILPHOTO -->" << p->getUrlPerfilPhoto() << RESTORE << endl;

	return flujo;
}

istream& operator>>(istream &flujo, Administrator * p){

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
    getline(flujo, surnames);

    cout << USER << "Introduce the name: " << RESTORE;
    getline(flujo, username);

    cout << USER << "Introduce the urlPerfilPhoto: " << RESTORE;
    getline(flujo, urlPerfilPhoto);

    p->setID(id_user);
    p->setSurnames(surnames);
    p->setUsername(username);
    p->setUrlPerfilPhoto(urlPerfilPhoto);
    
    return flujo;
}

Administrator& Administrator::operator=(const Administrator &example){
	if(&example != this){

		this->setID(example.getID());
		this->setSurnames(example.getSurnames());
		this->setUsername(example.getUsername());
		this->setUrlPerfilPhoto(example.getUrlPerfilPhoto());
	}
	
	return *this;
}

void Administrator::modifyUserAttributes(){

    //cout << DEBUG << " debug: modifyUserAttributes " << RESTORE << endl;

    this->User::printUser();
    cin >> this;
    
}






