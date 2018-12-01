/* Programa que muestra de 3 números introducidos cual es el mayor.
 */

#include <iostream>
using namespace std;

int main ()
{
    
    //Declaración de variables.
    double a = 0.0, b = 0.0, c = 0.0;
    
    //Mostramos para que sirve el programa.
    cout << "Programa muestra de tres numeros introducidos cual es el mayor." << endl;
    
    //Pedimos valores para las variables.
    cout << "Introduce un numero: ";
    cin >> a;
    cout << "Introduce otro numero: ";
    cin >> b;
    cout << "Introduce otro numero: ";
    cin >> c;
    
    //Condiciones para mostrar cual es el numero mayor.
    if ( a > b && a > c)
    {
        cout << "El numero mayor es: " << a << endl;
    }
    
    else
    {
        if ( (b > a) && (b > c))
        {
            cout << "El numero mayor es: " << b << endl;
        }
        
        else
        {
            if((c > a) && (c > b))
            {
                cout << "El numero mayor es: " << c << endl;
            }
            
            else
            {
               if ((a == b) && (a == c) && (b == c))
               {
                   cout << "Todos los numeros son iguales." << endl;
               }
                
               else
               {
                   cout << "Dos de los numeros son iguales. " << endl;
                   
                   if(a == b)
                   {
                       cout << "El primer numero: " << a << " y el segundo numero: " << b << " son iguales." << endl;
                   }
                   
                   if(a == c)
                   {
                       cout << "El primer numero: " << a << " y el tercer numero: " << c << " son iguales." << endl;
                   }
                   
                   if(b == c)
                   {
                       cout << "El segundo numero: " << b << " y el tercer numero: " << c << " son iguales." << endl;
                   }
               }
            }
        }
    }
}
