#include <iostream>
#include <iomanip>

#define RESTORE "\033[1;0m"
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"

using namespace std;

/**

* @brief este procedimiento sirve para pedir al usuario un numero para buscarlo en el vector.
* @param numeroBusqueda que pasaremos por referencia ya que cambiaremos su valor.
* @pre numeroBusqueda debe haber sido inicialiazado previamente a 0.
* @return no devuelve nada.
* @post este procedimiento cambiará el valor del numeroBusqueda por el que quiera el usuario.

*/

void elementoBusqueda(int &numeroBusqueda){

	cout << USER << "\nBienvenido a nuestro programa!! Este programa sirve para buscar un numero que elijas en un vector con unos valores predeterminados." <<  RESTORE << endl;

	cout << USER << "\nCual es el numero que quieres buscar? " << RESTORE;
	cin >> numeroBusqueda;
	//cout << DEBUG << "Numero a buscar: " << numeroBusqueda << RESTORE << endl;

	cout << endl;

}

/**

* @brief Este procedimiento sirve para recorrer el vector y buscar un elemento y almacenar en la posicion en la que está.
* @param v[] vector que recorreremos para buscar el numero deseado.
* @param util que contiene el numero de componentes utilizados en el vector.
* @param num, numero a buscar.
* @param pos, que guardará la posición en la que se encuentra el numero deseado.
* @param encontrado que pasamos por referencia y booleano para que nos diga si lo ha encontrado o no.
* @pre v[] debe de estar inicializado con los valores por defecto.
* @pre util debe estar inicilizado.
* @pre num debe de haber sido escogido ya por el usuario.
* @return no devuelve nada.
* @post pos guardará la posición en la que se encuentre el numero deseado para después ser mostrada.

*/

void busqueda(const int v[], int util, int num, int &posicion, bool &encontrado){
	
	int i = 0;

	for(i = 0; i < util && i != num; i++){

			if(v[i] == num){

				encontrado = true;
				posicion = i;
				//cout << DEBUG << "posicion: " << posicion << endl;
			}

		//cout << DEBUG << "i: " << i << endl;
	}
}

/**

* @brief Procedimiento que guarda en un vector las posiciones en las que se encuentra el numero que se busca.
* @param v[] vector que recorreremos para buscar el numero deseado.
* @param util que contiene el numero de componentes utilizados en el vector.
* @param num, numero a buscar.
* @param posiciones[] que guardará las posiciones en las que se encuentra el numero buscado.
* @param util_posiciones
* @param encontrado que pasamos por referencia y booleano para que nos diga si lo ha encontrado o no.
* @pre v[] debe de estar inicializado con los valores por defecto.
* @pre util debe estar inicilizado.
* @pre num debe de haber sido escogido ya por el usuario.
* @pre util_posiciones debe estar pasado por referencia para cambiar su valor con el transcurso del procedimiento.
* @return no devuelve nada.
* @post posiciones[] guardará la posición en la que se encuentra el numero deseado dentro del vector.
* @post util_posiciones guardará el numero de componentes utilizados en el vector posiciones[].
* @post encontrado guardara como bool si ha encontrado el numero o si no.

*/

void busqueda2(const int v[], int util, int num, int posiciones[], int &util_posiciones, bool &encontrado){

	for(int i = 0; i < util; i++){

			if(v[i] == num){

				encontrado = true;
				posiciones[util_posiciones] = i;
				
				//cout << DEBUG << "i: " << i << endl;
				//cout << DEBUG << "posiciones: " << posiciones[util_posiciones] << RESTORE << endl;

				util_posiciones++;
				//cout << DEBUG << "util_posiciones: " << util_posiciones << RESTORE << endl;				

			}		
	}

}

/**

* @brief Procedimiento que sirve para mostrar por la pantalla el vector.
* @param vector[] que pasamos por "copia" ya que simplemente vamos a mostrarlo por pantalla y no cambiar sus valores.
* @param util_v que nos tiene guardado el numero de componentes utilizados por el vector.
* @pre vector[] debe de tener los valores introducidos.
* @pre debe estar activa la salida por pantalla.
* @return no devuelve nada.

*/

void imprimirVector(const int vector[], int util_v){

	for(int i = 0; i < util_v - 1; i++){

		cout <<  vector[i] << ", ";

	}

	cout << vector[util_v - 1];

}

int main(){


	const int DIM = 10;//Dimensión maxima para los vectores.

	int v[DIM] = {2, -1, 3, -2, 3}; //Vector predeterminado que utilizaremos para buscar numeros dentro de él.
	int util_v = 5; //Numero de componentes utilizados por el vector v[].

	int numeroBusqueda = 0; //Numero que buscaremos cuando el usuario introduzca uno.

	int pos = 0; //Posición en la que se encuentra el primer valor correspodiente al numero buscado si es que existe.

	int posiciones[DIM]; //Vector en el que almacenaremos las posiciones de los numeros deseados cuando haya más de 1.
	int util_posiciones = 0; //Numero de componentes utilizados por el vector posiciones[] Que corresponde al numero de posiciones en el que se encuentra el numero a buscar.

	bool encontrado = false; //Bool que nos servirá para comprobar si el numero ha sido encontrado o no.


	//Pedimos al usuario un numero para buscar.
	elementoBusqueda(numeroBusqueda);

	//Imprimimos vector.
	cout << USER << "El vector sobre el que haremos la busqueda será: {" << RESTORE ;
	imprimirVector(v, util_v);
	cout << USER << "} " << RESTORE << endl;

	//Busqueda para una posición Primer Ejer.
	busqueda(v, util_v, numeroBusqueda, pos, encontrado);

	//Busqueda para varias posiciones Segundo Ejer.
	busqueda2(v, util_v, numeroBusqueda, posiciones, util_posiciones, encontrado);


	//Si no se ha encontrado siempre mostrará este mensaje.
	if(encontrado == false){

		cout << USER << "\nLo sentimos pero el numero elegido no se encuentra en el vector. " << RESTORE << endl;

	}else {

		//Para una posicion Primer ejer.
		cout << USER << "\nHemos encontrado su numero en la posicion: " << RESTORE << pos << endl;

		//Para varias posiciones Segundo ejer.
		cout << USER << "\nEl/Los numero/s deseado/s se encuentra/n en la/s posion/es: {" << RESTORE;
		imprimirVector(posiciones, util_posiciones);
		cout << USER << "} " << RESTORE << endl;

	}

	//Finaliza el programa.
	cout << USER << "\nPrograma finalizado..." << RESTORE << endl;

}