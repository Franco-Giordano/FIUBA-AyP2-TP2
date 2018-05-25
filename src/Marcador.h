/*
 * Marcador.h
 *
 *  Created on: 23 may. 2018
 *      Author: frank
 */

#ifndef MARCADOR_H_
#define MARCADOR_H_

#include "Jugador.h"
#include <iostream>

class Marcador {
private:

public:
	//Post: crea un objeto marcador, el cual sera utilizado para mostrar por pantalla al jugador el estado actual
	// de su granja.
	Marcador();

	//Pre: recibe por parametro un puntero al jugador al cual se le mostrara su estado.
	//Post: Muestra por pantalla la cantidad de terrenos que posee, su dinero, su uso del tanque de agua y del almacen.
	void mostrarTurno(Jugador* jugadorActual);


	void mostrarPuntuacionFinal() {
		//FALTA HACERJKFALJSDKLÑFJADFJADFJKLASDFJADFJFJ
	}


};


#endif /* MARCADOR_H_ */
