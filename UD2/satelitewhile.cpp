#include <iostream>
using namespace std;

int main()
{
    int i = 0, b = 0;
    int sum = 0, med = 0;
    
    cin >> i;
    cout << "Recibido: " << i << endl;
    
    while(i >= 0)
    {
        sum = sum + i;
        cout << "Procesando: " << i << endl;
        cin >> i;
        cout << "Recibido: " << i << endl;
        b++;
    }
    
    med = (sum/b);
    
    cout << "La media de los datos recibidos es: " << med << endl;
    cout << "Transmisión finalizada." << endl;
}
