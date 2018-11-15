#include <iostream>
using namespace std;

int main()
{
    
    double num = 0.0, mit = 0.0, i = 0.0, sum = 0.0, c;
    
    cout << "Programa que muestra si el numero introducido es un numero perfecto." << endl;
    
    cout << "Introduce un numero: ";
    cin >> num;
    
    mit = num/2;
    
    while(i <= mit)
    {
        if(num == (i*i))
        {
            sum = sum + 1;
        }
        
        i = i + 1;
    }
    
    if (sum == 1)
    {
        cout << "El numero es un cuadrado perfecto." << endl;
    }
    
    else
    {
        cout << "El numero no es un cuadrado perfecto." << endl;
    }
    
    
}
