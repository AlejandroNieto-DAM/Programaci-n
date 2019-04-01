//
//
//  Author: Alejandro Nieto
//  Version: 1.0
//

#define RESTORE "\033[1;0m"
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"

#include <iostream>
using namespace std;

class Polinomio{
	private:

		float *coef;
		int grado;
		int max_grado;
		resize();

	public:
		
		/*

		 * @brief Inicializa el polinomio creando su vector de coeficientes y asignando a 0 sus otros atributos.
		 * @post El polinomio quedará inicializado.
		 * @version: 1.0
		 * @author: Alejandro Nieto.

		*/
		Polinomio(); //Constructor por defecto.

		/*

		 * @brief Inicializa el atributo max_grado asignandole un valor que indicará el grado maximo del Polinomio.
		 * @param maxGrado que el el máximo grado que podrá tomar nuestro Polinomio.
		 * @post El atributo max_grado y grado del polinomio quedarán inicializados.
		 * @version: 1.0
		 * @author: Alejandro Nieto.

		*/
		Polinomio(int maxGrado); //Otro constructor.

		/*

		 * @brief Asigna a la posicion i del vector coef del polinomio un valor c.
		 * @param i que es la posicion del vector coef a la que queremos acceder.
		 * @param c que es valor que queremos introducir en la posicion i.
		 * @pre El polinomio debe de estar inicializado.
		 * @pre i > 0 && <= max_grado.
		 * @post Se introducira el valor c en la posicion i haciendo una suma/resta si ya habia valores introducidos.
		 * @version: 1.0
		 * @author: Alejandro Nieto.

		*/
		void setCoeficiente(int i, float c);
		void Polinomio::setCoeficienteV1(int i, float c);
		void Polinomio::setCoeficienteV2(int i, float c);

		/*

		 * @brief Devuelve el coeficiente de la posicion i.
		 * @param i que es la posicion del vector coef a la que queremos acceder para ver su grado.
		 * @pre El polinomio debe de estar inicializado.
		 * @pre i > 0 && <= max_grado.
		 * @post Devuelve por pantalla el valor del coeficiente de la posicion indicada.
		 * @version: 1.0
		 * @author: Alejandro Nieto.

		*/
		float getCoeficiente(int i) const;

		/*

		 * @brief Devuelve el grado de una posicion.
		 * @pre El polinomio debe de estar inicializado.
		 * @pre 
		 * @post Devuelve por pantalla el grado de una posicion del vector de coeficientes.
		 * @version: 1.0
		 * @author: Alejandro Nieto.

		*/
		int getGrado() const;

		/*

		 * @brief Muestra por pantalla el polinomio al completo.
		 * @pre El polinomio debe existir.
		 * @post Muestra por pantalla el polinomio al completo.
		 * @version: 1.0
		 * @author: Alejandro Nieto.

		*/
		void print() const;

		/*

		 * @brief Destruye el polinomio asignando a 0 todos sus atributos.
		 * @pre El polinomio debe estar creado.
		 * @post El polinomio quedará destruido.
		 * @version: 1.0
		 * @author: Alejandro Nieto.

		*/
		~Polinomio(); //Destructor.
};


/*Polinomio::Polinomio{

	//cout << DEBUG << "debug: polinomio " << RESTORE << endl;

	coef = new float [10];
	max_grado = 0;
	grado = 0;
	
	for(int i = 0; i < 10; i++){
		coef[i] = 0;
	}

}*/

Polinomio::Polinomio(int maxGrado){

	//cout << DEBUG << "debug: polinomio " << RESTORE << endl;

	max_grado = maxGrado;
	coef = new float [max_grado + 1];
	
	grado = maxGrado;
	
	for(int i = 0; i <= max_grado; i++){
		coef[i] = 0;
	}

	
}

void Polinomio::setCoeficienteV0(int i, float c){
	//cout << DEBUG << "debug: setCoeficiente " << RESTORE << endl;
	coef[i] = c;
}

void Polinomio::setCoeficienteV1(int i, float c){
	//cout << DEBUG << "debug: setCoeficiente " << RESTORE << endl;

	bool encontrado = false;
	coef[i] = c;

	for(int i = max_grado; i >= 0 && encontrado == false; i--){
		if(coef[i] != 0){
			grado = i;
			encontrado = true;
		}
	}
}

void Polinomio::setCoeficienteV2(int i, float c){
	//cout << DEBUG << "debug: setCoeficiente " << RESTORE << endl;

	bool encontrado = false;

	if(i > max_grado){
		resize();
	}

	coef[i] = c;

	for(int i = max_grado; i >= 0 && encontrado == false; i--){
			if(coef[i] != 0){
				grado = i;
				encontrado = true;
			}
	}
}

float Polinomio::getCoeficiente(int i) const{
	//cout << DEBUG << "debug: getCoeficiente " << RESTORE << endl;
	return coef[i];
}

int Polinomio::getGrado() const{
	//cout << DEBUG << "debug: getGrado " << RESTORE << endl;
	return grado;
}

void Polinomio::print() const{
	//cout << DEBUG << "debug: print " << RESTORE << endl;
	for(int i = max_grado; i >= 0; i--){
		cout << getCoeficiente(i) << "x" << i << " ";  
	}
}

Polinomio::~Polinomio(){
	//cout << DEBUG << "debug: destructor " << RESTORE << endl;
	for(int i = max_grado; i >= 0; i--){
		setCoeficiente(i, 0);  
	}
	delete [] coef;
	coef = 0;
	grado = 0;
	max_grado = 0;

}

int main(){

	//Polinomio p1;
	//Polinomio p2;

	Polinomio p1 (2);
	Polinomio p2 (3);

	p1.setCoeficiente(0, 0.1);
	//cout << DEBUG << "Grado del Polinomio nº1: " << p1.getGrado() << RESTORE << endl;
	p1.setCoeficiente(1, -1.0);
	//cout << DEBUG << "Grado del Polinomio nº1: " << p1.getGrado() << RESTORE << endl;
	p1.setCoeficiente(2, -2.0);
	//cout << DEBUG << "Grado del Polinomio nº1: " << p1.getGrado() << RESTORE << endl;
	p1.setCoeficiente(2, 0.0);
	//cout << DEBUG << "Grado del Polinomio nº1: " << p1.getGrado() << RESTORE << endl;

	cout << USER << "**** Ya hemos inicializado el Polinomio nº1 *******" << RESTORE << endl;

	p2.setCoeficiente(0, 0.1);
	p2.setCoeficiente(1, -3.0);
	p2.setCoeficiente(2, 5.0);
	p2.setCoeficiente(3, 2.0);

	cout << USER << "**** Ya hemos inicializado el Polinomio nº2 *******" << RESTORE << endl;
	
	cout << USER << "Coeficiente de grado 1 del Polinomio nº1: " << p1.getCoeficiente(1) << RESTORE << endl;
	
	cout << USER << "Coeficiente de grado 3 del Polinomio nº2: " << p2.getCoeficiente(3) << RESTORE << endl;

	cout << USER << "Grado del Polinomio nº1: " << p1.getGrado() << RESTORE << endl;
	
	cout << USER << "Grado del Polinomio nº2: " << p2.getGrado() << RESTORE << endl;

	cout << USER << "Polinomio nº1: " << RESTORE << endl;
	p1.print();
	cout << endl;
	cout << USER << "Polinomio nº2: " << RESTORE << endl;
	p2.print();
	cout << endl; 
}