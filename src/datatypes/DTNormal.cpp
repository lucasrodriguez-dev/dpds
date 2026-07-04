#include "DTNormal.h"

DTNormal::DTNormal(float mu, float sigmaSquare) {
    this->mu = mu;
    this->sigmaSquare = sigmaSquare;
}

float DTNormal::getMu() const {
    return mu;
}
float DTNormal::getSigmaSquare() const {
    return sigmaSquare;
}