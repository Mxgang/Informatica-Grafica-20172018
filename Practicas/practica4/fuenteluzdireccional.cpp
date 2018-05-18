#include "fuenteluzdireccional.h"
FuenteLuzDireccional::FuenteLuzDireccional(GLenum indice_luz_, float latitud, float longitud){
	indice_luz = indice_luz_;

    color[0] = 1;
    color[1] = 1;
    color[2] = 1;

	posicion[0] = latitud;
	posicion[1] = longitud;
	posicion[2] = 0.0;
	posicion[3] = 0.0; //Direccional
}

void FuenteLuzDireccional::aumentarLatitud(){posicion[0]++;actualizarPosicion();}
void FuenteLuzDireccional::disminuirLatitud(){posicion[0]--;actualizarPosicion();}
void FuenteLuzDireccional::aumentarLongitud(){posicion[1]++;actualizarPosicion();}
void FuenteLuzDireccional::disminuirLongitud(){posicion[1]--;actualizarPosicion();}
void FuenteLuzDireccional::actualizarPosicion(){
	glLightfv(indice_luz, GL_POSITION, (GLfloat *) &posicion);
	glLightfv(indice_luz, GL_AMBIENT, (GLfloat *) &color);
	glLightfv(indice_luz, GL_SPECULAR, (GLfloat *) &color);
	glLightfv(indice_luz, GL_DIFFUSE, (GLfloat *) &color);
}
