#include <iostream>
using namespace std;

void hanoi(int fichas, int origen, int destino, int auxiliar){

	if(fichas > 0){

		hanoi(fichas - 1, origen, auxiliar, destino);
		cout << "Mover ficha de " << origen << " a " << destino << endl;
		hanoi(fichas - 1, auxiliar, destino, origen);
	}
	
}

void introducirPiezas (int &fichas){

	cout << "Introduce el numero de piezas de la torre de Hanoi: ";
	cin >> fichas;
	cout << endl;
}

int main(){

	int fichas = 0;
	int origen = 1;
	int destino = 3;
	int auxiliar = 2;

	introducirPiezas(fichas);
	hanoi(fichas, origen, destino, auxiliar);

}