#include "DTBinNeg.h"

DTBinNeg::DTBinNeg(int r,float p) {
    this->r = r;
    this->p = p;
}

int DTBinNeg::getR() const {
    return r;
}
float DTBinNeg::getP() const {
    return p;
}