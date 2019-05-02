//
//
//  Author: Alejandro Nieto
//  Version: 1.0
//

#define RESTORE "\033[1;0m"
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;

class Polinomio{
	private:

		float *coef;
		int grado;
		int max_grado;

		/*
	
		 * @brief Aumenta la dimension del vector de coeficientes del polinomio.
		 * @pre grado > max_grado
		 * @post El vector quedará aumentado hasta que max_grado >= grado.
		 * @ver 1.0
		 * @author Alejandro Nieto.

		*/
		void resize();

		/*
	
		 * @brief Aumenta la dimension del vector de coeficientes del polinomio.
		 * @pre grado > max_grado
		 * @post El vector quedará aumentado hasta que max_grado >= grado.
		 * @ver 2.0
		 * @author Alejandro Nieto.
		 
		*/
		void resizeV2Aumentar(int i);

		/*
	
		 * @brief Disminuye la dimension del vector de coeficientes del polinomio.
		 * @pre grado < ((max_grado/2) - 1);
		 * @post El vector quedará disminuido hasta su mitad.
		 * @ver 2.0
		 * @author Alejandro Nieto.
		 
		*/
		void resizeV2Disminuir(int i);

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
		 * @version: 3.0
		 * @author: Alejandro Nieto.

		*/
		void setCoeficienteV0(int i, float c);
		void setCoeficienteV1(int i, float c);
		void setCoeficienteV2(int i, float c);
		void setCoeficienteV3(int i, float c);

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

		/*

		 * @brief Devuelve el max_grado de un polinomio.
		 * @version: 1.0
		 * @author Alejandro Nieto.

		*/
		int getMaxGrado() const;


		/*

		 * @brief Crea un polinomio a partir de otro.
		 * @param i que el el polinomio del cual crearemos una copia exacta.
		 * @post Se creará un polinomio exactamente igual que i.
		 * @ver 1.0
		 * @author Alejandro Nieto.

		*/
		Polinomio(const Polinomio &c); //Constructor por parámetros.


		/*

		 * @brief Suma dos polinomios y los guarda en el polinomio desde el que se llama este método.
		 * @param a que es el polinomio que sumaremos al polinomio al que pertenece este polinomio.
		 * @post El resultado quedará guardado en el polinomio desde el que se llame este método.

		*/
		void sumaPolinomiosV1(const Polinomio &a);


		/*
		
		 * @brief Realiza la suma de dos polinomios y la guarda en el interior del objeto que llama a este metodo.
		 * @param p2 que es un polinomio que vamos a sumar.
		 * @param p3 que es un polinomio que vamos a sumar.
		 * @post El valor de la suma de los polinomios sera el valor de este propio polinomio.

		*/
		void sumarV2(const Polinomio &p2,const Polinomio &p3);

		/*

		 * @brief Suma dos polinomios y devuelve los valores del nuevo polinomio.
		 * @param a que es el polinomio que sumaremos al polinomio al que pertenece este polinomio.
		 * @post El resultado sera devuelto y almacenado en otro polinomio.

		*/
		Polinomio operator+(const Polinomio &a);

		/*

		 * @brief Suma dos polinomios y devuelve el puntero del nuevo polinomio.
		 * @param a que es el puntero del polinomio que sumaremos al polinomio al que pertenece este metodo.
		 * @post El puntero del nuevo objeto será devuelto.

		*/
		Polinomio* sumarV4(const Polinomio *a);

		/*

		 * @brief Iguala dos polinomios y devuelve el puntero del nuevo polinomio.
		 * @param p que es el polinomio que igualaremos al polinomio al que pertenece este metodo.
		 * @pre ambos polinomios deben de estar creados.
		 * @post El contenido del puntero this del nuevo objeto será devuelto.

		*/
		Polinomio& operator=(const Polinomio &p);

		/*
		 * @brief Sobrecarga del operador << cuando hay un polinomio para que se muestre totalmente por pantalla.
		*/
		friend ostream& operator<<(ostream &flujo, const Polinomio &p);

		/*
		 * @brief Sobrecarga del operador << cuando hay un polinomio para que se pueda introducir.
		*/
		friend istream& operator>>(istream &flujo, const Polinomio &p);

};



Polinomio::Polinomio(){

	//cout << DEBUG << "debug: polinomio " << RESTORE << endl;

	coef = new float [1];
	max_grado = 0;
	grado = 0;
	
	for(int i = 0; i < 1; i++){
		coef[i] = 0;
	}

}

