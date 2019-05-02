/* 
 * File:   Vendedor.h
 * Author: neozizou
 * TAREAS: REMODELAR LA CLASE PARA PERFECCIONARLA SEGÚN NUESTRA METODOLOGÍA:  POR EJEMPLO HACER LAS
 * 			  SOBRECARGAS PERTINENTES e IMPLEMENTAR LOS MÉTODOS QUE FALTAN.
 * Created on 24 de abril de 2012, 9:23
 */

#ifndef VENDEDOR_H
#define	VENDEDOR_H

#include <iostream>
#include <string>
#include "Cliente.h" //ojo que usa la Clase Cliente!!!
#include "Persona.h"
#include <stdlib.h>
using namespace std;

class Vendedor: public Persona {
    private:
        Cliente* vector_clientes;
        int dim_actual;
        int utiles;

    public:
        //Funcionalidad Mínima
        Vendedor(): Persona() {
                this->dim_actual = 1;
                this->utiles = 0;
                this->vector_clientes = new Cliente[this->dim_actual];
                if (!this->vector_clientes){
                    cerr << "Error en la creación del vector de clientes" << endl;
                    exit(-1);
                }
        };
        //Constructor por parámetros
        Vendedor(const Vendedor& v);
        Vendedor(string DNI, string nombre, int edad): Persona(DNI, nombre, edad){
                    this->dim_actual = 1;
                    this->utiles = 0;
                    this->vector_clientes = new Cliente[this->dim_actual];
                    if (!this->vector_clientes){
                        cerr << "Error en la creación del vector de clientes" << endl;
                        exit(-1);
                     }
        };
        //Destructor de la clase Vendedor
        ~Vendedor();
        //Los GETS
        inline int getUtiles() const { return this->utiles; }
        inline int getDim_Actual() const { return this->dim_actual; }
        //SOBRECARGA DE OPERADOR =
        Vendedor& operator=(const Vendedor &v);
        //PRINT
        void print() const;

        //Funcionalidad Avanzada
        /**
         *@brief Añade un cliente al vector de clientes del objeto
         */
        void vender(const Cliente &c);

        /**
         * @brief Aumenta la dimension del vector de clientes de vendedor.
         * @pre utiles == dimension
         * @post El vector quedará aumentado en 1.
        */
        Cliente* resizeAumentar();
         
        /**
         *@brief Me devuelve el cliente que está en la posición "pos"
          * del vector de clientes del objeto
         */
        void getCliente(int pos) const;
};

#endif	/* VENDEDOR_H */

