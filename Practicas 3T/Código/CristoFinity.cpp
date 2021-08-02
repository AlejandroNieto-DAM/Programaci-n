#include "CristoFinity.h"
#include "User.h"
#include "Element.h"
#include <iostream>
#include "UserNormal.h"
#include <stdlib.h>
#include "libreriapugi/src/pugixml.cpp"
#include <string.h>
#include <stdio.h>
#include "Administrator.h"
#include <fstream>
using namespace std;


#define RESTORE   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define DEBUG   "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define USER  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"  

CristoFinity::CristoFinity(){

    //cout << DEBUG << " debug: CristoFinity Constructor " << RESTORE << endl;

	this->dim_existingElements = 0;
	this->dim_existingUsers = 0;
	this->array_ExistingElements = new Element * [1];
	this->array_ExistingUsers = new User * [1];
    this->userActual = new User();
    
    this->importMediaXml();
    this->importUsersXml();


}

void CristoFinity::resizeCristoFinityAddElement(){

	//cout << DEBUG << "debug: resizeCristoFinityAddElement " << RESTORE << endl;

	int nuevaDim = this->getDimElements();

	Element **auxiliar;
	auxiliar = new Element * [nuevaDim + 1];

	if (auxiliar == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }

    for(int i = 0; i <= nuevaDim; i++){
		auxiliar[i] = 0;
	}

    for(int i = 0; i < this->getDimElements(); i++){
    	auxiliar[i] = this->array_ExistingElements[i];
    }

    delete [] this->array_ExistingElements;

    this->array_ExistingElements = auxiliar;

    this->dim_existingElements++;

    auxiliar = 0;

}

void CristoFinity::resizeCristoFinityAddUser(){

	//cout << DEBUG << "debug: resizeCristoFinityAddUser " << RESTORE << endl;

	int nuevaDim = this->dim_existingUsers;

	User **auxiliar;
	auxiliar = new User * [nuevaDim + 1];

	if (auxiliar == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }

    for(int i = 0; i <= nuevaDim; i++){
		auxiliar[i] = 0;
	}

    for(int i = 0; i < this->dim_existingUsers; i++){
    	auxiliar[i] = this->array_ExistingUsers[i];
    }

    //cout << array_ExistingUsers<< endl;
    //cout << auxiliar << endl;

    delete [] this->array_ExistingUsers;

    this->array_ExistingUsers = auxiliar;

    this->dim_existingUsers++;

    auxiliar = 0;

    //cout << array_ExistingUsers << endl;




}

void CristoFinity::resizeCristoFinityDeleteUser(){

	//cout << DEBUG << "debug: resizeCristoFinityDeleteUser " << RESTORE << endl;

	int nuevaDim = this->getDimUsers();

	User **auxiliar;
	auxiliar = new User * [nuevaDim];

	if (auxiliar == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }

    for(int i = 0; i <= nuevaDim; i++){
		auxiliar[i] = 0;
	}

    for(int i = 0; i < nuevaDim; i++){
    	auxiliar[i] = this->array_ExistingUsers[i];
    }

    delete [] this->array_ExistingUsers;

    this->array_ExistingUsers = auxiliar;

    this->dim_existingUsers--;

    auxiliar = 0;

}

void CristoFinity::resizeCristoFinityDeleteElement(){

	//cout << DEBUG << "debug: resizeCristoFinityDeleteElement " << RESTORE << endl;

	int nuevaDim = this->getDimElements();

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
    	auxiliar[i] = this->array_ExistingElements[i];
    }

    delete [] this->array_ExistingElements;

    this->array_ExistingElements = auxiliar;

    this->dim_existingElements--;

    auxiliar = 0;

    cout << "yeah" << endl;

}

void CristoFinity::addUser(User * userToAdd){

    //cout << DEBUG << " debug: addUser " << RESTORE << endl;

    this->resizeCristoFinityAddUser();
    this->array_ExistingUsers[this->getDimUsers() - 1] = userToAdd;

}

void CristoFinity::addElement(Element * elementToAdd){

    this->resizeCristoFinityAddElement();
    this->array_ExistingElements[this->getDimElements() - 1] = elementToAdd;        
    
}

void CristoFinity::printUsers(){

    for(int i = 0; i < this->getDimUsers(); i++){
       cout <<  USER << "User " << i << " : " << RESTORE << endl;
       this->array_ExistingUsers[i]->printUser();
    }

}

void CristoFinity::printElements(){

    cin.clear();
    cin.ignore();
    cin.sync();

    this->consultAveragePunctuationOfElement();

    for(int i = 0; i < this->getDimElements(); i++){
        cout <<  USER << "Element " << i << " : " << endl;
        array_ExistingElements[i]->printElement();
    }

}

void CristoFinity::printCristoFinity(){

    cout << USER << "Users will be print: " << RESTORE << endl;
    this->printUsers();

    cout << USER << "All media elements will be impresed: " << RESTORE << endl;
    this->printElements();

}

CristoFinity::~CristoFinity(){

   // cout << DEBUG << " debug: destructor of CristoFinity " << RESTORE << endl;

    string fich = "cristofinity.xml";

    this->exportXml(fich);

    for(int i = 0; i < this->getDimElements(); i++){
        delete array_ExistingElements[i];
    }

    for(int i = 0; i < this->getDimUsers(); i++){
        delete array_ExistingUsers[i];
    }

    delete [] array_ExistingElements;
    delete [] array_ExistingUsers;

    dim_existingUsers = 0;
    dim_existingElements = 0;
	
}

void CristoFinity::menuLogin(){

    //cout << DEBUG << " debug: MenuLogin() " << RESTORE << endl;

    int option = 0;

    cout << USER << "INTRODUCE [1] TO LOGIN. " << RESTORE << endl;
    cout << USER << "INTRODUCE [2] TO EXIT." << RESTORE << endl;

    do{
        cin >> option;
        if(option < 1 || option > 2){
            cout << USER << "You have introduced a wrong number! Try again." << RESTORE << endl;
        }
    }while(option < 1 || option > 2);

    if(option == 1){
        this->menu();
    } else {
        cout << USER << "Byee!" << RESTORE << endl;
    }

}


void CristoFinity::menu(){


    //cout << DEBUG << " debug: Menu() " << RESTORE << endl;

    int position = 0;
    string login = "";
    bool find = false;
    char comparation[100];
    char comparation2[100];
    

    cout << USER << "WELCOME TO CRISTOFINITY. ENJOY THE CONTENT!!" << RESTORE << endl;

       do{
            
            cout << USER << "INTRODUCE YOUR LOGIN --> " << RESTORE;
            cin >> login;
  
            for(int i = 0;  i < this->getDimUsers() && find == false; i++){

                strcpy(comparation ,this->array_ExistingUsers[i]->getID().c_str());
                strcpy(comparation2, login.c_str());

                if(strstr(comparation2, comparation) != 0){
                    find = true;
                    position = i;
                }
            }
            
        }while(find == false);

        userActual = this->array_ExistingUsers[position];
        

        if(Administrator *h = dynamic_cast<Administrator*>(this->array_ExistingUsers[position])){

            this->menuAdmin();

        } else if(UserNormal *h = dynamic_cast<UserNormal*>(this->array_ExistingUsers[position])){

            this->menuUser();

        }
        


}

