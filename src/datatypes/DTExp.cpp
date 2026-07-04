#include "DTExp.h"

DTExp::DTExp(float lambda) {
    this->lambda = lambda;
}

float DTExp::getLambda() const {
    return lambda;
}