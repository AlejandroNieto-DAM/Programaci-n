#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    
    double valor = 0.0, acumulado = 0.0, monstruo = 0.0, i = 0.0;
    int n = 0, enteroV = 0;;
    bool entero = false;
    
    cout << "Introduce el numero de aproximacion que quieres de PI: ";
    do
    {
    cin >> i;
        
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');
        cout << "Has introducido un caracter no valido! Try again: ";
        cin >> i;
    }
    enteroV = i;
        if((i - 1) != (enteroV - 1) )
        {
            cout << "Has introducido un valor decimal!. Try again: ";
            entero = false;
        }
        else if((i > 100) || (i <= 0))
        {
            cout << "Solo permitimos introducir un numero entre 1 y 100. Try again: ";
        }
        else
        {
            entero = true;
        }
        
    }while((entero == false) || (i > 100) || (i <= 0));
    
    enteroV = i;
    
    
        
    for(n = 0; n <= enteroV; n++)
    {
        monstruo = ((2*n+1)*(2*n+1)*(2*n+1));
        valor = ((pow(-1,n))/(monstruo));
        acumulado = acumulado + valor;
    }
    
    acumulado*= 32;
    acumulado  = pow(acumulado,(1.0/3.0));
    
    cout << "Valor con " << i << " sumandos: " << acumulado << endl;
}

