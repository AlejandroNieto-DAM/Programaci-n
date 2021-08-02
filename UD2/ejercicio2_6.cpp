/*  Ejemplo ecuación de segundo grado con if.
 */

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    
    //Declaración de variables.
    double a = 0.0, b = 0.0, c = 0.0;
    double monstruo = 0.0;
    double x1 = 0.0, x2 = 0.0;

    //Introducción de valores de variables.
    cout << "\n Introduce coef. de 2o grado: ";
    cin >> a;
    cout << "\n Introduce coef. de 1er grado: ";
    cin >> b;
    cout << "\n Introduce coef. independiente: ";
    cin >> c;

    monstruo = (b*b - 4*a*c);
    
   //Operaciones.
    if ((a == 0) && (b != 0) && (c != 0)) //Filtramos valores que no queremos.
    {
        cout << "Es una ecuación de primer grado con resultado: " << (-c/b) << endl;

    }  else  if(monstruo < 0) { //Si el discriminante es menor que 0.
       
        cout << "El discriminante es negativo por lo que no tiene solución." << endl;

    } else if((a == 0) && (b == 0) && (c == 0)) { //Caso en el que todos los valores sean 0.
         	 
        cout << "Todos los numeros son 0 por lo que no hay ecuación." << endl; 
              
    } else {
        
        x1 = ( -b + sqrt( b*b - 4*a*c)) / (2*a);
        x2 = ( -b - sqrt( b*b - 4*a*c)) / (2*a);
        
        //Solución.
        cout << "Las raíces son: " << x1 << " y " << x2 << endl;

    }
    
   
}


