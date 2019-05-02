/* 
 * File:   persona.h
 * Author: neozizou
 *
 * Modificated on 7 de mayo de 2018, 11:07
 * Muy importante la lectura:
 * http://c.conclase.net/curso/index.php?cap=037#inicio
 *  
 */
#include <iostream>
#include <string.h>
using namespace std;

class Persona{

    protected:
        string nombre;
        string apellido1;
        string apellido2;
        int edad;
            
    public:
        Persona();
        //No hace falta destructor porque todos los atributos miembros son estáticos
        virtual ~Persona();
        void vectorPersona(int dimension);
        void setNombre(string nomb);
        void setApellido1(string ape1);
        void setApellido2(string ape2);
        void setEdad(int ed);
        void comer();
        virtual void orinar();
        virtual void print();         
};

class Hombre: public Persona{
    protected:
        bool pagafantas;
    public:
        Hombre() : Persona(){pagafantas = true;};
        Hombre(string nombre, string apellido1, string apellido2, int edad,
                bool pagafantas) : Persona() {
                    this->pagafantas = pagafantas;
                    this->nombre = nombre;
                    this->apellido1 = apellido1;
                    this->apellido2 = apellido2;
                    this->edad = edad;
        };
        ~Hombre();
        //No hace falta destructor porque todos los atributos miembros son estáticos
        inline void setPagafantas(bool pagafantas) {this->pagafantas = pagafantas;};
        void orinar();
        void print();

};

class Mujer: public Persona{
    protected:
        bool embarazada;
    public:
        Mujer() : Persona(){embarazada = false;};
        Mujer(string nombre, string apellido1, string apellido2, int edad,
                bool embarazada) : Persona() {
                    this->embarazada = embarazada;
                    this->nombre = nombre;
                    this->apellido1 = apellido1;
                    this->apellido2 = apellido2;
                    this->edad = edad;
        };
        
        ~Mujer();
        //No hace falta destructor porque todos los atributos miembros son estáticos
        inline void setEmbarazada(bool embarazada) {this->embarazada = embarazada;};
        void orinar();
        void print();
};

class Renault : public Hombre{
        private:
            bool golfo;
        public:
            inline bool getGolfo(){return golfo;};
            inline void setGolfo(bool golfo){this->golfo = golfo;};
            void print();
            void orinar();
};
