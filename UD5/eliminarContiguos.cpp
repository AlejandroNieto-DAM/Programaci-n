#include <iostream>
using namespace std;

/*

* @brief Leer el util para ver en que distacia nos movemos por el vector.
* @param util_v que pasamos por referencia ya que lo vamos a cambiar dentro del modulo.
* @pre util_v se tomara desde la entrada de teclado.
* @return no devuelve nada.
* @post util_v ha de ser menor que DIM = 100 y mayor que 0.

*/
void leerUtil(int &util_v){

	do{

		cout << "Introduce el numero de componentes a utilizar: ";
		cin >> util_v;

	}while(util_v < 1 || util_v > 100);

}


/*

* @brief Introducir todos las letras del vector dados por el util_v.
* @param int util_v que indica el numero de componentes utilizados.
* @param int vector[] para introducir todas las letras.
* @pre no se podran introducir mas de el numero dado por util_v.
* @return no devuelve nada.
* @post deben de introducirse datos compatibles con char.

*/
void introducirVector(int util_v, char vector[]){

	for(int i = 0; i < util_v; i++){

		cout << "Introduce las letra deseada " << i + 1 << " : ";
		cin >> vector[i];

	}

}

/*

* @brief Este modulo elimina las letras repetidas contiguas.
* @param int util_v para ver el numero de componentes utilizados en el primer vector.
* @param int util_v2 por referencia para calcular el numero de componentes que vamos a utilizar en el segundo vector.
* @param char vector[] donde tenemos almacenados todas las letras incluso las repetidas.
* @param char vectorNR[] donde vamos a almacenar las letras sin sus contiguas repetidas.
* @pre util_v no debe ser mayor al numero de componentes utilizados por vector[].
* @return no devuelve nada.
* @post vectorNR[] ha de guardas las letras sin estar repetidas sus contiguas.

*/
void borrarRepetidosContiguos(int util_v, const char vector[], int &util_v2, char vectorNR[]){

	vectorNR[0] = vector[0];
	util_v2 ++;

	for(int i = 1; i < util_v; i++){

		if(vector[i] != vector[i-1]){

			vectorNR[util_v2] = vector[i];
			util_v2 ++;

		}


	}

}


/*

* @brief Imprime las letras no repetidas guardados en el segundo vector.
* @param util_v2 que determina el tamaño maximo del vector de letras.
* @param vectorNR[] que tiene las letras sin repetir.
* @pre util_v2 debe tener el tamaño de componentes utilizados dentro del vectorNR. Debe estar activa la salida por pantalla.
* @return no devuelve nada.

*/
void imprimirNR(int util_v2, const char vectorNR[]){

	for(int i = 0; i < util_v2; i++){

		cout << vectorNR[i];

		if(i < util_v2 - 1){
			cout << ", ";
		}
		else{
			cout << ".";
		}



	}

	cout << endl;

}

int main(){

	const int DIM = 100;
	char vector[DIM], vectorNR[DIM];
	int util_v = 0, util_v2 = 0;

	leerUtil(util_v);
	introducirVector(util_v, vector);
	borrarRepetidosContiguos(util_v, vector, util_v2, vectorNR);
	imprimirNR(util_v2, vectorNR);


}