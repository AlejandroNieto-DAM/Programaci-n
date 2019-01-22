#include <iostream>
using namespace std;

void imprime_vector(const int v[], int util);
void solo_pares(const int v[], int util_v, int pares[], int &util_pares);

int main(){

	const int DIM = 100;
	int entrada[DIM] = {8, 1, 3, 2, 4, 3, 8},
		salida[DIM];

	int util_entrada = 7, util_salida = 0;

	solo_pares(entrada, util_entrada, salida, util_salida);
	imprime_vector(salida, util_salida);	
}

void solo_pares(const int v[], int util_v, int pares[], int &util_pares){

	util_pares = 0;

	for(int i = 0; i < util_v; i++){

		if(v[i] % 2 == 0){

			pares[util_pares] = v[i];
			util_pares++;

		}

	}
}

void imprime_vector (const int v[], int util){

	for(int i = 0; i < util; i++){

		cout << v[i] << " ";

	}
}