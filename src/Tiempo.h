/*
 * Tiempo.h
 *
 *  Created on: 23 may. 2018
 *      Author: fedei
 */

#ifndef SRC_TIEMPO_H_
#define SRC_TIEMPO_H_

#include "Jugador.h"

class Tiempo{

private:

	Jugador* jugador;

public:

	/*Post: Crea el objeto tiempo, a partir de un jugador recibido. Cada jugador tendr� su tiempo,
	el mismo es el encargado de madurar las parcelas, secarlas, y liberarlas. */
	Tiempo(Jugador* jugadorRecibido);

	/*Post: Enjevece en un turno la parcela. */
	void madurarParcela(Terreno* terrenoRecibido, unsigned int fila, unsigned int columna);

	/*Post: Libera la parcela seleccionada y la elimina.*/
	void liberarParcela(Terreno* terrenoRecibido, unsigned int fila, unsigned int columna);

	//Hacer que recorra la lista de terrenos, y a su vez, todas las parcelas de cada terreno, xd
	void madurarTerreno(Terreno* terrenoActual);

	//Post: cambia el estado inicial cada parcela de cada terreno de cada jugador.
	void madurarTodosLosTerrenosDelJugador();

};


#endif /* SRC_TIEMPO_H_ */
