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

int fibonacci2 (int n, int num1, int num2){

	int suma = 0; 
	int sumaF = 0;


	if(n > 3){

		suma = num1 + num2;
		//cout << "suma : " << suma << endl; 
		num1 = num2;
		num2 = suma;

		//cout << "n: " << n << endl;

		sumaF = fibonacci2(n - 1, num1, num2);

	} else {

		sumaF = num1 + num2;
		
	}

	return sumaF;

}


int main(){
	
	int numero = 0;
	int num1 = 0;
	int num2 = 1;
	int fibonacci = 0;

	cout << "Introduce un numero para mostrar tantos numeros en la sucesion de Fibonacci: ";
	cin >> numero;

	cout << "Fibonacci (iterativo): ";
	fibonacci1(numero);

	fibonacci = fibonacci2(numero, num1, num2);
	cout << "Fibonacci (recursivo): " << fibonacci << endl;
	 

}