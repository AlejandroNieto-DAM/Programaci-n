#include <iostream>
using namespace std;

int main()
{
    int x = 0, contador2 = 0;
    int res = 0;
    bool salida = false;
    
    do
    {
        
        cout << "Que tabla de multiplicar quieres hacer? Si quieres terminar el programama pon 0:  ";
        cin >> x;

	if(x == 0)
	{
		salida = true;
	}

        else
	{
       		 do
       		 {
            
         	   	res = x * contador2;
            		cout << x << " x " << contador2 << " = " << res << endl;
           		contador2 = contador2 + 1;
            
       		 }
       		 while(contador2 <= 10);
		
		salida = false;
        
	}

        contador2 = 0;
    }
    while(salida == false);
    
}
