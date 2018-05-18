#include "coordenadas_textura.h"

CoordenadasTextura::CoordenadasTextura(){
}

void CoordenadasTextura::sets(float s_){
    s = s_;
}
void CoordenadasTextura::sett(float t_){
    t = t_;
}


float CoordenadasTextura::gets(){
    return s;
}
float CoordenadasTextura::gett(){
    return t;
}
