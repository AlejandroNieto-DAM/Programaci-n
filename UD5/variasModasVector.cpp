#include <iostream>
#include <iomanip>
using namespace std;

#define RESTORE "\033[1;0m"
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"

/**

* @brief Procedimiento que sirve para mostrar por la pantalla el vector.
* @param array[] que pasamos por "copia" ya que simplemente vamos a mostrarlo por pantalla y no cambiar sus valores.
* @param util_v que nos tiene guardado el numero de componentes utilizados por el vector.
* @pre array[] debe de tener valores introducidos.
* @pre debe estar activa la salida por pantalla.
* @return no devuelve nada.

*/
void imprimeCadena(int util_v, const int array[]){

	for(int i = 0; i < util_v - 1; i++){

		cout << array[i] << ", ";
	}

	cout << array[util_v - 1];

}

/**

* @brief Calcula los numeros que más veces se repiten en el vector.
* @param util_v que guarda el numero de componentes utilizados en el vector.
* @param array[] que tiene guardados unos valores predeterminados.
* @param moda[] que almecenará el valor de los numeros que más veces se repiten.
* @pre util_v > 0 && util_v <= 100.
* @return no devuelve nada.
* @post moda[] almacenará el numero que mas veces se repita.

*/

void calculaModas(int util_v, const int array[], int &util_moda, int moda[]){

	int suma = 0;
	int res = 0;
	int suma2 = 0;


	for(int i = 0; i < util_v; i++){

		//Igualamos la suma a 0 para que empiece a sumar los iguales de la siguiente iteración.
		suma = 0;

		for(int j = 0; j < util_v; j++){

			//Si son iguales se hará suma++ que indicará el numero de veces que se repite.
			if(array[i] == array[j]){

				suma++;
				//cout << DEBUG << "Valor suma: " << suma << RESTORE << endl;
			}

			if(i == 0){
				res = suma;
			}

		}

		if(suma == res){

					moda[util_moda] = array[i];
					util_moda++;

		} 

		cout << DEBUG << "Util_moda " << util_moda << RESTORE << endl;


	}


}

/**

* @brief Ordena los elementos de un vector.
* @param v[] que tiene guardados unos elementos anteriormente guardados.
* @param util_v que nos indica el numero de componentes utilizados en vector.
* @pre util_v debe ser mayor que 0.
* @pre v[] debe tener guardados valores en su interior.
* @return no devuelve nada.
* @post el vector quedará ordenado después de ejecutar el bucle.

*/

void OrdBurbuja (int v[], int util_v){

	int auxiliar = 0;

	for(int izqa = 0; izqa < util_v; izqa++){

		for(int i = 0; i < util_v; i++){

			if(v[izqa] < v[i]){

				auxiliar = v[izqa];
				v[izqa] = v[i];
				v[i] = auxiliar;

			}

		}

	}

}

/*

* @brief Muestra los componentes de un vector ordenado sin repetir los que son iguales.
* @param v[] que contiene los elementos ordenados en su interior.
* @param util_v que debe contener los componentes utilizados en el vector.
* @pre util_v > 0 && < DIM
* @pre v[] debe haber sido inicializado y ordenado anteriormente.
* @return no devuelve nada. 

*/

void imprimirVector2 (const int v[], int util_v){

	for(int i = 0; i < util_v - 1; i++){

		if(v[i] != v[i + 1]){

			cout << v[i] << ", ";

		}

	}

	cout << v[util_v - 1] << "." << endl;


}
int main(){

	const int DIM = 100;

	int vector_moda[DIM] = { 2, 1, 3, 4, 5, 6, 7, 8};
	int util_v = 8;

	int moda[DIM];
	int util_moda = 0;

	int maxRepes = 0;

	cout << USER << "Bienvenido a nuestro programa... Vamos a calcular cual es la moda(numero más repetido) del siguiente vector..." << RESTORE << endl;

	//Mostramos el vector por pantalla al usuario.
	cout << "Vector: {";
	imprimeCadena(util_v, vector_moda);
	cout << "}";

	cout << endl;

	//Calculamos la moda del vector.
	calculaModas(util_v, vector_moda, util_moda, moda);

	OrdBurbuja(moda, util_moda);

	//Mostramos la moda.
	cout << USER << "La/s moda/s es/son: " << RESTORE << endl;
	imprimirVector2(moda, util_moda);
	cout << USER << "\nGracias por utilizar este programa! Goodbye..." << RESTORE << endl;


}