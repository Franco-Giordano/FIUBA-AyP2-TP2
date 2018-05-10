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

	Cultivo cultivo;

public:

	//Post: Crea una parcela, con un tipo de cultivo Vacío, con estado Libre, y sin regar.
	Parcela();

	
	//Post: Devuelve true si est� plantada, false si no lo est�.
	//Podria servir para las validaciones, como estaLibre.
	bool estaPlantada();

	//Post: Devuelve true si est� regada, false si no lo est�.
	// Cambie el nombre, porque me parece mas claro comparar con un si esta o no esta regada
	// que con obtenerRegado.
	bool estaRegada();

	//Post: Devuelve true si est� libre, false si no lo est�.
	bool estaLibre();

	//Post: Devuelve el objeto cultivo por referencia, para modificaciones. OJO CON ESTO, fijense que les parece.
	Cultivo& obtenerCultivo();

	void liberarParcela();

	//Post: Siembra un cultivo, asignandole las propiedades de dicho cultivo al cultivo contenido por la parcela.
	void sembrarCultivo(std::string nombreLeido,int costoSemillaLeido,int tiempoCosechaLeido,
						int rentabilidadLeida, int tiempoRecuperacionLeido,Monedero &monedero,
						int consumoDeAguaRecibido);

	//Pre:  El estado de regada debe ser False.
	//Post: Cambia el estado de regada a True.
	void regarParcela(TanqueDeAgua& tanqueAgua,int costoDeAgua);

	//Agregado que faltaba de antes.
	void cultivarParcela(Monedero& monedero);

	//ob



};


#endif /* PARCELA_H_ */
