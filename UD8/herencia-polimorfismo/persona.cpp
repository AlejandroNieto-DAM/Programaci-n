#include <iostream>
#include <string.h>
#include "persona.h"
using namespace std;

Persona::Persona(){
  
  nombre = "NULL";
  apellido1 = "NULL";
  apellido2 = "NULL";
  edad = 0;
  
}

Persona::~Persona(){
    cout << "debug: Destruyendo el objeto Persona: " << this->nombre << " " << this->apellido1 << endl;
}

void Persona::setNombre(string nomb){
  
  this->nombre = nomb;
  
}

void Persona::setApellido1(string ape1){
  
  this->apellido1 = ape1;
  
}

void Persona::setApellido2(string ape2){
  
  this->apellido2 = ape2;
  
}

void Persona::setEdad(int ed){
  
  this->edad = ed;
  
}

void Persona::orinar(){
  
  cout << this->nombre << " " << this->apellido1 << " " << "esta orinando ¿pero cómo?" << endl;
  
}

void Persona::comer(){
  
  cout << this->nombre << " " << this->apellido1 << " " << "esta comiendo chicha de la buena..." << endl;
  
}

void Persona::print(){
  
  cout << endl;
  cout << "Nombre: " << this->nombre << endl;
  cout << "Primer apellido: " << this->apellido1 << endl;
  cout << "Segundo apellido: " << this->apellido2 << endl;
  cout << "Edad: " << this->edad << endl;
  cout << endl;
  
}

/*---------------------------------- Class Hombre -------------------------------------*/

Hombre::~Hombre(){
    cout << "debug: Destruyendo el objeto Hombre: " << this->nombre << " " << this->apellido1 << endl;
}

void Hombre::orinar(){
  
  cout << this->nombre << " " << this->apellido1 << " " << "esta orinando de pie tratando de no salirse..." << endl;
  
}

void Hombre::print(){
  /*CÓDIGO COMO EL DE PERSONA*/
  cout << endl;
  cout << "Nombre: " << this->nombre << endl;
  cout << "Primer apellido: " << this->apellido1 << endl;
  cout << "Segundo apellido: " << this->apellido2 << endl;
  cout << "Edad: " << this->edad << endl;

  /*AÑADO LOS ATRIBUTOS PROPIOS DE HOMBRE*/
  cout << "Pagafantas: " << this->pagafantas << endl;
  cout << endl;
}

/*---------------------------------- Class Mujer -------------------------------------*/

Mujer::~Mujer(){
    cout << "debug: Destruyendo el objeto Mujer: " << this->nombre << " "<< this->apellido1 << endl;
}

void Mujer::orinar(){
  
  cout << this->nombre << " " << this->apellido1 << " " << "esta orinando sentada y educadamente..." << endl;
  
}

void Mujer::print(){
  /*CÓDIGO COMO EL DE PERSONA*/
  /*cout << endl;
  cout << "Nombre: " << this->nombre << endl;
  cout << "Primer apellido: " << this->apellido1 << endl;
  cout << "Segundo apellido: " << this->apellido2 << endl;
  cout << "Edad: " << this->edad << endl;*/
  this->Persona::print();  

  /*AÑADO LOS ATRIBUTOS PROPIOS DE MUJER*/
  cout << "Embarazada: " << this->embarazada << endl;
  cout << endl;
}

/*---------------------------------- Class Renault -------------------------------------*/
void Renault::print(){
  /*AÑADO LOS ATRIBUTOS PROPIOS DE MUJER*/
  cout << "Golfo: " << this->porreta << endl;
}

void Renault::orinar(){
  /*AÑADO LOS ATRIBUTOS PROPIOS DE MUJER*/
  cout << "El Hombre de tipo Renault orina golfeando y saliendose: " << this->golfo << endl;
}
