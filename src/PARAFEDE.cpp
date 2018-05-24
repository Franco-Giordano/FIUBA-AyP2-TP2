//void impresionFinDeJuego(Lista<Jugador*>* jugadores)
//{
//	unsigned int ganador;
//	for (unsigned int j=0; j<jugadores->contarElementos(); j++)
//	{
//		Jugador* jugadorActual=jugadores->obtener(j);
//		Jugador* jugadorSiguiente=jugadores->obtener(j+1);
//		cout<<"Jugador "<<j+1<<endl;
//		cout<<"Cantidad de terrenos: "<<jugadorActual->obtenerListaTerreno()->contarElementos()<<endl;
//		cout<<"Creditos: "<<jugadorActual->monedero->obtenerDineroActual()<<endl;
//		if(jugadorActual->monedero->obtenerDineroActual() > jugadorSiguiente->monedero->obtenerDineroActual())
//			ganador=j;
//		else
//			ganador=j+1;
//	}
//	cout<<"El ganador es el jugador "<< ganador+1;
//}
//
//void verMisTerrenos(Jugador* jugadorActual)
//{
//	unsigned int f, c, t; //fila, columna, terreno
//	for(t=0; t<jugadorActual->obtenerListaTerreno()->contarElementos(); t++)
//	{
//		cout<<"Terreno "<<t+1<<endl;
//		for (f=0; f<jugadorActual->obtenerListaTerreno()->obtener(t)->obtenerFilas(); f++)
//		{
//			for (c=0; c<jugadorActual->obtenerListaTerreno()->obtener(t)->obtenerColumnas(); c++)
//			{
//				if (jugadorActual->obtenerListaTerreno()->obtener(t)->obtenerParcela(f,c).estaLibre())
//				cout<<"L"; //libre
//				if (jugadorActual->obtenerListaTerreno()->obtener(t)->obtenerParcela(f,c).estaPlantada())
//				cout<<"P"; //plantada
//			}
//			cout<<endl;
//		}
//		cout<<endl;
//	}
//}
