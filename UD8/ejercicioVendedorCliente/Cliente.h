/* 
 * File:   Cliente.h
 * Author: neozizou
 * Version: 1.0
 * TAREAS: REMODELAR LA CLASE PARA PERFECCIONARLA SEGÚN NUESTRA METODOLOGÍA:  POR EJEMPLO HACER LAS
 * 			  SOBRECARGAS PERTINENTES.
 *
 * Created on 24 de abril de 2012, 8:49
 */

#ifndef CLIENTE_H
#define	CLIENTE_H

#include <string>
using namespace std;
#include "Persona.h"

class Cliente: public Persona {

    public:
        //Constructores
        Cliente(): Persona(){};
        Cliente(const Cliente &c);
        Cliente(string DNI, string nombre, int edad);
        //Destructor
        ~Cliente();
        //PRINT
        void print() const;

};


#endif	/* CLIENTE_H */

