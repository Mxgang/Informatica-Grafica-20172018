#include "O3DR.h"
#include <GL/glut.h>
#include <cmath>


void O3DR::revolucion(int num_caras)
{

    _vertex3f aux;
    double angulo = (2 * M_PI)/num_caras;
    double angulo_aux = (2 * M_PI)/num_caras;

    int tamanio = vertices.size();
    for(int i = 0; i < num_caras; i++){
        for(int j = 0; j < tamanio;j++){
            aux.x =  vertices[j].x * cos(angulo);
            aux.z =  vertices[j].x * sin(angulo);
            aux.y  = vertices[j].y;
            vertices.push_back(aux);
        }
        angulo += angulo_aux;
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








/*
 // TAPAS (en el caso que tenga que poner tapas al tubo o a los vasos)
    for(int i = 0; i < num_caras; i++){
           triangles.push_back(_vertex3i(vertices.size()-2,tamanio*i,tamanio*(i+1))); //Caras inferiores tapa
    }
    for(int i = 0; i < num_caras; i++){
           triangles.push_back(_vertex3i(vertices.size()-1,tamanio*i + tamanio-1,(tamanio*(i+1))+ tamanio-1)); //Caras superiores tapa

    }
*/


/*void O3DR::draw_barrido(int vueltas) //INTENTO FALLIDO
{

    int tamanio = vertices.size();
    for(int i = 0; i < tamanio; i++){

        double incr_angulo = (2 * M_PI)/vueltas;

        for(int j = 0; j < vueltas; j++){
            double angulo = j * incr_angulo;
            double x1 = 0;
            double z1 = 0;
            if(vertices[i].x != 0){
                x1 = vertices[i].x * cos(angulo);
            }
            z1 = vertices[i].x * sin(angulo);
            vertices.push_back(_vertex3f(x1,vertices[i].y,z1));
        }

    }

    int indice = 0;
    for(int i = 0; i < vueltas; i++){
        for(int j = 0; j < vertices.size()-1; j++){

            triangles.push_back(_vertex3i(j,j+1,vueltas+j));
            triangles.push_back(_vertex3i(j+1,vueltas+j,vueltas+j+1));
        }
    }


}*/

