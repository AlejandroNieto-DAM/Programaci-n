#include <iostream>
using namespace std;

/**

* @brief Procedimiento que sirve para mostrar por la pantalla el vector.
* @param array[] que pasamos por "copia" ya que simplemente vamos a mostrarlo por pantalla y no cambiar sus valores.
* @param util_v que nos tiene guardado el numero de componentes utilizados por el vector.
* @pre array[] debe de tener valores introducidos.
* @pre debe estar activa la salida por pantalla.
* @return no devuelve nada.

*/
void imprimeCadena(int util_v, char array[]);

/**

* @brief Procedimiento que sirve para unir cadenas en un vector.
* @param util_v que guarda los componentes utilizados en array[].
* @param util_v2 que guarda los componentes utilizados en array2[].
* @param util_v3 que guardará los componentes utilizados en array3[] y por eso lo pasamos por referencia.
* @param array[] que tiene unos valores introducidos por defecto.
* @param array2[] que tiene unos valores introducidos por defecto.
* @param array3[] que contendrá los valores de ambos vectores array[] y array2[].
* @pre util_v + util_v2 no será mayor a la dimensión máxima que puede tener un vector (100).
* @return no devuelve nada.
* @post array3[] almacenará las dos cadenas y su util por tanto cambiará.

*/
void concatenarCadenas(int util_v, const char array[], int util_v2, const char array2[], int &util_v3, char array3[]);

/*

* @brief Procedimiento que sirve para quitar los espacios que pueda haber en la cadena.
* @param util_v3 que contiene el numero de componentes utilizados en array3[].
* @param array3[] que contiene los valores de array[] y array2[].
* @param DIM que es la dimensión maxima de un vector ya que vamos a utilizar uno auxiliar.
* @pre util_v3 > 0 && util_v3 <= 100
* @return no devuelve nada.

*/
void quitarEspacios(int &util_v3, char array3[], const int DIM);

int main(){

	const int DIM = 100;

	char array[DIM] = {'a', ' ', 'b', ' ', 'c'}, array2[DIM] = {'d', ' ', 'e', ' ', 'f'}, array3[DIM];

	int util_v = 5, util_v2 = 5, util_v3 = 0;


	cout << "Vector1: {";
	imprimeCadena(util_v, array);
	cout << "} " << endl;

	cout << "Vector2: {";
	imprimeCadena(util_v2, array2);
	cout << "} " << endl;

	concatenarCadenas(util_v, array, util_v2, array2, util_v3, array3);
	quitarEspacios(util_v3, array3, DIM);

	cout << "Vector final: {";
	imprimeCadena(util_v3, array3);
	cout << "} " << endl;


}

void imprimeCadena(int util_v, char array[]){

	for(int i = 0; i < util_v - 1; i++){

		cout << array[i] << ", ";
	}

	cout << array[util_v - 1];

}

void concatenarCadenas(int util_v, char array[], int util_v2, char array2[], int &util_v3, char array3[]){

	int util_v32 = 0;
	int i = 0;

	for(int i = 0; i < util_v; i++){

		array3[i] = array[i];
		util_v3++;
	}

	for(int i = 0; i < util_v2; i++){

		array3[util_v + i] = array2[i];
		util_v3++;
	}

}

void quitarEspacios(int &util_v3, char array3[], const int DIM){

	char aux[DIM];
	int util_aux = 0;

	for(int i = 0; i < util_v3; i++){

		if(array3[i] != 32){

			array3[util_aux] = array3[i];
			util_aux++;

		}

	}

	util_v3 = util_aux;

}	
