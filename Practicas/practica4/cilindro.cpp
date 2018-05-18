#include "cilindro.h"

cilindro::cilindro(){
    vertices.resize(4);

    vertices[0] = _vertex3f(0,0.5,0);
    vertices[1] = _vertex3f(0.5,0.5,0);
    vertices[2] = _vertex3f(0.5,-0.5,0);
    vertices[3] = _vertex3f(0,-0.5,0);


}

cilindro::~cilindro(){
    vertices.clear();
}
