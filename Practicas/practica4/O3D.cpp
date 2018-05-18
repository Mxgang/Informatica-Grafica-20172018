#include "O3D.h"
#include <GL/glut.h>



void O3D::draw_lines(){
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

    glBegin(GL_TRIANGLES);
        glColor3f(0,1,0);
        for(int i = 0; i < triangles.size(); i++){
            glVertex3f(vertices[triangles[i]._0].x,vertices[triangles[i]._0].y,vertices[triangles[i]._0].z);
            glVertex3f(vertices[triangles[i]._1].x,vertices[triangles[i]._1].y,vertices[triangles[i]._1].z);
            glVertex3f(vertices[triangles[i]._2].x,vertices[triangles[i]._2].y,vertices[triangles[i]._2].z);

		}

		
	glEnd();
}

void O3D::draw_fill(int shade){
    glPolygonMode(GL_FRONT,GL_FILL);

        glBegin(GL_TRIANGLES);

            vector<_vertex3f> sum;
            vector<double> confluyentes;
            sum.resize(vertices.size());
            confluyentes.resize(vertices.size());

            for (unsigned int i=0;i<triangles.size();i++){
                _vertex3f v1(vertices[triangles[i]._0].x,vertices[triangles[i]._0].y,vertices[triangles[i]._0].z);
                _vertex3f v2(vertices[triangles[i]._1].x,vertices[triangles[i]._1].y,vertices[triangles[i]._1].z);
                _vertex3f v3(vertices[triangles[i]._2].x,vertices[triangles[i]._2].y,vertices[triangles[i]._2].z);
                _vertex3f vector1(v2.x-v1.x, v2.y-v1.y, v2.z-v1.z);
                _vertex3f vector2(v3.x-v1.x, v3.y-v1.y, v3.z-v1.z);
                _vertex3f normal = producto_vectorial(vector1,vector2);

                if(producto_escalar(normal, v1) < 0.0)
                {
                    normal.x = -normal.x;
                    normal.y = -normal.y;
                    normal.z = -normal.z;
                }

                normales.push_back(normal.normalize());

                if(shade == 1)
                {
                    glNormal3f(normales[i].x,normales[i].y,normales[i].z);
                }
                if(shade != 2)
                {

                    glVertex3f(v1.x, v1.y, v1.z);
                    glVertex3f(v2.x, v2.y, v2.z);
                    glVertex3f(v3.x, v3.y, v3.z);
                }
            }

            if(shade==2)
            {
                for(unsigned int i=0; i<triangles.size(); i++)
                {
                    sum[triangles[i]._0].x+=normales[i].x;
                    sum[triangles[i]._0].y+=normales[i].y;
                    sum[triangles[i]._0].z+=normales[i].z;

                    confluyentes[triangles[i]._0]++;

                    sum[triangles[i]._1].x+=normales[i].x;
                    sum[triangles[i]._1].y+=normales[i].y;
                    sum[triangles[i]._1].z+=normales[i].z;

                    confluyentes[triangles[i]._1]++;

                    sum[triangles[i]._2].x+=normales[i].x;
                    sum[triangles[i]._2].y+=normales[i].y;
                    sum[triangles[i]._2].z+=normales[i].z;

                    confluyentes[triangles[i]._2]++;
                }

                for(int k=0; k<sum.size(); ++k)
                {
                    _vertex3f normal_vertice(sum[k].x/confluyentes[k],sum[k].y/confluyentes[k],sum[k].z/confluyentes[k]);
                    normales_vertices.push_back(normal_vertice.normalize());
                }

                for (unsigned int i=0;i<triangles.size();i++){

                    _vertex3f v1(vertices[triangles[i]._0].x,vertices[triangles[i]._0].y,vertices[triangles[i]._0].z);
                    _vertex3f v2(vertices[triangles[i]._1].x,vertices[triangles[i]._1].y,vertices[triangles[i]._1].z);
                    _vertex3f v3(vertices[triangles[i]._2].x,vertices[triangles[i]._2].y,vertices[triangles[i]._2].z);

                    glNormal3f(normales_vertices[triangles[i]._0].x, normales_vertices[triangles[i]._0].y, normales_vertices[triangles[i]._0].z);
                    glVertex3f(v1.x, v1.y, v1.z);
                    glNormal3f(normales_vertices[triangles[i]._1].x, normales_vertices[triangles[i]._1].y, normales_vertices[triangles[i]._1].z);
                    glVertex3f(v2.x, v2.y, v2.z);
                    glNormal3f(normales_vertices[triangles[i]._2].x, normales_vertices[triangles[i]._2].y, normales_vertices[triangles[i]._2].z);
                    glVertex3f(v3.x, v3.y, v3.z);
                }
            }
        glEnd();
}//funcion







void O3D::draw_chess(){
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_TRIANGLES);

            for(int i = 0; i < triangles.size(); i++){
                if(i%2==0)
                    glColor3f(1,0,0);
                else
                    glColor3f(0,1,0);
                glVertex3f(vertices[triangles[i]._0].x,vertices[triangles[i]._0].y,vertices[triangles[i]._0].z),
                glVertex3f(vertices[triangles[i]._1].x,vertices[triangles[i]._1].y,vertices[triangles[i]._1].z),
                glVertex3f(vertices[triangles[i]._2].x,vertices[triangles[i]._2].y,vertices[triangles[i]._2].z);
            }

    glEnd();
}


_vertex3f O3D::producto_vectorial(_vertex3f a, _vertex3f b){
    _vertex3f N;
    N.x = a.y * b.z - a.z * b.y;
    N.y = a.z * b.x - a.x * b.z;
    N.z = a.x * b.y - a.y * b.x;

    return N;
}
float O3D::producto_escalar(_vertex3f v1, _vertex3f v2)
{
    return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

void O3D::cargar_textura(bool cargado) {
    //CARGAR TEXTURA
    if (!cargado){
        if (Imagen.load("tierra.jpg")==false) cout << "Image not loaded" << endl;

        // reflejo vertical
        Imagen=Imagen.mirrored(false,true);
        //

        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        // parametros de aplicacion de la textura
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
        // asignacion de la textura
        glTexImage2D(GL_TEXTURE_2D,0,4,Imagen.width(),Imagen.height(),0,GL_BGRA,GL_UNSIGNED_BYTE,Imagen.bits());

        glEnable(GL_TEXTURE_2D);
    }



    glBegin(GL_QUADS);
        glTexCoord2f(0,0);
        glVertex3f(-0.5,-0.5,0.5);
        glTexCoord2f(1,0);
        glVertex3f(0.5,-0.5,0.5);
        glTexCoord2f(1,1);
        glVertex3f(0.5,0.5,0.5);
        glTexCoord2f(0,1);
        glVertex3f(-0.5,0.5,0.5);
        glEnd();








}


