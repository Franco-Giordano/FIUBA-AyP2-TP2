/*
 * Candidato.h
 *
 *  Created on: 22 jun. 2018
 *      Author: franco
 */

#ifndef SRC_CANDIDATO_H_
#define SRC_CANDIDATO_H_

template <class T>
class Candidato { //TODO probablemente necesitemos atributos para cambiar peso (no creo que de identificador haga falta)
private:
	T identificador;

	unsigned int peso;

public:
	Candidato<T>(T ident, unsigned int peso) {
		this->identificador = ident;

		this->peso = peso;
	}

	T obtenerIdentificador() {
		return identificador;
	}

	unsigned int obtenerPeso() {
		return peso;
	}
};


#endif /* SRC_CANDIDATO_H_ */
