#include "Cliente.h"
#include <string>
#include <iostream>
using namespace std;

Cliente::Cliente(const Cliente &c){
    this->DNI = c.getDNI();
    this->nombre = c.getNombre();
    this->edad = c.getEdad();
}

Cliente::Cliente(string DNI, string nombre, int edad){
    this->DNI = DNI;
    this->nombre = nombre;
    this->edad = edad;
}

Cliente::~Cliente(){
    //cout << "debug: destructor Cliente " << endl;
    //no hace nada porque sólo tiene variables estáticas
    this->DNI = "NULL";
    this->nombre = "NULL";
    this->edad = 0;
}

void Cliente::print() const{
    cout << "Impresión de Cliente: " << endl;
    this->Persona::print();
}

 


