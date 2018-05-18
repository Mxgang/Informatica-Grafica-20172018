#include "fuenteluz.h"
void FuenteLuz::activarFuente(){
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);
    glEnable(GL_LIGHTING);
    glEnable(indice_luz);
    glEnable(GL_DEPTH_TEST);

    glLightfv(indice_luz, GL_POSITION, (GLfloat *) &posicion);
    glLightfv(indice_luz, GL_AMBIENT, (GLfloat *) &color);
    glLightfv(indice_luz, GL_SPECULAR, (GLfloat *) &color);
    glLightfv(indice_luz, GL_DIFFUSE, (GLfloat *) &color);
}

void FuenteLuz::desactivarFuente(){
    glDisable(GL_LIGHTING);
    glDisable(indice_luz);
}

void FuenteLuz::cambiarColor(float r, float g, float b){
    color[0] = r;
    color[1] = g;
    color[2] = b;
    glLightfv(indice_luz, GL_AMBIENT, (GLfloat *) &color);
    glLightfv(indice_luz, GL_SPECULAR, (GLfloat *) &color);
    glLightfv(indice_luz, GL_DIFFUSE, (GLfloat *) &color);
}

