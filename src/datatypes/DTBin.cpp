#include "datatypes/DTBin.h"

DTBin::DTBin(unsigned int n,float p) {
    if(p < 0 || p > 1){
        throw ParametroInvalidoException("La probabilidad debe pertenecer al intervalo [0,1]");
    }
    this->n = n;
    this->p = p;
}

unsigned int DTBin::getN() const {
    return n;
}
float DTBin::getP() const {
    return p;
}