#include <iostream>
#include <cmath>
using namespace std;

void leerNumeros (double &a, double &b, double &c){

	cout << "Bienvenido al programa que calcula una ecuacion de 2º grado." << endl;
	cout << "Introduce x2, x y c respectivamente: ";
	cin >> a;
	cin >> b;
	cin >> c;

}

int posibleResultado (double a, double b, double c, int &solucionable){

	if((a == 0 ) || ((b*b - 4*a*c) < 0) || (a == 0 && b == 0 && c == 0) || (a = 0))  {

		solucionable = 0;
	
	} else {

		solucionable++;

	}


	return solucionable;

}


void calcularResultado (double a, double b, double c, double &resultado1, double &resultado2){

	double monstruo = 0;

	monstruo = sqrt(b*b - (4 * a * c));
	
	resultado1 = ((-b + monstruo) / 2*a);
	resultado2 = ((-b - monstruo) / 2*a);

} 

void imprimirResultado (double resultado1, double resultado2){

	cout << "Las soluciones son " << resultado1 << " y " << resultado2 << endl;;

}

void errorEcuacion (){

	cout << "No hemos podido solucionar tu ecuacion." << endl;

}

int main(){

	double x2 = 0, x = 0, c = 0, res1 = 0, res2 = 0;
	int solucionable;

	leerNumeros(x2,x,c);

	solucionable = posibleResultado(x2,x,c,solucionable);


	if(solucionable != 0){

		calcularResultado(x2,x,c,res1,res2);
		imprimirResultado(res1,res2);

	} else if (solucionable == 0){

		errorEcuacion();

	}


}