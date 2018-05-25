#ifndef NodoCoordenado_H_
#define NodoCoordenado_H_

#ifndef NULL
#define NULL 0
#endif



template<class T> class NodoCoordenado {

    private:

        T dato;

        NodoCoordenado<T>* siguiente;

        unsigned int coordenada;

    public:

        /*
         * pre: coordenada esta en el intervalo [1, maximo de la lista].
         * post: el NodoCoordenado resulta inicializado con el dato dado
         *       y sin un NodoCoordenado siguiente.
         *
         */
        NodoCoordenado(T dato, unsigned int coordenada) {

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
        NodoCoordenado<T>* obtenerSiguiente() {

            return this->siguiente;
        }

        /*
         * post: cambia el siguiente NodoCoordenado por nuevoSiguiente.
         */
        void cambiarSiguiente(NodoCoordenado<T>* nuevoSiguiente) {

            this->siguiente = nuevoSiguiente;
        }


        /*
         * POST: Devuelve la coordenada del Nodo.
         */
        unsigned int obtenerCoordenada(){
        	return this->coordenada;
        }

        /* POST: Devuelve la coordenada del Nodo que le sigue, devuelve 0 si es el ultimo.
         *
         */
        unsigned int obtenerCoordenadaSiguiente(){
        	if (this->obtenerSiguiente()!= NULL){
        		return this->obtenerSiguiente()->obtenerCoordenada();
        	}
        	return 0;
        }

};


#endif /* NodoCoordenado_H_ */
