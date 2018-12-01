#include <iostream>
using namespace std;

int main()
{
    double nota = 0.0;
    
    cout << "Programa que te dice segun la nota si estas suspenso o aprobado." << endl;
    
    cout << "Introduce una nota: ";
    cin >> nota;
    
    if ((nota <= 10.0) && (nota >= 0.0))
    {
        if (nota < 5.0)
        {
            cout << "Estás suspenso." << endl;
        }
        
        else if ((nota >= 5) && (nota < 7))
        {
                cout << "Estás aprobado." << endl;
        }
        
        else if ((nota >= 7) && (nota < 9))
        {
                cout << "Tienes un notable." << endl;
        }
                
        else
        {
        cout << "Tienes un sobresaliente. " << endl;
        }
        
    }
    
    else
    {
        cout << "La nota no puede ser mayor que 10 o menor que 0." << endl;
    }
}

