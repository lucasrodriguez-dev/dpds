#include "DTBinNeg.h"

DTBinNeg::DTBinNeg(unsigned int r,float p) {
    if(r < 1){
        throw ParametroInvalidoException("La cantidad de éxitos debe ser mayor o igual que 1");
    }
    if(p < 0 || p > 1){
        throw ParametroInvalidoException("La probabilidad debe pertenecer al intervalo [0,1]");
    }
    this->r = r;
    this->p = p;
}

unsigned int DTBinNeg::getR() const {
    return r;
}
float DTBinNeg::getP() const {
    return p;
}