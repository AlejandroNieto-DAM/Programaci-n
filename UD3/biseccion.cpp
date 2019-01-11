#include <iostream>
using namespace std;

int main(){

	double precision;
	double izq = 0, der = 1, centro;

	cout << "Escribe la precision deseada: ";
	cin >> precision;

	while(der - izq > precision) {

		centro = (der+izq)/2;

		if(centro * centro * centro + centro-1 < 0) {

			izq = centro;

		} else {

			der = centro;

		}

		cout << "Solucion: " << (der+izq)/2 << endl;

	}

}