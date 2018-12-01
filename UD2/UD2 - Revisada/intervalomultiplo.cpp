#include <iostream>
using namespace std;

int main()
{
    int a = 0, b = 0, x = 0;
    double res = 0.0, sum = 0.0;
    
    cout << "Programa que muestra los multiplos en un intervalo del numero x. " << endl;
    
    cout << "Para introducir unos valores correctos para el intervalo a debe ser mayor que b y que ambos sean mayor que 1." << endl;
    
    cout << "Introduce el comienzo del intervalo (a): ";
    cin >> a;
    cout << "Introduce el final del intervalo (b): ";
    cin >> b;
    
    while((a >= b) || ((b <= 0) || (a <= 0)))
    {
        cout << "Los valores introducidos no son posibles. Recuerda que tienes que introducir valores mayor que 0 y que a sea mayor que b. " << endl;
        cout << "Introduce el comienzo del intervalo (a): ";
        cin >> a;
        cout << "Introduce el final del intervalo (b): ";
        cin >> b;
    }
    

    cout << "Introduce el numero x: ";
    cin >> x;
   
        
    for(int i = a; i <= b; i++)
    {
        res = (i%x);
        
        if(res == 0)
        {
            cout << "- " << i << " es multiplo." << endl;
        }
        
    }
    
    
    
}