void CristoFinity::menuUser(){

    //cout << DEBUG << " debug: menuUser " << RESTORE << endl;

    int option = 0;

    cout << GREEN << "You have logged in as normal user..." << RESTORE << endl;

    do{
        cout << GREEN << "\nUSER --> " << userActual->getID() << RESTORE << endl;

        cout << USER << "[1] See my list of media visualized. " << RESTORE << endl;
        cout << USER << "[2] Add media to my list of media." << RESTORE << endl;
        cout << USER << "[3] Delete media of my list. " << RESTORE << endl;
        cout << USER << "[4] Add comment to media." << RESTORE << endl;
        cout << USER << "[5] Delete comment of a media. " << RESTORE << endl;
        cout << USER << "[6] Modify mi User. " << RESTORE << endl;
        cout << USER << "[7] Find Media. " << RESTORE << endl;
        cout << USER << "[8] Consult average punctuation of all medias. " << RESTORE << endl;
        cout << USER << "[9] RANKINGS. " << RESTORE << endl;
        cout << USER << "[10] Record. " << RESTORE << endl;
        cout << USER << "[0] Exit. " << RESTORE << endl;

        do{

            cin >> option;

            if(option < 0 && option > 10){
                cout << USER << "Sorry. You have introduced a wrong option. Try again: " << RESTORE;
            }

        }while(option < 0 && option > 10);

        switch(option){

            case 1:
                userActual->printElementsInUser();
                break;

            case 2:

                if(this->getDimElements() != 0){
                    this->addElementToUserNormal();
                    this->calculateTotalLikes();
                    this->consultAveragePunctuationOfElement();
                } else {
                    cout << MAGENTA << "Sorry...We dont have any media now...Try again later..." << RESTORE << endl;
                }

                break;

            case 3:
                if(UserNormal *h = dynamic_cast<UserNormal*>(userActual)){
                    h->deleteElementToNormalUser();
                }
                this->calculateTotalLikes();
                this->consultAveragePunctuationOfElement();

                break;

            case 4:
                this->userComment();
                this->consultAveragePunctuationOfElement();
                break;

            case 5:
                this->deleteCommentInMedia();
                this->consultAveragePunctuationOfElement();
                break;

            case 6:
                this->modifyMyUser();
                break;

            case 7:
                if(this->getDimElements() != 0){
                    this->findElement();
                    this->organizeElementsByID();
                } else {
                    cout << MAGENTA << "Sorry...We dont have any media now...Try again later..." << RESTORE << endl;
                }
                break;

            case 8:
                if(this->getDimElements() != 0){
                    this->consultAveragePunctuationOfElement();
                    this->seeAllAveragePunctuations();
                } else {
                    cout << MAGENTA << "Sorry...We dont have any media now...Try again later..." << RESTORE << endl;
                }
                break;

            case 9:
                if(this->getDimElements() != 0 && this->getDimUsers() != 0){
                this->consultAveragePunctuationOfElement();
                this->rankings();
                } else {
                    cout << MAGENTA << "Sorry...We dont have any media and users now...Try again later..." << RESTORE << endl;
                }
                break;

            case 10:
                if(userActual->getDimSearch() != 0){
                userActual->printSearch();
                } else {
                    cout << MAGENTA << "You didnt do any search..." << RESTORE << endl;
                }
                break;

            case 0:
                cout << USER << "Bye!" << RESTORE << endl;
                this->menuLogin();
                break;
        }


    }while(option != 0);

    

}

void CristoFinity::menuAdmin(){

    //cout << DEBUG << " debug: menuAdmin " << RESTORE << endl;

    int option = 0;

    cout << GREEN << "You have logged in as ADMIN user..." << RESTORE << endl;

    do{
        cout << GREEN << "\nUSER --> " << userActual->getID() << RESTORE << endl;
        cout << USER << "[1] Add new User." << RESTORE << endl;
        cout << USER << "[2] Delete User. " << RESTORE << endl;
        cout << USER << "[3] Find User. " << RESTORE << endl;
        cout << USER << "[4] Add new Media. " << RESTORE << endl;
        cout << USER << "[5] Delete Media. " << RESTORE << endl;
        cout << USER << "[6] Find Media. " << RESTORE << endl;
        cout << USER << "[7] Show all Users registered. " << RESTORE << endl;
        cout << USER << "[8] Show all Media registered. " << RESTORE << endl;
        cout << USER << "[9] Add comment to Media. " << RESTORE << endl;
        cout << USER << "[10] Modify Media Attributes." << RESTORE << endl;
        cout << USER << "[11] Modify User Attributes. " << RESTORE << endl;
        cout << USER << "[12] Delete comment and valoration. " << RESTORE << endl;
        cout << USER << "[13] Consult average punctuation of all medias. " << RESTORE << endl;
        cout << USER << "[14] RANKINGS. " << RESTORE << endl;
        cout << USER << "[15] Export all data. " << RESTORE << endl;
        cout << USER << "[16] Record. " << RESTORE << endl;
        cout << USER << "[0] Exit. " << RESTORE << endl;

        do{
            cin >> option;
            if(option < 0 && option > 16){
                cout << USER << "You enter a wrong option... Try again..." << RESTORE << endl;
            }
        }while(option < 0 && option > 16);

        switch(option){

            case 1:
                this->userRegister();
                break;

            case 2:
                if(this->getDimUsers() > 1){
                    this->deleteUser();
                    this->consultAveragePunctuationOfElement();
                } else {
                    cout << MAGENTA << "There are no users..." << RESTORE << endl;
                }
                break;

            case 3:
                if(this->getDimUsers() > 1){
                    this->findUser();
                } else {
                    cout << MAGENTA << "There are no users..." << RESTORE << endl;
                }
                break;

            case 4:
                this->elementRegister();
                this->organizeElementsByID();
                break;

            case 5:

                if(this->getDimElements() != 0){
                    this->deleteElement();
                    this->organizeElementsByID();
                    this->consultAveragePunctuationOfElement();
                }

                break;

            case 6:
                if(this->getDimElements() != 0){
                    this->findElement();
                    this->organizeElementsByID();
                } else {
                        cout << MAGENTA << "Sorry...We dont have any media now...Try again later..." << RESTORE << endl;
                }
                break;

            case 7:
                if(this->getDimUsers() != 0){
                    this->printUsers();
                } else {
                        cout << MAGENTA << "Sorry...There are no users..." << RESTORE << endl;
                }
                break;

            case 8:
                if(this->getDimElements() != 0){
                    this->calculateTotalLikes();
                    this->consultAveragePunctuationOfElement();
                    this->printElements();
                } else {
                        cout << MAGENTA << "Sorry...We dont have any media now...Try again later..." << RESTORE << endl;
                }
                break;

            case 9:
                if(this->getDimElements() != 0){
                    this->adminComment();
                    this->consultAveragePunctuationOfElement();
                } else {
                        cout << MAGENTA << "Sorry...We dont have any media now...Try again later..." << RESTORE << endl;
                }
                break;

            case 10:
                if(this->getDimElements() != 0){
                    this->modifyElement();
                } else {
                        cout << MAGENTA << "Sorry...We dont have any media now...Try again later..." << RESTORE << endl;
                }
                break;

            case 11:
                this->modifyUser();

                break;

            case 12:
                if(this->getDimElements() != 0){
                    this->adminDeleteComment();
                    this->consultAveragePunctuationOfElement();
                } else {
                        cout << MAGENTA << "Sorry...We dont have any media now...Try again later..." << RESTORE << endl;
                }
                break;

            case 13:
                if(this->getDimElements() != 0){
                    this->consultAveragePunctuationOfElement();
                    this->seeAllAveragePunctuations();
                } else {
                        cout << MAGENTA << "Sorry...We dont have any media now...Try again later..." << RESTORE << endl;
                }
                break;

            case 14:
                if(this->getDimElements() != 0 && this->getDimUsers() != 0){
                    this->consultAveragePunctuationOfElement();
                    this->rankings();
                } else {
                    cout << MAGENTA << "Sorry...We dont have any media and users now...Try again later..." << RESTORE << endl;

                }
                break;

            case 15:
                this->consultAveragePunctuationOfElement();
                this->exportXMLbyUsers();
                break;

            case 16:
                if(userActual->getDimSearch() != 0){
                    userActual->printSearch();
                } else {
                    cout << MAGENTA << "You didnt realize a search..." << RESTORE << endl;
                }
                break;

            case 0:
                cout << USER << "Bye!" << RESTORE << endl;
                this->menuLogin();
                break;

        }


    }while(option != 0);
    

    
}

