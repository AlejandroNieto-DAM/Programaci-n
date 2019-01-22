#include <iostream>
using namespace std;


void leerUtil (int &util_v){

	cout << "Cuantos numeros deseas introducir? ";
	cin >> util_v;

}

void leerVector (int util_v, int vector1[]){

	for(int i = 0; i < util_v; i++){

		cout << "Introduce el numero " << i + 1 << " : ";
		cin >> vector1[i];

	}


}

void cambiarVector (const int vector1[], int util_v, int vector2[], int &util_v2){

	for(int i = 0; i < util_v; i++){

		if(vector1[i] % 2 == 0){

			vector2[util_v2] = vector1[i];
			util_v2++;

		}

	}

}

void imprimirVector (const int vector2[], int util_v2){

	for(int i = 0; i < util_v2; i++){

		cout <<  vector2[i] << " ";

	}

}

int main(){

	int DIM = 100;
	int vector1[DIM], vector2[DIM];

	int util_v = 0, util_v2 = 0;

	leerUtil(util_v);
	leerVector(util_v, vector1);
	cambiarVector(vector1, util_v, vector2, util_v2);
	imprimirVector(vector2, util_v2);


}