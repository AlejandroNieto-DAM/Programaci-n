#include <iostream>
using namespace std;

/*

* @brief Leer el util para ver en que distacia nos movemos por el vector.
* @param util_v que pasamos por referencia ya que lo vamos a cambiar dentro del modulo.
* @pre util_v se tomara desde la entrada de teclado.
* @return no devuelve nada.
* @post util_v ha de ser menor que DIM = 100 y mayor que 0.

*/

void leerUtil(int &util_v){

	do{

		cout << "Introduce el numero de componentes a utilizar en el vector: ";
		cin >> util_v;

	}while(util_v < 1 || util_v > 100);

}


/*

* @brief Introducir todos los numeros del vector dados por el util_v.
* @param int util_v que indica el numero de componentes utilizados.
* @param int vector[] para introducir todos los numeros.
* @pre no se podran introducir mas de el numero dado por util_v.
* @return no devuelve nada.
* @post Los numeros introducidos en el vector han de ser enteros para indicar si son primos o no posteriormente.

*/
void leerVector(int vectorEnteros[], int util_v){

	for(int i = 0; i < util_v; i++){

		cout << "Introduce el numero " << i + 1 << " : ";
		cin >> vectorEnteros[i];

	}

	
}


/*

* @brief introduce los numeros primos calculados en otro vector.
* @param int vector[] nos da el numero necesario para calcular si es primo.
* @param int util_v que determina el máximo del vector.
* @param int util_v2 que determinará el tamaño del segundo vector.
* @param int vectorPrimos[] que almacenará los numeros primos calculados.
* @pre el maximo del vector lo determina el util_v que no podra pasarse.
* @return no devuelve nada.
* @post se almacenaran los numeros primos.

*/
void calcularVectorPrimos(const int vectorEnteros[], int util_v, int vectorPrimos[], int &util_v2){

	int suma = 0;
	int contador = 0;


	for(int i = 0; i < util_v; i++){

		contador = vectorEnteros[i];

		for(int z = 1; z <= contador ; z++){

			if(contador % z == 0){

				suma++;

			}

		}

		if(suma == 2){

			vectorPrimos[util_v2] = contador;
			util_v2 += 1;

		}

		suma = 0;

	}

}


/*

* @brief Imprime los numeros primos guardados en el segundo vector.
* @param util_v2 que determina el tamaño maximo del vector de primos.
* @param vectorPrimos[] que tiene los numeros primos ya almacenados.
* @pre util_v2 debe tener el tamaño de componentes utilizados dentro del vectorPrimos. Debe estar activa la salida por pantalla.
* @return no devuelve nada.

*/
void imprimirPrimos(int util_v2, const int vectorPrimos[]){

	for(int i = 0; i < util_v2; i++){

		cout << vectorPrimos << endl;

	}

}

int main(){

	const int DIM = 100;
	int vectorEnteros[DIM] = {0}, vectorPrimos[DIM] = {0};
	int util_v = 0, util_v2 = 0;

	leerUtil(util_v);
	leerVector(vectorEnteros, util_v);
	calcularVectorPrimos(vectorEnteros, util_v, vectorPrimos, util_v2);
	imprimirPrimos(util_v2, vectorPrimos);

}