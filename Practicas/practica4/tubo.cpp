#include "tubo.h"

tubo::tubo()
{
    vertices.resize(2);

    vertices[0] = _vertex3f(0.5,0.5,0);
    vertices[1] = _vertex3f(0.5,-0.5,0);

}

tubo::~tubo(){

    vertices.clear();
}
