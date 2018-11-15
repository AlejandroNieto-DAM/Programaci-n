/* Programa que muestra la relación entre dos circunferencias.
 */
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	
    //Declaración de variables.
	double x1 = 0.0, y1 = 0.0, r1 = 0.0;
	double x2 = 0.0, y2 = 0.0, r2 = 0.0;
	double dis = 0.0, pri = 0.0, sec = 0.0;

    //Mostramos para que sirve.
	cout << "Programa que muestra que relación tiene una circunferencia con la otra. " << endl;

    //Pedimos valores para nuestras variables.
	cout << "Introduce la x del centro de la primera circunferencia: ";
	cin >> x1;
	cout << "Introduce la y del centro de la primera circunferencia: ";
	cin >> y1;
	cout << "Introduce el radio de la primera circunferencia: ";
	cin >> r1;
	cout << "Introduce la x del centro de la segunda circunferencia: ";
	cin >> x2;
	cout << "Introduce la x del centro de la segunda circunferencia: ";
	cin >> y2;
	cout << "Introduce el radio de la segunda circunferencia: ";
	cin >> r2;

    //Calculamos la distancia entre los puntos que necesitaremos mas adelante.
	pri = ((x2*x2) - (2 * x2 * x1) + (x1*x1));
	sec = ((y2*y2) - (2 * y2 * y1) + (y1*y1));
	dis = (sqrt(pri + sec));

    //Misma circunferencia.
	if ( (x1 == x2) && (y1 == y2) && (r1 == r2) )
	{
		cout << "Es la misma circunferencia!" << endl;
	}
    //Primera circunferencia dentro de la segunda y tangentes.
	else if (((((x2 + r2) > (x1 + r1)) && ((y2 + r2) > (y1 + r1))) && (r2 > r1)) && ((dis == r2 - r1) || (dis == r1 - r2)))
	{
		cout << "La primera circunferencia esta dentro de la segunda! Y son tangentes! " << endl;
	}
	//Segunda circunferencia dentro de la primera y tangentes.
	else if (((((x1 + r1) > (x2 + r2)) && ((y1 + r1) > (y2 + r2))) && (r1 > r2)) && ((dis == r2 - r1) || (dis == r1 - r2)))
	{
		cout << "La segunda circunferencia esta dentro de la primera! Y son tangentes! " << endl;
	}
    //Primera circunferencia dentro de la segunda.
    else if ((((x2 + r2) > (x1 + r1)) && ((y2 + r2) > (y1 + r1))) && (r2 > r1))
    {
        cout << "La primera circunferencia esta dentro de la segunda!" << endl;
    }
    //Segunda circunferencia dentro de la primera.
    else if ((((x1 + r1) > (x2 + r2)) && ((y1 + r1) > (y2 + r2))) && (r1 > r2))
    {
        cout << "La segunda circunferencia esta dentro de la primera!" << endl;
    }
    //Tangentes exteriores.
	else if (dis == (r2 + r1))
	{
		cout << "Estas circunferencias son tangentes exteriores!" << endl;
	}
    //Son exteriores.
	else if (dis > (r2 + r1))
	{
		cout << "Estas circunferencias son exteriores! No se cortan! " << endl;
	}
    //Tienen dos puntos de corte.
	else
	{
		cout << "Estas circunferencias se cortan! Tienen dos puntos de corte en común!" << endl;
	}
	

}
