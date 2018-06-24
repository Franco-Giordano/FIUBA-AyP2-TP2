#include "Correo.h"
#include <iostream>
using namespace std;

Correo::Correo(Lista<Destino*>* destinosValidos, Cultivo* cultivoAEnviar) {
	this->destinosValidos = destinosValidos;
	this->costoEnvio = 0;
	this->cultivoAEnviar = cultivoAEnviar;
}

Cultivo* Correo::cultivoParaEnviar() {
	return cultivoAEnviar;
}

void Correo::enviarCultivo(unsigned int posicionCultivoAEnviar, Almacen* almacen) {
	almacen->quitarCultivo(posicionCultivoAEnviar);
}

void Correo::cobrar(Destino* destino, Monedero* monedero) {
	unsigned int rentabilidad = obtenerRentabilidad();
	int ganancia = rentabilidad - destino->obtenerPrecio();
	monedero->sumarDinero(ganancia);
}

unsigned int Correo::obtenerRentabilidad() {
	return cultivoAEnviar->obtenerRentabilidad();
}

//int Correo::calcularCostoEnvio(Destino* destino) {
//	return destino->obtenerPrecio();
//}
