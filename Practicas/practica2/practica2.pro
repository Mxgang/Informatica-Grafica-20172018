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
    esfera.h

SOURCES = \
    practica2.cc \
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
    esfera.cpp

LIBS += -L/casa/dmartin/codigo/funciontecas/freeglut/lib \
    -lglut

CONFIG += console
QT += opengl


