#include "base.h"


Base::Base()
{

}

void Base::draw(int opcion, bool revol, int giro, double mov){

    glMatrixMode(GL_MODELVIEW);
    // base
    glPushMatrix();
    glTranslatef(0,0.5,0);
    glScalef(8,1,8);


    if(opcion == 1){
        otrocubo.draw_points();

    }
    else if(opcion == 2){
        otrocubo.draw_lines();
    }
    else if(opcion == 3){
        otrocubo.draw_fill();
    }
    else if(opcion == 4){
        otrocubo.draw_chess();
    }

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1,0);
    brazo_central.draw(opcion,revol,giro,mov);
    glPopMatrix();


}

