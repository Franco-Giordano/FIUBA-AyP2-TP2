/*
 * MEGAPRUEBAAAAAAAA.cpp
 *
 *  Created on: 20 jun. 2018
 *      Author: frank
 */
#include "DirectorDeJuego.h"
#include "Terreno.h"
#include "Secretario.h"
#include "LectorCSV.h"
#include "Marcador.h"
#include "DronAereo.h"
#include "Participantes.h"
#include "GrafoDirigidoPonderado.h"
#include "MinHeap.h"

using namespace std;
int main() {

	LectorCSV lectorDestinos("src/destinos.txt", 5);

	CatalogoDe<Destino> catalogoDeDestinos(lectorDestinos.obtenerLista());

	GrafoDirigidoPonderado<Destino> grafoDestinos(&catalogoDeDestinos);

	grafoDestinos.imprimirListaAdyacencia();

	ListaNombrada<unsigned int>* adyacentesOrigen = grafoDestinos.obtenerListaAdyacencia()->obtenerDato(1);

	MinHeap colaConPrioridad(grafoDestinos.obtenerListaAdyacencia(), 1);

	colaConPrioridad.imprimirHeap();

}
