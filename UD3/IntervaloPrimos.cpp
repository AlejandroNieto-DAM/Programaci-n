#include <iostream>
using namespace std;


/*

@brief Lee los numeros de entrada necesarios para el intervalo.
@param @a y @b son los numeros del intervalo.
@pre @a < @b para calcular bien el intervalo.

*/

void leerIntervalo(int &a, int &b){

	cout << "\nVamos a introducir un intervalo para calcular cuantos numeros primos hay." << endl;
	cout << "\nIntroduce el numero inicial del intervalo: ";
	cin >> a;
	cout << "Introduce el ultimo numero del intervalo: ";
	cin >> b;

}


/*

@brief Calcula el total de numeros primos en un intervalo.
@param @x y @y siendo el intervalo para calcular los primos.
@pre @x < @y para el intervalo.
@return devuelve el total de numeros primos en el intervalo.
@post @total debera ser un numero entero positivo o igual a 0.

*/

int calcularTotalPrimos(int x, int y){

	int suma = 0;
	int total = 0;

	for(int i = x; i <= y; i++){

		for(int z = 1; z <= i; z++){

			if(i % z == 0){

				suma++;

			}


		}


		if(suma == 2){

			total++;

		}

		suma = 0;

	}


	return total;


}


/*

@brief Imprime el resultado de acuerdo a la variable @totalIntervalo.
@param @totalIntervalo numero de total de primos en un intervalo.

*/

void imprimirTotal(int totalIntervalo){


	cout << "El numero total de numeros primos en el intervalo es: " << totalIntervalo << endl;

}


int main() {


	int numeroPrincipio = 0, numeroFinal = 0, totalPrimos = 0;



	leerIntervalo(numeroPrincipio, numeroFinal);

	totalPrimos = calcularTotalPrimos(numeroPrincipio, numeroFinal);

	imprimirTotal(totalPrimos);



}