void CristoFinity::importMediaXml(){

    //cout << DEBUG << " debug: importXML " << RESTORE << endl;

    pugi::xml_document doc;

    pugi::xml_parse_result result = doc.load_file("cristofinity.xml");

    cout << "Load result: " << result.description() << ", mesh name: " << doc.child("mesh").attribute("name").value() << endl;

    string type;
    string film = "Pelicula";
    string series = "Serie";
    string song = "Cancion";
    string videogame = "Videojuego";



    pugi::xml_node tools = doc.child("cristofinity");

    for (pugi::xml_node tool = tools.child("catalogo").child("media"); tool; tool = tool.next_sibling("media")){
    

        string elementType;
        cout << elementType;
        string id_element;
        string title;
        string elementGenre;
        string elementDurationInSec;
        string publicationDate;
        string pegi;
        string description;
        string totalikes;
        string punctuation;

        elementType = tool.child_value("tipo");
        id_element = tool.child_value("idmedia");
        title = tool.child_value("titulo");
        elementGenre = tool.child_value("genero");
        elementDurationInSec = tool.child_value("duracionensegundos");
        publicationDate = tool.child_value("fechapublicacion");
        pegi = tool.child_value("pegi");
        description = tool.child_value("descripcion");
        totalikes = tool.child_value("totalmegusta");

        if(strcmp(elementType.c_str(), film.c_str()) == 0){

            Film *auxiliar = new Film();

            string script;
            string productor;
            string cast;
            string direction;

            script = tool.child_value("guion");
            productor = tool.child_value("productor");
            cast = tool.child_value("reparto");
            direction = tool.child_value("direccion");

            auxiliar->setIDElement(atoi(id_element.c_str()));
            auxiliar->setTitle(title);
            auxiliar->setGenre(elementGenre);
            auxiliar->setElementDuration(atoi(elementDurationInSec.c_str()));
            auxiliar->setPublicationDate(publicationDate);
            auxiliar->setPegi(atoi(pegi.c_str()));
            auxiliar->setDescription(description);
            auxiliar->setScript(script);
            auxiliar->setProductor(productor);
            auxiliar->setCast(cast);
            auxiliar->setDirection(direction);
            auxiliar->setTotalLikes(atoi(totalikes.c_str()));

            this->addElement(auxiliar);



        } else if(strcmp(elementType.c_str(), series.c_str()) == 0){

            Series *auxiliar = new Series();

            string script;
            string productor;
            string cast;
            string direction;

            string seasons;
            string chapters;
            string inEmision;
            bool emision = false;

            script = tool.child_value("guion");
            productor = tool.child_value("productor");
            cast = tool.child_value("reparto");
            direction = tool.child_value("direccion");

            seasons = tool.child_value("temporadas");
            chapters = tool.child_value("capitulos");
            inEmision = tool.child_value("estado");

            if(inEmision == "finalizada"){
                emision = false;
            } else {
                emision = true;
            }

            auxiliar->setIDElement(atoi(id_element.c_str()));
            auxiliar->setTitle(title);
            auxiliar->setGenre(elementGenre);
            auxiliar->setElementDuration(atoi(elementDurationInSec.c_str()));
            auxiliar->setPublicationDate(publicationDate);
            auxiliar->setPegi(atoi(pegi.c_str()));
            auxiliar->setDescription(description);
            auxiliar->setScript(script);
            auxiliar->setProductor(productor);
            auxiliar->setCast(cast);
            auxiliar->setDirection(direction);
            auxiliar->setChapters(atoi(chapters.c_str()));
            auxiliar->setSeasons(atoi(seasons.c_str()));
            auxiliar->setEmision(emision);
            auxiliar->setTotalLikes(atoi(totalikes.c_str()));

            this->addElement(auxiliar);
            
        } else if(strcmp(elementType.c_str(), song.c_str()) == 0){

            Song *auxiliar = new Song();

            string artist;
            string album;

            artist = tool.child_value("artista");
            album = tool.child_value("album");

            auxiliar->setIDElement(atoi(id_element.c_str()));
            auxiliar->setTitle(title);
            auxiliar->setGenre(elementGenre);
            auxiliar->setElementDuration(atoi(elementDurationInSec.c_str()));
            auxiliar->setPublicationDate(publicationDate);
            auxiliar->setPegi(atoi(pegi.c_str()));
            auxiliar->setDescription(description);
            auxiliar->setArtist(artist);
            auxiliar->setAlbum(album);
            auxiliar->setTotalLikes(atoi(totalikes.c_str()));

            this->addElement(auxiliar);

            
        } else if(strcmp(elementType.c_str(), videogame.c_str()) == 0){

            VideoGame *auxiliar = new VideoGame();

            string developer;
            string editor;
            string players;
            string platform;

            developer = tool.child_value("desarrollador");
            editor = tool.child_value("editor");
            players = tool.child_value("jugadores");
            platform = tool.child_value("plataformas");

            auxiliar->setIDElement(atoi(id_element.c_str()));
            auxiliar->setTitle(title);
            auxiliar->setGenre(elementGenre);
            auxiliar->setElementDuration(atoi(elementDurationInSec.c_str()));
            auxiliar->setPublicationDate(publicationDate);
            auxiliar->setPegi(atoi(pegi.c_str()));
            auxiliar->setDescription(description);
            auxiliar->setPlatform(platform);
            auxiliar->setPlayers(atoi(players.c_str()));
            auxiliar->setEditor(editor);
            auxiliar->setDeveloper(developer);
            auxiliar->setTotalLikes(atoi(totalikes.c_str()));

            this->addElement(auxiliar);         
        }



        pugi::xml_node commentsLoop = tool.child("listacomentarios");

            for(pugi::xml_node child = commentsLoop.child("comentario"); child; child = child.next_sibling()){

                Comment *commentToAdd = new Comment();

                string idComment;
                string userLogin;
                string text;

                idComment = child.child_value("idcomentario");
                userLogin = child.child_value("login");
                text = child.child_value("texto");

                
                commentToAdd->setIDComment(atoi(idComment.c_str()));
                commentToAdd->setIDUserInComment(userLogin);
                commentToAdd->setValoration(text);

                this->array_ExistingElements[this->getDimElements() - 1]->addComment(commentToAdd);
                
            }

            pugi::xml_node valorationsLoop = tool.child("valoraciones");

            int idValoration = 1;

            for(pugi::xml_node child = valorationsLoop.child("valoracion"); child; child = child.next_sibling("valoracion")){

                Valoration *valorationToAdd = new Valoration();

                string userLogin;
                string punctuation;
                
                
                userLogin = child.child_value("idusuario");
                punctuation = child.child_value("puntuacion");
                
                valorationToAdd->setValorationPoints(atoi(punctuation.c_str()));
                valorationToAdd->setUserValoration(userLogin);
                valorationToAdd->setIDValoration(idValoration);
                //cout << BLUE << idValoration << RESTORE << endl;

                idValoration++;

                this->array_ExistingElements[this->getDimElements() - 1]->addValoration(valorationToAdd);

            }
    }

}


void CristoFinity::importUsersXml(){

    //cout << DEBUG << " debug: importXML " << RESTORE << endl;

    pugi::xml_document doc;

    pugi::xml_parse_result result = doc.load_file("cristofinity.xml");

    cout << "Load result: " << result.description() << ", mesh name: " << doc.child("mesh").attribute("name").value() << endl;
    
    cout << endl;

    string type;
    string stringWithoutSpaces;
    string normal = "normal";
    string admin = "admin";
  
    pugi::xml_node tools = doc.child("cristofinity");

    for (pugi::xml_node tool = tools.child("usuarios").child("usuario"); tool; tool = tool.next_sibling("usuario")){
     
        string id;
        string loginWithoutSpaces;
        string username;
        string surnames;
        string url;

        id = tool.child_value("login");

        for(int i = 0; i < id.size(); i++){
            if(type[i] != ' '){
                loginWithoutSpaces += id[i];
            } else if (type[i] != ' ' && i != 0){
                loginWithoutSpaces.clear();
            }
        }

        //cout << loginWithoutSpaces << endl;

        /*for(int i = 0; i < loginWithoutSpaces.size(); i++){
            //cout << loginWithoutSpaces[i] << endl;
            cout << i + 1 << endl;
        }*/

        username = tool.child_value("nombre");
        surnames = tool.child_value("apellidos");
        url = tool.child_value("urlfotoperfil");

        stringWithoutSpaces = "";
        type = "";

        type = tool.child_value("tipousuario");
        
        for(int i = 0; i < sizeof(type); i++){
            if(type[i] != ' '){
                stringWithoutSpaces += type[i];
            }
        }

        if(strcmp(stringWithoutSpaces.c_str(), normal.c_str()) == 0){

            UserNormal *auxiliar = new UserNormal();

            auxiliar->setID(loginWithoutSpaces);
            auxiliar->setUsername(username);
            auxiliar->setSurnames(surnames);
            auxiliar->setUrlPerfilPhoto(url);
 
            string visualizations = "";
            string visualizationsWithoutSpaces = "";
            int  stringConter = 0;

            visualizations = tool.child_value("listamedia");
            //cout << visualizations << endl;

            for(int i = stringConter; i <= visualizations.size(); i++){
                if(visualizations[i] != ' '){
                    visualizationsWithoutSpaces += visualizations[i];
                    //cout << GREEN << visualizationsWithoutSpaces << RESTORE << endl;

                } else {

                    Element *elementToAdd;

                    //cout << BLUE << visualizationsWithoutSpaces << RESTORE << endl;

                    int id = 0;
                    id = atoi(visualizationsWithoutSpaces.c_str());

                    for(int j = 0; j < this->getDimElements(); j++){
                        if(id == this->array_ExistingElements[j]->getIDElement()){
                            elementToAdd = this->array_ExistingElements[j];
                            auxiliar->addElement(elementToAdd);
                        } else {
                            elementToAdd =0;
                        }
                    }

                   visualizationsWithoutSpaces = "";

                }

                if(i == visualizations.size()){

                    Element *elementToAdd;

                    //cout << BLUE << visualizationsWithoutSpaces << RESTORE << endl;

                    int id = 0;
                    id = atoi(visualizationsWithoutSpaces.c_str());

                    for(int j = 0; j < this->getDimElements(); j++){
                        if(id == this->array_ExistingElements[j]->getIDElement()){
                            elementToAdd = this->array_ExistingElements[j];
                            auxiliar->addElement(elementToAdd);
                        } else {
                            elementToAdd =0;
                        }
                    }

                   visualizationsWithoutSpaces = "";

                }

                stringConter++; 

            } 

            this->addUser(auxiliar);

        } else if(strcmp(admin.c_str(), stringWithoutSpaces.c_str()) == 0){

            Administrator *auxiliar = new Administrator();

            auxiliar->setID(loginWithoutSpaces);
            auxiliar->setUsername(username);
            auxiliar->setSurnames(surnames);
            auxiliar->setUrlPerfilPhoto(url);

            this->addUser(auxiliar);

        }
    }
}

