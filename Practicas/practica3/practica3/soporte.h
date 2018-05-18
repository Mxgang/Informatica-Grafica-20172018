#ifndef SOPORTE_H
#define SOPORTE_H

#include <cubo.h>
#include <brazossoporte.h>
#include <partecentral.h>

class Soporte : public ParteCentralSup
{
private:
    Cubo micubo;
    BrazosSoporte mibrazosoporte;
    ParteCentral micentro;
public:
    Soporte();
    void draw(int opcion, bool revol, double mov);
};

#endif // SOPORTE_H
