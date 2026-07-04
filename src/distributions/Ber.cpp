#include "Ber.h"

Ber::Ber(float p) {
    if(p < 0 || p > 1){
        throw ParametroInvalidoException("La probabilidad debe pertenecer al intervalo [0,1]");
    }
    this->p = p;
}

float Ber::esperanza() const {
    return p;
}
float Ber::varianza() const {
    return p*(1-p);
}
float Ber::evaluar(float x) const {
    if(x = 1){
        return p;
    }
    if(x = 0){
        return 1-p;
    }
    return 0;
}
float Ber::distribucionAcumulada(float x) const {
    if(x < 0){
        return 0;
    }
    if(x < 1){
        return 1-p;
    }
    return 1;
}