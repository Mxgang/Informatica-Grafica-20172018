#ifndef _FUENTELUZ_H
#define _FUENTELUZ_H
#include <GL/gl.h>
    #include <GL/glut.h>

class FuenteLuz{

protected:
  GLenum indice_luz;
  float color[3];
  float posicion[4]; //Solo si es posicional
public:
  void activarFuente();
  void desactivarFuente();

  void cambiarColor(float r, float g, float b);
};
#endif

