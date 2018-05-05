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

	//Post: Crea una parcela, con un tipo de cultivo Vac√≠o, con estado Libre, y sin regar.
	Parcela();

	//Post: Devuelve el objeto cultivo por referencia, para modificaciones. OJO CON ESTO, fijense que les parece.
	Cultivo& obtenerCultivo();


	//Post: Siembra un cultivo, asignandole las propiedades de dicho cultivo al cultivo contenido por la parcela.
	void sembrarCultivo(std::string nombreLeido,int costoSemillaLeido,int tiempoCosechaLeido,int rentabilidadLeida,
												int tiempoRecuperacionLeido,Monedero &monedero);

	//Pre:  El estado de regada debe ser False.
	//Post: Cambia el estado de regada a True.
	void regarParcela(TanqueDeAgua& tanqueAgua,int costoDeAgua);

	//Post: Devuelve true si est· regada, false si no lo est·.
	bool obtenerRegado();

};


#endif /* PARCELA_H_ */
