#include "tablero.h"

Tablero::Tablero(){

        vertices.resize(4);
        triangles.resize(2);

        vertices[0] =_vertex3f(-0.5,-0.5,0.5);
        vertices[1] =_vertex3f(0.5,-0.5,0.5);
        vertices[2] =_vertex3f(0.5,0.5,0.5);
        vertices[3] =_vertex3f(-0.5,0.5,0.5);


        triangles[0] = _vertex3i(0,1,3);
        triangles[1] = _vertex3i(1,2,3);

    }
Tablero::~Tablero(){
        triangles.clear();
        vertices.clear();
}
