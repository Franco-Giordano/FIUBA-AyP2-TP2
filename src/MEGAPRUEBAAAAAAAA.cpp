/*
 * MEGAPRUEBAAAAAAAA.cpp
 *
 *  Created on: 20 jun. 2018
 *      Author: frank
 */
#include "ColaConPrioridad.h"
#include "DirectorDeJuego.h"
#include "Terreno.h"
#include "Secretario.h"
#include "LectorCSV.h"
#include "Marcador.h"
#include "DronAereo.h"
#include "Participantes.h"
#include "GPS.h"
#include "GrafoDirigidoPonderado.h"

using namespace std;
int main() {

	LectorCSV lectorDestinos("src/destinos.txt", 5);

	LectorCSV lectorSemillas("src/cultivos.txt", 6);

	CatalogoDe<Cultivo> catalogoDeSemillas(lectorSemillas.obtenerLista());

	CatalogoDe<Destino> catalogoDeDestinos(lectorDestinos.obtenerLista());

	GPS miRealizadorDeGPS("almacen", &catalogoDeSemillas, &catalogoDeDestinos);



//
//	GrafoDirigidoPonderado<Destino> grafoDestinos(&catalogoDeDestinos, "papa");
//
//	grafoDestinos.imprimirListaAdyacencia();
//
//	ColaConPrioridad colaConPrioridad(grafoDestinos.obtenerListaAdyacencia(), 1);
//
//	colaConPrioridad.imprimirHeap();
//
//	cout << endl;
//
//	cout << colaConPrioridad.removerRaiz().obtenerIdentificador() << endl;
//
//
//	cout << colaConPrioridad.removerRaiz().obtenerIdentificador() << endl;
//
//
//	cout << colaConPrioridad.removerRaiz().obtenerIdentificador() << endl;
//
//	cout << colaConPrioridad.removerRaiz().obtenerIdentificador() << endl;
//
//	cout << colaConPrioridad.removerRaiz().obtenerIdentificador() << endl;

//	colaConPrioridad.imprimirHeap();
//
//	cout << endl;
//
//	cout << "Vamo a mofidicar el peso: " << endl;
//
//	colaConPrioridad.mejorarPeso("tierra del fuego", 1);
//
//	cout << "Peso modificado xd" << endl;
//
//	colaConPrioridad.imprimirHeap();
}
