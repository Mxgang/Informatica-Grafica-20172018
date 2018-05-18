#ifndef O3D_H
#define O3D_H

#include <vector>
#include <O3DS.h>
#include <GL/glut.h>
#include <QImage>
#include <iostream>



using namespace std;

class O3D : public O3DS{

protected:

    vector<_vertex3i> triangles;
    vector<_vertex3f> normales;
    vector<_vertex3f> normales_vertices;
    QImage Imagen;


public:

    void draw_lines();
    void draw_fill(int shade);
    void draw_chess();
    _vertex3f producto_vectorial(_vertex3f a, _vertex3f b);
    float producto_escalar(_vertex3f v1, _vertex3f v2);
    void cargar_textura(bool cargado);



};

#endif
