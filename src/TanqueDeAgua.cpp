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

unsigned int TanqueDeAgua::agregarAgua(int cantidad){
	unsigned int cantidadAguaPerdida = 0;
	this->cantidadDeAguaActual += cantidad;
	if (this->cantidadDeAguaActual > this->capacidadMaxima) {
		cantidadAguaPerdida = this->cantidadDeAguaActual - this->capacidadMaxima;
		this->cantidadDeAguaActual = this->capacidadMaxima;
	}

	return cantidadAguaPerdida;
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

void TanqueDeAgua::ampliarTanque(int ampliacionElegida){

	capacidadMaxima+= ampliacionElegida;

}

TanqueDeAgua::~TanqueDeAgua() {

}

