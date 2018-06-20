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

using namespace std;
int main() {

	LectorCSV lectorDestinos("src/destinos.txt", 5);

	CatalogoDe<Destino> catalogoDeDestinos(lectorDestinos.obtenerLista());

	cout << catalogoDeDestinos.obtenerPosicion(0)->obtenerOrigen() << catalogoDeDestinos.obtenerPosicion(1)->obtenerOrigen()<< endl;

}