void CristoFinity::exportXml(string fich){

    //cout << DEBUG << " debug: exportXml " << RESTORE << endl;

    ofstream fs;
    fs.open(fich.c_str());

    fs << "<cristofinity>" << endl;

        fs << "\t<totalcatalogo>" << this->getDimElements() << "</totalcatalogo>" << endl;
        fs << "\t<totalusuarios>" << this->getDimUsers() << "</totalusuarios>" << endl;

        fs << "\t<catalogo>" << endl;

    for(int i = 0; i < this->getDimElements(); i++){
        fs << "\t\t<media>" << endl;
        fs << "\t\t\t<idmedia>" << this->array_ExistingElements[i]->getIDElement() << "</idmedia>"<< endl;
        fs << "\t\t\t<titulo>" << this->array_ExistingElements[i]->getTitle() << "</titulo>" << endl;
        fs << "\t\t\t<genero>" << this->array_ExistingElements[i]->getGenre() << "</genero>" << endl;
        fs << "\t\t\t<duracionensegundos>" << this->array_ExistingElements[i]->getElementDuration() << "</duracionensegundos>" << endl;
        fs << "\t\t\t<fechapublicacion>" << this->array_ExistingElements[i]->getPublicationDate() << "</fechapublicacion>" << endl;
        fs << "\t\t\t<pegi>" << this->array_ExistingElements[i]->getPegi() << "</pegi>" << endl;
        fs << "\t\t\t<descripcion>" << this->array_ExistingElements[i]->getDescription() << "</descripcion>" << endl;
        fs << "\t\t\t<totalmegusta>" << this->array_ExistingElements[i]->getTotalLikes() << "</totalmegusta>" << endl;
        fs << "\t\t\t<punctuation>" << this->array_ExistingElements[i]->getPunctuation() << "</punctuation>" << endl;

        if(Film *h = dynamic_cast<Film*>(this->array_ExistingElements[i])){

            fs << "\t\t\t<reparto>" << h->getCast() << "</reparto>" << endl;
            fs << "\t\t\t<direccion>" << h->getDirection() << "</direccion>" << endl;
            fs << "\t\t\t<guion>" << h->getScript() << "</guion>" << endl;
            fs << "\t\t\t<productor>" << h->getProductor() << "</productor>" << endl;

            if(Series *h = dynamic_cast<Series*>(this->array_ExistingElements[i])){

                fs << "\t\t\t<temporadas>" << h->getSeasons() << "</temporadas>" << endl;
                fs << "\t\t\t<capitulos>" << h->getChapters() << "</capitulos>" << endl;

                if(h->getEmision() == false){
                    fs << "\t\t\t<estado>finalizada</estado>" << endl;
                } else {
                    fs << "\t\t\t<estado>activa</estado>" << endl;
                }

                fs << "\t\t\t<tipo>Serie</tipo>" << endl;

            } else {

                fs << "\t\t\t<tipo>Pelicula</tipo>" << endl;

            }

        }

        if(Song *h = dynamic_cast<Song*>(this->array_ExistingElements[i])){
            fs << "\t\t\t<album>" << h->getAlbum() << "</album>" << endl;
            fs << "\t\t\t<artista>" << h->getArtist() << "</artista>" << endl;
            fs << "\t\t\t<tipo>Cancion</tipo>" << endl;


        }

        if(VideoGame *h = dynamic_cast<VideoGame*>(this->array_ExistingElements[i])){
            fs << "\t\t\t<plataformas>" << h->getPlatform() << "</plataformas>" << endl;
            fs << "\t\t\t<jugadores>" << h->getPlayers() << "</jugadores>" << endl;
            fs << "\t\t\t<editor>" << h->getEditor() << "</editor>" << endl;
            fs << "\t\t\t<tipo>Videojuego</tipo>" << endl;

        }

        if(Element *h = dynamic_cast<Element*>(this->array_ExistingElements[i])){

            fs << "\t\t\t<totalcomentarios>" << h->getDimComments() << "</totalcomentarios>" << endl;
            fs << "\t\t\t<listacomentarios>"<< endl;
            for(int i = 0; i < h->getDimComments(); i++){
                fs << "\t\t\t\t<comentario>" << endl;
                fs << "\t\t\t\t\t<idcomentario>" << h->getIDCommentInElement(i) << "</idcomentario>" << endl; 
                fs << "\t\t\t\t\t<login>" << h->getIDUserInComment(i) << "</login>" << endl; 
                fs << "\t\t\t\t\t<texto>" << h->getValorationInElement(i) << "</texto>" << endl; 
                fs << "\t\t\t\t</comentario>" << endl;

            }

            fs << "\t\t\t</listacomentarios>"<< endl;
            fs << "\t\t\t<totalvaloraciones>" << h->getDimValorations() << "</totalvaloraciones>" << endl;
            fs << "\t\t\t<valoraciones>"<< endl;

            for(int i = 0; i < h->getDimValorations(); i++){
                fs << "\t\t\t\t<valoracion>" << endl;
                fs << "\t\t\t\t\t<idusuario>" << h->getIDUserValoration(i) << "</idusuario>" << endl; 
                fs << "\t\t\t\t\t<puntuacion>" << h->getValorationPoints(i) << "</puntuacion>" << endl; 
                fs << "\t\t\t\t</valoracion>" << endl;

            }

            fs << "\t\t\t</valoraciones>"<< endl;
        }

        fs << "\t\t</media>" << endl;
    }
        fs << "\t</catalogo>" << endl;
        fs << "\t<usuarios>" << endl;

    for(int i = 0; i < this->getDimUsers(); i++){
        fs << "\t\t<usuario>" << endl;
        fs << "\t\t\t<login>" << this->array_ExistingUsers[i]->getID() << "</login>" << endl;
        fs << "\t\t\t<nombre>" << this->array_ExistingUsers[i]->getUsername() << "</nombre>" << endl;
        fs << "\t\t\t<apellidos>" << this->array_ExistingUsers[i]->getSurnames() << "</apellidos>" << endl;
        fs << "\t\t\t<urlfotoperfil>" << this->array_ExistingUsers[i]->getUrlPerfilPhoto() << "</urlfotoperfil>" << endl;

        if(UserNormal *h = dynamic_cast<UserNormal*>(this->array_ExistingUsers[i])){

            fs << "\t\t\t<tipousuario>normal</tipousuario>" << endl;   
            fs << "\t\t\t<totallistamedia>" << h->getDimVisualizations() << "</totallistamedia>" << endl;
            fs << "\t\t\t<listamedia>";

            if(h->getDimVisualizations() != 0){
                for(int i = 0; i < h->getDimVisualizations() - 1; i++){ 
                    fs << h->getIDElementInUser(i) << " ";
                }
                    fs << h->getIDElementInUser((h->getDimVisualizations()-1));
            } 

            fs << "</listamedia>" << endl;

        } else if(Administrator *h = dynamic_cast<Administrator*>(this->array_ExistingUsers[i])){

            fs << "\t\t\t<tipousuario>admin</tipousuario>" << endl;   

        }
        fs << "\t\t</usuario>" << endl;

    }
        fs << "\t</usuarios>" << endl;


    fs << "</cristofinity>" << endl;


    fs.close();
}

void CristoFinity::exportXMLbyUsers(){

    //cout << DEBUG << " debug: exportXMLbyUsers " << RESTORE << endl;

    string fich_name;

    cout << USER << "Introduce the name of the file you want to export all data:  " << RESTORE;
    cin >> fich_name;

    this->exportXml(fich_name);
}


void CristoFinity::administratorUserRegister(){

    //cout << DEBUG << " debug: normalUserRegister " << RESTORE << endl;

    bool find = false;

    Administrator *newUser = new Administrator();

    do{

        find = false;
        cin >> newUser;

        for(int i = 0; i < this->getDimUsers(); i++){
            if(this->array_ExistingUsers[i]->getID() == newUser->getID()){
                find = true;
            } 
        }

    }while(find == true);

    this->addUser(newUser);

    newUser = 0;

}

