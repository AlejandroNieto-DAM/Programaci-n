HELP: Ejemplos de Código

Jaime Matas Bustos
18:55

intropunteritosv0.cpp
C++
Comentarios de la clase
Aún no hay ningún comentario de la clase.
¿Por qué no inicias tú la conversación?
HELP: Ejemplos de CódigoEntregando…
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct Alumno{
    string nombre;
    int edad;
};

int main(){
    int edad = 21;
    int *ptri_edad, *prti_otro = 0; //inicialización de seguridad, para borrar la basura
    //void *ptr;
    
    cout << "---- INTRODUCCIÓN AL MANEJO BÁSICO DE PUNTEROS ---- " << endl;
    cout << "PEDRO imprimo la dirección de memoria basura... ¿qué saldrá?: " << ptri_edad << endl;
    ptri_edad  = &edad; //GUARDO LA DIRECCIÓN DE MEMORIA DE EDAD
    cout << "La dirección de memoria de la variable edad es: " << &edad << endl;
    cout << "La dirección de memoria de la variable edad guardada en el puntero es: " << ptri_edad << " DEBE SER LA MISMA!!!" << endl;
    cout << "El valor de memoria de la variable edad, accedido mediante el puntero es: " << *ptri_edad << endl; //MUESTRA EL CONTENIDO DE LA DIRECCIÓN QUE GUARDA EL PUNTERO
    *ptri_edad = 17; //CAMBIO EL VALOR DE LA CAJITA A LA QUE APUNTA EL PUNTERO (edad) equivalente a hacer: edad = 17
    cout << "Le cambio el valor a partir del puntero, y el nuevo valor es: " << *ptri_edad << endl;
    cout << "Para que seais creyentes imprimo la edad y veréis cómo ha cambiado a tráves del puntero: " << edad << endl;
    
    /*cout << "Pregunta de Antonio: ¿Y si le quito el asterisco *ptri_edad = 17?: ";
    ptri_edad = 17;
    cout << "El puntero vale: " << ptri_edad << " y la edad: " << edad << endl;*/
    

    //VAMOS A SER MALITOS...
 
    ptri_edad = -1; //cambio la dirección de memoria 16 bits!!!!!!! != *ptri_edad = (*ptr_edad) + 1;
    cout << "La nueva dirección de memoria es: " << ptri_edad << endl;
    cout << "El valor de memoria de esta dirección misteriosa, accedido mediante el puntero es: " << *ptri_edad << endl;	//AL SER PUNTERO A ENTERO LO INTERPRETA COMO UN INT
    *ptri_edad = 120;//CAMBIO EL VALOR DE LA CAJITA A LA QUE APUNTA EL PUNTERO (ahora es una posición que no controlo!!)
    cout << "PELIGRO: Le cambio el valor a partir del puntero, y el nuevo valor es: " << *ptri_edad << endl;
    cout << "Pregunta de Antonio: ¿cambia el valor o la dirección?: " << *ptri_edad++ << endl;
    cout << "Respuesta es que imprime el contenido y después cambia la dirección: " << ptri_edad << endl;
    cout << "Pregunta de Antonio2: ¿habrá cambiado el valor de edad?: " << edad << endl;
    
    
    //PARA HACERLO HABRÍA QUE PROGRAMAR ESTA SENTENCIA     *ptri_edad = (*ptri_edad) + 1;
    
   // EXISTEN LOS PUNTEROS A FUNCIONES!!!
   // int *ptr = &(main);
   // cout << ptr;
    
   /* cout << "---- PUNTEROS Y VECTORES ---- " << endl;
    int v[10] = {5,7,2,1,0};
    cout << "La dirección de v: " << v << endl;
    cout << "La dirección de v[0]: " << &(v[0]) << endl;
    cout << "La dirección de v[1]: " << &(v[1]) << endl;
    //v = v + 1; //NO ME DEJA CAMBIAR LA DIRECCIÓN PORQUE ES CONSTANTE
    //v = ptr_edad; //NO ME DEJA CAMBIAR LA DIRECCIÓN PORQUE ES CONSTANTE
    cout << "El valor de v[1]: " << v[1] << endl;
    cout << "Mirar que forma más curiosa de acceder a una posición de memoria: *(v+1): " << *(v+1) << endl;
    cout << "Mirar otra forma curiosa de acceder al valor de una posición: *(&(v[1])): " << *(&(v[1])) << endl;
    
    int *otroptr;
    otroptr = v; //otroptr apunta ahora a mi vector porque he ASIGNADO
    cout << "Al asignar a otro puntero, el puntero del vector puedo poner otroptr[1]: " << otroptr[1] << endl;
    cout << "O esto otro *(otroptr+1): " << *(otroptr+1) << endl;
    cout << "¿Por qué?: Porque otroptr tiene la misma dirección que v: " << otroptr << endl;
    
    /*
    cout << "---- INTODUCCIÓN A MEMORIA DINÁMICA ---- " << endl;
    //1º) Declaro el puntero
    int *p;
    //2º) Solicito al Sistema Operativo que me reserve la memoria pertinente
    p = new int;
    
    //3º) Compruebo que el SO me ha devuelto correctamente la dirección de memoria donde se almacena la nueva variable //CONSEJO ANTIHACKER
    if (p == 0){
        cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        exit(-1);
    }
    //4º) Juego con ella
    *p = 3;
    cout << "El puntero p apunta a la siguiente dirección de memoria del heap: " << p << " y su valor es: " << *p << endl;
    //5º) Liberar la memoria cuando no se usa
    delete p;
    //CONSEJO ANTIHACKER
    cout << "¿Se queda la dirección de p, pese a estar liberado el bloque del heap?: " << p << " y su valor es: " << *p << endl;
    p = 0;
    
    
    Alumno *tarekina;
    tarekina = new Alumno;
    //También se podría hacer en una línea: Alumno *tarekina = new Alumno;
    
    if (tarekina == 0){
        cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        exit(-1);
    }
    (*tarekina).edad = 33;
    (*tarekina).nombre = "Tarekina";
    
    cout << "Alumno: " << (*tarekina).nombre << " y Edad: " << (*tarekina).edad << endl;
   
    
    //Código equivalente totalmente es este
    //La -> se utiliza más habitualmente para estructuras DINÁMICAS, mientras que el punto HAY QUE usarlo
    //en estructuras ESTÁTICAS (Recuerda: Alumno *a = new Alumno; (DINÁMICA) vs Alumno a; (ESTÁTICA))
    tarekina->edad = 35;
    tarekina->nombre = "La Tarekina";
    
    cout << "Alumno: " << tarekina->nombre << " y Edad: " << tarekina->edad << endl;
    
    delete tarekina;
    tarekina = 0;*/
    
}