#include "esfera.h"
#include <cmath>

esfera::esfera()
{
    int tamanio = 52;
    vertices.resize(tamanio);

    double incr_angulo = 90/tamanio;
    double angulo = 0;

    //punto inicial
    vertices[0] = _vertex3f(0,-0.5,0);

    for(int i = 1; i < tamanio-1; i++){
            vertices[i] = _vertex3f(cos(angulo)*0.5,-sin(angulo)*0.5,0);
            vertices[i] = _vertex3f(cos(angulo)*0.5,sin(angulo)*0.5,0);

            angulo+=incr_angulo;
    }
    //punto final
    vertices[tamanio-1] = _vertex3f(0,0.5,0);

}

esfera::~esfera(){
    vertices.clear();
}
