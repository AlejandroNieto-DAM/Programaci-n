#include <iostream>
using namespace std;

/*

@brief Lee un numero de entrada dado en seg.
@param int tiempo en segundos.
@pre debe estar activa la entrada por teclado.
@return no devuelve nada.
@post tiempo no puede ser 0 ni mayor a 24 horas (86400).

*/
void leerNumero (int &tiempo){


	cout << "Introduce un numero de segundos no superior a un dia (86400) para mostrarlo en horas, minutos y segundos: ";
	cin >> tiempo;

	while(tiempo > 86400){

		cout << "Has introducido un numero incorrecto! Try again: ";
		cin >> tiempo;

	}

}


/*

@brief Cambia los segundos a horas, minutos y segundos.
@param int tiempo en segundos para calcular el cambio a int horas, int minutos e int segundos.
@pre tiempo menor que 86400 y mayor que 0.
@return tiempo cambiado a horas, minutos y segundos.
@post se almacenara lo introducido en horas, minutos y segundos.

*/
void intercambiar (int tiempo, int &horas, int &minutos, int &segundos){

	horas = tiempo/3600;
	minutos = ((tiempo - (horas * 3600))/60);
	segundos = (tiempo - (horas * 3600) - (60 * minutos));

}


/*

@brief Imprime el resultado final.
@param int horas, int minutos e int segundos.
@pre debe estar activa la salida por pantalla.
@return no devuelve nada.
@post no tiene.

*/
void imprimirResultado (int horas, int minutos, int segundos){

	cout << "Lo introducido se traduce en " << horas << " horas, " << minutos << " minutos y " << segundos << " segundos." << endl;

}


int main(){

	int tiempo = 0, horas = 0, minutos = 0, segundos = 0;

	leerNumero(tiempo);

	intercambiar(tiempo,horas,minutos,segundos);

	imprimirResultado(horas,minutos,segundos);

}