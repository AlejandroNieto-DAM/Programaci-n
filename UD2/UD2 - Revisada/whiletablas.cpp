#include <iostream>
using namespace std;

int main()
{
    int i = 0;
    int x = 0;
    
    
    cout << "Que tabla de multiplicar quieres? ";
    cin >> x;
    
    while( i <= 10 )
    {
        
        cout << x << " x " << i  << " = " << x*i << endl;
        
        i = i + 1;
        
    }
}
