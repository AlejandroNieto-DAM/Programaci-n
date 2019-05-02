#include <iostream>
#include "Vendedor.h"
#include "Cliente.h"

using namespace std;

int main(){

	Cliente Antonio;
	Vendedor Jose;
	Vendedor Luis;

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

	//cout << "Jose print " << endl;
	cout << "******* Imprimimos el vendedor Jose al completo con todos sus clientes *******" << endl;
	Jose.print();

	//Prueba del operador = en vendedor
	
	/*Luis = Jose; 
	cout << "Luis print " << endl;
	Luis.print();
	*/

	//Cliente raul("12345678B", "Raul", 18);
	//raul.print();
	
	
}