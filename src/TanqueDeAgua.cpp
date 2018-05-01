#include "TanqueDeAgua.h"

using namespace std;

TanqueDeAgua::TanqueDeAgua(unsigned int N, unsigned int M, unsigned int dificultad) {
	this->cantidadDeAguaActual=0;
	this->cantidadDeAguaMaxima= (N * M * 2) / dificultad;

}

void TanqueDeAgua::agregarAgua(int cantidad){
	this->cantidadDeAguaActual += cantidad;
}

void TanqueDeAgua::restarAgua(int cantidad){
	this->cantidadDeAguaActual -= cantidad;
}

int TanqueDeAgua::obtenerCantidadDeAguaActual(){
	return this->cantidadDeAguaActual;
}

int TanqueDeAgua::obtenerCantidadDeAguaMaxima(){
	return this->cantidadDeAguaMaxima;
}

void TanqueDeAgua::ampliarTanque(int dificultad, Monedero &monedero){
	int ampliacionElegida;

	cout << "Puede ampliar el tanque en 5, 10 o 15 unidades,"
				" para ello presione 1, 2 o 3 respectivamente." << endl;
	cin >> ampliacionElegida;

	// validar (ampliacionElegida); FALTA CREAR

	cantidadDeAguaMaxima+= ampliacionElegida*5;  //amplia el tanque

	int dineroGastado= ampliacionElegida*5*dificultad;
	monedero.gastarDinero(dineroGastado);

}

TanqueDeAgua::~TanqueDeAgua() {

}
