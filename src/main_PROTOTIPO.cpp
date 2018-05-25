/*
 * main.cpp
 *
 *  Created on: 30 abr. 2018
 *      Author: frank
 */

#include "Terreno.h"
#include "Parcela.h"
#include "Jugador.h"
#include "Secretario.h"
#include "LectorCSV.h"
#include "Peon.h"
#include "Dado.h"
#include "Marcador.h"
#include "DronAereo.h"
#include "Tiempo.h"

#include <iostream>

using namespace std;
int main() {

	LectorCSV lectorSemillas("cultivos.txt", 6);

	LectorCSV lectorDestinos("destinos.txt", 4);

	CatalogoDe<Cultivo> catalogoDeSemillas(lectorSemillas.obtenerLista());

	CatalogoDe<Destino> catalogoDeDestinos(lectorDestinos.obtenerLista());

	CatalogoDe<Cultivo>* pCatalogoDeSemillas = &catalogoDeSemillas;

	CatalogoDe<Destino>* pCatalogoDeDestinos = &catalogoDeDestinos;

	Secretario secretario(pCatalogoDeSemillas, pCatalogoDeDestinos);

	Lista<Jugador*>* jugadores = new Lista<Jugador*>;

	for (int i = 1; i <= secretario.obtenerNumeroDeJugadores(); i++) {
		Jugador* jugador = new Jugador(secretario.obtenerFilas(),
				secretario.obtenerColumnas(), secretario.obtenerDificultad());
		jugadores->agregar(jugador);
	}

	cout << "Mandando a volar el dron, estara listo en unos momentos!..." << endl;
	DronAereo dron(secretario.obtenerFilas(), secretario.obtenerColumnas());

	Dado dado;

	Marcador marcador;

	unsigned int numeroJugador = 1;
	for (int i = 1; i <= secretario.obtenerCantidadTurnos(); i++) {

		cout << "-----------------------TURNO " << i
				<< "-----------------------" << endl;

		jugadores->iniciarCursor();

		Jugador* jugadorActual;
		while (jugadores->avanzarCursor()) {
			jugadorActual = jugadores->obtenerCursor();

			Tiempo tiempo(jugadorActual);
			tiempo.madurarTodosLosTerrenosDelJugador();

			cout << "/////Jugador nº " << numeroJugador << "/////" << endl;
			unsigned int resultadoDado = dado.obtenerNumeroRandom();
			cout << "// Obtuviste " << resultadoDado << " en tu dado! Ganaste "<< resultadoDado * 5 << " de agua." << endl;
			unsigned int aguaPerdida =
					jugadorActual->obtenerTanqueDeAgua()->agregarAgua(resultadoDado * 5);
			if (aguaPerdida != 0) {
				std::cout << "// ****Perdiste " << aguaPerdida<< " unidad(es) de riego!****" << endl;
			}

			marcador.mostrarTurno(jugadorActual);

			cout << "++Tomando fotos de  sus terrenos al principio de turno, aguarde un momento...++"<< endl;
			dron.tomarFoto(jugadorActual, numeroJugador, i);
			secretario.atenderJugador(jugadorActual);

			cout << "++Tomando fotos de sus terrenos al final de turno, aguarde un momento...++"<< endl;
			dron.tomarFoto(jugadorActual, numeroJugador, i);

			numeroJugador++;
		}
		numeroJugador = 1;

	}

	//imprimir score final (ganador)

	jugadores->iniciarCursor();
	while (jugadores->avanzarCursor()) {
		delete jugadores->obtenerCursor();
	}
	delete jugadores;

	return 0;

}

