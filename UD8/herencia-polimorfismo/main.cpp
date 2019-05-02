#include <iostream>
#include <string.h>
#include "persona.h"
using namespace std;

int main(){

  /*Uso de Polimorfismo y Generalizacion*/
  Hombre h1;
  Persona p1;
 
  h1.print();
  
  /*Veamos la potencia de la herencia*/
  h1.setNombre("Paquito");
  h1.setApellido1("Martínez");
  h1.setApellido2("Soria");
  h1.setEdad(21);
  h1.setPagafantas(true);
  h1.print();
  h1.comer();
  
  p1.setNombre("Persona");
  p1.setApellido1("Generica");
  p1.setApellido2("Polimorfica");
  p1.setEdad(21);
  p1.print();
  p1.comer();
  
  Mujer m1;
  m1.setNombre("Antoñita");
  m1.setApellido1("Perez");
  m1.setApellido2("Robles");
  m1.setEdad(20);
  m1.setEmbarazada(false);
  m1.print();
  m1.comer();
  
  cout << endl;
  
  h1.orinar();
  m1.orinar();
  p1.orinar();

/*
  /*Veamos la potencia del polimorfismo
  cout << "VEAMOS LA POTENCIA DEL POLIMORFISMO" << endl;
  Persona *p; //PODEMOS TRABAJAR CON PUNTEROS A PERSONA!!
  p=&h1; //LE PASO LA DIRECCIÓN DE MEMORIA DE UN OBJETO HOMBRE
  p->orinar(); // SE COMPORTA COMO UN HOMBRE!!!
  p= &m1; //LE PASO LA DIRECCIÓN DE MEMORIA DE UN OBJETO MUJER
  p->orinar(); // SE COMPORTA COMO UNA MUJER!!!

  /*Veamos que sencillo resulta crear un array polimórfico de Personas
  cout << "FUNCIONAMIENTO DE UN ARRAY POLIMÓRFICO (ESTÁTICO): " << endl;
  int utiles = 0;
  const int DIM = 10;
  Persona* vector_polimorfico [DIM]; //los punteros da igual que sean estáticos o dinámicos
  //Meto en el vector Personas, Hombres, Mujeres, etc
  //PERO NECESARIAMENTE TENGO QUE USAR DIRECCIONES DE MEMORIA DE OBJETOS!!!
  vector_polimorfico[0] = &m1;
  vector_polimorfico[1] = &h1;
  vector_polimorfico[2] = &p1;
  utiles = 3;
  //Imprimimos el vector y HACEMOS LLAMADAS A MÉTODOS POLIMÓRFICOS
  cout << endl << "IMPRIMIMOS EL VECTOR POLIMÓRFICO:" << endl;
  for (int i=0; i < utiles; i++){
      vector_polimorfico[i]->print();
      vector_polimorfico[i]->orinar();
  }
  
  cout << endl << "CREACIÓN DINÁMICA DE OBJETOS POLIMÓRFICOS Y ALMACENAMIENTO EN EL ARRAY (ESTÁTICO):" << endl;
  //Pedir al usuario los datos para crear Hombres o Mujeres y almacenarlos en un array polimórfico
  vector_polimorfico[3] = new Hombre("Pepe","Llorón","Guardiola", 42, true);
  vector_polimorfico[4] = new Mujer("Pepa","Pepita","Pepona",34, false);
  utiles = utiles + 2;
  vector_polimorfico[3]->print();
  vector_polimorfico[4]->print();
  
  cout << endl << "ALMACENAMIENTO EN UN ARRAY DINÁMICO DE LIGADURAS DINÁMICAS:" << endl;
  Persona** vector_polimorfico_din = new Persona*[5];
  for(int i=0; i < utiles; i++){
      vector_polimorfico_din[i] = vector_polimorfico[i];
      vector_polimorfico_din[i]->print();
      vector_polimorfico_din[i]->orinar();
  }

  
  cout << "PREGUNTA ANTONIO: ¿Antonio al no heredar de persona lo puedo meter en un array polimófico?" << endl;
  Antonio un_antonio;
  un_antonio.setPorreta(true);
  cout << "RESPUESTA: ¿Se permite la ligadura dinámica de objetos que no pertenecen a la jerarquía de clases? " << endl;
  vector_polimorfico[utiles] = &un_antonio;
  //ERROR EN TIEMPO DE COMPILACIÓN: 
  //main.cpp:95:32: error: assigning to 'Persona *' from incompatible type 'Antonio'
  
  utiles++;
  
  cout << "VOLVEMOS A IMPRIMIR EL VECTOR POLIMÓRFICO..." << endl;
  for (int i=0; i < utiles; i++){
      vector_polimorfico[i]->print();
      vector_polimorfico[i]->orinar();
  }
  
  //Ojo con lo que borramos
  delete vector_polimorfico[3];
  delete vector_polimorfico[4];
  delete [] vector_polimorfico_din;
 */
}
