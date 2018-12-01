#include <iostream>
using namespace std;

int main()
{
    int i = 1, n = 0;
    int fac = 1;
    
    cout << "Introduce un numero para calcular su factorial: ";
    cin >> n;
    
    while (i <= n)
    {
        fac = fac * i;
        i++;
    }
    
    cout << "El factorial del numero " << n << " es " << fac << endl;
}
