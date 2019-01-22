#include <iostream>
using namespace std;


void leerUtil (int &util_v){

	cout << "Cuantos numeros deseas introducir? ";
	cin >> util_v;

}

void leerVector (int util_v, double vector1[]){

	for(int i = 0; i < util_v; i++){

		cout << "Introduce el numero " << i + 1 << " : ";
		cin >> vector1[i];

	}


}

void cambiarVector (const double vector1[], int util_v, double vector2[]){

	for(int i = 0; i < util_v; i++){

		vector2[i] = vector1[i];

	}

}

void imprimirVector (const double vector2[], int util_v){

	for(int i = 0; i < util_v; i++){

		cout <<  vector2[i] << " ";

	}

}

int main(){

	int DIM = 100;
	double vector1[DIM], vector2[DIM];

	int util_v = 0;

	leerUtil(util_v);
	leerVector(util_v, vector1);
	cambiarVector(vector1, util_v, vector2);
	imprimirVector(vector2, util_v);


}