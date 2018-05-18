#ifndef _FUENTELUZDIRECCIONAL_H
#define _FUENTELUZDIRECCIONAL_H
#include <GL/gl.h>
    #include <GL/glut.h>
#include "fuenteluz.h"

class FuenteLuzDireccional : public FuenteLuz{
public:
	FuenteLuzDireccional(GLenum indice_luz_, float latitud, float longitud);
	void aumentarLatitud();
	void disminuirLatitud();
	void aumentarLongitud();
	void disminuirLongitud();
private:
	void actualizarPosicion();
};
#endif
