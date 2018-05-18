#include "partecentralsup.h"

ParteCentralSup::ParteCentralSup()
{

}

void ParteCentralSup::draw(int opcion, bool revol, double mov){


    glPushMatrix();
    mipartecentral.draw(opcion,revol);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1+(0.25/sqrt(2)),(0.25/sqrt(2)),0);
    glRotatef(-45-mov,0,0,1);
    brazos.draw(opcion,revol,true);
    glPopMatrix();
    revol = true;
    glPushMatrix();
    glTranslatef(1-(0.25/sqrt(2)),(0.25/sqrt(2))-4.75+(mov/10),0);
    glRotatef(135-mov,0,0,1);
    brazos.draw(opcion,revol,false);
    glPopMatrix();



}
