#include <iostream>
#include <iomanip>
#define RESTORE "\033[1;0m"
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"
using namespace std;

/**

* @brief Procedimiento que sirve para ver los el numero de componentes a utilizar en el vector.
* @param util_v (E) que pasamos por referencia ya que vamos a cambiar su valor.
* @pre util_v tendria que haber sido inicializado a 0 para que no contenga basura.
* @return no devuelve nada.
* @post util_v contendra el numero de componentes a utilizar en el vector.

*/
void leerUtil (int &util_v){

	cout << "Cuantos numeros deseas introducir? ";
	cin >> util_v;

}


/**

* @brief Procedimiento que utilizamos para introducir los valores en el vector.
* @param util_v que pasamos por copia ya que no vamos a cambiar su valor.
* @param vector1[] (E) que pasamos por referencia ya que vamos a introducir valores dentro de él.
* @pre debe estar activa la entrada por teclado.
* @pre util_v debe de tener un valor distinto de 0.
* @return no devuelve nada.
* @post vector1[] debe guardar los valores introducidos hasta el útil anteriormente seleccionado.

*/

void leerVector (int util_v, double vector1[]){

	for(int i = 0; i < util_v; i++){

		cout << "Introduce el numero " << i + 1 << " : ";
		cin >> vector1[i];

	}


}

/**

* @brief Procedimiento que utilizaremos para almacenar los valores introducidos en el vector anterior en otro.
* @param util_v que pasamos por copia ya que no vamos a cambiar su valor.
* @param vector1[] que pasamos por "copia" ya que vamos a copiar sus valores dentro de vector2[].
* @param vector2[] que pasamos por referencia ya que vamos a introducir los valores del primer vector dentro de él.
* @pre debe estar activa la entrada por teclado.
* @pre util_v debe de tener un valor distinto de 0.
* @pre vector1[] debe de tener valores almacenados.
* @return no devuelve nada.
* @post vector2[] debe guardar los valores introducidos en el vector1[] hasta el útil anteriormente seleccionado.

*/

void cambiarVector (const double vector1[], int util_v, double vector2[]){

	for(int i = 0; i < util_v; i++){

		vector2[i] = vector1[i];

	}

}

/**

* @brief Procedimiento que sirve para mostrar por la pantalla el vector.
* @param vector2[] que pasamos por "copia" ya que simplemente vamos a mostrarlo por pantalla y no cambiar sus valores.
* @param util_v que nos tiene guardado el numero de componentes utilizados por el vector.
* @pre vector2[] debe de tener los valores introducidos del vector1[]
* @pre debe estar activa la salida por pantalla.
* @return no devuelve nada.

*/

void imprimirVector (const double vector2[], int util_v){

	for(int i = 0; i < util_v; i++){

		cout <<  vector2[i] << " ";

	}

}

int main(){

	int DIM = 100;
	double vector1[DIM], vector2[DIM];

	int util_v = 0;

	leerUtil(util_v);
	leerVector(util_v, vector1);
	cambiarVector(vector1, util_v, vector2);
	imprimirVector(vector2, util_v);


}