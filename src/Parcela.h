/*
 * Parcela.h
 *
 *  Created on: 4 may. 2018
 *      Author: federico
 */

#ifndef PARCELA_H_
#define PARCELA_H_

#include "Cultivo.h"

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

	//Post: Devuelve el objeto cultivo por referencia, para modificaciones. OJO CON ESTO, fijense que les parece.
	Cultivo& obtenerCultivo();

	/*
	//Post: Siembra un cultivo, asignandole las propiedades de dicho cultivo al cultivo contenido por la parcela. Esta función podría ser una de las que se use, solamente que por
	void sembrarCultivo(std::string nombreLeido,int costoSemillaLeido,int tiempoCosechaLeido,int rentabilidadLeida,int tiempoRecuperacionLeido);
	*/
};


#endif /* PARCELA_H_ */
