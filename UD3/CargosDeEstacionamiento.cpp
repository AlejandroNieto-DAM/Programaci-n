#include <iostream>
using namespace std;

/*

@brief Leer los numeros de entrada y hace los respectivos calculos.
@param double horas que el automovil ha estado estacionado, double totalHoras para el total de las horas de los automoviles,
		double totalDinero para calcular el dinero recaudado.
@pre horas debe ser un double positivo.
@return cambiar el valor de @totalHoras y totalDinero mientras metas un valor distinto a 0 en horas.
@post totalHoras y totalDinero deben ser siempre positivos.

*/
void leerYcalcularCargos (double &horas, double &totalHoras, double &totalDinero){

	int contador = 0;
	double dinero = 0.0

	while(cin >> horas && horas != 0) {

		if(contador == 0){

			cout << "Automovil" << "\tHoras" << "\t" << "\tCargo" << endl;

		}

		contador++;

		if(horas <= 3) {

			totalHoras += horas;
			dinero = 2.0;
			totalDinero += dinero;


		} else if ((horas > 3) && (horas < 24)) {

			totalHoras += horas;

			dinero = 2.0;

			for(int i = 3; i < horas; i++){

				dinero += 0.5;

			}

			totalDinero += dinero;


		} else if (horas == 24){

			totalHoras += 10;
			dinero = 10.0;
			totalDinero += dinero;

		}

		cout << contador << "\t" << "\t" << horas << "\t" << "\t" <<  dinero << endl;

		dinero = 0;

	}

}


/*

@brief Imprime el resultado final de la suma de las horas y los cargos.
@param double totalHoras y double totalDinero que son las sumas de las horas y el dinero respectivamente.
@pre debe estar activa la salida por pantalla.
@return no devuelve nada.

*/
void imprimirResultadoTotal (double totalHoras, double totalDinero){

	cout << "TOTAL" << "\t" << "\t" << totalHoras << "\t" << "\t" << totalDinero << endl;

}

int main(){

	double horas = 0.0, totalDinero = 0.0, totalHoras = 0.0;

	
	leerYcalcularCargos(horas, totalHoras, totalDinero, dinero);
	imprimirResultadoTotal(totalHoras, totalDinero);

}