void CristoFinity::normalUserRegister(){

    //cout << DEBUG << " debug: normalUserRegister " << RESTORE << endl;

    bool find = false;

    UserNormal *newUser = new UserNormal();

    do{

        find = false;
        cin >> newUser;

        for(int i = 0; i < this->getDimUsers(); i++){
            if(this->array_ExistingUsers[i]->getID() == newUser->getID()){
                find = true;
            } 
        }

    }while(find == true);

    this->addUser(newUser);

    newUser = 0;

}
void CristoFinity::userRegister(){

    //cout << DEBUG << " debug: userRegister " << RESTORE << endl;

    int option = 0;

    do{
        cout << USER << "What do you want to register? " << RESTORE << endl;
        cout << USER << "[1] Normal User Register. " << RESTORE << endl;
        cout << USER << "[2] Administrator User Register. " << RESTORE << endl;
        cin >> option;

    }while(option != 1 && option != 2);

    if(option == 1){
        this->normalUserRegister();
    } else {
        this->administratorUserRegister();
    }
    

}

void CristoFinity::deleteUser(){

    int position = 0;

    int commentPosition = 0;

    position = findIDUser();

    if(this->array_ExistingUsers[position]->getID() == userActual->getID()){
        cout << MAGENTA << "Bro why you want to delete yourself? " << RESTORE << endl;
    } else {

        User *auxiliar = 0;

        auxiliar = this->array_ExistingUsers[position];
        this->array_ExistingUsers[position] = this->array_ExistingUsers[this->getDimUsers() - 1];
        this->array_ExistingUsers[this->getDimUsers() - 1] = auxiliar;

        this->resizeCristoFinityDeleteUser();
    }

}

void CristoFinity::deleteElement(){

    //cout << DEBUG << " debug: deleteElement " << RESTORE << endl;

    int position = 0;
    int id = 0;

    this->printElements();

    cout << USER << "Introduce the id of the media you want to delete: " << endl;

    position = this->findIDElement();

    Element *auxiliar = 0;


    for(int j = 0; j < this->getDimUsers(); j++){

        if(UserNormal * h = dynamic_cast<UserNormal*>(this->array_ExistingUsers[j])){

            for(int x = 0; x < h->getDimVisualizations(); x++){
                if(h->getIDElementInUser(x) == this->array_ExistingElements[position]->getIDElement()){
                    h->deleteElementInUser(x);
                }
            }
        }
    }

    for(int i = (this->array_ExistingElements[position]->getDimComments() - 1); i >= 0; i--){
        this->array_ExistingElements[position]->deleteComment(i);
        this->array_ExistingElements[position]->deleteValoration(i);

    }
    
    auxiliar = this->array_ExistingElements[this->getDimElements() - 1];
    this->array_ExistingElements[this->getDimElements() - 1] = this->array_ExistingElements[position];
    this->array_ExistingElements[position] = auxiliar;

    this->resizeCristoFinityDeleteElement();
    cout << "yeah pero fuera " << endl;

    this->organizeElementsByID();

}

void CristoFinity::findUser(){

    //cout << DEBUG << " debug: findUser " << RESTORE << endl;

    int option = 0;
    
    

        cout << USER << "\nTHAT ARE THE OPTIONS TO SEE THE USERS!!" << RESTORE << endl;
        cout << USER << "[1] Find one user and see all." << RESTORE << endl;
        cout << USER << "[2] Users with +=3 medias associated. " << RESTORE << endl;
        cout << USER << "[3] Users with -3 medias associated. " << RESTORE << endl;

        do{
            cin >> option;
            if(option < 1 || option > 3){
                cout << MAGENTA << "Wrong option...Try again..." << RESTORE << endl;
            }
        }while(option < 1 || option > 3);

        switch(option){

            case 1:
                this->findUserById();
                break;

            case 2:
                this->findUsersPlus3();
                break;

            case 3:
                this->findUsersLess3();
                break;


        }


    

}

void CristoFinity::findUserById(){

    int position = 0;
    
    position = this->findIDUser();

    if(UserNormal *h = dynamic_cast<UserNormal*>(this->array_ExistingUsers[position])){
        h->printUserAtAll();
    } else {
        this->array_ExistingUsers[position]->printUser();
    }
}

void CristoFinity::findUsersPlus3(){

    int minComments = 3;
    int userComments = 0;

    for(int i = 0; i < this->getDimUsers(); i++){
        userComments = this->calculateTotalCommentsOfUser(this->array_ExistingUsers[i]);
            if(userComments >= minComments){
                this->array_ExistingUsers[i]->printUser();
            }
    }
}

void CristoFinity::findUsersLess3(){

    int maxComments = 3;
    int userComments = 0;

    for(int i = 0; i < this->getDimUsers(); i++){
        if(UserNormal * h = dynamic_cast<UserNormal*>(this->array_ExistingUsers[i])){
            userComments = this->calculateTotalCommentsOfUser(h);
                if(userComments < maxComments){
                    h->printUser();
                }
        }
    }
}

void CristoFinity::elementRegister(){

    //cout << DEBUG << " debug: elementRegister " << RESTORE << endl;

    int option = 0;

    cout << USER << "What media do you want to register? " << RESTORE << endl;
    cout << USER << "[1] Film." << RESTORE << endl;
    cout << USER << "[2] Series. " << RESTORE << endl;
    cout << USER << "[3] Song. " << RESTORE << endl;
    cout << USER << "[4] VideoGame. " << RESTORE << endl;

    do{
        cin >> option;

        if(option < 1 && option > 4){
            cout << USER << "Wrong option. You have to introduce a option between 1 and 4. Try again." << RESTORE << endl; 
        }
    }while(option < 1 && option > 4);

    switch(option){

        case 1:
            this->addFilm();
            break;

        case 2:
            this->addSeries();
            break;

        case 3:
            this->addSong();
            break;

        case 4:
            this->addVideoGame();
            break;
    }
}

int CristoFinity::nextID(){

    //cout << DEBUG << " debug: nextElementID " << RESTORE << endl;

    int nextID = 0;

    if(this->getDimElements() == 0){
        nextID = 1;
    } else {   
        nextID = ((this->array_ExistingElements[this->getDimElements()-1]->getIDElement()) + 1);
    }

    return nextID;
}


void CristoFinity::addFilm(){

    //cout << DEBUG << " debug: addFilm " << RESTORE << endl;

    Film *auxiliar = new Film();

    cin >> auxiliar;

    int nextID = 0;
    nextID = this->nextID();
    auxiliar->setIDElement(nextID);

    this->addElement(auxiliar);

}

void CristoFinity::addSeries(){

    //cout << DEBUG << " debug: addFilm " << RESTORE << endl;

    Series *auxiliar = new Series();

    cin >> auxiliar;

    int nextID = 0;
    nextID = this->nextID();
    auxiliar->setIDElement(nextID);

    this->addElement(auxiliar);

}

void CristoFinity::addSong(){

    //cout << DEBUG << " debug: addSong " << RESTORE << endl;

    Song *auxiliar = new Song();

    cin >> auxiliar;

    int nextID = 0;
    nextID = this->nextID();
    auxiliar->setIDElement(nextID);

    this->addElement(auxiliar);
}

void CristoFinity::addVideoGame(){

    //cout << DEBUG << " debug: addVideoGame " << RESTORE << endl;

    VideoGame *auxiliar = new VideoGame();

    cin >> auxiliar;

    int nextID = 0;
    nextID = this->nextID();
    auxiliar->setIDElement(nextID);

    this->addElement(auxiliar);
    
}

void CristoFinity::adminComment(){

    //cout << DEBUG << " debug: addCommentAdmin " << RESTORE << endl;

    int position = 0;

    this->printElements();

    cout << USER << "Introduce the ID of the media you want to add a comment : " << RESTORE;

    position = findIDElement();

    this->array_ExistingElements[position]->insertComment(userActual->getID());


}

