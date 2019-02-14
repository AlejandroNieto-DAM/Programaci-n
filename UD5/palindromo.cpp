#include <iostream>
#include <string.h>
using namespace std;

/*

* @brief Procedimiento que sirve para quitar los espacios que pueda haber en la cadena.
* @param util_v que contiene el numero de componentes utilizados en frase[].
* @param frase[] que contiene unos valores por defecto.
* @param util_v2 que pasamos por referencia ya que será nuestros nuevo utiles cuando quitemos los espacios.
* @pre util_v > 0 && util_v <= 100
* @return no devuelve nada.
* @post util_v2 contendrá el nuevo numero de componentes que utilizamos cuando quitemos los espacios.

*/
void quitarEspacios(int util_v, char frase[], int &util_v2){

	cout << "Vamos a quitarle los espacios... Se mostrará la próxima vez que se imprima..." << endl;

	for(int i = 0; i < util_v; i++){

		if(frase[i] != 32){

			frase[util_v2] = frase[i];
			util_v2++;

		}

	}

}

/**

* @brief Función que sirve para ver si el contenido del vector es palindromo no (Palindromo = que se lea igual si empiezas desde 
  el principio o el final)
* @param util_v2 que es el numero de componentes utilizados en frase[] después de quitar los espacios.
* @param frase[] que contiene los datos sin espacios.
* @param verdad que almacenará el valor booleano de si es palindromo el vector o no.
* @pre util_v2 > 0 && util_v2 <= 100
* @return no devuelve nada.
* @post verdad guardará el valor booleano TRUE|FALSE.

*/
bool palindromo(int util_v2, char frase[], bool &verdad){

	int suma = 0;
	int contador = util_v2 - 1;

	for(int i  = 0; i < contador; i++){

		if(frase[i] != frase[contador - i]){

			suma++;

		}

	}

	if(suma != 0){

		verdad = false;

	} else if(suma == 0){

		verdad = true;

	}

	return verdad;

}

/**

* @brief Procedimiento que sirve para mostrar por la pantalla el vector.
* @param frase[] que pasamos por "copia" ya que simplemente vamos a mostrarlo por pantalla y no cambiar sus valores.
* @param util_v que nos tiene guardado el numero de componentes utilizados por el vector.
* @pre frase[] debe de tener valores introducidos.
* @pre debe estar activa la salida por pantalla.
* @return no devuelve nada.

*/
void imprimir(int util_v, const char frase[]){

	for(int i = 0; i < util_v - 1; i++){

		cout << frase[i] << ", ";

	}

	cout << frase[util_v - 1];

}


int main(){

	const int DIM = 100;

	char frase[DIM]= { 'a', 'r', 'r', 'o', 'z', ' ', 'z', 'o', 'r', 'r', 'a'};
	int util_v = 11, util_v2 = 0;
	bool verdad = false;

	cout << "Vector: {";
	imprimir(util_v, frase);
	cout << "}";

	quitarEspacios(util_v, frase, util_v2);
	palindromo(util_v2, frase, verdad);

	cout << "Vector: {";
	imprimir(util_v2, frase);
	cout << "}";

	cout << endl;
	
	if(verdad == false){

		cout << "No es palindromo." << endl;

	} else if(verdad == true){

		cout << "Es palindromo. " << endl;

	}

}