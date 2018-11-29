#include <iostream>
using namespace std;

int main()
{
    
    int sum = 0, numeroComienzo = 0, numeroEntero = 0;
    double numero = 0.0;
    bool entero = false;
    cout << "Introduce un numero para ver su cubo: ";
    
    do
    {
        cin >> numero;
      
        while(cin.fail())
        {
            
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Has introducido una variable incorrecta!. Prueba otra vez: ";
            cin >> numero;
        }
        
        numeroEntero = numero;
        
        if((numero - 1) != (numeroEntero - 1))
        {
            cout << "Has introducido un numero decimal! Introduce un numero de nuevo: ";
            entero = false;
        }
        else
        {
            entero = true;
        }
        
    }
    while(entero == false);

    numeroComienzo = (numeroEntero * (numeroEntero - 1)) + 1;
    
    for(int i = 0; i < numero; i++)
    {
        sum = sum + numeroComienzo;
        numeroComienzo += 2;
    }
    
    cout << "El cubo del numero introducido es: " << sum << endl;
    
    
}
