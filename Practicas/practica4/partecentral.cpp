#include "partecentral.h"

ParteCentral::ParteCentral()
{

}

void ParteCentral::draw(int opcion, bool revol,int shade){

    glMatrixMode(GL_MODELVIEW);
    if(!revol){
        micilindro.revolucion(30);
    }
    // parte central
    glPushMatrix();
    glTranslatef(0,0.75,0);
    glScalef(2,1.5,2);
    if(opcion == 1){
        micilindro.draw_points();

    }
    else if(opcion == 2){
        micilindro.draw_lines();
    }
    else if(opcion == 3){
        micilindro.draw_fill(shade);
    }
    else if(opcion == 4){
        micilindro.draw_chess();
    }
    glPopMatrix();
}
