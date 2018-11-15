#include <iostream>
using namespace std;

int main()
{
    double a = 0.0, b = 0.0;
    
    cout << "Introduce dos numeros positivos. " << endl;
    
    do
    {
        cout << "Introduce el primer numero: ";
        cin >> a;
        cout << "Introduce el segundo numero: ";
        cin >> b;
    } while((a < 0) || (b < 0));
    
    cout << "Has introducido los numeros correctos." << endl;
}
