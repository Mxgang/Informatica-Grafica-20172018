#include "brazocentral.h"

BrazoCentral::BrazoCentral()
{

}

void BrazoCentral::draw(int opcion, bool revol, int giro, double mov){

    glMatrixMode(GL_MODELVIEW);
    // base
    glPushMatrix();
    glTranslatef(0,6,0);
    glScalef(0.5,12,0.5);
    if(!revol){
        otrocilindro.revolucion(15);
    }

    if(opcion == 1){
        otrocilindro.draw_points();

    }
    else if(opcion == 2){
        otrocilindro.draw_lines();
    }
    else if(opcion == 3){
        otrocilindro.draw_fill();
    }
    else if(opcion == 4){
        otrocilindro.draw_chess();
    }


    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,6+(mov/10),0);
    glRotatef(giro,0,1,0);
    misoporte.draw(opcion,revol,mov);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0,12,0);
    glRotatef(giro,0,1,0);
    mipartesup.draw(opcion,revol,mov);
    glPopMatrix();


}

