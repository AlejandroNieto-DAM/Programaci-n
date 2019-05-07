#include "Persona.h"
#include <string>
#include <iostream>
using namespace std;

Persona::Persona(){
    this->DNI = "NULL";
    this->nombre = "NULL";
    this->edad = 0;
}

Persona::Persona(const Persona &c){
    this->DNI = c.getDNI();
    this->nombre = c.getNombre();
    this->edad = c.getEdad();
}

Persona::Persona(string DNI, string nombre, int edad){
    this->DNI = DNI;
    this->nombre = nombre;
    this->edad = edad;
}

Persona::~Persona(){
    //cout << "debug: destructor Persona " << endl;
    //no hace nada porque sólo tiene variables estáticas
    this->DNI = "NULL";
    this->nombre = "NULL";
    this->edad = 0;
}

void Persona::print() const{
    cout << "Impresión de Persona: " << endl;
    cout << "DNI: " << this->DNI << endl;
    cout << "Nombre: " << this->nombre << endl;
    cout << "Edad: " << this->edad << endl;
}
