#ifndef BRAZOS_H
#define BRAZOS_H

#include <esfera.h>
#include <cilindro.h>
#include <GL/glut.h>
#include <O3DR.h>
#include <cubo.h>
#include <O3DPLY.h>

class Brazos
{
private:
    esfera miesfera;
    cilindro micilindro;
    O3DPLY objeto;
    bool abierto = true;

public:
    Brazos();
    void draw(int opcion, bool revol, bool centrado, int shade);
};

#endif // BRAZOS_H
