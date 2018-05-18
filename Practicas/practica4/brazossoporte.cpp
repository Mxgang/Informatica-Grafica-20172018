#include "brazossoporte.h"

BrazosSoporte::BrazosSoporte()
{

}

void BrazosSoporte::draw(int opcion, bool revol, int shade){

    glMatrixMode(GL_MODELVIEW);
    // base
    glPushMatrix();
    if(!revol){
        micilindro.revolucion(10);
    }
    glTranslatef(0,1.75,0); //cambiar el ejeX
    glScalef(0.25,3.5,0.25);

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
