#include <iostream>
using namespace std;

int main(){

	const int totalNotas = 5;
	double notas[totalNotas] = {0};
	int media = 0;

	for(int i = 0; i < 5; i++){

		cout << "Introduce la nota " << i+1 << " : ";
		cin >> notas[i];

	}

	for(int i = 0; i < 5; i++){

		media += notas[i];

	}

	cout << "La media de las notas introducidas es " << media/totalNotas << endl;


}