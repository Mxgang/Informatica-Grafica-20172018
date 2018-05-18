#ifndef _FUENTELUZPOSICIONAL_H
#define _FUENTELUZPOSICIONAL_H
#include <GL/gl.h>
    #include <GL/glut.h>
#include "fuenteluz.h"

class FuenteLuzPosicional : public FuenteLuz{
public:
	FuenteLuzPosicional(GLenum indice_luz_);
};

#endif
