#include <iostream>
using namespace std;

#include <iomanip>
#define RESTORE "\033[1;0m"
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"

int main(){

	const int FIL = 20, COL = 30; //Dimensión de la matriz en filas y columnas.

	double m[FIL][COL]; //Declaración de la matriz con su máxima dimensión.

	int fil_enc = 0, col_enc = 0, util_fil = 0, util_col = 0; //fil_enc y col_enc que utilizaremos para guardar la posición del número buscado.
															  // util_fil y util_col que utilizaremos para ver el numero de filas y columnas que utilizará el usuario.
	double buscado = 0; //Utilizaremos esta variable para introducir el número que buscaremos en la mátriz.

	bool encontrado = false; //Para agilizar el proceso cuando se ha encontrado en numero y que el bucle for no siga iterando.



	do{

		cout << USER << "Introduce el numero de filas que quieres utilizar, el numero ha de ser mayor que 0 y menor que 20: " << RESTORE;
		cin >> util_fil;

	} while((util_fil < 1) || (util_fil > FIL));



	do{

		cout << USER << "Introduce el numero de columnas que quieres utilizar, el numero ha de ser mayor que 0 y menor que 30: " << RESTORE;
		cin >> util_col;

	} while((util_col < 1) || (util_col > COL));


	for(int f = 0; f < util_fil; f++){

		for(int c = 0; c < util_col; c++){

			cout << USER << "Introduce el numero que será colocado en " << RESTORE << f << USER << "," << RESTORE << c << USER << " : " << RESTORE;
			cin >> m[f][c];

		}

	}

	cout << USER << "Introduce un numero para buscarlo en la matriz anteriormente introducida  :) " << RESTORE;
	cin >> buscado;


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

	//cout << DEBUG << "encontrado: " << encontrado << RESTORE << endl;

	if(encontrado){

		cout << USER << "El número buscado " << RESTORE << buscado << USER << " se ha encontrado en la posición " << RESTORE << fil_enc << USER << "," << RESTORE << col_enc << endl;

	} else {

		cout << USER << "Su numero no se ha encontrado :( " << RESTORE << endl;
	}

}