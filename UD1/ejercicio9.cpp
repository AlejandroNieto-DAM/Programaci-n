/* Algortimo para resolver una ecuación de segundo grado. */

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    
    //Declaración de varibles.
    double a, b, c;
    double pos, neg;
    int j;
    double k;
    
    //Pedimos por pantalla unos valores para las variables teniendo en cuenta la estructura de la ecuación.
    cout << "Teniendo en cuenta que la estructura de una ecuación de segundo grado es ax^2 + bx + c = 0, introduce unos valores para a, b y c respectivamente." << endl;
    cin >> a;
    cin >> b;
    cin >> c;

    //Operaciones.
    j = pow(b,2);
    k = sqrt(j-4*a*c);
    pos = ((-b) + (k - (4*a*c)));
    neg = ((-b) - (k - (4*a*c)));
    pos = pos/(2*a);
    neg = neg/(2*a);
    
    //Mostramos por pantalla el resultado obtenido para x en la ecuación.
    cout << "Los resultados de x son: " << pos << " y " << neg << endl;
    cout << "Si sale de solucion Nan es que no tiene solucion la ecuacion para los numeros introducidos. " << endl;
    
    
}
