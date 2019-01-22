#include <iostream>
using namespace std;

void imprimeVector (int v[], int util){
	
	for(int i = 0; i < util; i++){
		cout << v[i] << " ";
	}

}

void imprimeDobleVector (int v[], int util){
	
	for(int i = 0; i < util; i++){
		v[i] *= 2;
	}

	imprimeVector(v, util);

}

int main(){

	const int DIM_VECTOR = 5;
	int vector[DIM_VECTOR] = {4, 2, 7};
	int util_vector = 3;

	imprimeDobleVector(vector, util_vector);
	imprimeVector(vector, util_vector);
	

}