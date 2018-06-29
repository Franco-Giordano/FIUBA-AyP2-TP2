#include "Correo.h"
#include <iostream>

using namespace std;

Correo::Correo(Cultivo* cultivoAEnviar) {
	this->costoEnvio = 0;
	this->cultivoAEnviar = cultivoAEnviar;
}

Cultivo* Correo::cultivoParaEnviar() {
	return cultivoAEnviar;
}

void Correo::enviarCultivo(unsigned int posicionCultivoAEnviar, Almacen* almacen) {
	almacen->quitarCultivo(posicionCultivoAEnviar);
}

void Correo::cobrar(unsigned int precio, Monedero* monedero) {
	unsigned int rentabilidad = obtenerRentabilidad();
	int ganancia = rentabilidad - precio;
	monedero->sumarDinero(ganancia);
}

unsigned int Correo::obtenerRentabilidad() {
	return cultivoAEnviar->obtenerRentabilidad();
}
