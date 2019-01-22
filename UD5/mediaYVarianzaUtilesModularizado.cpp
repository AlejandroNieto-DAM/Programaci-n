#include <iostream>
#include <cmath>
using namespace std;

/*
@brief Lee la entrada para los espacios utilizados del vector.
@param int util_nota para ver los espacios utilizados del vector.
@pre debe estar activa la entrada por teclado.
@return no devuelve nada.
@post util_nota debe ser entre 1 y 100 para cumplir con la dimensión del vector.
*/

void LecturaUtil (int &util_nota){

	do{

        cout << "Introduce el numero de alumnos entre 1 y 100: ";
        cin >> util_nota;

    }while(util_nota < 1 || util_nota > 100);

}


/*
@brief Se introducen los valores del vector.
@param int util_nota parar no movernos por los 100 espacios del vector y double nota[] para introducir los valores.
@pre debe estar activa la entrada por teclado.
@return no devuelve nada.
@post nota[] debe guardas los valores del vector.
*/

void IntroducirValores(int util_nota, double nota[]){

	for(int i = 0; i < util_nota; i++){

        cout << "Introduce la nota del alumno " << i+1 << " : ";
        cin >> nota[i];

    }
}


/*
@brief Se calcula la media de los numeros introducidos en el vector anteriormente.
@param int util_nota parar no movernos por los 100 espacios del vector, double nota[] para introducir los valores y double media para la media.
@pre todas las variables mecionadas deben tener almacenado algun valor.
@return no devuelve nada.
@post media debe guardar la media de los datos del vector.
*/
void calculoMedia (int util_nota, double nota[], double &media){

    for(int i = 0; i < util_nota; i++){

        media += nota[i];

    }

    media /= util_nota;

}


/*
@brief Se introducen los valores del vector.
@param int util_nota, double nota[], double desviacion y double media.
@pre haber calculado anteriormente la media de datos del vector.
@return no devuelve nada.
@post desviacion debe guardar el valor calculado.
*/
void calculoDesviacion (int util_nota, double nota[], double &desviación, double media){

    for(int i = 0; i < util_nota; i++){

        desviación += fabs(nota[i] - media);

    }

    desviación /= util_nota;

}


/*
@brief Se introducen los valores del vector.
@param int util_nota, double nota[], double varianza y double media.
@pre media debe de haber sido calculada anteriormente.
@return no devuelve nada.
@post varianza debe guardar el valor calculado.
*/
void calculoVarianza (int util_nota, double nota[], double &varianza, double media){

    for(int i = 0; i < util_nota; i++){

        varianza += (nota[i] - media) * (nota[i] - media);

    }

    varianza /= util_nota;

}


/*
@brief Imprimir los resultados por pantalla.
@param double desviacion, double varianza y double media.
@pre debe estar activa la salida por pantalla.
@return no devuelve nada.
*/
void imprimirResultados (double &media, double &desviación, double &varianza){

  	cout << "La nota media es " << media << endl;
    cout << "La desviación media es " << desviación << endl;
    cout << "La varianza es " << varianza << endl;

} 

int main(){

    const int alumnos = 100;
    double nota[alumnos] = {0};
    int util_nota = 0;

    double media = 0, desviación = 0, varianza = 0;

    LecturaUtil(util_nota);
    IntroducirValores(util_nota, nota);
    calculoMedia(util_nota, nota, media); calculoDesviacion(util_nota, nota, desviación, media); calculoVarianza(util_nota, nota, varianza, media);
    imprimirResultados(media, desviación, varianza);

}