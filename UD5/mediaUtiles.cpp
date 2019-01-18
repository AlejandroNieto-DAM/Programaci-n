#include <iostream>
using namespace std;

int main(){

	const int DIM_V = 100;
	double v[DIM_V];
	int util_v = 0;
	double media = 0.0;

	do{

		cout << "Introduce el numero de alumnos entre 1 y 100: ";
		cin >> util_v;

	}while(util_v < 1 || util_v > 100);


	for(int i = 0; i < util_v; i++){

		cout << "Introduce la nota del alumno " << i + 1 << " : ";
		cin >> v[i];

	}

	for(int i = 0; i < util_v; i++){

		media += v[i];

	}

	media /= util_v;

	cout << "La media de las notas introducidas es: " << media << endl;


}