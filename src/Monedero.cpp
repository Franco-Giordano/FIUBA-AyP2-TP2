#include "Monedero.h"

Monedero::Monedero(unsigned int N, unsigned int M, unsigned int dificultad){

	this->dinero= (2*N*M) / dificultad;

}

int Monedero::obtenerDineroActual(){
	return this->dinero;
}

bool Monedero::dineroSuficiente(unsigned int dineroAGastar){
	return (this->dinero >= dineroAGastar);
}
void Monedero::sumarDinero(unsigned int dineroASumar){
	this->dinero += dineroASumar;

}

void Monedero::gastarDinero(unsigned int dineroAGastar){
	this->dinero -= dineroAGastar;
}

Monedero::~Monedero() {
}
