#include "cubo.h"

Cubo::Cubo(){

		vertices.resize(8);
        triangles.resize(12);

        vertices[0] =_vertex3f(-0.5,-0.5,0.5);
        vertices[1] =_vertex3f(0.5,-0.5,0.5);
        vertices[2] =_vertex3f(0.5,0.5,0.5);
        vertices[3] =_vertex3f(-0.5,0.5,0.5);
        vertices[4] =_vertex3f(0.5,0.5,-0.5);
        vertices[5] =_vertex3f(-0.5,0.5,-0.5);
        vertices[6] =_vertex3f(-0.5,-0.5,-0.5);
        vertices[7] =_vertex3f(0.5,-0.5,-0.5);

        triangles[0] = _vertex3i(0,1,3);
        triangles[1] = _vertex3i(1,2,3);
        triangles[2] = _vertex3i(1,7,2);
        triangles[3] = _vertex3i(7,4,2);
        triangles[4] = _vertex3i(7,6,4);
        triangles[5] = _vertex3i(6,5,4);
        triangles[6] = _vertex3i(6,0,5);
        triangles[7] = _vertex3i(0,3,5);
        triangles[8] = _vertex3i(3,2,5);
        triangles[9] = _vertex3i(2,4,5);
        triangles[10] = _vertex3i(6,1,0);
        triangles[11] = _vertex3i(6,7,1);
	}
Cubo::~Cubo(){
        triangles.clear();
        vertices.clear();
}

