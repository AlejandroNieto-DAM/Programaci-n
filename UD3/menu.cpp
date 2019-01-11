#include <iostream>
using namespace std;

void leerNumerosMayor (int &numero, int &max){

	numero = 0;

	cout << "Programa que muestra el MAX de una secuencia de numeros." << endl;

	for(int i = 0; i < 10; i++){

		cout << "Introduce el numero " << i + 1 << ": ";
		cin >> numero;

		if(numero > max){

			max = numero;

		}

	}


}

void leerNumerosMenor (int &numero, int &min){

	numero = 0;

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

void imprimirMAX (int MAX){

	cout << "El numero menor de la sucesion de valores es: " << MAX << endl;


}

void imprimirMin (int min){

	cout << "El numero menor de la sucesion de valores es: " << min << endl;


}

void Menu (int &numeroMenu, int &numeroIntroducido, int &numeroMax, int &numeroMin){

	cout << "Bienvenido a mi programa para calcular o el maximo o el minimo de una sucesion de numeros." << endl;

	cout << "Introduce el numero 1 para calcular el MAXIMO..." << endl;

	cout << "Introduce el numero 2 para calcular el minimo..." << endl;

	cin >> numeroMenu;

	if(numeroMenu == 1){

		leerNumerosMayor(numeroIntroducido, numeroMax);
		imprimirMAX(numeroMax);

	} else if (numeroMenu == 2){

		leerNumerosMenor(numeroIntroducido, numeroMin);
		imprimirMin(numeroMin);

	} else {

		cout << "Numero incorrecto. Programa finalizado." << endl;

	}

}

int main(){

	int numeroIntroducido = 0, numeroMax = 0, numeroMin = 0;
	int opcion = 0;

	Menu(opcion, numeroIntroducido, numeroMax, numeroMin);

}