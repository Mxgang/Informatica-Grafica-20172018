#include "tetraedro.h"

Tetraedro::Tetraedro(){

    vertices.resize(4);
    triangles.resize(4);

    vertices[0] = _vertex3f(0,0.5,0);
    vertices[1] = _vertex3f(0,-0.5,-0.5);
    vertices[2] = _vertex3f(-0.5,-0.5,0.5);
    vertices[3] = _vertex3f(0.5,-0.5,0.5);

    triangles[0] = _vertex3i(1,3,2);
    triangles[1] = _vertex3i(0,3,1);
    triangles[2] = _vertex3i(0,2,3);
    triangles[3] = _vertex3i(0,1,2);
}

Tetraedro::~Tetraedro(){
    triangles.clear();
    vertices.clear();
}

