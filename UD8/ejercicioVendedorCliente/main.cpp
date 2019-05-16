#include <iostream>
#include "Vendedor.h"
#include "Cliente.h"

using namespace std;

int main(){

	Cliente Antonio;
	Vendedor Jose;
	Vendedor Luis;
	Persona Pepito;

	//Utilizamos sets de Vendedor
	Jose.setDNI("34756447");
	Jose.setNombre("Jose");
	Jose.setEdad(19);

	//Utilizamos sets de Cliente
	Antonio.setDNI("34756447");
	Antonio.setNombre("Antonio");
	Antonio.setEdad(20);

	//Utilizamos gets de Cliente
	cout << "******* Utilizamos los gets *******" << endl;
	cout << Antonio.getDNI() << endl;
	cout << Antonio.getNombre() << endl;
	cout << Antonio.getEdad() << endl;
	cout << endl;

	//Imprimir de cliente
	cout << "******* Utilizamos la funcion print de cliente *******" << endl;
	Antonio.print();
	cout << endl;

	//Constructor por parametros de cliente.
	cout << "******* Creamos cliente Pepe igual que Antonio y lo mostramos *******" << endl;
	Cliente Pepe (Antonio);
	Pepe.print();
	cout << endl;

	cout << "******* Añadimos al vendedor Jose el cliente Antonio *******" << endl;
	Jose.vender(Antonio);

	//Prueba Resize
	
	cout << "******* Creamos 3 clientes y los añadimos al vendedor Jose para comprobar el resize *******" << endl;
	Cliente Pepe1 (Antonio);
	Cliente Pepe2 (Antonio);
	Cliente Pepe3 (Antonio);
	Jose.vender(Pepe);
	Jose.vender(Pepe1);
	Jose.vender(Pepe2);
	Jose.vender(Pepe3);
	
	cout << "******* Utilizamos el getCliente *******" << endl;
	Jose.getCliente(0);
	cout << endl;	
	
	cout << "Jose print " << endl;
	cout << "******* Imprimimos el vendedor Jose al completo con todos sus clientes *******" << endl;
	Jose.print();

	//Prueba del operador = en vendedor*/
	
	Luis = Jose; 
	cout << "Luis print " << endl;
	Luis.print();
	

	Cliente raul("12345678B", "Raul", 18);
	raul.print();
	


	cout << "************ Vector estatico de personas estaticas. **************" << endl;

	Persona vector_estatico_personas[10];
	vector_estatico_personas[0] = Antonio;
	vector_estatico_personas[1] = Luis;
	vector_estatico_personas[2] = Pepito;

	for(int i = 0; i < 3; i++){
		vector_estatico_personas[i].print();
	}


	cout << "*************** Vector estatico de punteros dinamicos a personas. *********" << endl;

	Persona* vector_estatico_personas2[10];
	vector_estatico_personas2[0] = &Antonio;
	vector_estatico_personas2[1] = &Luis;
	vector_estatico_personas2[2] = &Pepito;
	vector_estatico_personas2[3] = new Cliente("83256287", "Mateo", 28);


	for(int i = 0; i < 4; i++){
		vector_estatico_personas2[i]->print();
	}


	cout << "************* Vector dinamico de personas estaticas. *************" << endl;
	
	Persona *vector_dinamico_personas3 = new Persona[10];
	vector_dinamico_personas3[0] = Antonio;
	vector_dinamico_personas3[1] = Luis;
	vector_dinamico_personas3[2] = Pepito;

	for(int i = 0; i < 4; i++){
		vector_dinamico_personas3[i].print();
	}


	cout << "***************** Vector dinamico de punteros dinamicos a personas. *************" << endl;
	
	Persona **vector_dinamico_personas4 = new Persona*[10];
	vector_dinamico_personas4[0] = &Antonio;
	vector_dinamico_personas4[1] = &Luis;
	vector_dinamico_personas4[2] = &Pepito;
	vector_dinamico_personas4[3] = new Cliente("83256287", "Mateo", 28);

	for(int i = 0; i < 4; i++){
		vector_dinamico_personas4[i]->print();

	}

	cout << "\n************* Introspección de tipos. **************" << endl;


	for(int i = 0; i < 4; i++){
		if(Vendedor *h = dynamic_cast<Vendedor*>(vector_dinamico_personas4[i])){
			h->print();
			cout << "Tiene " << h->getUtiles() << " clientes." << endl;
		}

	}

	cout << "\nLuis es un objeto de tipo -> " << typeid(Luis).name() << endl;



	delete [] vector_dinamico_personas3;
	delete vector_estatico_personas2[3];
	delete vector_dinamico_personas4[3];
	delete [] vector_dinamico_personas4;



}