#ifndef PERSONA_H
#define	PERSONA_H

#include <string>
using namespace std;

class Persona {
    protected:
        string DNI;
        string nombre;
        int edad;

    public:
        //Funcionalidad Mínima
        Persona();
        Persona(const Persona& v);
        Persona(string DNI, string nombre, int edad);
        ~Persona();
        //Los SETS
        inline void setDNI(string DNI) { this->DNI = DNI; }
        inline void setNombre(string nombre) { this->nombre = nombre; }
        inline void setEdad(int edad) { this->edad = edad; }
        //Los GETS
        inline string getDNI() const { return this->DNI; }
        inline string getNombre() const { return this->nombre; }
        inline int getEdad() const { return this->edad; }
        //PRINT
        void print() const;

};

#endif	/* PERSONA_H */

