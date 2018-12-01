#include <iostream>
using namespace std;

int main()
{
    
    char sim;
    double a = 0.0, b = 0.0;
    
    cout << "Programa que suma, resta, multiplica o divide dos numeros según lo que elija el usuario." << endl;
    
    cout << "Introduce el primer numero: ";
    cin >> a;
    cout << "Introduce el segundo numero: ";
    cin >> b;
    
    cout << "Introduce + para sumar, - para restar, * para multiplicar y / para dividir: ";
    cin >> sim;
    
    switch (sim) {
        case '+' :
            cout << "La suma de los numeros es: " << a + b << endl;
            break;
        case '-' :
            cout << "La resde de los numeros es: " << a - b << endl;
            break;
        case '*' :
            cout << "La multiplicacion de los numeros es: " << a * b << endl;
            break;
        case '/' :
            cout << "La division de los numeros es: " << a / b << endl;
            break;
        default:
            cout << "No has introducido un simbolo correcto. " << endl;
    }
}
