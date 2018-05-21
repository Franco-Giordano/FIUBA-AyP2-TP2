#ifndef ACCIONES_H_
#define ACCIONES_H_

#include <iostream>
#include "Jugador.h"

class Acciones{
private:
	unsigned int opcionElegida;
	Jugador* jugador;
public:
	/*
	 * post: inicializa la opcionElegida en 0
	 */
	Acciones(Jugador* pJugador);
	/*
	 * post: le muestra por pantalla a cada jugador las acciones que puede realizar durante el juego
	 */
	unsigned int obtenerAccionDeJugador();

	bool esSiembraValida(Parcela* parcelaElegida, Cultivo* cultivoElegido);

	bool esRiegoValido(Parcela* parcelaElegida);

private:
	/*
	 * post: valida si la opcion ingresada es correcta
	 */
	bool opcionValida(unsigned int minimo,unsigned int maximo, unsigned int opcion);
};

#endif /* ACCIONES_H_ */
