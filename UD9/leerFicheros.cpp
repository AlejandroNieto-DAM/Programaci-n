#include <iostream>
#include <fstream>

using namespace std;

int main(){

	char cadena[128];

	ofstream fs("antonio.txt");

	fs << "Hola mundo" << endl;

	fs.close();

	ifstream fe("antonio.txt");

	fe.getline(cadena, 128);

	cout << cadena << endl;


	
}