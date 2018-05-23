* Nodo.h
 *
 *  Created on: 6 may. 2018
 *      Author: Alvaro
 */

#ifndef NODOMODIFICADO_H_
#define NODOMODIFICADO_H_

#ifndef NULL
#define NULL 0
#endif

template<class T> class Nodo {

    private:

        T dato;

        Nodo<T>* siguiente;

        unsigned int coordenada;

    public:

        /*
         * pre: coordenada esta en el intervalo [1, maximo de la lista].
         * post: el Nodo resulta inicializado con el dato dado
         *       y sin un Nodo siguiente.
         *
         */
        Nodo(T dato, unsigned int coordenada) {

            this->dato = dato;
            this->siguiente = NULL;
            this->coordenada= coordenada;
        }

        /*
         * post: devuelve el valor del dato.
         */
        T obtenerDato() {

            return this->dato;
        }

        /*
         * post: cambia el valor del dato.
         */
        void cambiarDato(T nuevoDato) {

            this->dato = nuevoDato;
        }

        /*
         * post: devuelve el siguiente Nodo.
         */
        Nodo<T>* obtenerSiguiente() {

            return this->siguiente;
        }

        /*
         * post: cambia el siguiente Nodo por nuevoSiguiente.
         */
        void cambiarSiguiente(Nodo<T>* nuevoSiguiente) {

            this->siguiente = nuevoSiguiente;
        }

        unsigned int obtenerCoordenada(){
        	return this->coordenada;
        }

        unsigned int obtenerCoordenadaSiguiente(){
        	if (this->obtenerSiguiente()!= NULL){
        		return this->obtenerSiguiente()->obtenerCoordenada();
        	}

        	return 0;
        }

};


#endif /* NODOMODIFICADO_H_ */
