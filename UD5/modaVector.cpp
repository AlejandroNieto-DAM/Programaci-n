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

* @brief Calcula el numero que más veces se repite en el vector.
* @param util_v que guarda el numero de componentes utilizados en el vector.
* @param array[] que tiene guardados unos valores predeterminados.
* @param moda que almecenará el valor del numero que más veces se repite.
* @pre util_v > 0 && util_v <= 100.
* @return no devuelve nada.
* @post moda almacenará el numero que mas veces se repita.

*/
void calculaModa(int util_v, const int array[], int &moda){

	int suma = 0;
	int res = 0;


	for(int i = 0; i < util_v; i++){

		//Igualamos la suma a 0 para que empiece a sumar los iguales de la siguiente iteración.
		suma = 0;

		for(int j = 0; j < util_v; j++){

			//Si son iguales se hará suma++ que indicará el numero de veces que se repite.
			if(array[i] == array[j]){

				suma++;
				//cout << DEBUG << "Valor suma: " << suma << RESTORE << endl;
			}

			//Si la suma es mayor que el res anterior la moda será diferente de la anterior ya que este nuevo numero se repite mas veces.
			if(suma > res){

				res = suma;
				//cout << DEBUG << "Valor res: " << res << RESTORE << endl;
				moda = array[i];
				//cout << DEBUG << "Valor moda: " << moda << RESTORE << endl;

			}

		}

	}

}

/**

* @brief Mostramos por pantalla el resultado de la moda.
* @param moda que guarda el numero que mas veces se repite en el vector.
* @pre moda debe de tener un valor correspodiente al numero que mas veces se repite.
* @return no devuelve nada.

*/
void imprimeModa(int moda){

	cout << USER << "La moda ya ha sido calculada y es: " << RESTORE << moda << endl;
	cout << USER << "Gracias por utilizar este programa! Goodbye..." << RESTORE << endl;

}


int main(){

	const int DIM = 100;
	int vector_moda[DIM] = { 3, 5, 5, 2, 2, 5, 5, 2};
	int util_v = 8;
	int moda = 0;

	cout << USER << "Bienvenido a nuestro programa... Vamos a calcular cual es la moda(numero más repetido) del siguiente vector..." << RESTORE << endl;

	//Mostramos el vector por pantalla al usuario.
	cout << "Vector: {";
	imprimeCadena(util_v, vector_moda);
	cout << "}";

	cout << endl;

	//Calculamos la moda del vector.
	calculaModa(util_v, vector_moda, moda);

	//Mostramos la moda.
	imprimeModa(moda);


}