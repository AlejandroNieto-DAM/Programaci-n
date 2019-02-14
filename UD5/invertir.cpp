#include <iostream>
using namespace std;

/*

* @brief Procedimiento para invertir los componentes del vector.
* @param util_v que almacena el numero de componentes utilizados en el vector array[].
* @param array[] que ya tiene almacenados unos valores por defecto.
* @param DIM que contiene la dimensión máxima que puede tener el vector.
* @pre util_v > 0 && util_v <= 100.
* @return no devuelve nada.
* @post array[] cambiará todos sus valores de lugar invirtiendolos.

*/
void invertirCadena(int util_v, char array[], const int DIM);

/**

* @brief Procedimiento que sirve para mostrar por la pantalla el vector.
* @param array[] que pasamos por "copia" ya que simplemente vamos a mostrarlo por pantalla y no cambiar sus valores.
* @param util_v que nos tiene guardado el numero de componentes utilizados por el vector.
* @pre array[] debe de tener valores introducidos.
* @pre debe estar activa la salida por pantalla.
* @return no devuelve nada.

*/
void imprimirCadena(int util_v, char array[]);

int main(){

	const int DIM = 100;
	char array[DIM] = {'a', 'b', 'c', 'd', 'e'};
	int util_v = 5;

	imprimirCadena(util_v, array);
	invertirCadena(util_v, array, DIM);
	imprimirCadena(util_v, array);
}

void invertirCadena(int util_v, char array[], const int DIM){

	char array2[DIM];
	int util_v2 = 0;
	int contador = util_v - 1;

	for(int i = 0; i < util_v; i++){

		array2[util_v2] = array[contador - i];
		util_v2++;
	}



	for(int i = 0; i < util_v; i++){

		array[i] = array2[i];

	}

}

void imprimirCadena(int util_v, char array[]){

	for(int i = 0; i < util_v; i++){

		cout << array[i];

	}

	cout << endl;


}