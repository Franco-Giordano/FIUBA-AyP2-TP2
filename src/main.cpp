/*
 * main.cpp
 *
 *  Created on: 30 abr. 2018
 *      Author: frank
 */

#include "DirectorDeJuego.h"
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
#include "Participantes.h"

using namespace std;
int main() {

	LectorCSV lectorSemillas("src/cultivos.txt", 6);

	LectorCSV lectorDestinos("src/destinos.txt", 4);

	CatalogoDe<Cultivo> catalogoDeSemillas(lectorSemillas.obtenerLista());

	CatalogoDe<Destino> catalogoDeDestinos(lectorDestinos.obtenerLista());

	CatalogoDe<Cultivo>* pCatalogoDeSemillas = &catalogoDeSemillas;

	CatalogoDe<Destino>* pCatalogoDeDestinos = &catalogoDeDestinos;

	DirectorDeJuego director(pCatalogoDeSemillas, pCatalogoDeDestinos);

	Participantes participantes(director.obtenerNumeroDeJugadores(), director.obtenerFilas(), director.obtenerColumnas(), director.obtenerDificultad());

	director.invitarJugadoresApartida(participantes.obtenerListaParticipantes());

	director.coordinarJuego();

	Marcador marcador;
	marcador.mostrarPuntuacionFinal(participantes.obtenerListaParticipantes());

	return 0;

}
