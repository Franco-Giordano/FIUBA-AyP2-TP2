/*
 * Mercado.h
 *
 *  Created on: 23 may. 2018
 *      Author: frank
 */

#ifndef MERCADO_H_
#define MERCADO_H_

#include "Jugador.h"

class Mercado{
private:
	unsigned int dificultad;
public:

	Mercado (unsigned int dificultad);

	void comprarCapacidadTanque(Jugador* jugador, unsigned int ampliacionElegida);

	void comprarCapacidadAlmacen(Jugador* jugador, unsigned int ampliacionElegida);

	void venderTerrenoAjugador(Jugador* jugador, unsigned int filas, unsigned int columnas) ;

	void comprarTerrenoDeJugador(Jugador* jugador, unsigned int posicionTerreno, unsigned int costoActual);

};



#endif /* MERCADO_H_ */
