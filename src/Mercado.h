class Mercado{
private:
	unsigned int dificultad;
public:
	//Pre: recibe la dificultad del juego
	//Post: crea un objeto mercado, el cual se encarga de manejar las compras del jugador
	Mercado (unsigned int dificultad);

	//Pre: recibe el jugador que va a realizar la accion y la ampliacion que se va a realizar
	//Post: el mercado le vende al jugador la capacidad del tanque recibida.
	void venderCapacidadDeTanque(Jugador* jugador, unsigned int ampliacionElegida);

	//Pre: recibe el jugador que va a realizar la accion y la ampliacion que se va a realizar
	//Post: el mercado le vende al jugador la capacidad del almacen recibida.
	void venderCapacidadDeAlmacen(Jugador* jugador, unsigned int ampliacionElegida);

	//Post: El mercado le vende al jugador un terreno, agregandolo a su lista de terrenos.
	void venderTerrenoAJugador(Jugador* jugador, unsigned int filas, unsigned int columnas) ;

	//Post: remueve de la lista de terrenos un terreno, sumando el dinero al jugador.
	void comprarTerrenoDeJugador(Jugador* jugador, unsigned int posicionTerreno, unsigned int costoActual);

};



#endif /* MERCADO_H_ */
