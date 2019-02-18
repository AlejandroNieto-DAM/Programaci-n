#include <iostream>
using namespace std;

#include <iomanip>
#define RESTORE "\033[1;0m"
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"

const int FIL = 20, COL = 30; //Dimensión de la matriz en filas y columnas.


/**

* @brief Introducimos el numero de filas y de columnas que definiran la matriz
* @param utilFilas que pasamos por referencia ya que su valor va a ser cambiado.
* @param utilColumnas que pasamos por referencia ya que su valor va a ser cambiado.
* @pre utilFilas tiene que pasarse por referencia.
* @pre utilColumnas tiene que pasarse por referencia.
* @return no devuelve nada.
* @post utilFilas será mayor que 0 y menor o igual que 20.
* @post utilColumnas será mayor que 0 y menor o igual que 30.

*/

void introducirFILyCOL(int &utilFilas, int &utilColumnas){

	do{

		cout << USER << "Introduce el numero de filas que quieres utilizar, el numero ha de ser mayor que 0 y menor que 20: " << RESTORE;
		cin >> utilFilas;

	} while((utilFilas < 1) || (utilFilas > FIL));



	do{

		cout << USER << "Introduce el numero de columnas que quieres utilizar, el numero ha de ser mayor que 0 y menor que 30: " << RESTORE;
		cin >> utilColumnas;

	} while((utilColumnas < 1) || (utilColumnas > COL));


/**

* @brief Procedimiento que sirve para rellenar la matriz.
* @param vector[][] en quien introduciremos los valores.
* @param util_fil que define el numero de filas de la matriz
* @param util_col que define el numero de columnas de la matriz
* @pre vector[][] debe de estar pasado por referencia.
* @pre util_fil > 0 && < 20
* @pre util_col > 0 && < 30
* @return no devuelve nada.
* @post vector[][] mantendra valores en su interior

*/

}

void rellenarMatriz (double vector[][COL], int util_fil, int util_col){

	for(int f = 0; f < util_fil; f++){

		for(int c = 0; c < util_col; c++){

			cout << USER << "Introduce el numero que será colocado en " << RESTORE << f << USER << "," << RESTORE << c << USER << " : " << RESTORE;
			cin >> vector[f][c];

		}

	}

}


/**

* @brief Procedimiento para pedir al usuario un valor para buscarlo en la matriz.
* @param buscado que almacenara el valor que vamos a buscar.
* @pre buscado debe estar pasado por referencia.
* @return no devuelve nada.
* @post buscado contendrá el numero a buscar en la matriz.

*/

void numeroBuscar (double &buscado){

	cout << USER << "Introduce un numero para buscarlo en la matriz anteriormente introducida: " << RESTORE;
	cin >> buscado;

}

void imprimirMatriz (double vector[][COL], int util_filas, int util_columnas){

	for(int f = 0; f < util_filas; f++){

		for(int c = 0; c < util_columnas; c++){

			cout <<  vector[f][c] << "\t";

		}

		cout << endl;

	}

}

/**

* @brief Recorre una fila de la matriz como un vector.
* @param m[] que es la matriz dividida por filas para recorrerlas como un vector normal.
* @param util_col que pasamos por copia y que guarda el numero de componentes utilizados por fila.
* @param elemento que guarda el valor del elemento que se busca.
* @pre m[] debe de tener valores introducidos anteriormente.
* @pre util_col > 0 && < COL.
* @pre elemento debe de estar inicializado.
* @return devuelve la columna donde se encuentra el numero buscado.
* @post devuelve la posicion en la que se encuentra el numero buscado.

*/

int buscaSec(const double m[], int util_col, int elemento){

	int columna_num = 0;

	for(int c = 0; c < util_col; c++){

			if(m[c] == elemento){

				columna_num = c;

			}
	}

	return columna_num;

}

/**

* @brief Procedimiento para buscar el numero anteriormente introducido a buscar por el usuario.
* @param m[][] que tiene valores en su interior.
* @param util_fil que nos indica el numero de filas de la matriz.
* @param util_col que nos indica el numero de columnas de la matriz.
* @param buscado que tiene el numero a buscar.
* @param encontrado que nos indicara si se encuentra o no el valor.
* @param fil_enc que almacenará el valor de la fila donde se encuentre el numero buscado.
* @param col_enc que almacenará el valor de la columna donde se encuentre el numero buscado.
* @pre m[][] que debe de mantener valores en su interior.
* @pre util_fil debe de haber sido inicializado.
* @pre util_col debe de haber sido inicializado.
* @pre buscado que mantendrá el valor anteriormente introducido por el usuario.
* @pre encontrado debe de pasarse por referencia.
* @pre fil_enc que pasamos por referencia ya que su valor cambiará
* @pre col_enc que pasamos por referencia ya que su valor cambiará
* @return no devuelve nada.
* @post fil_enc y col_enc guardaran la posicion del numero buscado en la matriz.

*/
void buscarNumero (double m[][COL], int util_fil, int util_col, double buscado,bool &encontrado, int &fil_enc, int &col_enc){

	fil_enc = -1;
	col_enc = -1;

	int f = 0;

	for(f = 0; col_enc == -1 && (f < util_fil); f++){

		col_enc = buscaSec(m[f], util_col, buscado);
		//cout << DEBUG << "col_enc: " << col_enc << endl;

	}

	if(col_enc != -1){

		fil_enc = f; 
		encontrado = true;
	}

}

/**

* @brief Imprime la posicion del numero buscado.
* @param encontrado que segun su valor mostrara un resultado u otro.
* @param buscado que es el valor que se estaba buscando.
* @param fil_enc que pasamos por copia para mostrar su valor.
* @param col_enc que pasamos por copia para mostrar su valor.
* @pre encontrado que segun su valor mostrara un resultado u otro.
* @pre fil_enc que almacena la fila en que se encuentra el valor buscado.
* @pre col_enc que almacena la columna en que se encuentra el valor buscado
* @return no devuelve nada.

*/
void imprimirResultado (bool encontrado, double buscado, int fil_enc, int col_enc){

	//cout << DEBUG << "encontrado: " << encontrado << RESTORE << endl;

	if(encontrado){

		cout << USER << "\nEl número buscado, " << RESTORE << buscado << USER << " se ha encontrado en la posición: " << RESTORE << fil_enc << USER << "," << RESTORE << col_enc << endl;

	} else {

		cout << USER << "\nSu numero no se ha encontrado :( " << RESTORE << endl;
	}

}

int main(){

	

	double m[FIL][COL]; //Declaración de la matriz con su máxima dimensión.

	int fil_enc = 0, col_enc = 0, util_fil = 0, util_col = 0; //fil_enc y col_enc que utilizaremos para guardar la posición del número buscado.
															  // util_fil y util_col que utilizaremos para ver el numero de filas y columnas que utilizará el usuario.
	double buscado = 0; //Utilizaremos esta variable para introducir el número que buscaremos en la mátriz.

	bool encontrado = false; //Para agilizar el proceso cuando se ha encontrado en numero y que el bucle for no siga iterando.


	introducirFILyCOL(util_fil, util_col);

	rellenarMatriz(m, util_fil, util_col);

	imprimirMatriz(m, util_fil, util_col);

	numeroBuscar(buscado);

	buscarNumero(m, util_fil, util_col, buscado, encontrado, fil_enc, col_enc);

	cout << USER << "********* BUSCANDO EL NUMERO *********" << RESTORE << endl;

	imprimirResultado(encontrado, buscado, fil_enc, col_enc);

}