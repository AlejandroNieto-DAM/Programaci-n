#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    double res = 0.0;
    
    cout << "Introduce un numero crack: ";
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        res = res + ((1.0-i)/i);
    }
    
    cout << "El resultado es " << res << endl;
}
