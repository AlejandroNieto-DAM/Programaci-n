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

         /**
         * @brief Aumenta la dimension del vector de clientes de vendedor.
         * @pre utiles == dimension
         * @post El vector quedará aumentado en 1.
        */
        Cliente* resizeAumentar();
         

    public:
        //Funcionalidad Mínima
        Vendedor();
        //Constructor por parámetros
        Vendedor(const Vendedor& v);
        Vendedor(string DNI, string nombre, int edad);
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
         *@brief Me devuelve el cliente que está en la posición "pos"
          * del vector de clientes del objeto
         */
        void getCliente(int pos) const;
};

#endif	/* VENDEDOR_H */

