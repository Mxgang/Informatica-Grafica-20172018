#include "fuenteluzposicional.h"
FuenteLuzPosicional::FuenteLuzPosicional(GLenum indice_luz_){
	indice_luz = indice_luz_;

	color[0] = 1.0;
	color[1] = 1.0;
	color[2] = 1.0;

	posicion[0] = 20.0;
	posicion[1] = 200.0;
	posicion[2] = -50.0;
	posicion[3] = 10.0; //Posicional
}
