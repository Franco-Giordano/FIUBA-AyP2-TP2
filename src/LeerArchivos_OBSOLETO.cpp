#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void leerNotas(string rutaEntrada) ;
void escribirSecuencia( string rutaSalida);



int main() {

	std::string archivoConNotas = "destinos.txt";
	std::string archivoConSecuencia = "destinos.txt";

	leerNotas(archivoConNotas);

	//escribirSecuencia(archivoConSecuencia);

	return 0;
}

//Este es el que importa, no tuve tiempo de dejarlo lindo, pero lo subo para que ya puedan ver como funciona!
void leerNotas(std::string rutaEntrada) {

	/* crea el archivo y abre la ruta especificada */
	std::ifstream entrada;
	entrada.open(rutaEntrada.c_str());

	/* lee la primera línea completa */
	std::string lineaLeida;

	/* lee el resto del archivo */
	while (! entrada.eof()) {

		std::getline(entrada, lineaLeida);

//
//		int padron;
//		string nombre;
//		int nota;
//
//		/* intenta leer un número de padrón */
//		entrada >> padron;
//
		/* verifica que no haya llegado al fin del archivo */
		if (! entrada.eof()) {

//			/* lee el nombre y la nota */
//			entrada >> nombre;
//			entrada >> nota;
//
//			std::cout << padron << " | " << nota << " | " << nombre << std::endl;

			cout << lineaLeida << endl;

			for (unsigned int i = 0; i < lineaLeida.length(); i++) {

				char caracter = lineaLeida[i];

				if (caracter == ',') {
					cout << '-';
				} else if (caracter != ' '){
					cout << lineaLeida[i];
				}
 			}

			cout << endl;
		}
	}

	/* cierra el archivo, liberando el recurso */
	entrada.close();
}


void escribirSecuencia(std::string rutaSalida) {

	/* abre un archivo de salida */
	std::ofstream salida;
	salida.open(rutaSalida.c_str());

	/* escribe el contenido del archivo */
	salida << "-- Secuencia de valores --" << std::endl;

	for (int i = 0; i < 10; i++) {

		salida << i << ": " << i * 2 << std::endl;
	}

	/* cierra el archivo, liberando el recurso */
	salida.close();
}

