#include <iostream>
using namespace std;

/*

@brief Lee 10 numeros de entrada para calcular cual es el mayor y cual es el menor.
@param @numero introducido 10 veces.
@pre @numero debe ser un int.
@return cambia el valor de @max y @min necesarios para imprimirlos después.

*/

void leerNumeros (int &numero, int &max, int &min){

	cout << "Programa que muestra el MAX y el min de una secuencia de numeros." << endl;

	for(int i = 0; i < 10; i++){

		cout << "Introduce el numero " << i + 1 << ": ";
		cin >> numero;

		if(numero > max){

			max = numero;

		}

		if(i == 0){

			min = numero;

		}

		if(numero < min){

			min = numero;

		}

	}


}


/*

@brief Imprime el numero mayor y el numero menor de acuerdo a lo calculado.

*/

void imprimirMAXmin (int MAX, int min){

	cout << "El numero mayor de la sucesion de valores es: " << MAX << endl;

	cout << "El numero menor de la sucesion de valores es: " << min << endl;


}

int main(){

	int numeroIntroducido = 0, numeroMax = 0, numeroMin = 0;

	leerNumeros(numeroIntroducido, numeroMax, numeroMin);
	imprimirMAXmin(numeroMax, numeroMin);


}