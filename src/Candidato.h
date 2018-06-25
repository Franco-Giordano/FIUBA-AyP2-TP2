/*
 * Candidato.h
 *
 *  Created on: 22 jun. 2018
 *      Author: franco
 */

#ifndef SRC_CANDIDATOH
#define SRC_CANDIDATOH

template <class T>
class Candidato {
private:
    T identificador;

    unsigned int peso;

public:

    //Post: crea un candidato, el cual representa un nodo del heap y que posee un identificador y un peso. Este peso
    // es el del camino del grafo ponderado.
    Candidato<T>(T ident, unsigned int peso) {
        this->identificador = ident;

        this->peso = peso;
    }

    // Post: devuelve el identificador que es de tipo T.
    T obtenerIdentificador() {
        return identificador;
    }

    // Post: modifica el peso actual por el nuevoPeso recibidio por parametro.
    void modificarPeso(unsigned int nuevoPeso){
        this->peso= nuevoPeso;
    }

    // Post: devuelve el peso del candidato.
    unsigned int obtenerPeso() {
        return peso;
    }
};


#endif /* SRC_CANDIDATOH */
