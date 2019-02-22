#include <iostream>
using namespace std;

#include <iomanip>
#define RESTORE "\033[1;0m"
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"


struct Tiempo {

	int hora; //0-23
	int minutos; //00-59
	int segundos; //00-59
	bool am; //true para AM false para PM

};

int main (){

	Tiempo ahora;

	cout << "Introduce la hora (0-23): ";
	cin >> ahora.hora;
	cout << endl;

	ahora.am = ahora.hora < 12;

	if(ahora.am){

		cout << "AM ";

	} else {

		cout << "PM ";

	}
	

	cout << "Introduce los minutos (00-59): ";
	cin >> ahora.minutos;
	cout << endl;

	cout << "Introduce los segundos (00-59): ";
	cin >> ahora.segundos;
	cout << endl;

	cout << USER << ahora.hora << "-" << ahora.minutos << "-" << ahora.segundos << RESTORE << endl;


}