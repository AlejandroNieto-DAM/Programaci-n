/**
 * File:   Vendedor.cpp
 * Author: neozizou
 * Version: 1.0
 * 
 * Created on 24 de abril de 2012, 9:23
 */

#include "Vendedor.h"
#include "Cliente.h"
#include <iostream>
#include <stdlib.h>

Vendedor::Vendedor(): Persona() {
    this->dim_actual = 1;
    this->utiles = 0;
    this->vector_clientes = new Cliente[this->dim_actual];
    if (!this->vector_clientes){
        cerr << "Error en la creación del vector de clientes" << endl;
        exit(-1);
    }
}

Vendedor::Vendedor(const Vendedor &v){
    this->DNI = v.getDNI();
    this->nombre = v.getNombre();
    this->edad = v.getEdad();
    //ASIGNACIÓN DEL ARRAY CLIENTES
    //Borro
    //delete [] this->vector_clientes; //SOBRA PORQUE ESTÁS CONSTRUYENDO EL OBJETO Y NO HAY NADA RESERVADO!!
    //Reservo con el tamaño del array del vendedor que me pasan
    this->vector_clientes = new Cliente[v.getDim_Actual()];
    if (!this->vector_clientes){
        cerr << "Error en la creación del vector de clientes" << endl;
        exit(-1);
    }
    //Asigno las útiles y la dimensión
    this->dim_actual = v.getDim_Actual();
    this->utiles = v.getUtiles();
    //Copio los valores
    for (int i=0; i < this->dim_actual; i++)
        this->vector_clientes[i] = v.vector_clientes[i];
}

Vendedor::Vendedor(string DNI, string nombre, int edad): Persona(DNI, nombre, edad){
    this->dim_actual = 1;
    this->utiles = 0;
    this->vector_clientes = new Cliente[this->dim_actual];
    if (!this->vector_clientes){
        cerr << "Error en la creación del vector de clientes" << endl;
        exit(-1);
    }
}

Vendedor::~Vendedor(){
    //cout << "debug: destructor Vendedor " << endl;
    this->DNI = "NULL";
    this->nombre = "NULL";
    this->edad = 0;
    //Ahora hay que liberar la memoria reservada del vector clientes
    delete [] this->vector_clientes;
    utiles = 0;
    dim_actual = 0;
}

Vendedor& Vendedor::operator=(const Vendedor &v){
    this->DNI = v.getDNI();
    this->nombre = v.getNombre();
    this->edad = v.getEdad();


    
    //borro y reservo el nuevo espacio y copio los valores
        //Primero borro
        delete [] this->vector_clientes;
        //Reservo con el tamaño del array del vendedor que me pasan
        this->vector_clientes = new Cliente[v.getDim_Actual()];
        if (!this->vector_clientes){
            cerr << "Error en la creación del vector de clientes" << endl;
            exit(-1);
        }
        //Asigno las útiles y la dimensión
        this->dim_actual = v.getDim_Actual();
        this->utiles = v.getUtiles();
        //Copio los valores
        for (int i=0; i < this->utiles; i++)
            this->vector_clientes[i] = v.vector_clientes[i];
    
    return *this;
}

void Vendedor::print() const{
    cout << "Impresión de Vendedor: " << endl;
    /*cout << "DNI: " << this->DNI << endl;
    cout << "Nombre: " << this->nombre << endl;
    cout << "Edad: " << this->edad << endl;*/
    this->Persona::print();
    cout << endl;
    cout << "Sus clientes son..." << endl;
    cout << endl;
    for(int i = 0; i < this->utiles; i++){
        this->getCliente(i);
        cout << endl;
    }

}


//Funcionalidad Avanzada
/**
 *@brief Añade un cliente al vector de clientes del objeto
 */
void Vendedor::vender(const Cliente &c){
	if(this->utiles == this->dim_actual){
		this->vector_clientes = this->resizeAumentar();
	} 

	//cout << this->getUtiles() << endl;

	vector_clientes[utiles] = c;
	//cout << "Dentro" << endl;
	//vector_clientes[utiles].print();
    utiles++;


}

/**
 *@brief Me devuelve el cliente que está en la posición "pos"
  * del vector de clientes del objeto
 */
void Vendedor::getCliente(int pos) const{
	if(pos >= 0 && pos <= dim_actual){
		vector_clientes[pos].print();;
	}else {
        cout << "No se ha podido devolver el cliente de esa posicion..." << endl;
    }
}

/**
* @brief Aumenta la dimensión del vector de clientes.
*/
Cliente* Vendedor::resizeAumentar(){

    //cout << "debug: resizeAumentar " << endl;
	int nuevaDim = this->dim_actual + 1;

	Cliente *auxiliar = new Cliente[nuevaDim];

        if (auxiliar == 0){
            cerr << "Error al aumentar memoria" << endl;
            exit(-1);
    	}

    for(int i = 0; i < utiles; i++){
    	auxiliar[i] = vector_clientes[i];
    }

    delete [] this->vector_clientes;

    this->vector_clientes = auxiliar;

    dim_actual = nuevaDim;

    auxiliar = 0;

    return this->vector_clientes;

}

