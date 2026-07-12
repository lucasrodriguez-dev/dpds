#include "datatypes/DTNormal.h"

DTNormal::DTNormal(float mu, float sigmaSquare) {
    if(sigmaSquare <= 0){
        throw ParametroInvalidoException("sigma^2 debe ser mayor que 0");
    }
    this->mu = mu;
    this->sigmaSquare = sigmaSquare;
}

float DTNormal::getMu() const {
    return mu;
}
float DTNormal::getSigmaSquare() const {
    return sigmaSquare;
}