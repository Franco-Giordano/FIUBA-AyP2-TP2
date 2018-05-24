#ifndef ACCIONES_H_
#define ACCIONES_H_

#include <iostream>
#include "Jugador.h"

class Acciones {
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

	bool esSiembraValida(Terreno* terreno, unsigned int fila,
			unsigned int columna, Cultivo* cultivoElegido);

	bool esCosechaValida(Terreno* terreno, unsigned int fila,
			unsigned int columna);

	bool esRiegoValido(Terreno* terreno, unsigned int fila,
			unsigned int columna);

	bool compraCapacidadTanqueValida(unsigned int ampliacionElegida,
			unsigned int dificultad);

	bool compraCapacidadAlmacenValida(unsigned int ampliacionElegida,
			unsigned int dificultad);

	bool puedeComprarTerreno(unsigned int dificultad, unsigned int filas,
			unsigned int columnas);

	bool tieneMasDeUnTerreno();

private:
	/*
	 * post: valida si la opcion ingresada es correcta
	 */
	bool opcionValida(unsigned int minimo, unsigned int maximo,
			unsigned int opcion);
};

#endif /* ACCIONES_H_ */
