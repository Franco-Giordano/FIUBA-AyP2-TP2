/*
 * Parcela.h
 *
 *  Created on: 4 may. 2018
 *      Author: federico
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
		Cosechada,
		Podrida,
		Seca,
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

	//Post: Crea una parcela, con un tipo de cultivo Vacío, con estado Libre, y sin regar.
	Parcela();

	//Post: Devuelve true si estaplantada, false si no lo esta
	//Podria servir para las validaciones, como estaLibre.
	bool estaPlantada();

	//Post: Devuelve true si esta regada, false si no lo esta.
	bool estaRegada();

	//Post: Devuelve true si esta libre, false si no lo esta.
	bool estaLibre();

	//Post: Devuelve un puntero a la "bolsa de semillas", especificamente apuntando al cultivo que est� plantado en la parcela.
	Cultivo* obtenerCultivo();

	//Post:  Libera la parcela, dejando al cultivo en NULL y el estado en Libre.
	void liberarParcela();

	//Post: Siembra un cultivo, asignandole las propiedades de dicho cultivo al cultivo contenido por la parcela.
	void sembrarCultivo(Cultivo* cultivoParaSembrar, Monedero* monedero);

	//Pre:  El estado de regada debe ser False.
	//Post: Cambia el estado de regada a True.
	void regarParcela(TanqueDeAgua* tanqueAgua,int costoDeAgua);


	//Post: quita el cultivo de la parcela y lo manda al almacen.  Luego la parcela es puesta en estado "Plantada"
	// y su puntero a cultivo es puesto en "Null".
	void cosecharParcela(Monedero* monedero, Almacen* almacen);

	//Post: Devuelve el tiempo actual que falta hasta la cosecha de la parcela.
	int obtenerTiempoCosecha();

	//Devuelve el tiempo de recuperaci�n actual de la parcela.
	int obtenerTiempoRecuperacion();

};


#endif /* PARCELA_H_ */
