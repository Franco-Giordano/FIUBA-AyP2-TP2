/*
 * DirectorDeJuego.h
 *
 *  Created on: 25 may. 2018
 *      Author: frank
 */

#ifndef SRC_DIRECTORDEJUEGO_H_
#define SRC_DIRECTORDEJUEGO_H_

#include "Jugador.h"
#include "Catalogo.h"

class DirectorDeJuego {
private:
	unsigned int turnos, numeroDeJugadores, filas, columnas, dificultad;
    CatalogoDe<Cultivo>* catalogoSemillas;
    CatalogoDe<Destino>* catalogoDestinos;

    Lista<Jugador*>* jugadores;

public:
	DirectorDeJuego(CatalogoDe<Cultivo>* pCatalogoSemillas, CatalogoDe<Destino>* pCatalogoDestinos);

	void invitarJugadoresApartida(Lista<Jugador*>* jugadores);

	int obtenerNumero(int minimo, int maximo, std::string textoOpcional = "");

	int obtenerNumero(int minimo, std::string textoOpcional = "");

	int obtenerNumeroDeJugadores();

	int obtenerCantidadTurnos();

	int obtenerFilas();

	int obtenerColumnas();

	int obtenerDificultad();

	void coordinarJuego();

	void anunciarJugadorYregalarAgua(unsigned int numeroJugador);

};

#endif /* SRC_DIRECTORDEJUEGO_H_ */
