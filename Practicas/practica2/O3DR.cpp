#include "O3DR.h"
#include <GL/glut.h>
#include <cmath>


void O3DR::revolucion(int num_caras)
{

    _vertex3f aux;


    int inicial = 45;
    int final = 120;

    //Ángulo en el que comienza
    //double angulo_inicial = (inicial*M_PI)/180;
    //número de veces a incrementar (120 es el angulo final y 45 el inicial)
    //double new_angulo = (((final-inicial)*M_PI)/180)/num_caras;

    //360 grados
    double angulo_inicial = (2 * M_PI)/num_caras;
    double new_angulo = (2 * M_PI)/num_caras;

    int tamanio = vertices.size();
    for(int i = 0; i < num_caras; i++){
        for(int j = 0; j < tamanio;j++){
            aux.x =  vertices[j].x * cos(angulo_inicial);
            aux.z =  vertices[j].x * sin(angulo_inicial);
            aux.y  = vertices[j].y;
            vertices.push_back(aux);
        }
        angulo_inicial += new_angulo;
    }

    int indice=0;

    for(int i = 0; i < num_caras; i++){
        for(int j = 0; j < tamanio - 1; j++){
            indice = (i * tamanio) + j; // Numero de caras
            triangles.push_back(_vertex3i(indice,indice+tamanio,indice+1)); //Caras superiores
            triangles.push_back(_vertex3i(indice+1,indice+tamanio,indice+1+tamanio)); //Caras inferiores
        }

    }


}



