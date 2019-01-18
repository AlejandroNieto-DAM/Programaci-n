/* Programa para calcular la media y desviación de 3 valores introducidos. */

#include <iostream>
#include <cmath>
using namespace std;

int main(){

    const int alumnos = 100;
    double nota[alumnos] = {0};
    double media = 0;
    double desviación = 0;
    double varianza = 0;

    for(int i = 0; i < alumnos; i++){

        cout << "Introduce la nota del alumno " << i+1 << " : ";
        cin >> nota[i];

    }

    for(int i = 0; i < alumnos; i++){

        media += nota[i];

    }

    media /= alumnos;

    for(int i = 0; i < alumnos; i++){

        desviación += fabs(nota[i] - media);

    }

    desviación /= alumnos;

    for(int i = 0; i < alumnos; i++){

        varianza += (nota[i] - media) * (nota[i] - media);

    }

    varianza /= alumnos;

    cout << "La nota media es " << media << endl;
    cout << "La desviación media es " << desviación << endl;
    cout << "La varianza es " << varianza << endl;




}