#include <iostream>
using namespace std;

/**

* @brief Calcula el factorial de un numero n introducido por el usuario.
* @param n que mantiene el valor introducido por el usuario.
* @pre n != 0 
* @return devuelve el factorial 
* @post f guardará el valor del factorial de n;

*/

int factorial(int n){

	int f = 0;

	if(n == 0){

		f = 1;
	} else {

		f = n * factorial(n - 1);
	}

	return f;

}

int factorial2(int n){

	int sum = 1;

	for(int i = 1; i <= n; i++){

		sum *= i;

	}

	return sum;

}


int main(){

	int n = 0;
	int res1 = 0, res2 = 0;

	cout << "Introduce un numero para calcular su factorial: ";
	cin >> n;

	res1 = factorial(n);

	cout << "El factorial (recursivo) es: " << res1 << endl;

	res2 = factorial2(n);

	cout << "El factorial (iterativo) es: " << res2 << endl;

	cout << "PROGRAMA FINALIZADO." << endl;

}