/*
 * tanqueDeAgua.cpp
 *
 *  Created on: 28 abr. 2018
 *      Author: Alvaro
 */

#include "TanqueDeAgua.h"

using namespace std;

TanqueDeAgua::TanqueDeAgua(unsigned int N, unsigned int M, unsigned int dificultad) {
	this->cantidadDeAguaActual=0;
	this->capacidadMaxima= (N * M * 2) / dificultad;

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
	return this->capacidadMaxima;
}

bool TanqueDeAgua:: hayAguaEnElTanque(){
	return this->cantidadDeAguaActual>0;
}

void TanqueDeAgua::ampliarTanque(int dificultad, Monedero* monedero, int ampliacionElegida){

	capacidadMaxima+= ampliacionElegida;  //amplia el tanque

	int dineroGastado= ampliacionElegida*dificultad;
	monedero->gastarDinero(dineroGastado);

}

TanqueDeAgua::~TanqueDeAgua() {

}

