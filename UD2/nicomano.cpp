#include <iostream>
using namespace std;

int main()
{
    int  numero = 0, sum2 = 0, sum = 0, contador = 0;
    int imp = 1;
    
    for(int variable = 0; variable <= 100; variable++)
    {
        for(int i = 0; i < numero; i++)
        {
            sum2 = sum2 + i;
        }
        
        contador = -sum2;
        
        while(contador < numero)
        {
            if(contador >= 0)
            {
                sum += imp;
            }
            
            imp+=2;
            contador += 1;
        }
        
        cout << "El cubo de " << numero << " es " << sum << endl;
        
        numero++;
        
        sum2 = 0, sum = 0, contador = 0, imp = 1;
    }
}

