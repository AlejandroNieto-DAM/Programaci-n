#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct Persona{
    string nombre;
    int edad;
};

void setNombre(Persona *p, string nombre){
    //(*p).nombre = nombre  //tb vale
    p->nombre = nombre;    //cuando tenemos punteros nos gusta más usar el operador flecha
}

void setEdad (Persona *p, int edad){
    p->edad = edad;
}

string getNombre(Persona *p){
    return p->nombre;
}

int getEdad (Persona *p){
    return p->edad;
}

void printPersona(Persona *p){
    cout << "Persona: " << getNombre(p) << " tiene " << p->edad << " años." << endl;
}

void printVectorPersonas(Persona *v, int util_v){
    for(int i=0; i < util_v; i++)
        printPersona(&v[i]);
}

Persona* crearPersona(){
    Persona *p = new Persona;
    if (p == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }
    return p;
}

void borrarPersona(Persona *p){
    //formateo a cero/nulo todos los datos que tiene una persona
    p->nombre = "";
    p->edad = -1;
    //borro el fragmento de memoria
    delete p;
    //elimino la dirección que referenciaba al fragmento de memoria
    p = 0;
}

/**
 * @brief Cambia la dimensión del vector a una nueva dim_nueva
 *  1) Creo un vector nuevo con la nueva dimension
 *  2) Copio el contenido del vector que me pasan, en el nuevo vector (OJO SI ES MÁS GRANDE O MÁS CHICO)
 *  3) Libero la memoria del vector que me pasan
 *  4) Devuelvo el puntero del nuevo vector
 */
Persona* resize(Persona *v, int util_actual, int dim_actual,  int dim_nueva){

    Persona *a;
    a = new Persona [dim_nueva];

    if(dim_nueva > dim_actual){
        for(int i = 0; i < util_actual; i++){
            a[i] = v[i];
        }
    } else {
        for(int i = 0; i < dim_nueva; i++){
            a[i] = v[i];
        }
    }

    delete [] v;

    dim_actual = dim_nueva;


    v = a;

    a = 0;

    return v;
    
}

/**
 * @brief Módulo que inserta la Persona p, en el Vector Dinámico de Personas v.
 *  En los escenarios necesarios realiza una llamada al módulo resize para que l nueva persona p pueda introducirse sin problemas y sea transparente para el programado que utilice este módulo
 *
 */
void insertarPersonaenVector(Persona* v, int &util_actual, int &dim_actual, Persona * p){

    if(util_actual < dim_actual){
        v[util_actual] = *p;
          util_actual++;
    } else if (util_actual == dim_actual){
        v = resize(v, util_actual, dim_actual, dim_actual + 1);
        v[util_actual] = *p;
          util_actual++;
    } else {
        cout << "Uops hemos tenido un problema..." << endl;
    }
    
}

int main(){
    
    Persona pepe_estatico; //memoria estática
    //1º) Declaro los punteros
    Persona *pepe = 0, *carlos = 0, *jose = 0; //memoria dinámica
    
    //2º) Pedir memoria al SO
    pepe = crearPersona();
    carlos = crearPersona();
    jose = crearPersona();

    //3º) METEMOS DATOS
    setNombre(pepe,"Pepe");
    setEdad(pepe, 20);
    setNombre(jose,"Jose");
    setEdad(jose, 5);
    setNombre(carlos,"Carlos");
    setEdad(carlos, 47);
    
    
    //AHORA VAMOS A USAR UN VECTOR DINÁMICO
    //Persona v[20]; //memoria estática: ME HA CREADO 20 PERSONAS ESTÁTICAS!!!!!
    
    //1ª ALTERNATIVA: UN VECTOR DINÁMICO DE PERSONAS
    int tamanio = 3;
    int util_v = 0;
    Persona *v = new Persona[tamanio]; //memoria dinámica: ME HE CREADO "tamanio" PERSONAS DINÁMICAS
    if (v == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }
    v[0] = pepe_estatico; //TIPOS COMPATIBLES!!!
    //v[0] = pepe; //TIPOS INCOMPATIBLES!!!
    v[0] = *pepe; //UNA COPIA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    v[1] = *jose;
    v[2] = *carlos;
    util_v = 3;
    //v contiene la dirección de la primera Persona
    printVectorPersonas(v, util_v);
    
    //Uso del resize
    int nuevo_tam = tamanio+2;
    v = resize(v, util_v, tamanio, nuevo_tam );
    printVectorPersonas(v,util_v);
    
    nuevo_tam = tamanio-4;
    v = resize(v, util_v, tamanio, nuevo_tam);
    printVectorPersonas(v, util_v);
    // cout << "¿Dime cuantos alumnos nuevos quieres tener en el vector?" <<
    
    //LIBERAR LA MEMORIA
    delete [] v;  //BORRO LAS COPIAS DE LAS PERSONAS!!!!
    //Borro las personas que tenía creadas antes
    borrarPersona(pepe);
    borrarPersona(carlos);
    borrarPersona(jose);
    //Borrar las direcciones donde estaba la memoria reservada
    v = pepe = carlos = jose = 0;
}
