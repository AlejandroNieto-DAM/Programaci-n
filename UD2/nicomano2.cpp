#include <iostream>
using namespace std;

int cubo (int n){
    
    int suma = 0;
    int i;
    int numeroEntero;
    int numeroComienzo;
    
    numeroEntero = n;
    numeroComienzo = (numeroEntero * (numeroEntero - 1)) + 1;
    for(int i = 0; i < n; i++)
    {
        suma = suma + numeroComienzo;
        numeroComienzo += 2;
    }
    
    return suma;
    
}


int main()
{
    
    int sum = 0, numeroComienzo = 0, numeroEntero = 0;
    double numero = 0.0;
    bool entero = false;
    int valor = 0;
    int count = 1;
    bool correcto = false;
    char letra;
    
    
    cout << "Introduce un numero entero para ver su cubo: ";
    
    do
    {
        cin >> numero;
        
        numeroEntero = numero;
        
        if((cin.fail() || ((numero > 100) || (numero <= 0)) || (numeroEntero != numero))) {
            
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Has introducido una variable incorrecta!. Prueba otra vez (Con un numero entero que este entre 1-100): ";
            entero = false;
            
        } else {
            
            cout << "Tu numero escogido es: " << numero << endl;
            entero = true;
            
        }
        
    }
    while((entero == false) || (correcto = false));
    
    
    valor = cubo(numero);
    
    cout << "El cubo del numero introducido es: " << valor << endl;
    
    
}
