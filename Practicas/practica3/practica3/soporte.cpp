#include "soporte.h"

Soporte::Soporte()
{

}

void Soporte::draw(int opcion, bool revol, double mov){

    glMatrixMode(GL_MODELVIEW);
    // cubo pequeño
    glPushMatrix();
    glTranslatef(-0.5,-2.75,0);
    glScalef(0.25,5.5,0.25);
    if(opcion == 1){
        micubo.draw_points();

    }
    else if(opcion == 2){
        micubo.draw_lines();
    }
    else if(opcion == 3){
        micubo.draw_fill();
    }
    else if(opcion == 4){
        micubo.draw_chess();
    }
    glPopMatrix();

    glPushMatrix();
    micentro.draw(opcion,revol);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1+(0.25/sqrt(2)),1.5-(0.25/sqrt(2)),0);
    glRotatef(45+mov,0,0,1);
    mibrazosoporte.draw(opcion,revol);
    glPopMatrix();
    revol = true;
    glPushMatrix();
    glTranslatef(1-(0.25/sqrt(2)),1.5-(0.25/sqrt(2))+5-(mov/10),0);
    glRotatef(-135+mov,0,0,1);
    mibrazosoporte.draw(opcion,revol);
    glPopMatrix();


}
