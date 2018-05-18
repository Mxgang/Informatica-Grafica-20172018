HEADERS = \ 
    O3D.h \
    O3DS.h \
    cubo.h \
    tetraedro.h \
    vertex.h \
    O3DR.h \
    O3DPLY.h \
    cilindro.h \
    vaso.h \
    vaso_inverso.h \
    cono.h \
    tubo.h \
    base.h \
    brazocentral.h \
    soporte.h \
    brazossoporte.h \
    partecentralsup.h \
    brazos.h \
    partecentral.h \
    esfera.h \
    tablero.h

SOURCES = \
    practica4.cc \
    cubo.cpp \
    O3D.cpp \
    O3DS.cpp \
    tetraedro.cpp \
    O3DPLY.cpp \
    O3DR.cpp \
    cilindro.cpp \
    vaso.cpp \
    vaso_inverso.cpp \
    cono.cpp \
    tubo.cpp \
    base.cpp \
    brazocentral.cpp \
    soporte.cpp \
    brazossoporte.cpp \
    partecentralsup.cpp \
    brazos.cpp \
    partecentral.cpp \
    esfera.cpp \
    tablero.cpp

LIBS += -L/casa/dmartin/codigo/funciontecas/freeglut/lib \
    -lglut

CONFIG += console
QT += opengl


