/* Algoritmo que calcula el numero pi a partir de unos valores iniciales y muestra pi1, pi2 y pi3. */

#include <iostream>
#include <math.h>
using namespace std;

int main ()
{
    
    //Declaración de variables.
    double x0, x1, x2;
    double y1, y2;
    double pi0, pi1, pi2;
    
    //Valores iniciales.
    x0 = sqrt (2);
    y1 = pow(2, 0.25);
    pi0 = sqrt(2) + 2;
    
    //Calculo de las iteraciones de las formulas para calcular pi1 y pi2.
    x1 = (sqrt (x0) + (1 / (sqrt (x0)))) * 0.5;
    x2 = (sqrt (x1) + (1 / (sqrt (x1)))) * 0.5;
    y2 = (y1 * (sqrt(x1)) + (1 / sqrt(x1))) / (y1 + 1);

    //Calculo de pi a partir de los valores anteriormente calculados.
    pi1 = ((x1+1) / (y1+1))*pi0;
    pi2 = ((x2+1) / (y2+1))*pi1;
    
    //Muestra por pantalla el valor para cada pi.
    cout << "Pi0 es: " << pi0 << endl;
    cout << "Pi1 es: " << pi1 << endl;
    cout << "Pi2 es: " << pi2 << endl;
}
