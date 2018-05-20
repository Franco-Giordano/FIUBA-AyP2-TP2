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

        void regar(Parcela* parcelaAtrabajar,TanqueDeAgua* tanque);

        void cosechar(Parcela* parcelaAtrabajar, Almacen* almacen);

        void sembrar(Parcela* parcelaATrabajar, Monedero* monedero, Cultivo* cultivo);

};


#endif /* SRC_PEON_H_ */
