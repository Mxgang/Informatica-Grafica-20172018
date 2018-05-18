#ifndef BRAZOSSOPORTE_H
#define BRAZOSSOPORTE_H

#include <partecentralsup.h>

class BrazosSoporte
{

private:
    cilindro micilindro;
public:
    BrazosSoporte();
    void draw(int opcion, bool revol, int shade);
};

#endif // BRAZOSSOPORTE_H
