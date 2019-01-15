#include <iostream>
using namespace std;

/*

@brief Lee 10 numeros de entrada para calcular cual es el mayor.
@param @numero introducido 10 veces.
@pre @numero debe ser un int.
@return cambia el valor de @max necesario para imprimirlo después.

*/

void leerNumerosMayor (int &numero, int &min){

	cout << "Programa que muestra el MAX de una secuencia de numeros." << endl;

	for(int i = 0; i < 10; i++){

		cout << "Introduce el numero " << i + 1 << ": ";
		cin >> numero;

		if(numero > max){

			max = numero;

		}

	}


}


/*

@brief Lee 10 numeros de entrada para calcular cual es el menor.
@param @numero introducido 10 veces.
@pre @numero debe ser un int.
@return cambia el valor de @min necesario para imprimirlo después.

*/
void leerNumerosMenor (int &numero, int &min){

	cout << "Programa que muestra el min de una secuencia de numeros." << endl;

	for(int i = 0; i < 10; i++){

		cout << "Introduce el numero " << i + 1 << ": ";
		cin >> numero;

		if(i == 0){

			min = numero;

		}

		if(numero < min){

			min = numero;

		}

	}


}


/*

@brief Imprime el numero mayor de acuerdo a lo calculado.

*/
void imprimirMAX (int MAX){

	cout << "El numero menor de la sucesion de valores es: " << min << endl;


}


/*

@brief Imprime el numero menor de acuerdo a lo calculado.

*/
void imprimirMAX (int min){

	cout << "El numero menor de la sucesion de valores es: " << min << endl;


}

/*

@brief Menú que de acuerdo a una variable se mostrará una opción u otra.
@param @numeroMenu para hacer una opción u otra.
@pre @numeroMenu deberá ser 1 o 2 sino dará un error.

*/
void Menu (int numeroMenu){

	cout << "Bienvenido a mi programa para calcular o el maximo o el minimo de una sucesion de numeros." << endl;

	cout << "Introduce el numero 1 para calcular el MAXIMO..." << endl;

	cout << "Introduce el numero 2 para calcular el minimo..." << endl;

	cin >> numeroMenu;

	if(numeroMenu == 1){

		leerNumerosMayor();

	} else if (numeroMenu == 2){

		leerNumerosMenor();

	} else {

		cout << "Numero incorrecto. Programa finalizado." << endl;

	}

}

int main(){

	int numeroIntroducido = 0, numeroMax = 0, numeroMin = 0;
	int opcion = 0;

	menu(opcion);

}