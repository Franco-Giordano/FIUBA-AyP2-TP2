#include "Acciones.h"
#include <limits>
#include "Marcador.h"

using namespace std;

Acciones::Acciones(Jugador* pJugador) {
	opcionElegida = 0;
	jugador = pJugador;
}

unsigned int Acciones::obtenerAccionDeJugador() {
	unsigned int opcion;

	Marcador marcador;
	marcador.mostrarTurno(this->jugador);

	cout << "Estas son las acciones que puede realizar, elija la que desea:" << endl;
	cout << "1. Sembrar" << endl;
	cout << "2. Cosechar" << endl;
	cout << "3. Regar" << endl;
	cout << "4. Enviar una cosecha" << endl;
	cout << "5. Comprar un terreno" << endl;
	cout << "6. Vender un terreno" << endl;
	cout << "7. Comprar capacidad del tanque de agua" << endl;
	cout << "8. Comprar capacidad del almacen" << endl;
	cout << "9. Mostrar terrenos por pantalla" << endl;
	cout << "10. Pasar de turno" << endl;
	cin >> opcion;
	while (!opcionValida(1, 10, opcion)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Opcion invalida, ingrese otra: " << endl;
		cin >> opcion;
	}
	opcionElegida = opcion;
	return opcionElegida;
}

bool Acciones::opcionValida(unsigned int minimo, unsigned int maximo, unsigned int opcion) {
	return (opcion >= minimo && opcion <= maximo);
}

bool Acciones::esSiembraValida(Terreno* terreno, unsigned int fila, unsigned int columna, Cultivo* cultivoElegido) {

	bool puedeComprarSemilla = jugador->obtenerMonedero()->dineroSuficiente(cultivoElegido->obtenerCostoSemilla());
	bool parcelaOcupada = terreno->estaOcupada(fila, columna);
	if (!parcelaOcupada && puedeComprarSemilla) {
		terreno->prepararParcela(fila, columna);
	}
	return !parcelaOcupada && puedeComprarSemilla;
}

bool Acciones::esCosechaValida(Terreno* terreno, unsigned int fila, unsigned int columna) {
	bool parcelaOcupada = terreno->estaOcupada(fila, columna);
	bool sePuedeCosecharParcela = false;

	if (parcelaOcupada) {
		sePuedeCosecharParcela = terreno->obtenerParcela(fila, columna)->sePuedeCosechar();
	}

	bool hayEspacioLibreEnAlmacen = this->jugador->obtenerAlmacen()->hayEspacioLibre();

	return parcelaOcupada && sePuedeCosecharParcela && hayEspacioLibreEnAlmacen;
}

bool Acciones::esRiegoValido(Terreno* terreno, unsigned int fila, unsigned int columna) {
	bool hayAguaSuficiente = false;
	bool parcelaOcupada = terreno->estaOcupada(fila, columna);
	if (parcelaOcupada) {
		hayAguaSuficiente = jugador->obtenerTanqueDeAgua()->obtenerCantidadDeAguaActual() >= terreno->obtenerParcela(fila, columna)->obtenerCultivo()->obtenerConsumoAgua();
	}

	return parcelaOcupada && terreno->obtenerParcela(fila, columna)->estaPlantada() && !terreno->obtenerParcela(fila, columna)->estaRegada() && hayAguaSuficiente;
}

bool Acciones::compraCapacidadTanqueValida(unsigned int ampliacionElegida, unsigned int dificultad) {
	return this->jugador->obtenerMonedero()->dineroSuficiente(dificultad * ampliacionElegida);
}

bool Acciones::compraCapacidadAlmacenValida(unsigned int ampliacionElegida, unsigned int dificultad) {
	return this->jugador->obtenerMonedero()->dineroSuficiente((dificultad + ampliacionElegida) * 10);
}

bool Acciones::puedeComprarTerreno(unsigned int dificultad, unsigned int filas, unsigned int columnas) {

	unsigned int cantidadTerrenos = jugador->obtenerListaTerreno()->contarElementos();

	return jugador->obtenerMonedero()->dineroSuficiente(filas * columnas * dificultad * cantidadTerrenos);
}

bool Acciones::tieneMasDeUnTerreno() {
	return jugador->obtenerListaTerreno()->contarElementos() > 1;
}

bool Acciones::esEnvioValido(Destino* destino, Correo correo){

	int ganancia= correo.obtenerRentabilidad() - destino->obtenerPrecio();

	return (ganancia > 0);
}

void Acciones::obtenerDestinosValidos(Lista<Destino*>* listaDestinos, Cultivo* cultivo, CatalogoDe<Destino>* catalogoDestinos) {

	unsigned int cantidad = catalogoDestinos->obtenerCantidadDisponible();

	for (unsigned int i = 0; i < cantidad; i++) {
		Destino* destinoActual = catalogoDestinos->obtenerPosicion(i);
		if (destinoActual->obtenerNombreCultivo() == cultivo->obtenerNombre()) {
			listaDestinos->agregar(destinoActual);
		}
	}
}

void Acciones::imprimirListaDestinos(Lista<Destino*>* destinosValidos) {
	unsigned int posicionDestino = 1;
	destinosValidos->iniciarCursor();
	while (destinosValidos->avanzarCursor()) {
		Destino* destinoActual = destinosValidos->obtenerCursor();
		cout << posicionDestino << ". " << destinoActual->obtenerNombre() << " | costo de envio: " << destinoActual->obtenerDistancia() * destinoActual->obtenerPrecio() << endl;
	}
}
