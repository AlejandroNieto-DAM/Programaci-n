#include <iostream>
using namespace std;

struct Tiempo {
	
	int hora;
	int mins;
	int segs;
	bool am;

};

struct Diferencia {
	
	int hora;
	int mins;
	int segs;

};

void mostrarTiempo (const Tiempo &hora){
	
	cout << hora.hora << "º " << hora.mins << "' " << hora.segs << "\" " << endl;  

}

void introduceTiempo (Tiempo &hora){

	cout << "Introduce que hora es: ";
	cin >> hora.hora;
	cout << endl;

	cout << "Introduce los minutos (0-59): ";
	cin >> hora.mins;
	cout << endl;

	cout << "Introduce los segundos (0-59): ";
	cin >> hora.segs;
	cout << endl;

	if(hora.hora <= 11 && hora.mins <= 59 && hora.segs <= 59){

		hora.am = true;

	} else {

		hora.am = false;

	}

}

void calculaDiferencia (const Tiempo &hora1, const Tiempo &hora2, Diferencia &tiempo){

	int segundosHora1 = 0;
	int segundosHora2 = 0;
	int segundos = 0;

	segundosHora1 = ((hora1.hora * 3600)+(hora1.mins * 60)+(hora1.segs));
	segundosHora2 = ((hora2.hora * 3600)+(hora2.mins * 60)+(hora2.segs));
	
	if(segundosHora2 >= segundosHora1){

		segundos = segundosHora2 - segundosHora1;

	} else if(segundosHora1 > segundosHora2){

		segundos = segundosHora2 + (86400 - segundosHora1);

	} 



	tiempo.hora = segundos / 3600;
	//cout << "hora: " << tiempo.hora << endl;

	tiempo.mins = (segundos - (3600 * tiempo.hora)) / 60;
	//cout << "mins: " << tiempo.mins << endl;

	tiempo.segs = (segundos - ( (3600 * tiempo.hora) + (60 * tiempo.mins)));
	//cout << "segs: " << tiempo.segs << endl;
}

void muestraDiferencias (const Diferencia &tiempo){

	cout << "El tiempo que queda es: " << tiempo.hora << "º " << tiempo.mins << "' " << tiempo.segs << "\" " << endl;  

}


int main (){

	Tiempo horaPrimera, horaSegunda;
	Diferencia tiempoQueQueda;

	cout << "\nIntroduce una hora ";
	introduceTiempo(horaPrimera);

	cout << "La hora que has introducido es: ";
	mostrarTiempo(horaPrimera);

	cout << "am " << horaPrimera.am << endl;

	cout << "Introduce otra hora. ";
	introduceTiempo(horaSegunda);

	cout << "La hora que has introducido es: ";
	mostrarTiempo(horaSegunda);


	cout << "\n************ CALCULANDO CUANTO TIEMPO QUEDA HASTA LA SEGUNDA HORA ************" << endl;
	calculaDiferencia(horaPrimera, horaSegunda, tiempoQueQueda);

	muestraDiferencias(tiempoQueQueda);



}