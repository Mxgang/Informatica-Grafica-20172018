//**************************************************************************
// Práctica 1
//
// Domingo Martin Perandres 2013-2016
//
// GPL
//**************************************************************************


#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include <vector>
#include <cubo.h>
#include <tetraedro.h>
#include <cilindro.h>
#include <cono.h>
#include <tubo.h>
#include <vaso.h>
#include <vaso_inverso.h>
#include <O3DPLY.h>
#include <base.h>

using namespace std;

// tamaño de los ejes
const int AXIS_SIZE=5000;
bool leido = false;
O3DPLY objeto;
Cubo cubo;
Tetraedro tetraedro;
cilindro micilindro;
cono micono;
tubo mitubo;
vaso mivaso;
vaso_inverso mivaso_inverso;
Base mibase;
bool girando = false;
int estado = 0;
double giro = 0;
double mov = -1;
bool revol = false;
int act1, act2, act3, act4, act5, act6, act7, act8 = 0;

int caso = 0;
int poligono = 1;

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Window_width,Window_height,Front_plane,Back_plane;

// variables que determninan la posicion y tamaño de la ventana X
int UI_window_pos_x=50,UI_window_pos_y=50,UI_window_width=500,UI_window_height=500;


void clear_window()
{

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void change_projection()
{

glMatrixMode(GL_PROJECTION);
glLoadIdentity();

// formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
//  Front_plane>0  Back_plane>PlanoDelantero)
glFrustum(-Window_width,Window_width,-Window_height,Window_height,Front_plane,Back_plane);
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void change_observer()
{

// posicion del observador
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0,0,-Observer_distance);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(Observer_angle_y,0,1,0);
}

//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void draw_axis()
{
glBegin(GL_LINES);
// eje X, color rojo
glColor3f(1,0,0);
glVertex3f(-AXIS_SIZE,0,0);
glVertex3f(AXIS_SIZE,0,0);
// eje Y, color verde
glColor3f(0,1,0);
glVertex3f(0,-AXIS_SIZE,0);
glVertex3f(0,AXIS_SIZE,0);
// eje Z, color azul
glColor3f(0,0,1);
glVertex3f(0,0,-AXIS_SIZE);
glVertex3f(0,0,AXIS_SIZE);
glEnd();
}


//**************************************************************************
// Funcion que dibuja los objetos
//***************************************************************************

void draw_objects()
{

    glPointSize(4);
    if(poligono == 1){

        switch(caso){

                case 1: cubo.draw_points();break;
                case 2: cubo.draw_lines();break;
                case 3: cubo.draw_fill();break;
                case 4: cubo.draw_chess();break;



        }
    }
    else if(poligono == 2){
        switch(caso){
                case 1: tetraedro.draw_points();break;
                case 2: tetraedro.draw_lines();break;
                case 3: tetraedro.draw_fill();break;
                case 4: tetraedro.draw_chess();break;
        }
    }
    else if(poligono == 3){

        if(leido==true){

            cout << "Introduzca el nombre del archivo PLY" << endl;
            string nombreArchivo;
            cin >> nombreArchivo;
            objeto.open(nombreArchivo);
            leido = false;
            objeto.close();
          }
        switch(caso){
            case 1: objeto.draw_points();break;
            case 2: objeto.draw_lines();break;
            case 3: objeto.draw_fill();break;
            case 4: objeto.draw_chess();break;

        }
    }
    else if(poligono == 4){

        switch(caso){
            case 1: micilindro.draw_points();break;
            case 2: micilindro.draw_lines();break;
            case 3: micilindro.draw_fill();break;
            case 4: micilindro.draw_chess();break;
         }
    }
    else if(poligono == 5){
        switch(caso){
            case 1: micono.draw_points();break;
            case 2: micono.draw_lines();break;
            case 3: micono.draw_fill();break;
            case 4: micono.draw_chess();break;
         }
    }
    else if(poligono == 6){
        switch(caso){
            case 1: mitubo.draw_points();break;
            case 2: mitubo.draw_lines();break;
            case 3: mitubo.draw_fill();break;
            case 4: mitubo.draw_chess();break;
         }
    }
    else if(poligono == 7){
        switch(caso){
            case 1: mivaso.draw_points();break;
            case 2: mivaso.draw_lines();break;
            case 3: mivaso.draw_fill();break;
            case 4: mivaso.draw_chess();break;
         }
    }
    else if(poligono == 8){
        switch(caso){
            case 1: mivaso_inverso.draw_points();break;
            case 2: mivaso_inverso.draw_lines();break;
            case 3: mivaso_inverso.draw_fill();break;
            case 4: mivaso_inverso.draw_chess();break;
         }
    }
    else if(poligono == 9){

        switch(caso){
            case 1: mibase.draw(1,revol,giro,mov);revol=true;estado=1;break;
            case 2: mibase.draw(2,revol,giro,mov);revol=true;estado=2;break;
            case 3: mibase.draw(3,revol,giro,mov);revol=true;estado=3;break;
            case 4: mibase.draw(4,revol,giro,mov);revol=true;estado=4;break;
            case 14:mibase.draw(estado,revol,giro,mov);revol=true;break;
            case 15:mibase.draw(estado,revol,giro,mov);revol=true;break;
            case 16:for(int i = 0; i < 9999; i=i){
                giro = (giro+1+(mov/20));
                mibase.draw(estado,revol,giro,mov);revol=true;break;
            }
            case 17:for(int i = 0; i < 9999; i=i){
                giro = (giro+1+(mov/20));
                mibase.draw(estado,revol,giro,mov);revol=true;break;
            }
            case 18:
                mibase.draw(estado,revol,giro,mov);revol=true;break;
            case 19:
                mibase.draw(estado,revol,giro,mov);revol=true;break;
            case 20:for(int i = 0; i < 9999; i=i){
                giro = (giro+1+(mov/20));
                mibase.draw(estado,revol,giro,mov);revol=true;break;
            }

         }

    }
glutPostRedisplay();
}

//**************************************************************************
//
//***************************************************************************

void draw_scene(void)
{

clear_window();
change_observer();
draw_axis();
draw_objects();
glutSwapBuffers();
}



//***************************************************************************
// Funcion llamada cuando se produce un cambio en el tamaño de la ventana
//
// el evento manda a la funcion:
// nuevo ancho
// nuevo alto
//***************************************************************************

void change_window_size(int Ancho1,int Alto1)
{
change_projection();
glViewport(0,0,Ancho1,Alto1);
glutPostRedisplay();
}


//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla normal
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton
//***************************************************************************

void normal_keys(unsigned char Tecla1,int x,int y)
{

    switch (toupper(Tecla1)) {

        case 'Q': exit(0); break;
        case 'W': caso = 1;draw_objects();break; //modo puntos
        case 'E': caso = 2;draw_objects();break; //modo líneas
        case 'R': caso = 3;draw_objects();break; //modo sólido
        case 'T': caso = 4;draw_objects();break; //modo ajedrez
        case 'Y': caso = 5; if(poligono==1)poligono = 2; else poligono = 1;draw_objects();break; //cambiar de cubo a tetraedro
        case 'A': caso = 7;draw_objects();poligono = 3;leido=true;break; //PLY
        case '1': caso = 8;draw_objects();poligono = 4; if(act1 == 0){micilindro.revolucion(30); act1=1;};break; //cilindro
        case '2': caso = 9;draw_objects();poligono = 5;if(act2 == 0){micono.revolucion(30); act2=1;};break; //cono
        case '3': caso = 10;draw_objects();poligono = 6;if(act3 == 0){mitubo.revolucion(30); act3=1;};break; //tubo
        case '4': caso = 11;draw_objects();poligono = 7;if(act4 == 0){mivaso.revolucion(30); act4=1;};break; //vaso
        case '5': caso = 12;draw_objects();poligono = 8;if(act5 == 0){mivaso_inverso.revolucion(30); act5=1;};break; //vaso inverso
        case '6': caso = 13;draw_objects();poligono = 9;if(act6 == 0){act6=1;};break; //dibujar regulador
        case 'G': caso = 14;giro = (giro+1)+(mov/5);break; //girar manualmente
        case 'H': caso = 15;giro = (giro-1)-(mov/5);break;
        case 'B': caso = 16;if(mov<35)mov++;break; //girar y mover arriba
        case 'N': caso = 17;mov--;break; //girar y mover abajo
        case 'K': caso = 18;if(mov<35)mov++;break; //mover arriba en manualmente
        case 'L': caso = 19;mov--;break; //mover abajo manualmente
        case 'V': caso = 20;break; //solo girar
    }
}

//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla especial
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton

//***************************************************************************

void special_keys(int Tecla1,int x,int y)
{

switch (Tecla1){
    case GLUT_KEY_LEFT:Observer_angle_y--;break;
    case GLUT_KEY_RIGHT:Observer_angle_y++;break;
    case GLUT_KEY_UP:Observer_angle_x--;break;
    case GLUT_KEY_DOWN:Observer_angle_x++;break;
    case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
    case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
    }
glutPostRedisplay();
}



//***************************************************************************
// Funcion de incializacion
//***************************************************************************

void initialize(void)
{
// se inicalizan la ventana y los planos de corte
Window_width=5;
Window_height=5;
Front_plane=10;
Back_plane=1000;

// se inicia la posicion del observador, en el eje z
Observer_distance=2*Front_plane;
Observer_angle_x=0;
Observer_angle_y=0;

// se indica cual sera el color para limpiar la ventana	(r,v,a,al)
// blanco=(1,1,1,1) rojo=(1,0,0,1), ...
glClearColor(1,1,1,1);

// se habilita el z-bufer
glEnable(GL_DEPTH_TEST);
//
change_projection();
//
glViewport(0,0,UI_window_width,UI_window_height);
}


//***************************************************************************
// Programa principal
//
// Se encarga de iniciar la ventana, asignar las funciones e comenzar el
// bucle de eventos
//***************************************************************************

int main(int argc, char **argv)
{

// se llama a la inicialización de glut
glutInit(&argc, argv);

// se indica las caracteristicas que se desean para la visualización con OpenGL
// Las posibilidades son:
// GLUT_SIMPLE -> memoria de imagen simple
// GLUT_DOUBLE -> memoria de imagen doble
// GLUT_INDEX -> memoria de imagen con color indizado
// GLUT_RGB -> memoria de imagen con componentes rojo, verde y azul para cada pixel
// GLUT_RGBA -> memoria de imagen con componentes rojo, verde, azul y alfa para cada pixel
// GLUT_DEPTH -> memoria de profundidad o z-bufer
// GLUT_STENCIL -> memoria de estarcido
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

// posicion de la esquina inferior izquierdad de la ventana
glutInitWindowPosition(UI_window_pos_x,UI_window_pos_y);

// tamaño de la ventana (ancho y alto)
glutInitWindowSize(UI_window_width,UI_window_height);

// llamada para crear la ventana, indicando el titulo (no se visualiza hasta que se llama
// al bucle de eventos)
glutCreateWindow("Práctica 1");


// asignación de la funcion llamada "dibujar" al evento de dibujo
glutDisplayFunc(draw_scene);
// asignación de la funcion llamada "cambiar_tamanio_ventana" al evento correspondiente
glutReshapeFunc(change_window_size);
// asignación de la funcion llamada "tecla_normal" al evento correspondiente
glutKeyboardFunc(normal_keys);
// asignación de la funcion llamada "tecla_Especial" al evento correspondiente
glutSpecialFunc(special_keys);

// funcion de inicialización
initialize();

// inicio del bucle de eventos
glutMainLoop();
return 0;
}

