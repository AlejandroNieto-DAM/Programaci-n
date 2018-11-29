#include <iostream>
using namespace std;

int main()
{
    
    int numero = 0, sum = 0, numeroComienzo = 0;
    
    cout << "Introduce un numero para ver su cubo: ";
    cin >> numero;
    
    while(cin.fail())
    {
        
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Has introducido una variable incorrecta!. Prueba otra vez: ";
        cin >> numero;
    }
    
    numeroComienzo = (numero * (numero - 1)) + 1;
    
    for(int i = 0; i < numero; i++)
    {
        sum = sum + numeroComienzo;
        numeroComienzo += 2;
    }
    
    cout << "El cubo del numero introducido es: " << sum << endl;
    
    
}
