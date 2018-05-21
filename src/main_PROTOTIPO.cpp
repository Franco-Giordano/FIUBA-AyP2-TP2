/*
 * main.cpp
 *
 *  Created on: 30 abr. 2018
 *      Author: frank
 */

#include "Lista.h"
#include "Jugador.h"
#include "LectorCSV.h"
#include "Catalogo.h"
#include "Cultivo.h"
#include "Secretario.h"

int main() {

	LectorCSV lectorSemillas("cultivos.txt", 6);

	LectorCSV lectorDestinos("destinos.txt", 4);

	CatalogoDe<Cultivo> catalogoDeSemillas(lectorSemillas.obtenerLista());

	CatalogoDe<Destino> catalogoDeDestinos(lectorDestinos.obtenerLista());

	CatalogoDe<Cultivo>* pCatalogoDeSemillas = &catalogoDeSemillas;

	CatalogoDe<Destino>* pCatalogoDeDestinos = &catalogoDeDestinos;

	Secretario secretario(pCatalogoDeSemillas, pCatalogoDeDestinos);

	Lista<Jugador*>* jugadores= new Lista<Jugador*>;

	for (int i=1; i<= secretario.obtenerNumeroDeJugadores(); i++){
		Jugador* jugador= new Jugador(secretario.obtenerFilas(), secretario.obtenerColumnas(),secretario.obtenerDificultad());
		jugadores->agregar(jugador);
	}



	for (int i=1; i <= secretario.obtenerCantidadTurnos(); i++) {

		//Imprimir turno, puntuaciones?

		jugadores->iniciarCursor();

		Jugador* jugadorActual;
		while (jugadores->avanzarCursor()) {
			jugadorActual = jugadores->obtenerCursor();

			//imprimir que jugador jugara con sus datos
			//imprimirBMP();

			secretario.atenderJugador(jugadorActual);

			//pudrir y secar sus sus terrenos
		}

	}

	//imprimir score final (ganador)








	jugadores->iniciarCursor();
	while (jugadores->avanzarCursor()) {
		delete jugadores->obtenerCursor();
	}
	delete jugadores;

	return 0;
}


