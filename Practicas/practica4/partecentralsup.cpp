#include "partecentralsup.h"

ParteCentralSup::ParteCentralSup()
{

}

void ParteCentralSup::draw(int opcion, bool revol, double mov,int shade){


    glPushMatrix();
    mipartecentral.draw(opcion,revol,shade);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1+(0.25/sqrt(2)),(0.25/sqrt(2)),0);
    glRotatef(-45-mov,0,0,1);
    brazos.draw(opcion,revol,true,shade);
    glPopMatrix();
    revol = true;
    glPushMatrix();
    glTranslatef(1-(0.25/sqrt(2)),(0.25/sqrt(2)),0);
    glRotatef(45+mov,0,0,1);
    brazos.draw(opcion,revol,false,shade);
    glPopMatrix();



}
