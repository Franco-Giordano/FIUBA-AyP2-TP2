/* 
*Mercado.cpp
* Created by:Alvaro
*25 may. 2018
*01:02:57
*/

#include "Mercado.h"
#include <iostream>
using namespace std;

Mercado::Mercado(unsigned int dificultad){
	this->dificultad= dificultad;
}

void Mercado::comprarCapacidadTanque(Jugador* jugador, unsigned int ampliacionElegida) {
		jugador->obtenerTanqueDeAgua()->ampliarTanque(ampliacionElegida);

		int dineroGastado= ampliacionElegida*dificultad;
		jugador->obtenerMonedero()->gastarDinero(dineroGastado);

	}

void Mercado::comprarCapacidadAlmacen(Jugador* jugador, unsigned int ampliacionElegida) {
		jugador->obtenerAlmacen()->agrandarAlmacen(ampliacionElegida);

		int dineroGastado= (ampliacionElegida + dificultad) *10;
		jugador->obtenerMonedero()->gastarDinero(dineroGastado);

}

void Mercado::venderTerrenoAjugador(Jugador* jugador, unsigned int filas, unsigned int columnas) {

	unsigned int cantidadTerrenos = jugador->obtenerListaTerreno()->contarElementos();

	jugador->obtenerMonedero()->gastarDinero(filas*columnas*dificultad*cantidadTerrenos);

	Terreno* nuevoTerreno = new Terreno(filas, columnas);

	jugador->obtenerListaTerreno()->agregar(nuevoTerreno);

}

void Mercado::comprarTerrenoDeJugador(Jugador* jugador, unsigned int posicionTerreno, unsigned int costoActual) {
	jugador->obtenerListaTerreno()->remover(posicionTerreno);
	jugador->obtenerMonedero()->sumarDinero(costoActual);
}



