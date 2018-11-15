/* Programa para calcular la media y desviación de 3 valores introducidos. */

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    // Declaración de variables.
    double x, x1, x2;
    double a, b, c;
    double m, d;
    
    //Mostramos por pantalla que va a realizar el programa.
    cout << "Este es un programa para calcular la media y la desviacion de los valores que vas a introducir. Teniendo en cuenta que m = ((x+x1+x2)/3) y que d = sqrt((((x-m)^2)+((x1-m)^2)+((x2-m)^2))/3)." << endl;
    
    // Se dice al usuario que introduzca 3 valores.
    cout << "Introduce un valor para x: ";
    cin >> x;
    cout << "Introduce un valor para x1: ";
    cin >> x1;
    cout << "Introduce un valor para x2: ";
    cin >> x2;
    
    
    //Operaciones para calcular la media y desviación.
    m = ((x+x1+x2)/3);
    
    a = x-m;
    b = x1-m;
    c = x2 - m;
    
    d = sqrt((pow(a,2))+(pow(b,2))+(pow(c,2))/3);
    
    //Mostramos por pantalla el resultado de la media y  la desviación.
    cout << "La media de los valores introducidos es: " << m << " y su desviacion: " << d << endl;
}
