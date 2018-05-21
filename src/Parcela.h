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


enum Estado
	{
		Libre,
		Plantada,
		Recuperando,
	};

class Parcela
{

private:

	Estado estado;

	bool regada;

	Cultivo* cultivo;

	int tiempoCosecha;

	int tiempoRecuperacion;



public:

	//Post: Crea una parcela, con un cultivo NULL (o vacio), con estado Libre, y sin regar.
	Parcela();

	//Post: Devuelve true si estaplantada, false si no lo esta
	//Podria servir para las validaciones, como estaLibre.
	bool estaPlantada();

	//Post: Devuelve true si esta regada, false si no lo esta.
	bool estaRegada();

	//Post: Devuelve true si esta libre, false si no lo esta.
	bool estaLibre();

	//Post:  Libera la parcela, dejando al cultivo en NULL y el estado en Libre.
	void liberarParcela();

	//Post: Devuelve un puntero a la "bolsa de semillas", especificamente apuntando al cultivo que est� plantado en la parcela.
	Cultivo* obtenerCultivo();

	//Post: Devuelve el tiempo actual que falta hasta la cosecha de la parcela.
	int obtenerTiempoCosecha();

	//Post:Devuelve el tiempo de recuperacion actual de la parcela.
	int obtenerTiempoRecuperacion();

	//Post: modificar el tiempo de cosecha por el recibido por par�metro.
	void modificarTiempoCosecha(int tiempoCosechaRecibido);


	void modificarTiempoRecuperacion(int tiempoRecuperacionRecibido);

	void modificarEstado(Estado estadoRecibido);

	void modificarCultivo(Cultivo* cultivoRecibido);

	void modificarRegado();

	bool sePuedeSembrar();

	bool sePuedeCosechar();

};


#endif /* PARCELA_H_ */
