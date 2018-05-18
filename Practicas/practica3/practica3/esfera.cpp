#include "esfera.h"
#include "vertex.h"


esfera::esfera(){

    _vertex3f vertice;
              double increRad = M_PI / 10;
              double radio = 0.5;

               int i = 0;
                 _vertex3i triangulo;

                for( double teta = 0; teta < M_PI; teta += increRad){
                    for( double phi = 0; phi < 2*M_PI; phi += increRad){


                   vertice.z =(radio)*((float) sin(teta))*((float)cos(phi));
                   vertice.x =(radio)*((float) sin(teta))*((float)sin(phi));
                   vertice.y =(radio)*((float) cos(teta));


                   vertices.push_back( vertice );

                   //VERTICE 2
                   vertice.z =(radio)*((float) sin(teta+increRad))*((float)cos(phi));
                   vertice.x =(radio)*((float) sin(teta+increRad))*((float)sin(phi));
                   vertice.y =(radio)*((float) cos(teta+increRad));

                   vertices.push_back( vertice );

                   //VERTICE 3
                   vertice.z =(radio)*((float) sin(teta+increRad))*((float)cos(phi+increRad));
                   vertice.x =(radio)*((float) sin(teta+increRad))*((float)sin(phi+increRad));
                   vertice.y =(radio)*((float) cos(teta+increRad));

                   vertices.push_back( vertice );

                   //VERTICE 4
                   vertice.z =(radio)*((float) sin(teta))*((float)cos(phi+increRad));
                   vertice.x =(radio)*((float) sin(teta))*((float)sin(phi+increRad));
                   vertice.y =(radio)*((float) cos(teta));

                   vertices.push_back( vertice );

                   triangulo( i, i + 1, i + 2);
                   triangles.push_back( triangulo );
                   triangulo( i, i +2, i +3 );
                   triangles.push_back( triangulo );
                   i += 4;

                    }
                }



    }


esfera::~esfera(){
    vertices.clear();
}
