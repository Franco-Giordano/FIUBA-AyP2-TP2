/*
 * Peon.cpp
 *
 *  Created on: 20 may. 2018
 *      Author: Federico
 */

#include "Peon.h"

void Peon::regar(Parcela* parcelaATrabajar, TanqueDeAgua* tanqueAgua) {

	int consumoAgua = parcelaATrabajar->obtenerCultivo()->obtenerConsumoAgua();
	parcelaATrabajar->regar();
	tanqueAgua->restarAgua(consumoAgua);

}

void Peon::cosechar(Parcela* parcelaATrabajar, Almacen* almacen) {

	parcelaATrabajar->modificarTiempoRecuperacion(parcelaATrabajar->obtenerCultivo()->obtenerTiempoRecuperacion());

	almacen->agregarCultivo(parcelaATrabajar->obtenerCultivo());
	parcelaATrabajar->modificarCultivo(NULL);
	parcelaATrabajar->modificarEstado(Recuperando);

}

void Peon::sembrar(Parcela* parcelaATrabajar, Monedero* monedero, Cultivo* cultivo) {

	monedero->gastarDinero(cultivo->obtenerCostoSemilla());
	parcelaATrabajar->modificarCultivo(cultivo);
	parcelaATrabajar->modificarEstado(Plantada);
	parcelaATrabajar->modificarTiempoCosecha(cultivo->obtenerTiempoCosecha());
}

