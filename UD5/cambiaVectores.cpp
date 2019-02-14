#include <iostream>
#include <iomanip>

#define RESTORE "\033[1;0m"
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"

using namespace std;

/**

* @brief Procedimiento que sirve para mostrar por pantalla los vectores.
* @param util_v que guarda el numero de componentes utilizados en v[].
* @param util_v2 que guarda el numero de componentes utilizados en v2[].
* @param v[] que guarda una serie de caracteres distinto de v2[].
* @param v2[] que guarda una serie de caracteres distinto de v[].
* @pre util_v debe ser distinto de 0, es decir que este inicializado.
* @pre util_v2 debe ser distinto de 0, es decir que este inicializado.
* @pre v[] debe de tener una serie de valores guardados con unos utiles en concreto.
* @pre v2[] debe de tener una serie de valores guardados con unos utiles en concreto.
* @return no devuelve nada.

*/

void imprimir(int &util_v, char v[], int &util_v2, char v2[]){

	

	cout << USER <<  "Vector1 : " << RESTORE;

	for(int i = 0; i < util_v; i++){

		cout << v[i];


	}

	cout << endl;

	cout << USER << "Vector2 : " << RESTORE;

	for(int i = 0; i < util_v2; i++){

		cout << v2[i];


	}

	cout << endl;

}

/**

* @brief procedimiento que nos intercambiará el contenido de un vector en otro utilizando un vector local auxiliar.
* @param util_v que guarda el numero de componentes utilizados en v[].
* @param util_v2 que guarda el numero de componentes utilizados en v2[].
* @param v[] que guarda una serie de caracteres distinto de v2[].
* @param v2[] que guarda una serie de caracteres distinto de v[].
* @param DIM que es una constante ya que la dimensión del vector no cambiará nunca.
* @pre util_v debe ser distinto de 0, es decir que este inicializado.
* @pre util_v2 debe ser distinto de 0, es decir que este inicializado.
* @pre v[] debe de tener una serie de valores guardados con unos utiles en concreto.
* @pre v2[] debe de tener una serie de valores guardados con unos utiles en concreto.
* @pre la suma de ambos utiles no debe ser mayor que la Dimensión total que puede alcanzar un vector.
* @return no devuelve nada.
* @post se cambiará el contenido de v[] por el de v2[] y al contrario.

*/

void intercambiarVectores(int &util_v, char v[], int &util_v2, char v2[], const int DIM){

	int aux[DIM];
	int aux2 = 0;

	//cout << DEBUG << "Util_v sin cambiar: " << util_v << endl;
	//cout << DEBUG << "Util_v2 sin cambiar: " << util_v2 << endl;

	if(util_v2 >= util_v){

		for(int i = 0; i < util_v2; i++){

			aux[i] = v[i];
			v[i] = v2[i];
			v2[i] = aux[i];

		}

	} else {


		for(int i = 0; i < util_v; i++){

			aux[i] = v[i];
			v[i] = v2[i];
			v2[i] = aux[i];

		}
	}

	aux2 = util_v;
	util_v = util_v2;
	util_v2 = aux2;

	//cout << DEBUG << "Util_v cambiado: " << util_v << endl;
	//cout << DEBUG << "Util_v2 cambiado: " << util_v2 << endl;
}

int main(){

	const int DIM = 100;
	char vector1[DIM] = {'a','r','r','o','z'}, vector2[DIM] = {'a','r','r','o','z','a','r','r','o','z','a','r','r','o','z'};
	int util_v = 5, util_v2 = 15;


	cout << USER << "Vamos a mostrar los vectores antes antes de que sena intercambiados: " << RESTORE << endl;
	imprimir(util_v, vector1, util_v2, vector2);

	intercambiarVectores(util_v, vector1, util_v2, vector2, DIM);

	cout << USER << "Los vectores han sido intercambiados: " << RESTORE << endl;
	imprimir(util_v, vector1, util_v2, vector2);
	cout << USER << "Programa finalizado..." << RESTORE << endl;


}