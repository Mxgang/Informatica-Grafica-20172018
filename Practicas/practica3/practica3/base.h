#ifndef BASE_H
#define BASE_H

#include <brazocentral.h>

class Base : public BrazoCentral{

private:
    Cubo otrocubo;
    BrazoCentral brazo_central;
public:

    Base();
    void draw(int opcion,bool revol, int giro, double mov);
};

#endif // BASE_H
