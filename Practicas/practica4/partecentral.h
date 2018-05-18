#ifndef PARTECENTRAL_H
#define PARTECENTRAL_H

#include <cilindro.h>
#include <GL/glut.h>

class ParteCentral
{
private:
    cilindro micilindro;
public:
    ParteCentral();
    void draw(int opcion, bool revol,int shade);
};

#endif // PARTECENTRAL_H
