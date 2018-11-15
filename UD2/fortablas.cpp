#include <iostream>
using namespace std;

int main ()
{
    
    int x = 0;
    
    cout << "Introduce el numero de la tabla que quieres ver: ";
    cin >> x;
    
    for(int i = 0; i<=10; i++)
    {
        cout << x << " x " << i << " = " << x*i << endl;
    }
}
