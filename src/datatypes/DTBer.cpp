#include "DTBer.h"

DTBer::DTBer(float p) {
    if(p < 0 || p > 1){
        throw ParametroInvalidoException("La probabilidad debe pertenecer al intervalo [0,1]");
    }
    this->p = p;
}

float DTBer::getP() const {
    return p;
}