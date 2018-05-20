/*
 * Jugador.h
 *
 *  Created on: 5 may. 2018
 *      Author: Alvaro
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

#include "Dado.h"
#include "Terreno.h"
#include "Lista.h"
#include "Peon.h"

class Jugador {

private:
	int cantidadDeTerrenos;
	Monedero* monedero;
	Lista<Terreno*>* terrenos;
	TanqueDeAgua* tanque;
	Almacen* almacen;
	Peon peon;

public:
	//PRE: Para crear un jugador se reciben un monedero, un tanque y un almacen (todos recien creados) y ademas se
	// reciben N y M, las cuales seran las dimensiones del terreno inicial del jugador. Cada jugador se crea con un
	// terreno inicialmente.
	//Post: se crea el objeto jugador.
	Jugador(int N, int M, int dificultad);

	//Post: Devuelve el puntero al objeto monedero.
	Monedero* obtenerMonedero();

	//Post: Devuelve el puntero al tanque de agua.
	TanqueDeAgua* obtenerTanqueDeAgua();

	//Post: Devuelve el puntero al almacen.
	Almacen* obtenerAlmacen();

	//Devuelve un puntero a la lista de punteros "Terreno".
	Lista<Terreno*>* obtenerListaTerreno();

	//Post: Agrega un terreno, metodo creado para probar el funcionamiento.
	void agregarTerreno(int N, int M);

	//Falta hacer el objeto "Servicio de envios".
	void enviarADestino();

	//Pre: N y M  son las dimensiones del terreno a comprar las cuales deben ser enteros validos.
	//Post: agrega un terreno de las dimensiones elegidas en la ultima posicion de la lista.
	void comprarTerreno(int N, int M);

	//POST: quita el terreno elegido por el usuario (ingreso por teclado)
	void venderTerreno(int terrenoAVender);

	//Post: le suma el entero capacidadAAgregar a la capacidad del almacen.
	void agrandarAlmacen(int capacidadAAgregar, int dificultad);


	~Jugador();
};

#endif /* JUGADOR_H_ */
