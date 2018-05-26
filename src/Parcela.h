/*
 * Parcela.h
 *
 *  Created on: 4 may. 2018
 *      Author: Federico
 */

#ifndef PARCELA_H_
#define PARCELA_H_

#include "Cultivo.h"
#include "Monedero.h"
#include "TanqueDeAgua.h"
#include "Almacen.h"

enum Estado {
	Libre, Plantada, Recuperando, ListaParaCosecha,
};

class Parcela {

private:

	Estado estado;

	bool regada;

	Cultivo* cultivo;

	int tiempoCosecha;

	int tiempoRecuperacion;

public:

	//Post: crea una parcela, con un puntero a cultivo NULL (o vacio), con estado Libre, y ya regada. Tiene
	// los atributos tiempo de recuperacion y tiempo de cosecha los cuales son inicializados en 0, luego los
	// mismos seran modificados dependiendo del cultivo que se siembre en la parcela.
	Parcela();

	//Post: devuelve true si estaplantada, false si no lo esta.
	bool estaPlantada();

	//Post: devuelve true si esta regada, false si no lo esta.
	bool estaRegada();

	//Post: devuelve true si esta libre, false si no lo esta.
	bool estaLibre();

	//Post: devuelve true si esta lista para cosechar, false en caso contrario.
	bool estaListaParaCosechar();

	//Post:  libera la parcela, dejando al cultivo en NULL y el estado en Libre.
	void liberarParcela();

	//Post: devuelve un puntero a la "bolsa de semillas", especificamente apuntando al cultivo que esta plantado en la parcela.
	Cultivo* obtenerCultivo();

	//Post: devuelve el tiempo actual que falta hasta la cosecha de la parcela.
	int obtenerTiempoCosecha();

	//Post:devuelve el tiempo de recuperacion actual de la parcela.
	int obtenerTiempoRecuperacion();

	//Post: devuelve el estado de la parcela.
	Estado obtenerEstado();

	//Post: modificar el tiempo de cosecha por el recibido por par�metro.
	void modificarTiempoCosecha(int tiempoCosechaRecibido);

	//Pre:  recibe el tiempo de recuperacion del cultivo que se va a cultivar.
	//Post: asigna el tiempo de recuperacion del cultivo en la parcela, el cual se restara a lo largo de los turnos.
	void modificarTiempoRecuperacion(int tiempoRecuperacionRecibido);

	//Pre: recibe un enum estado.
	//Post: le asigna el Estado recibidio a la parcela.
	void modificarEstado(Estado estadoRecibido);

	//Pre: recibe un puntero del cultivo.
	//Post: le asigna el cultivo recibido a la parcela.
	void modificarCultivo(Cultivo* cultivoRecibido);

	//Post: cambia el bool de la parcela a regada.
	void regar();

	//Post: cambia el bool de la parcela a no regada.
	void secar();

	//Post: si se puede sembrar la parcela devuelve true.
	bool sePuedeSembrar();

	//Post: si se puede cosechar la parcela devuelve true.
	bool sePuedeCosechar();

};

#endif /* PARCELA_H_ */
