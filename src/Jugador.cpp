/*
 * Usuario.cpp
 *
 *  Created on: 5 may. 2018
 *      Author: Alvaro
 */

#include "Jugador.h"

#include "Monedero.h"
#include "Lista.h"

using namespace std;

Jugador::Jugador (int N, int M, int dificultad) {
	this->cantidadDeTerrenos= 1;
	this->monedero = new Monedero(N, M, dificultad);
	this->terrenos= new Lista<Terreno*>;
	Terreno* terreno=new Terreno(N,M);
		terrenos->agregar(terreno);
	this->tanque= new TanqueDeAgua (N, M, dificultad);
	this->almacen= new Almacen (N, M, dificultad);
}

Lista<Terreno*>* Jugador::obtenerListaTerreno(){
	return this->terrenos;
}


Monedero* Jugador::obtenerMonedero(){
	return this->monedero;
}

TanqueDeAgua* Jugador::obtenerTanqueDeAgua(){
	return this->tanque;
}

Almacen* Jugador:: obtenerAlmacen(){
	return this->almacen;
}


void Jugador::regar(int terrenoARegar, int posFila, int posColumna ){

	int consumoDeAgua= terrenos->obtener(terrenoARegar)->obtenerParcela(posFila, posColumna).
						obtenerCultivo()->obtenerConsumoDeAgua();

	this->terrenos->obtener(terrenoARegar)->obtenerParcela(posFila, posColumna).regarParcela(this->tanque, consumoDeAgua);


}

void Jugador::sembrar(int terrenoASembrar, int posFila, int posColumna, Cultivo* cultivo){
	terrenos->obtener(terrenoASembrar)->obtenerParcela(posFila, posColumna).sembrarCultivo(cultivo, this->monedero);
}

void Jugador::cosechar(int terrenoACultivar, int posFila, int posColumna){
	this->terrenos->obtener(terrenoACultivar)->obtenerParcela(posFila, posColumna).
			cosecharParcela(this->monedero, this->almacen);
}


void Jugador::agregarTerreno(int N, int M){
	Terreno* terreno= new Terreno(N,M);
	this->terrenos->agregar(terreno);
}

void Jugador::comprarTerreno(int N, int M){

	Terreno* terreno = new Terreno(N,M);
	this->cantidadDeTerrenos++;
	this->terrenos->agregar(terreno);
}

void Jugador::venderTerreno(int terrenoAVender){

	this->terrenos->remover(terrenoAVender);
	this->cantidadDeTerrenos--;
}

void Jugador::agrandarAlmacen(int capacidadAAgregar, int dificultad){
	this->almacen->agrandarAlmacen(this->monedero, capacidadAAgregar, dificultad);
}



Jugador::~Jugador() {
	delete this->terrenos;

}