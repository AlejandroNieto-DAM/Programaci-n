#include <iostream>
using namespace std;
int main()
{
    int a[5];
    
    for(int i=0; i<5; i++)
    {
        cout << "Introduce el numero " << i+1 << " : ";
        cin >> a[i];
    }
    
    int v;
    
    for(int b=0; b<5; b++)
    {
        for(int c=0; c<5; c++)
        {
            if(a[c]>a[b])
               {
                   v=a[c];
                   a[c]=a[b];
                   a[b]=v;
               }
        }
    }
               
               cout << "El numero mayor es: " << a[4] << endl;
               cout << "El numero menor es: " << a[0] << endl;
               
               cout << "Ahora vamos a mostrar los numeros de mayor a menor." << endl;
               
               for(int g=4; g>=0; g--)
               {
                   cout << a[g] << endl;
               }
}
