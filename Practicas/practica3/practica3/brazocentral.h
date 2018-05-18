#ifndef BRAZOCENTRAL_H
#define BRAZOCENTRAL_H

#include <soporte.h>

class BrazoCentral : public Soporte{

private:
    cilindro otrocilindro;
    Soporte misoporte;
        ParteCentralSup mipartesup;
public:

    BrazoCentral();
    void draw(int opcion,bool revol, int giro, double mov);

};

#endif // BRAZOCENTRAL_H
