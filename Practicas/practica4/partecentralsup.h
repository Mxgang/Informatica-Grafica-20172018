#ifndef PARTECENTRALSUP_H
#define PARTECENTRALSUP_H

#include <brazos.h>
#include <partecentral.h>

class ParteCentralSup : public Brazos
{
private:
    Brazos brazos;
    ParteCentral mipartecentral;
public:
    ParteCentralSup();
    void draw(int opcion, bool revo, double mov,int shade);

};

#endif // PARTECENTRALSUP_H