void CristoFinity::adminDeleteComment(){

    int position = 0;
    int commentToDelete = 0; 
    int positionOfCommentToDelete = 0;

    this->printElements();

    cout << USER << "Introduce the id of the media you want to delete a comment: " << RESTORE;

    position = this->findIDElement();

    this->array_ExistingElements[position]->printElementAtAll();

    if(this->array_ExistingElements[position]->getDimComments() != 0){
        
        this->array_ExistingElements[position]->printElementAtAll();

        do{
            cout << "Introduce the id of the comment you want to delete: " << RESTORE;
            cin >> commentToDelete;
        }while(commentToDelete < 1 || commentToDelete > this->array_ExistingElements[position]->getDimComments());

        
        for(int i = 0; i < this->array_ExistingElements[position]->getDimComments(); i++){
            if(this->array_ExistingElements[position]->getIDCommentInElement(i) == commentToDelete){
                positionOfCommentToDelete = i;
            }
        }

        this->array_ExistingElements[position]->deleteComment(positionOfCommentToDelete);
        this->array_ExistingElements[position]->deleteValoration(positionOfCommentToDelete);

        //cout << this->array_ExistingElements[position]->getDimComments() <<endl;
        
    } else {

        cout << USER << "This media dont have any comments or valorations :( " << RESTORE << endl;
    }


}

void CristoFinity::userComment(){

    //cout << DEBUG << " debug: addCommentUser " << RESTORE << endl;

    int idToFind = 0;
    int position = 0;
    bool find = false;

    if(UserNormal *h = dynamic_cast<UserNormal*>(userActual)){

        h->printElementsInUser();

        do{

            cout << USER << "Introduce the ID of the media you want to add a comment : " << RESTORE;
            cin >> idToFind;

            for(int i = 0; i < h->getDimVisualizations(); i++){
                if(h->getIDElementInUser(i) == idToFind){
                    position = i;
                    find = true;
                }
            }

        }while(find == false);

        int truePosition = 0;

        for(int i = 0; i < this->getDimElements(); i++){
            if(this->array_ExistingElements[i]->getIDElement() == h->getIDElementInUser(position)){
                truePosition = i;
            }
        }

        for(int i = 0; i < this->array_ExistingElements[truePosition]->getDimComments(); i++){
            if(this->array_ExistingElements[truePosition]->getIDUserInComment(i) == h->getID()){
                this->array_ExistingElements[truePosition]->deleteComment(i);
                this->array_ExistingElements[truePosition]->deleteValoration(i);
            }
        }

        h->insertComment(position);
    }

}

int CristoFinity::findElementInNormalUser(){

    //cout << DEBUG << " debug: deleteCommentUser " << RESTORE << endl;

    int idToFind = 0;
    int position = 0;
    bool find = false;

    if(UserNormal *h = dynamic_cast<UserNormal*>(userActual)){

        h->printElementsInUser();

        do{

            cout << USER << "Introduce the ID of the media you want to delete a comment or valoration: " << RESTORE;
            cin >> idToFind;

            for(int i = 0; i < h->getDimVisualizations(); i++){
                if(h->getIDElementInUser(i) == idToFind){
                    find = true;
                }
            }

        }while(find == false);


        for(int i = 0; i < this->getDimElements(); i++){
            if(this->array_ExistingElements[i]->getIDElement() == idToFind){
                position = i;
            }
        }

    }

    return position;
}

void CristoFinity::deleteCommentInMedia(){


    int position = findElementInNormalUser();
    int commentToDelete = 0;
    int positionOfCommentToDelete = 0;

    if(this->array_ExistingElements[position]->getDimComments() != 0){

        this->array_ExistingElements[position]->printElementAtAll();

        do{
            cout << "Introduce the id of the comment you want to delete: " << RESTORE;
            cin >> commentToDelete;
        }while(commentToDelete < 1 || commentToDelete > this->array_ExistingElements[position]->getDimComments());

        for(int i = 0; i < this->array_ExistingElements[position]->getDimComments(); i++){
            if(this->array_ExistingElements[position]->getIDCommentInElement(i) == commentToDelete){
                positionOfCommentToDelete = i;
            }
        }

        if( this->array_ExistingElements[position]->getIDUserInComment(positionOfCommentToDelete) == userActual->getID()){
            this->array_ExistingElements[position]->deleteComment(positionOfCommentToDelete);
            this->array_ExistingElements[position]->deleteValoration(positionOfCommentToDelete);

        } else {
            cout << USER << "You cant delete a comment that is not yours...Try again..." << endl;
        }
    } else {

        cout << USER << "This media dont have any comments :( " << RESTORE << endl;
    }

}

int CristoFinity::findIDElement(){

    //cout << DEBUG << " debug: findIDElement " << RESTORE << endl;

    int idToFind = 0;
    int position = 0;
    bool find = false;

    do{

        cin >> idToFind;

        for(int i = 0; i < this->getDimElements(); i++){
            if(this->array_ExistingElements[i]->getIDElement() == idToFind){
                position = i;
                find = true;
            }
        }

        if(find == false){
            cout << MAGENTA << "This element couldnt be find :(... Try again. " << RESTORE << endl;
        }

    }while(find == false);

    return position;
}

int CristoFinity::findIDUser(){

    //cout << DEBUG << " debug: findIDUser " << RESTORE << endl;

    this->printUsers();

    int position = 0;
    string login = "";
    bool find = false;
    char comparation[100];
    char comparation2[100];
    

   do{
        
        cout << USER << "INTRODUCE ONE LOGIN --> " << RESTORE;
        cin >> login;

        for(int i = 0;  i < this->getDimUsers() && find == false; i++){

            strcpy(comparation ,this->array_ExistingUsers[i]->getID().c_str());
            strcpy(comparation2, login.c_str());

            if(strstr(comparation2, comparation) != 0){
                find = true;
                position = i;
            }
        }
        
    }while(find == false);

    return position;


}

void CristoFinity::modifyElement(){

    //cout << DEBUG << " debug: modifyElement " << RESTORE << endl;

    int position = 0;

    if(this->getDimElements() != 0){
        this->printElements();
        position = findIDElement();
        this->array_ExistingElements[position]->modifyElementAttributes();
    } else  {
        cout << USER << "There is no elements :( " << RESTORE << endl;
    }
    
}

void CristoFinity::modifyUser(){

    //cout << DEBUG << " debug: modifyUser " << RESTORE << endl;

    int position = 0;

    if(this->getDimUsers() != 0){
        position = findIDUser();
        this->array_ExistingUsers[position]->modifyUserAttributes();
    } else  {
        cout << USER << "There is no users :( " << RESTORE << endl;
    }
}

void CristoFinity::modifyMyUser(){

    //cout << DEBUG << " debug: modifyUserNormal " << RESTORE << endl;

    bool invalid = false;

    cout << GREEN << userActual->getID() << RESTORE << endl;

    do{

        invalid = false;

        userActual->modifyUserAttributes();
        for(int i; i < this->getDimUsers() && invalid == false; i++){
            if(userActual->getID() == this->array_ExistingUsers[i]->getID()){
                invalid = true;
            }
        }

    }while(invalid == true);

}

void CristoFinity::addElementToUserNormal(){

    //cout << DEBUG << " debug: addElementToUserNormal" << RESTORE << endl;

    int idToFind = 0;
    int position = 0;
    bool find = false;

    this->printElements();

    do{

        cout << USER << "Introduce the ID of the media you want to add: " << RESTORE;
        cin >> idToFind;

        for(int i = 0; i < this->getDimElements(); i++){
            if(this->array_ExistingElements[i]->getIDElement() == idToFind){
                position = i;
                find = true;
            }
        }

    }while(find == false);

    find = false;

    if(UserNormal *h = dynamic_cast<UserNormal*>(userActual)){

        for(int i = 0; i < h->getDimVisualizations(); i++){
            if(h->getIDElementInUser(i) == this->array_ExistingElements[position]->getIDElement()){
                find = true;
            }
        }

        if(find == true){

            cout << MAGENTA << "You have this media already included :( " << RESTORE << endl;
        
        } else {

            h->addElement(this->array_ExistingElements[position]);

        }
    }
}

void CristoFinity::calculateTotalLikes(){

    //cout << DEBUG << " debug: calculateTotalLikes " << RESTORE << endl;

    int totalikes = 0;

    for(int i = 0; i < this->getDimElements(); i++){

        totalikes = 0;

        for(int j = 0; j < this->getDimUsers(); j++){

            if(UserNormal * h = dynamic_cast<UserNormal*>(this->array_ExistingUsers[j])){

                for(int x = 0; x < h->getDimVisualizations(); x++){
                    if(h->getIDElementInUser(x) == this->array_ExistingElements[i]->getIDElement()){
                      totalikes++;
                    }
                }
            }
        }

        this->array_ExistingElements[i]->setTotalLikes(totalikes);
    }
}

void CristoFinity::organizeElementsByID(){

    //cout << DEBUG << " debug: organizeElementsByID " << RESTORE << endl;

    Element *auxiliar;

    for(int i = 0; i < this->getDimElements(); i++){

        for(int j = 0; j < this->getDimElements(); j++){

            if(this->array_ExistingElements[i]->getIDElement() < this->array_ExistingElements[j]->getIDElement()){

                auxiliar = this->array_ExistingElements[j];
                this->array_ExistingElements[j] = this->array_ExistingElements[i];
                this->array_ExistingElements[i] = auxiliar;

            }
        }
    }


}

