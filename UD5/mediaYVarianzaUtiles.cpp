#include <iostream>
#include <cmath>
using namespace std;

int main(){

    const int alumnos = 100;
    double nota[alumnos] = {0};
    int util_nota = 0;
    double media = 0;
    double desviación = 0;
    double varianza = 0;

    do{

        cout << "Introduce el numero de alumnos entre 1 y 100: ";
        cin >> util_nota;

    }while(util_nota < 1 || util_nota > 100);


    for(int i = 0; i < util_nota; i++){

        cout << "Introduce la nota del alumno " << i+1 << " : ";
        cin >> nota[i];

    }

    for(int i = 0; i < util_nota; i++){

        media += nota[i];

    }

    media /= util_nota;

    for(int i = 0; i < util_nota; i++){

        desviación += fabs(nota[i] - media);

    }

    desviación /= util_nota;

    for(int i = 0; i < util_nota; i++){

        varianza += (nota[i] - media) * (nota[i] - media);

    }

    varianza /= util_nota;

    cout << "La nota media es " << media << endl;
    cout << "La desviación media es " << desviación << endl;
    cout << "La varianza es " << varianza << endl;




}