#include <iostream>
using namespace std;


/*

@brief Lee los numeros de entrada necesarios para el intervalo.
@param int a e int b son los numeros del intervalo.
@pre debe estar activa la entrada por teclado.
@return no devuelve nada.
@post a < b para calcular bien el intervalo.

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
@param int x e int y siendo el intervalo para calcular los primos.
@pre x < y para el intervalo.
@return devuelve el total de numeros primos en el intervalo.
@post total almacenara el resultado del total de los primos contados en el intervalo.

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
@param int totalIntervalo numero de total de primos en un intervalo.
@pre debe estar activa la salida por pantalla.
@return no devuelve nada.
@post no tiene.

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