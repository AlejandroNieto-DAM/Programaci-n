#include <iostream>
using namespace std;

/**

* @brief Procedimiento que sirve para mostrar por la pantalla el vector.
* @param array[] que pasamos por "copia" ya que simplemente vamos a mostrarlo por pantalla y no cambiar sus valores.
* @param util_v que nos tiene guardado el numero de componentes utilizados por el vector.
* @pre array[] debe de tener valores introducidos.
* @pre debe estar activa la salida por pantalla.
* @return no devuelve nada.

*/
void imprimirCadena(int array[], int util_v);

/*

* @brief Ordena el vector
* @param array[] que pasamos por referencia para cambiar sus valores de lugar.
* @param util_v que tiene el numero de componentes utilizados por array[].
* @pre array[] que debe de tener los valores anteriormente introducidos.
* @pre util_v > 0 && < DIM
* @return no devuelve nada.
* @post array[] estará ordenado

*/
void combsort (int array[], int util_v);


int main(){

	const int DIM = 10;
	int array[DIM] = {1, 2, 3, 4, 5};
	int util_v = 5;

	cout << "\nDESORDENADO: " << endl;
	imprimirCadena(array, util_v);

	combsort(array, util_v);

	cout << "\nORDENADO: " << endl;
	imprimirCadena(array, util_v);

}


void imprimirCadena(int array[], int util_v){

	for(int i = 0; i < util_v; i++){

		cout << array[i] << " ";

	}

	cout << endl;


}

void combsort (int array[], int util_v){

	int gap = util_v;
	int swaps = 0;
	int i = 0;
	int aux = 0;

	while(gap != 1 || swaps != 0){

		gap /= 1.3;
		if(gap == 9 || gap == 10) /* Esto va calculando la brecha que ira comparando los nunmeros a modo de 
									burbuja mientras esten desordenados y la brecha no sea igual que 1 */
			gap = 11; 
		if(gap < 1)
			gap = 1;				

		swaps = 0;
		i = 0;
		
		while(i + gap <= util_v){

			if(array[i] > array[i + gap]){ /* Bucle que va comparando la posicion i con la posicion i + gap hasta que sea i + gap mayor que 
												los utiles del vector mientras que haya cambios.*/

				aux = array[i];
				array[i] = array[i + gap];
				array[i + gap] = aux;

	            swaps = swaps + 1;

	            //cout << "swaps: " << swaps << endl;
			}

			i = i + 1;

			//cout << "i: " << i << endl;
		}

	}
	



}