void CristoFinity::consultAveragePunctuationOfElement(){

    //cout << DEBUG << " debug: calculateAveragePunctuation " << RESTORE << endl;

     /*0,5 * (media de las valoraciones (0-10) de cada usuario a ese Media)
      +  0,3 * (número total de asociaciones de ese Media por parte de todos los usuarios del sistema / número total de valoraciones en el sistema) 
      + 0,2 *(número total de comentarios de ese Media por parte de todos los usuarios del sistema / número total de comentarios en el sistema).*/

   
    float totalValorations = 0.0;
    float totalAssociationss = 0.0;
    float totalCommentsInMedia = 0.0;
    float totalComments = 0.0;
    float result = 0.0;

    for(int i = 0; i < this->getDimElements(); i++){

           totalValorations += this->array_ExistingElements[i]->getDimValorations();
    }

    for(int i = 0; i < this->getDimElements(); i++){

       totalComments += this->array_ExistingElements[i]->getDimComments();
    }

    for(int i = 0; i < this->getDimElements(); i++){

       this->array_ExistingElements[i]->calculatePunctuation();
    }


    for(int j = 0; j < this->getDimElements(); j++){

       this->calculateTotalLikes();

       totalAssociationss = this->array_ExistingElements[j]->getTotalLikes();
       totalCommentsInMedia = this->array_ExistingElements[j]->getDimComments();
       

       result = (0.5 * this->array_ExistingElements[j]->getPunctuation()) + (0.3 * (totalAssociationss / totalValorations)) + (0.2 * (totalCommentsInMedia / totalComments));
       this->array_ExistingElements[j]->setAveragePunctuation(result);
       //cout << result  << endl;

    }

}

void CristoFinity::seeAllAveragePunctuations(){

    //cout << DEBUG << " debug: seeAllAveragePunctuations " << RESTORE << endl;

    this->printElements();
    cout << USER << "Introduce the media of you want to see the average punctuation: " << RESTORE;
    int position = this->findIDElement();
    
    cout << USER << "IDMEDIA --> " << this->array_ExistingElements[position]->getIDElement() << RESTORE << endl;
    cout << USER << "TITLE --> " << this->array_ExistingElements[position]->getTitle() << RESTORE << endl;
    cout << USER << "AVERAGE PUNCTUATION --> " << this->array_ExistingElements[position]->getAveragePunctuation() << RESTORE << endl;

}

void CristoFinity::rankings(){

    //cout << DEBUG << " debug: rankings " << RESTORE << endl;

    userActual->searchToZero();

    int option = 0;
    cout << USER << "WELCOMEEEEEE TO THE RANKINGSSSSS LETS SEEE WHAT HAPPENS " << RESTORE << endl;

    cout << USER << "[1]TOP 3 OF THE BEST MEDIA." << RESTORE << endl;
    cout << USER << "[2]TOP 3 OF THE BEST MEDIA BY TYPE." << RESTORE << endl;
    cout << USER << "[3]TOP 3 USERS." << RESTORE << endl;

    do{

        cin >> option;
        if(option < 1 || option > 3){
            cout << USER << "You tried a wrong option. Pls try again..." << RESTORE << endl;
        }

    }while(option < 1 || option > 3);


    switch(option){

        case 1:
            this->topBestMedia();
            break;

        case 2:
            this->topMediaByType();
            break;

        case 3:
            this->topUsers();
            break;
    }
}

void CristoFinity::topUsers(){

    //cout << DEBUG << " debug: topUsers " << RESTORE << endl;

    int id;
    int id2;

    UserNormal *FreakZizou;
    UserNormal *Messi;
    User *salvameDelux;

    float userElementsAverage;
    float userElementsAverage2;

    float resultMedias = 0.0;
    float resultMedias2 = 0.0;
    int minPunct = 10;
    int maxPunct = 0;
   
    for(int i = 0; i < this->getDimUsers(); i++){

        if(UserNormal *person1 = dynamic_cast<UserNormal*>(this->array_ExistingUsers[i])){

            for(int j = 0; j < this->getDimUsers(); j++){

                if(UserNormal *person2 = dynamic_cast<UserNormal*>(this->array_ExistingUsers[j])){

                    for(int p = 0; p < person1->getDimVisualizations(); p++){
                        id = person1->getIDElementInUser(p);
                        for(int d = 0; d < this->getDimElements(); d++){
                            if(id == this->array_ExistingElements[d]->getIDElement()){
                                userElementsAverage += this->array_ExistingElements[d]->getPunctuation();
                            }
                        }
                    }

                    userElementsAverage = userElementsAverage / person1->getDimVisualizations();
                    
                    for(int p = 0; p < person2->getDimVisualizations(); p++){
                        id2 = person2->getIDElementInUser(p);
                        for(int l = 0; l < this->getDimElements(); l++){
                            if(id2 == this->array_ExistingElements[l]->getIDElement()){
                                userElementsAverage2 += this->array_ExistingElements[l]->getPunctuation();
                            }
                        }
                    }
                    //cout << userElementsAverage2 << endl;
                    userElementsAverage2 = userElementsAverage2 / person2->getDimVisualizations();

                    if(person1->getDimVisualizations() > person2->getDimVisualizations()){
                        if(userElementsAverage > maxPunct){
                            FreakZizou = person1;
                            resultMedias = userElementsAverage;
                            maxPunct = resultMedias;
                        }
                    }

                    if(person1->getDimVisualizations() < person2->getDimVisualizations()){
                        if(userElementsAverage < minPunct){
                            Messi = person1;
                            resultMedias2 = userElementsAverage;
                            //cout << "ha entrao en otro " << endl;
                            minPunct = resultMedias;
                        }
                    }

                    userElementsAverage2 = 0;
                    userElementsAverage = 0;
                }
            }
        }
    }

    int comments1 = 0;
    int comments2 = 0;
    int totalComments = 0;
    int maxComments = 0;

    for(int i = 0; i < this->getDimUsers(); i++){
        
        comments1 = calculateTotalCommentsOfUser(this->array_ExistingUsers[i]);

        if(comments1 > maxComments){
            salvameDelux = this->array_ExistingUsers[i];
            maxComments = comments1;
            //cout << maxComments << endl;
        }


    }

    cout << USER << "\nUSER FREAK ZIZOU: " << RESTORE << endl;
    FreakZizou->printUser();
    cout << BLUE << "AVERAGE OF THE AVERAGE OF HIS MEDIAS --> " << resultMedias << RESTORE << endl;
    cout << BLUE << "MEDIAS ASSOCIATED --> "  << FreakZizou->getDimVisualizations() << RESTORE << endl;

    cout << USER << "\nUSER MESSI: " << RESTORE << endl;
    Messi->printUser();
    cout << BLUE << "AVERAGE OF HIS MEDIAS --> " << resultMedias2 << RESTORE << endl;
    cout << BLUE << "MEDIAS ASSOCIATED --> "  << Messi->getDimVisualizations() << RESTORE << endl;

    cout << USER << "\nUSER SALVAME DELUX: " << RESTORE << endl;
    salvameDelux->printUser();
    cout << BLUE << "TOTAL COMMENTS --> " << maxComments << RESTORE << endl;
    

}

int CristoFinity::calculateTotalCommentsOfUser(User *auxiliar){

    int comments2 = 0;

    for(int j = 0; j < this->getDimElements(); j++){
        for(int x = 0; x < this->array_ExistingElements[j]->getDimComments(); x++){
             if(auxiliar->getID() == this->array_ExistingElements[j]->getIDUserInComment(x)){
                comments2++;
             }
        }
   
    }

    return comments2;

}

