#include "DTPois.h"

DTPois::DTPois(float lambda) {
    this->lambda = lambda;
}

float DTPois::getLambda() const {
    return lambda;
}