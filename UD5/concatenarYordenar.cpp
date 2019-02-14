#include <iostream>
using namespace std;

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
void concatenarCadenas(int util_v, int array[], int util_v2, int array2[], int &util_v3, int array3[]){

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


/**

* @brief Procedimiento que sirve para mostrar por la pantalla el vector.
* @param array[] que pasamos por "copia" ya que simplemente vamos a mostrarlo por pantalla y no cambiar sus valores.
* @param util_v que nos tiene guardado el numero de componentes utilizados por el vector.
* @pre array[] debe de tener valores introducidos.
* @pre debe estar activa la salida por pantalla.
* @return no devuelve nada.

*/
void imprimeCadena(const int array[], int util_v){

	if(util_v > 0){

		for(int i = 0; i < util_v - 1; i++){
			cout << array[i] << ", ";
		}

		cout << array[util_v - 1];

	}


}

/*

* @brief Procedimiento que sirve para ordenar de mayor a menor los componentes de un vector.
* @param util_v3 que guarda los componentes utilizados en array3[].
* @param array3[] que pasamos por referencia ya que moveremos de lugar los componentes que tiene.
* @pre util_v3 > 0 && util_v3 <= 100
* @return no devuelve nada.

*/
void ordenacion(int util_v3, int array3[]){

	int aux = 0;

	for(int i = 0; i < util_v3; i++){

		for(int j = 0; j < util_v3; j++){

			if(array3[i] >= array3[j]){

				aux = array3[i];
				array3[i] = array3[j];
				array3[j] = aux;

			}

		}

	}


}



int main(){

	const int DIM = 100;

	int array[DIM] = {1, 6, 5}, array2[DIM] = {2, 156, 67}, array3[DIM];

	int util_v = 3, util_v2 = 3, util_v3 = 0;

	cout << "Vamos a imprimir los vectores: " << endl;

	cout << "V1 = { ";
	imprimeCadena(array, util_v);
	cout << "}" << endl;

	cout << "V2 = { ";
	imprimeCadena(array2, util_v2);
	cout << "}" << endl;


	concatenarCadenas(util_v, array, util_v2, array2, util_v3, array3);


	ordenacion(util_v3, array3);

	cout << "Vector ordenado: {";
	imprimeCadena(array3, util_v3);
	cout << "}" << endl;


}


