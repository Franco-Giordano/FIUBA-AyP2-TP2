#ifndef ACCIONES_H_
#define ACCIONES_H_

#include <iostream>

class Acciones{
private:
	unsigned int opcionElegida;
public:
	/*
	 * post: inicializa la opcionElegida en 0
	 */
	Acciones();
	/*
	 * post: le muestra por pantalla a cada jugador las acciones que puede realizar durante el juego
	 */
	void mostrarAccionesPosibles();
	/*
	 * pre: la opcion debe ser válida
	 * post: devuelve la opcion elegida por el jugador, es decir, qué desea realizar
	 */
	unsigned int obtenerOpcionElegida();
private:
	/*
	 * post: valida si la opcion ingresada es correcta
	 */
	bool opcionValida(unsigned int opcion);
};

#endif /* ACCIONES_H_ */