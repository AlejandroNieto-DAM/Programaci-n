#include <iostream>
using namespace std;

int main()
{
    
    int i = 0;
    int x = 0;
    bool fin = false;
    
    for( i = 0 ; i <= 20 && !false ; i++ )
    {
        cin >> x;
        cout << "Recibido." << endl;
        if(x >= 0){
            cout << "Procesado." << endl;
        }
        
        else{
            fin = true;
        }
        
    }
    
    cout << "Transmisión finalizada." << endl;
}
