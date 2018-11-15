#include <iostream>
using namespace std;

int main()
{
    long double d = 0.0, sum = 0.0, fac = 1.0;
    int n = 0, c = 1;
    
    cout << "Aproximacion numero e diciendo el nivel de aproximación que quieres." << endl;
    
    cout << "Que nivel de aproximacion quieres? ";
    cin >> n;
    
        
    for (int i = 1; i <= n; i++)
    {
        
        fac = fac * i;
        d = (1/fac);
        sum = sum + d;
        
    }
    
    sum = sum + 1;
    
    cout << "El numero e al nivel " << n << " = " << sum << endl;
    
    
}
