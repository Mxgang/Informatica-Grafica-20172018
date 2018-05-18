#include "cono.h"

cono::cono()
{
    vertices.resize(3);

    vertices[0] = _vertex3f(0,-0.5,0);
    vertices[1] = _vertex3f(0.5,-0.5,0);
    vertices[2] = _vertex3f(0,0.5,0);

}

cono::~cono(){
    vertices.clear();
}

