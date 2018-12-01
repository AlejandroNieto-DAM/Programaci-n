#include <iostream>
using namespace std;

int main()
{
    int i = 0, n = 0;
    int sum = 0;
    
    cout << "Introduce un numero para calcular su sumatoria: ";
    cin >> n;
    
    while (i <= n)
    {
        sum = sum + i;
        i++;
    }
    
    cout << "La sumatoria del numero " << n << " es " << sum << endl;
}

