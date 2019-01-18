#include <iostream>
using namespace std;

int main(){

	const int DIM_V = 100;
	double v[DIM_V];
	double v2[DIM_V];
	int util_v = 0;
	double aux = 0;

	do{

		cout << "Introduce el numero de datos que vas a introducir: ";
		cin >> util_v;

	}while(util_v < 1 || util_v > 100);

	for(int i = 0; i < util_v; i++){

		cout << "Introduce el dato " << i + 1 << " : ";
		cin >> v[i];

	}

	for(int i = 0; i < util_v; i++){

		aux = v[i];
		v[i] = v2[i];
		v2[i] = aux;	

	}

	for(int i = 0; i < util_v; i++){

		cout << "El dato " << i + 1 << " es: " << v2[i] << endl;

	}

}