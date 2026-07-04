#include "DTBin.h"

DTBin::DTBin(int n,float p) {
    this->n = n;
    this->p = p;
}

int DTBin::getN() const {
    return n;
}
float DTBin::getP() const {
    return p;
}