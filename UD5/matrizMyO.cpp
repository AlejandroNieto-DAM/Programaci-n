#include <iostream>
using namespace std;

#include <iomanip>
#define RESTORE "\033[1;0m"
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"

const int FIL = 20, COL = 30; //Dimensión de la matriz en filas y columnas.

void introducirFILyCOL(int &utilFilas, int &utilColumnas){

	do{

		cout << USER << "Introduce el numero de filas que quieres utilizar, el numero ha de ser mayor que 0 y menor que 20: " << RESTORE;
		cin >> utilFilas;

	} while((utilFilas < 1) || (utilFilas > FIL));



	do{

		cout << USER << "Introduce el numero de columnas que quieres utilizar, el numero ha de ser mayor que 0 y menor que 30: " << RESTORE;
		cin >> utilColumnas;

	} while((utilColumnas < 1) || (utilColumnas > COL));

}

void rellenarMatriz (double vector[][COL], int util_fil, int util_col){

	for(int f = 0; f < util_fil; f++){

		for(int c = 0; c < util_col; c++){

			cout << USER << "Introduce el numero que será colocado en " << RESTORE << f << USER << "," << RESTORE << c << USER << " : " << RESTORE;
			cin >> vector[f][c];

		}

	}

}

void numeroBuscar (double &buscado){

	cout << USER << "Introduce un numero para buscarlo en la matriz anteriormente introducida: " << RESTORE;
	cin >> buscado;

}

void OrdInsercion (double v[][COL], int util_fil, int util_col){


	double aux = 0;

	for(int f = 0; f < util_fil; f++){

		for(int c = 0; c < util_col; c++){

			for(int f2 = 0; f2 < util_fil; f2++){

				for(int c2 = 0; c2 < util_col; c2++){

					if(v[f][c] > v[f2][c2]){

						aux = v[f][c];
						v[f][c] = v[f2][c2];
						v[f2][c2] = aux;


					}

				}

			}

		}

	}


}

void imprimirMatriz (double vector[][COL], int util_filas, int util_columnas){

	for(int f = 0; f < util_filas; f++){

		for(int c = 0; c < util_columnas; c++){

			cout <<  vector[f][c] << "\t";

		}

		cout << endl;

	}

}

void buscarNumero (double m[][COL], int util_fil, int util_col, double buscado,bool &encontrado, int &fil_enc, int &col_enc){

	for(int f = 0; !encontrado && f < util_fil; f++){

		for(int c = 0; !encontrado && c < util_col; c++){

			if(m[f][c] == buscado){

				encontrado = true;

				col_enc = c;
				//cout << DEBUG << "col_enc: " << col_enc << RESTORE << endl;
				fil_enc = f;
				//cout << DEBUG << "fil_enc: " << fil_enc << RESTORE << endl;

			}

		}

	}

}

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

	OrdInsercion(m, util_fil, util_col);

	imprimirMatriz(m, util_fil, util_col);

	numeroBuscar(buscado);

	buscarNumero(m, util_fil, util_col, buscado, encontrado, fil_enc, col_enc);

	cout << USER << "********* BUSCANDO EL NUMERO *********" << RESTORE << endl;

	imprimirResultado(encontrado, buscado, fil_enc, col_enc);

}