void CristoFinity::topBestMedia(){

    //cout << DEBUG << " debug: topBestMedia " << RESTORE << endl;

    Element *auxiliar;

    int numbersOfElementsInTop = 3;

    for(int i = 0; i < this->getDimElements(); i++){

        for(int j = 0; j < this->getDimElements(); j++){

            if(this->array_ExistingElements[i]->getAveragePunctuation() > this->array_ExistingElements[j]->getAveragePunctuation()){

                auxiliar = this->array_ExistingElements[j];
                this->array_ExistingElements[j] = this->array_ExistingElements[i];
                this->array_ExistingElements[i] = auxiliar;

            }
        }
    }

    for(int i = 0; i < numbersOfElementsInTop; i++){
        auxiliar = this->array_ExistingElements[i];
        userActual->addElementToSearch(auxiliar);
    }

    int oldDim = userActual->getDimSearch();

    auxiliar = this->array_ExistingElements[this->getDimElements() - 1];
    userActual->addElementToSearch(auxiliar);

    for(int i = 0; i < this->getDimElements(); i++){

        for(int j = 0; j < this->getDimElements(); j++){

            if(this->array_ExistingElements[i]->getPunctuation() < this->array_ExistingElements[j]->getPunctuation() && this->array_ExistingElements[i]->getDimComments() > this->array_ExistingElements[j]->getDimComments()){

                auxiliar = this->array_ExistingElements[i];
            }
        }
    }

    auxiliar;
    userActual->addElementToSearch(auxiliar);

    for(int i = 0; i < userActual->getDimSearch(); i++){
        if(i <  oldDim){
            cout << BLUE << "IN TOP " << i + 1 << RESTORE << endl;
            userActual->printElementInSearch(i);
        } else if (i ==  userActual->getDimSearch() - 2){
            cout << BLUE << "MEDIA HATED" << RESTORE << endl;
            userActual->printElementInSearch(i);
        } else if(i == userActual->getDimSearch() - 1){
            cout << BLUE << "MEDIA POLEMIC " << RESTORE << endl;
            userActual->printElementInSearch(i);
        }
    }

    oldDim = 0; 

    auxiliar = 0;

    this->organizeElementsByID();

}

void CristoFinity::topMediaByType(){

    //cout << DEBUG << " debug: topMediaByType " << RESTORE << endl;

    int option = 0;

    cout << USER << "THIS ARE THE TOP MEDIA BY TYPE!! What you want to see: " << RESTORE << endl;
    cout << USER << "[1] Top Films. " << RESTORE << endl;
    cout << USER << "[2] Top Series. " << RESTORE << endl;
    cout << USER << "[3] Top Songs. " << RESTORE << endl;
    cout << USER << "[4] Top VideoGames. " << RESTORE << endl;

    do{
        cin >> option;
        if(option < 0 && option > 4){
            cout << MAGENTA << "Wrong option!! Try again... " << RESTORE << endl;
        }
    }while(option < 0 && option > 4);

    switch(option){

        case 1:
            this->topFilms();
            break;

        case 2:
            this->topSeries();
            break;

        case 3:
            this->topSongs();
            break;

        case 4:
            this->topVideoGames();
            break;
    }

}


void CristoFinity::topFilms(){

   //cout << DEBUG << " debug: topFilms " << RESTORE << endl;

   Element *auxiliar;

   userActual->searchToZero();

   cout << userActual->getDimSearch() << endl;

   for(int i = 0; i < this->getDimElements(); i++){
        if(Series * h = dynamic_cast<Series*>(this->array_ExistingElements[i])){
            
        } else if(Film * h = dynamic_cast<Film*>(this->array_ExistingElements[i])){
                
            auxiliar = this->array_ExistingElements[i];
            userActual->addElementToSearch(auxiliar);
        }
           
   } 
   userActual->topFilms();
}

void CristoFinity::topSeries(){

   //cout << DEBUG << " debug: topFilms " << RESTORE << endl;

   Element *auxiliar;

   userActual->searchToZero();

   cout << userActual->getDimSearch() << endl;

   for(int i = 0; i < this->getDimElements(); i++){
        if(Series * h = dynamic_cast<Series*>(this->array_ExistingElements[i])){
         
            auxiliar = this->array_ExistingElements[i];
            userActual->addElementToSearch(auxiliar);   
        }
           
   } 
   userActual->topSeries();
}

void CristoFinity::topSongs(){

   //cout << DEBUG << " debug: topSongs " << RESTORE << endl;

   Element *auxiliar;

   userActual->searchToZero();

   cout << userActual->getDimSearch() << endl;

   for(int i = 0; i < this->getDimElements(); i++){
        if(Song * h = dynamic_cast<Song*>(this->array_ExistingElements[i])){
         
            auxiliar = this->array_ExistingElements[i];
            userActual->addElementToSearch(auxiliar);   
        }
           
   } 
   userActual->topSongs();
}

void CristoFinity::topVideoGames(){

   //cout << DEBUG << " debug: topVideoGames" << RESTORE << endl;

   Element *auxiliar;

   userActual->searchToZero();

   cout << userActual->getDimSearch() << endl;

   for(int i = 0; i < this->getDimElements(); i++){
        if(VideoGame * h = dynamic_cast<VideoGame*>(this->array_ExistingElements[i])){
         
            auxiliar = this->array_ExistingElements[i];
            userActual->addElementToSearch(auxiliar);   
        }
           
   } 
   userActual->topVideoGames();
}

void CristoFinity::findElement(){

    //cout << DEBUG << " debug: findElement " << RESTORE << endl;

    cin.clear();
    cin.ignore();
    cin.sync();

    for(int i = 0; i < this->getDimElements(); i++){
        this->array_ExistingElements[i]->calculatePunctuation();
    }

    int option = 0;

    cout << USER << "THIS ARE THE OPTIONS FOR A SEARCH: " <<  RESTORE << endl;
    cout << USER << "[1] Media with +5 of punctuation. " << RESTORE << endl;
    cout << USER << "[2] Media with -5 of punctuation. " << RESTORE << endl;
    cout << USER << "[3] Organize Media by comments and valorations. " << RESTORE << endl;
    cout << USER << "[4] Organize Media by name. " << RESTORE << endl;

    do{

        cin >> option;

        if(option < 1 && option > 4){
            cout << USER << "You tried a wrong option...Try again..." << RESTORE << endl;
        }

    }while(option < 1 && option > 4);

    switch(option){

        case 1:
            userActual->searchToZero();
            this->elementPlus5();
            break;

        case 2: 
            userActual->searchToZero();
            this->elementLess5();
            break;

        case 3:
            userActual->searchToZero();
            this->organizeElementByComments();
            break;

        case 4:
            userActual->searchToZero();
            this->organizeElementByName();
            break;

    }
}

void CristoFinity::elementPlus5(){

    //cout << DEBUG << " debug: mediaPlus5 " << RESTORE << endl;

    float punctuation = 5.0;
    float elementPunctuation = 0.0;
    Element *auxiliar;

    cout << this->getDimElements() << endl;

    for(int i = 0; i < this->getDimElements(); i++){

        elementPunctuation = this->array_ExistingElements[i]->getPunctuation();
        

        if(elementPunctuation >= punctuation){
            
            auxiliar = this->array_ExistingElements[i];
            userActual->addElementToSearch(this->array_ExistingElements[i]);
        }
    }

    userActual->printSearch();
}

void CristoFinity::elementLess5(){

    //cout << DEBUG << " debug: mediaPlus5 " << RESTORE << endl;

    float punctuation = 5.0;
    float elementPunctuation = 0.0;
    Element *auxiliar;

    cout << this->getDimElements() << endl;

    for(int i = 0; i < this->getDimElements(); i++){

        elementPunctuation = this->array_ExistingElements[i]->getPunctuation();
        

        if(elementPunctuation < punctuation){
            
            auxiliar = this->array_ExistingElements[i];
            userActual->addElementToSearch(this->array_ExistingElements[i]);
        }
    }

    userActual->printSearch();
}

void CristoFinity::organizeElementByName(){

    //cout << DEBUG << " debug: organizeElementByName " << RESTORE << endl;

    Element *auxiliar;

    for(int i = 0; i < this->getDimElements(); i++){
        for(int j = 0; j < this->getDimElements(); j++){
            if(this->array_ExistingElements[j]->getTitle() > this->array_ExistingElements[i]->getTitle()){

                auxiliar = this->array_ExistingElements[j];
                this->array_ExistingElements[j] = this->array_ExistingElements[i];
                this->array_ExistingElements[i] = auxiliar;
            }
        }
    }

    for(int i = 0; i < this->getDimElements(); i++){
        auxiliar = this->array_ExistingElements[i];
        userActual->addElementToSearch(auxiliar);
    }

    userActual->printSearch();

}

void CristoFinity::organizeElementByComments(){

    //cout << DEBUG << " debug: organizeElementByComments " << RESTORE << endl;

     Element *auxiliar;

    for(int i = 0; i < this->getDimElements(); i++){
        for(int j = 0; j < this->getDimElements(); j++){
            if(this->array_ExistingElements[j]->getDimComments() > this->array_ExistingElements[i]->getDimComments()){

                auxiliar = this->array_ExistingElements[j];
                this->array_ExistingElements[j] = this->array_ExistingElements[i];
                this->array_ExistingElements[i] = auxiliar;
            }
        }
    }

    for(int i = 0; i < this->getDimElements(); i++){
        auxiliar = this->array_ExistingElements[i];
        userActual->addElementToSearch(auxiliar);
    }

    userActual->printSearch();
}















