#include <iostream>
using namespace std;

void introduceNM (int &n, int &m){

	cout << "Introduce el valor m: ";
	cin >> m;
	cout << endl;



	cout << "Introduce el valor n: ";
	cin >> n;
	cout << endl;
	
}

int funcionAckerman (int m, int n){

	long double resultado = 0;

	if(m == 0){

		resultado = n + 1;

	} else if (m > 0 && n == 0){

		resultado = funcionAckerman(m - 1, 1);

	} else if (m > 0 && n > 0){

		resultado = funcionAckerman(m - 1, funcionAckerman(m, n - 1));

	}

	return resultado;

}


void imprimeResultado (int res){

	cout << "El resultado tras ejecutar la funcion de Ackerman es: " << res << endl;

}

int main(){

	int n = 0;
	int m = 0;
	long double resultado = 0;


	introduceNM(n, m);

	resultado = funcionAckerman(m, n);

	imprimeResultado(resultado);




}