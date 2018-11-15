/* Algoritmo que muestra a partir de los segundos cuantos dias, horas, minutos y segundos son. */

#include <iostream>
using namespace std;

int main()
{
    
    //Declaración de variables.
    int d, h, m, s, s2;
    
    //Notificamos al usuario de la función del programa.
    cout << "Este es un programa en el que introduces un numero de segundos y te digo cuantos dias, horas, minutos y segundos son." << endl;
    
    //Pedimos el número de segundos a convertir por el usuario.
    cout << "Introduce el numero de segundos: ";
    cin >> s;
    
    //Operaciones.
    d = s/86400;
    h = ((s-(86400*d))/3600);
    m = (s-((86400*d)+(3600*h)))/60;
    s2 = (s-((86400*d)+(3600*h)+(60*m)));
    
    //Mostramos por pantalla el resultado.
    cout << "Los segundos que has introducido son: "  << d  << " dias " << h << "h " << m << "m y " << s2 << "s." << endl;
}
