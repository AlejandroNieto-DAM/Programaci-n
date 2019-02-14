/**

* @brief Ordena los elementos de un vector.
* @param v[] que tiene guardados unos elementos anteriormente guardados.
* @param util_v que nos indica el numero de componentes utilizados en vector.
* @pre util_v debe ser mayor que 0.
* @pre v[] debe tener guardados valores en su interior.
* @return no devuelve nada.
* @post el vector quedará ordenado después de ejecutar el bucle.

*/

void OrdBurbuja (double v[], int util_v){

	bool cambio = true;
	double auxiliar = 0;

	for(int izqa = 0; izqa < util_v && cambio; izqa++){

		cambio = false;

		for(int i = util_v - 1; i > izqa; i++){

			if(v[i] < v[i - 1]){

				cambio = true;

				auxiliar = v[i];
				v[i] = v[i - 1];
				v[i - 1] = auxiliar;

			}

		}

	}

}


/**

*

*/

void OrdInsercion (double v[], int util_v){

	int zqda, i;
	double valor;

	for(izqa = 1; izqa < util_v; izqa++){

		valor = v[izqa];

		for(i = izqa; i > 0 && valor < v[i - 1]; i--){

			v[i] = v[i - 1];

		}

		v[i] = valor;

	}

}


/**
*
*/

void OrdSeleccion (double v[], int util_v){

	int pos_min = 0;
	double aux = 0;

	for(int i = 0; i < util_v - 1; i++){

		pos_min = i;

		for(int j = i + 1; j < util_v; j++){

			if(v[j] < v[pos_min]){

				pos_min = j;

			}

			aux = v[i];
			v[i] = v[pos_min];
			v[pos_min] = aux;

		}
	}
}