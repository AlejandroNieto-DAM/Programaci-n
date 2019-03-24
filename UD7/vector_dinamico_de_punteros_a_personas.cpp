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
	p->nombre = nombre;	//cuando tenemos punteros nos gusta más usar el operador flecha 
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

void printVectorPersonas(Persona **v, int util_v){
	for(int i=0; i < util_v; i++)
		printPersona(v[i]);
}

int main(){

	//Persona pepe; //memoria estática
	//1º) Declaro los punteros	
	Persona *pepe = 0, *carlos = 0, *jose = 0; //memoria dinámica
	
	//2º) Pedir memoria al SO
	pepe = new Persona;
	if (pepe == 0){
		cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
		exit(-1); 	
	}	
	carlos = new Persona;
	if (carlos == 0){
		cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
		exit(-1); 	
	}
	jose = new Persona;
	if (jose == 0){
		cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
		exit(-1); 	
	}
	//3º) METEMOS DATOS
	setNombre(pepe,"Pepe");
	setEdad(pepe, 20);
	setNombre(jose,"Jose");
	setEdad(jose, 5);
	setNombre(carlos,"Carlos");
	setEdad(carlos, 47);
	

	//AHORA VAMOS A USAR UN VECTOR DINÁMICO
	//Persona v[20]; //memoria estática: ME HA CREADO 20 PERSONAS ESTÁTICAS!!!!!
	
	//2ª ALTERNATIVA: UN VECTOR DINÁMICO DE PUNTEROS A PERSONAS
	int tamanio = 5;
	int util_v = 0;
	Persona **v = new Persona*[tamanio]; //memoria dinámica: ME HE CREADO "tamanio" PUNTEROS A PERSONAS DINÁMICAS
	if (v == 0){
		cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
		exit(-1); 	
	}	
	//v[0] = pepe; //TIPOS INCOMPATIBLES!!!
	v[0] = pepe; //SOLO LA DIRECCIÓN!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	v[1] = jose;
	v[2] = carlos;
	util_v = 3;	

	printVectorPersonas(v,util_v);		

	//LIBERAR LA MEMORIA
	//1º)BORRAR A LO QUE APUNTA EL VECTOR DE PUNTEROS
	for (int i=0; i < util_v; i++)
		delete v[i];
	
	delete [] v;  //BORRO EL VECTOR DE PUNTEROS PROPIAMENTE!!!!
	//Borro las personas que tenía creadas antes --> YA NO ME HACE FALTAAAAAAAAA!	
	//delete pepe;
	//delete carlos;
	//delete jose;
	//Borrar las direcciones donde estaba la memoria reservada
	pepe = carlos = jose = 0;
	v = 0;	
}

