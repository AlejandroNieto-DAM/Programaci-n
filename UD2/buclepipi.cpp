#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    
    double valor = 0, acumulado = 0, monstruo = 0;
    int i = 0, n = 0;
    
    cin >> i;
    
    
        
    for(n = 0; n <= i; n++)
    {
        monstruo = ((2*n+1)*(2*n+1)*(2*n+1));
        valor = ((pow(-1,n))/(monstruo));
        acumulado = acumulado + valor;
           
    }
    
    
    acumulado*= 32;
    acumulado  = pow(acumulado,(1.0/3.0));
    cout << "Valor con " << i << " sumandos: " << acumulado << endl;
}

