#ifndef BASE_H
#define BASE_H

#include <brazocentral.h>

class Base : public BrazoCentral{

private:
    Cubo otrocubo;
    BrazoCentral brazo;
public:

    Base();
    void draw(int opcion,bool revol, int giro, double mov, int shade);
};

#endif // BASE_H
