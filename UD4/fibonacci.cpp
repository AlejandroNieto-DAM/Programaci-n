#include <iostream>
using namespace std;

void fibonacci1(int n){

	int suma = 0;
	int num1 = 0;
	int num2 = 1;

	for(int i = 0; i < n; i++){

		if(i == 0){

			cout << num1 << " ";

		} else if(i == 1){

			cout << num2 << " ";

		} else {

			suma = num1 + num2;
			num1 = num2;
			num2 = suma;

			cout << suma << " ";

		}

	}

	cout << endl;



}

int fibonacci2 (int n){

	int suma = 0; 
	int num1 = 0;
	int num2 = 1;

	


}


int main(){
	
	int numero = 0;

	cout << "Introduce un numero para mostrar tantos numeros en la sucesion de Fibonacci: ";
	cin >> numero;

	cout << "Fibonacci (iterativo): ";
	fibonacci1(numero);

	cout << "Fibonacci (recursivo): ";
	fibonacci2(numero);

}