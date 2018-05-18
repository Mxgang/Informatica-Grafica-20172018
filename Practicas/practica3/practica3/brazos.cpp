#include "brazos.h"

Brazos::Brazos()
{

}

void Brazos::draw(int opcion, bool revol, bool centrado){


    glMatrixMode(GL_MODELVIEW);
    // brazos
    glPushMatrix();
    if(!revol){
        micilindro.revolucion(15);
        revol=true;
    }
    glTranslatef(0,-3,0);
    glScalef(0.5,6,0.5);
    if(opcion == 1){
        micilindro.draw_points();

    }
    else if(opcion == 2){
        micilindro.draw_lines();
    }
    else if(opcion == 3){
        micilindro.draw_fill();
    }
    else if(opcion == 4){
        micilindro.draw_chess();
    }
    glPopMatrix();


    glMatrixMode(GL_MODELVIEW);
    // esfera
    glPushMatrix();
    if(!revol){
        miesfera.revolucion(30);
    }
    glTranslatef(0,-6,0);
    glScalef(1.25,1.25,1.25);
    if(opcion == 1){
        miesfera.draw_points();

    }
    else if(opcion == 2){
        miesfera.draw_lines();
    }
    else if(opcion == 3){
        miesfera.draw_fill();
    }
    else if(opcion == 4){
        miesfera.draw_chess();
    }
    glPopMatrix();


    glMatrixMode(GL_MODELVIEW);
    // Beethoven
    if(abierto){
        objeto.open("beethoven.ply");
        abierto = false;
    }
    glPushMatrix();

    if(centrado){ //izquierda
        glTranslatef(-1.75,-4.75,0);
        glRotatef(45,0,0,1);
    }
    else{ //derecha
        glTranslatef(1.5,-7.5,0);
        glRotatef(-135,0,0,1);
    }
    glScalef(0.25,0.25,0.25);
    if(opcion == 1){
        objeto.draw_points();

    }
    else if(opcion == 2){
       objeto.draw_lines();
    }
    else if(opcion == 3){
        objeto.draw_fill();
    }
    else if(opcion == 4){
        objeto.draw_chess();
    }
    glPopMatrix();


}
