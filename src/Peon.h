/*
 * Peon.h
 *
 *  Created on: 20 may. 2018
 *      Author: Federico
 */

#ifndef SRC_PEON_H_
#define SRC_PEON_H_

#include "Parcela.h"

class Peon{

    public:

		//Pre: Recibe la parcela que se quiere regar y el tanque.
		//Post: Cambia el estado de la parcela a regada y resta el agua del tanque usada para el regado.
        void regar(Parcela* parcelaAtrabajar,TanqueDeAgua* tanque);

        //Pre: Recibe la parcela que se va a cosechar
        //Post: Quita el cultivo de la parcela y lo agrega al almacen.
        void cosechar(Parcela* parcelaAtrabajar, Almacen* almacen);

        //Pre: recibe la parcela que se desea sembrar, el monedero y el cultivo a sembrar
        //Post: siembra el cultivo en la parcela restando el costo del mismo en el monedero.
        void sembrar(Parcela* parcelaATrabajar, Monedero* monedero, Cultivo* cultivo);

};


#endif /* SRC_PEON_H_ */
