/*
 * Almacen.cpp
 *
 *  Created on: 6 may. 2018
 *      Author: Alvaro
 */

#include "Almacen.h"
#include <iostream>
using namespace std;

Almacen::Almacen(int N, int M, int dificultad) {
	this->capacidad= (2*(N+M))/dificultad;
	this->cultivos= new Lista<Cultivo*>;
}

int Almacen::obtenerCapacidad(){
	return this->capacidad;
}

bool Almacen:: capacidadValida(){
	return (cultivos->contarElementos() <= capacidad);
}

void Almacen::agrandarAlmacen(Monedero* monedero, unsigned int capacidadAAgregar, int dificultad){

	int precio= (capacidadAAgregar + dificultad) *10;

//	if (monedero->dineroSuficiente(precio)){             // Esto hay que validarlo

		monedero->gastarDinero(precio);
		this->capacidad += capacidadAAgregar;



}