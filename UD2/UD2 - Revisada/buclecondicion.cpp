#include <iostream>
using namespace std;

int main()
{
    double suma = 0.0;
    double num = 0.0;
    
    cout << "Programa que suma numeros hasta que introduzcas 0." << endl;
    
    cout << "Introduce un numero: ";
    cin >> num;
    suma = suma + num;
    
    while(num!=0)
    {
        cout << "Introduce un numero: ";
        cin >> num;
        suma = suma + num;
    }
    
    cout << "La suma total de todos los numeros introducidos es igual a: " << suma << endl;
}