Polinomio::Polinomio(int maxGrado){

	//cout << DEBUG << "debug: polinomio " << RESTORE << endl;

	max_grado = maxGrado;
	coef = new float [max_grado + 1];

	if (coef == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }
	
	grado = 0;
	
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
	unsigned int nuevoGrado = 0;
	bool encontrado = false;

	if(i < 0){

		do{

			cout << USER << "Coeficiente invalido..." << RESTORE << endl;
			cin >> nuevoGrado;

		}while(nuevoGrado < 0);

		i = nuevoGrado;
	} 

	if(i > max_grado){

		do{

			resize();

		}while(i > max_grado);

	}

	coef[i] = c;

	for(int i = max_grado; i >= 0 && encontrado == false; i--){
			if(coef[i] != 0){
				grado = i;
				encontrado = true;
			}
	}
	
	if(encontrado == false){
		grado = 0;
	}
}

void Polinomio::setCoeficienteV3(int i, float c){
	//cout << DEBUG << "debug: setCoeficiente " << RESTORE << endl;
	unsigned int nuevoGrado = 0;
	bool encontrado = false;

	if(i > max_grado){

		resizeV2Aumentar(i + 1);

	} 

	if(i < 0){

		do{

			cout << USER << "Coeficiente invalido..." << RESTORE << endl;
			cin >> nuevoGrado;

		}while(nuevoGrado < 0);

		i = nuevoGrado;
	} 

	coef[i] = c;


	for(int i = max_grado; i >= 0 && encontrado == false; i--){
			if(coef[i] != 0){
				grado = i;
				encontrado = true;
			}
	}
	
	if(encontrado == false){
		grado = 0;
	}

	if (grado < max_grado + 2){

		resizeV2Disminuir(grado);

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

	if(grado != 0){
		for(int i = grado; i >= 1; i--){
			if(getCoeficiente(i) != 0){
				cout << getCoeficiente(i) << "x^" << i << " ";
			} 
		}

		if (getCoeficiente(0) != 0){
			cout << getCoeficiente(0);
				
		}
		cout << endl;
	} else {
		cout << USER << "El polinomio esta completamente a 0 :( " << endl;
	}
}

Polinomio::~Polinomio(){
	//cout << DEBUG << "debug: destructor " << RESTORE << endl;
	for(int i = max_grado; i >= 0; i--){
		setCoeficienteV0(i, 0);  
	}
	delete [] coef;
	coef = 0;
	grado = 0;
	max_grado = 0;

}

void Polinomio::resize(){

	//cout << DEBUG << "debug: resize " << RESTORE << endl;

	int nuevaDim = max_grado * 2;

	float *auxiliar;
	auxiliar = new float [nuevaDim + 1];

	if (coef == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }

    for(int i = 0; i <= nuevaDim + 1; i++){
		auxiliar[i] = 0;
	}

    for(int i = 0; i <= max_grado; i++){
    	auxiliar[i] = coef[i];
    }

    delete [] coef;

    coef = auxiliar;

    max_grado = nuevaDim;

    auxiliar = 0;
}

void Polinomio::resizeV2Aumentar(int i){

	//cout << DEBUG << "debug: resize " << RESTORE << endl;

	int nuevaDim = i;

	float *auxiliar;
	auxiliar = new float [nuevaDim + 1];

	if (coef == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }

    for(int i = 0; i <= nuevaDim; i++){
		auxiliar[i] = 0;
	}

    for(int i = 0; i <= max_grado; i++){
    	auxiliar[i] = coef[i];
    }

    delete [] coef;

    coef = auxiliar;

    max_grado = nuevaDim;

    auxiliar = 0;

}

void Polinomio::resizeV2Disminuir(int i){

	//cout << DEBUG << "debug: resize " << RESTORE << endl;

	int nuevaDim = i;

	float *auxiliar;
	auxiliar = new float [nuevaDim + 1];

	if (coef == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }

    for(int i = 0; i <= nuevaDim; i++){
		auxiliar[i] = 0;
	}

    for(int i = 0; i <= nuevaDim; i++){
    	auxiliar[i] = coef[i];
    }

    delete [] coef;

    coef = auxiliar;

    max_grado = nuevaDim;

    auxiliar = 0;

}

int Polinomio::getMaxGrado() const{
	return max_grado;
}

Polinomio::Polinomio(const Polinomio &c){

	max_grado = c.max_grado;
	grado = c.grado;

	coef = new float [max_grado + 1];

	for(int i = 0; i <= max_grado; i++){
		coef[i] = c.coef[i];
	}
}

void Polinomio::sumaPolinomiosV1(const Polinomio &a){

	if(getGrado() >= a.getGrado()){

		for(int i = 0; i <= a.getGrado(); i++){	
			setCoeficienteV3(i, (getCoeficiente(i) + a.getCoeficiente(i)));
		}

	} else {

		for(int i = 0; i <= getGrado(); i++){	
			setCoeficienteV3(i, (getCoeficiente(i) + a.getCoeficiente(i)));
		}

		for(int i = getGrado() + 1 ; i <= a.getGrado(); i++){
			setCoeficienteV3(i, a.getCoeficiente(i));
		}

	}

}

void Polinomio::sumarV2(const Polinomio &p2,const Polinomio &p3){

	if(p2.getGrado() >= p3.getGrado()){
		for(int i = 0; i <= p2.getGrado(); i++){
			if(i <= p3.getGrado()){
				this->setCoeficienteV3(i, p2.getCoeficiente(i) + p3.getCoeficiente(i));
			} else {
				this->setCoeficienteV3(i, p2.getCoeficiente(i));
			}
		}
	} else {
		for(int i = 0; i <= p3.getGrado(); i++){
			if(i <= p2.getGrado()){
				this->setCoeficienteV3(i, p2.getCoeficiente(i) + p3.getCoeficiente(i));
			} else {
				this->setCoeficienteV3(i, p3.getCoeficiente(i));
			}
		}
	}

}

Polinomio Polinomio::operator+(const Polinomio &a){

	Polinomio p3 (2);

	if(this->getGrado() >= a.getGrado()){

		for(int i = 0; i <= this->getGrado(); i++){	
			
			if(i <= a.getGrado()){
				p3.setCoeficienteV3(i, (this->getCoeficiente(i) + a.getCoeficiente(i)));
			} else {
				p3.setCoeficienteV3(i, this->getCoeficiente(i));
			}
		}


	} else {

		for(int i = 0; i <= getGrado(); i++){	
			p3.setCoeficienteV3(i, (this->getCoeficiente(i) + a.getCoeficiente(i)));
		}

		for(int i = getGrado() + 1 ; i <= a.getGrado(); i++){
			p3.setCoeficienteV3(i, a.getCoeficiente(i));
		}

	}

	return p3;

}

Polinomio* Polinomio::sumarV4(const Polinomio *a){

	Polinomio *p3;
	p3 = new Polinomio(2);

	if(this->getGrado() >= a->getGrado()){

		for(int i = 0; i <= a->getGrado(); i++){	
			p3->setCoeficienteV3(i, (this->getCoeficiente(i) + a->getCoeficiente(i)));
		}

	} else {

		for(int i = 0; i <= getGrado(); i++){	
			p3->setCoeficienteV3(i, (this->getCoeficiente(i) + a->getCoeficiente(i)));
		}

		for(int i = this->getGrado() + 1 ; i <= a->getGrado(); i++){
			p3->setCoeficienteV3(i, a->getCoeficiente(i));
		}

	}

	return p3;

}

Polinomio& Polinomio::operator=(const Polinomio &p){
	if(&p != this){
		delete [] this->coef;
		this->max_grado = p.max_grado;
		this->grado = p.grado;
		this->coef = new float [this->max_grado + 1];
		for(int i = 0; i <= max_grado; i++){
			this->coef[i] = p.coef[i];
		}
	}

	return *this;
}

ostream& operator<<(ostream &flujo, const Polinomio &p){
	
	if(p.getGrado() != 0){
		for(int i = p.getGrado(); i >= 1; i--){
			if(p.getCoeficiente(i) != 0){
				flujo << p.getCoeficiente(i) << "x^" << i << " ";
			} 
		}

		if (p.getCoeficiente(0) != 0){
			flujo << p.getCoeficiente(0);
			
		}
		flujo << endl;
	} else {
		flujo << USER << "El polinomio esta completamente a 0 :( " << endl;
	}
	return flujo;
}

istream& operator>>(istream &flujo, Polinomio &p){

	int g;
	float v;

	do{
		flujo >> v >> g;
		if(g >= 0){
			p.setCoeficienteV3(g, v);
		}
	}while(g >= 0);
	return flujo;
}

int main(){

	Polinomio p1;

	float coeficiente = 0.0;
	int grado = 0;

	string nombre_fich = "antonio.txt";

	ofstream fs;
	fs.open(nombre_fich.c_str());

		cin >> p1;
		for(int i = 0; i <= p1.getGrado(); i++){
			fs << i << " " << p1.getCoeficiente(i) << endl;
		}

	fs.close();


	Polinomio p2;

	ifstream fe;
	fe.open(nombre_fich.c_str());

	do{
		fe >> grado >> coeficiente;
		p2.setCoeficienteV3(grado, coeficiente);
	}while(!fe.eof());

	fe.close();

	cout << p1;
	cout << p2;
}