#include "tanqueDeAgua.h"

using namespace std;

tanqueDeAgua::tanqueDeAgua(unsigned int N, unsigned int M, unsigned int dificultad) {
	this->cantidadDeAguaActual=0;
	this->cantidadDeAguaMaxima= (N * M * 2) / dificultad;

}

void tanqueDeAgua::agregarAgua(int cantidad){
	this->cantidadDeAguaActual += cantidad;
}

void tanqueDeAgua::restarAgua(int cantidad){
	this->cantidadDeAguaActual -= cantidad;
}

void tanqueDeAgua::ampliarTanque(int dificultad){
	int ampliacionElegida;

	cout << "Puede ampliar el tanque en 5, 10 o 15 unidades,"
				" para ello presione 1, 2 o 3 respectivamente." << endl;
	cin >> ampliacionElegida;
	// validar (ampliacionElegida); FALTA CREAR


	int dineroGastado= ampliacionElegida*5*dificultad;
	//monedero.restarDinero(dineroGastado);  FALTA CREAR

}

tanqueDeAgua::~tanqueDeAgua() {

}
