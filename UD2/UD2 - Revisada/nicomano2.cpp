#include <iostream>
using namespace std;

int main()
{
    
    int suma = 0, numeroComienzo = 0, numeroEntero = 0;
    double numero = 0.0;
    bool entero = false;
    int valor = 0;
    
    
    cout << "Introduce un numero entero para ver su cubo: ";
    
    do
    {
        cin >> numero;
        
        numeroEntero = numero;

       if ((cin.fail()) || ((numero > 100) || (numero <= 0)) || (numeroEntero != numero)) {
            
            cin.eof();
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Has introducido una variable incorrecta!. Prueba otra vez (Con un numero entero que este entre 1-100) Error variable: ";
           entero = false;
            
        } else {
            
            cout << "Tu numero escogido es: " << numeroEntero << endl;
            entero = true;
            
        }
        
    } while(entero == false);
    
    numeroComienzo = (numeroEntero * (numeroEntero - 1)) + 1;
    
    for(int i = 0; i < numeroEntero; i++)
    {
        suma = suma + numeroComienzo;
        numeroComienzo += 2;
    }
    
    
    cout << "El cubo del numero introducido es: " << suma << endl;
    
    
}

